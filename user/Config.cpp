#include "pch-il2cpp.h"
#include "Config.h"

#include <fstream>
#include <experimental/filesystem>

#include "PermissionGroups.h"
#include "Server.h"
#include "Chat.h"

std::string Config::m_ServerDir = "server/";
std::string Config::m_ConfigFile = "config.json";
std::string Config::m_PermissionsFile = "permissions.json";
std::string Config::m_UsersFile = "users.json";
bool Config::m_FirstTimeConfig = false;

bool Config::Exists(std::string path)
{
	return std::experimental::filesystem::v1::exists(path);
}

void Config::CreatePath(std::string path)
{
	if (!std::experimental::filesystem::v1::is_directory(path) || !std::experimental::filesystem::v1::exists(path)) {
		std::experimental::filesystem::v1::create_directory(path);
	}
}

void Config::WriteToFile(std::string path, Json::Value value)
{
	//std::cout << "[Config] WriteToFile " << path << std::endl;

	Json::StyledWriter writer;
	std::string strJson = writer.write(value);

	std::ofstream file(path);
	file << strJson;
	file.close();
}

Json::Value Config::ReadFile(std::string path)
{
	//std::cout << "[Config] ReadFile " << path << std::endl;

	std::ifstream file(path);

	Json::Value value;
	Json::Reader reader;

	if (!reader.parse(file, value, true)) {
		std::cout << "[Config] ERROR reading " << path << std::endl;
	}

	return value;
}

void Config::SaveJSON()
{
	std::cout << "[Config] Saving config" << std::endl;

	CreatePath("server");

	//

	Json::Value configValue;
	configValue["show_death_status_after_name"] = Chat::m_ShowDeathStatusAfterName;
	configValue["show_id_after_name"] = Chat::m_ShowIdAfterName;
	configValue["show_help_message"] = Chat::m_ShowHelpMessage;

	WriteToFile(m_ServerDir + m_ConfigFile, configValue);

	//

	Json::Value permissionsValue;

	for (auto pair : PermissionGroups::m_Groups)
	{
		auto key = pair.first;
		auto group = pair.second;

		Json::Value groupValue;
		groupValue["name"] = group->m_Name;
		groupValue["inherits_from"] = group->m_InheritsFromGroup;

		groupValue["permissions"] = Json::arrayValue;
		for (auto perm : group->m_Permissions)
		{
			groupValue["permissions"].append(perm);
		}

		permissionsValue[key] = groupValue;
	}

	WriteToFile(m_ServerDir + m_PermissionsFile, permissionsValue);

	//

	Json::Value usersValue = Json::objectValue;

	for (auto pair : Server::m_Players)
	{
		auto key = pair.first;
		auto player = pair.second;

		Json::Value playerValue;
		playerValue["username"] = player->m_Username;
		playerValue["group"] = player->m_PermissionGroup;

		usersValue[std::to_string(key)] = playerValue;
	}

	WriteToFile(m_ServerDir + m_UsersFile, usersValue);
}

void Config::LoadJSON()
{
	std::cout << "[Config] Loading config" << std::endl;

	if (!Exists("server/")) return;

	//

	Json::Value configValue = ReadFile(m_ServerDir + m_ConfigFile);
	Chat::m_ShowDeathStatusAfterName = configValue["show_death_status_after_name"].asBool();
	Chat::m_ShowIdAfterName = configValue["show_id_after_name"].asBool();
	Chat::m_ShowHelpMessage = configValue["show_help_message"].asBool();

	//

	Json::Value permissionsValue = ReadFile(m_ServerDir + m_PermissionsFile);

	for (auto key : permissionsValue.getMemberNames())
	{
		Json::Value groupValue = permissionsValue[key];

		if (!PermissionGroups::HasGroup(key)) {
			PermissionGroups::AddGroup(key);
		}

		auto group = PermissionGroups::GetGroup(key);

		group->m_Name = groupValue["name"].asString();
		group->m_InheritsFromGroup = groupValue["inherits_from"].asString();

		group->m_Permissions.clear();
		for (int i = 0; i < (int)groupValue["permissions"].size(); i++)
		{
			group->m_Permissions.push_back(groupValue["permissions"][i].asString());
		}
	}

	//

	Json::Value usersValue = ReadFile(m_ServerDir + m_UsersFile);

	for (auto key : usersValue.getMemberNames())
	{
		auto playerValue = usersValue[key];
		auto clientId = std::stoll(key);

		if (!Server::HasPlayer(clientId))
		{
			auto player = new Player(clientId);
			Server::AddPlayer(player);
		}

		auto player = Server::GetPlayer(clientId);
		
		player->m_Username = playerValue["username"].asString();
		player->m_PermissionGroup = playerValue["group"].asString();
	}
}