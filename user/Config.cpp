#include "pch-il2cpp.h"
#include "Config.h"

#include "PermissionGroups.h"
#include "Server.h"
#include "Mod.h"
#include "Chat.h"
#include "INIRead.h"

std::string Config::PATH_SERVER_FOLDER = "/server/";
std::string Config::PATH_PERMISSIONS_FOLDER = PATH_SERVER_FOLDER + "/permissions/";
std::string Config::PATH_PERMISSION_GROUPS_FOLDER = PATH_PERMISSIONS_FOLDER + "/groups/";

std::string Config::PATH_CONFIG_FILE = PATH_SERVER_FOLDER + "config.ini";
std::string Config::PATH_PLAYERS_FILE = PATH_SERVER_FOLDER + "players.json";
std::string Config::PATH_VERSION_FILE = PATH_SERVER_FOLDER + "version";

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

std::string Config::GetPath(std::string path)
{
	std::experimental::filesystem::path cwd = std::experimental::filesystem::current_path() / path;
	return cwd.string();
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

void Config::Save()
{
	std::cout << "[Config] Save" << std::endl;

	CreatePath(GetPath(PATH_SERVER_FOLDER));
	CreatePath(GetPath(PATH_PERMISSIONS_FOLDER));
	CreatePath(GetPath(PATH_PERMISSION_GROUPS_FOLDER));

	//version
	std::ofstream versionFile(GetPath(PATH_VERSION_FILE));
	versionFile << Mod::Version << std::endl;
	versionFile.close();

	//config.ini
	std::cout << "[Config] Saving " << PATH_CONFIG_FILE << std::endl;

	INIWrite::CreateINIFile(GetPath(PATH_CONFIG_FILE));
	INIWrite::AddLine("[Server]");
	INIWrite::AddBool("show_player_ids", Chat::ShowPlayerIdsAfterName);
	INIWrite::AddBool("show_death_status_after_name", Chat::ShowDeathStateAfterName);
	INIWrite::AddBool("help_message_show", Chat::ShowHelpMessage);
	INIWrite::AddString("help_message", Chat::HelpMessage);
	INIWrite::AddFloat("help_message_interval", Chat::BroadcastHelpInterval);
	INIWrite::AddBool("command_show_help_on_invalid_syntax", Command::AutoShowHelp);
	INIWrite::AddFloat("auto_save_interval", Server::AutoSaveInterval);

	INIWrite::CloseINIFile();

	//players.json
	std::cout << "[Config] Saving " << PATH_PLAYERS_FILE << std::endl;

	Json::Value playersValue = Json::objectValue;
	for (auto pair : Server::Players)
	{
		auto key = pair.first;
		auto player = pair.second;

		Json::Value playerValue;
		playerValue["username"] = player->Username;
		playerValue["group"] = player->PermissionGroupId;

		playersValue[std::to_string(key)] = playerValue;
	}

	WriteToFile(GetPath(PATH_PLAYERS_FILE), playersValue);

	//permissions
	PermissionGroups::SaveConfig();
}

void Config::Load()
{
	std::cout << "[Config] Load" << std::endl;

	ProcessV2toV3ConfigLoad();

	if (!Exists(GetPath(PATH_SERVER_FOLDER)))
	{
		std::cout << "[Config] Config not found" << std::endl;
		return;
	}

	//version
	std::string versionLine;
	std::ifstream versionFile(GetPath(PATH_VERSION_FILE));
	std::getline(versionFile, versionLine);
	versionFile.close();
	ProcessVersionChange(versionLine);

	//config.ini
	LoadConfigFile();

	//users.json
	std::cout << "[Config] Loading " << PATH_PLAYERS_FILE << std::endl;

	Json::Value usersValue = ReadFile(GetPath(PATH_PLAYERS_FILE));
	for (auto key : usersValue.getMemberNames())
	{
		auto playerValue = usersValue[key];
		auto clientId = std::stoll(key);
		auto player = Server::GetPlayer(clientId);

		if (!player) player = new Player(clientId);

		player->Username = playerValue["username"].asString();
		player->PermissionGroupId = playerValue["group"].asString();

		if (!Server::HasPlayer(clientId)) Server::AddPlayer(player);
	}

	//permissions
	PermissionGroups::LoadConfig();
}

void Config::LoadConfigFile()
{
	std::cout << "[Config] Loading " << PATH_CONFIG_FILE << std::endl;

	Chat::ShowPlayerIdsAfterName = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "show_player_ids");
	Chat::ShowDeathStateAfterName = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "show_death_status_after_name");
	Chat::ShowHelpMessage = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "help_message_show");
	Chat::HelpMessage = INIRead::GetString(GetPath(PATH_CONFIG_FILE), "Server", "help_message");
	Chat::BroadcastHelpInterval = INIRead::GetFloat(GetPath(PATH_CONFIG_FILE), "Server", "help_message_interval");
	Command::AutoShowHelp = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "command_show_help_on_invalid_syntax");
	Server::AutoSaveInterval = INIRead::GetFloat(GetPath(PATH_CONFIG_FILE), "Server", "auto_save_interval");

	std::cout << "[Config] AutoSaveInterval= " << Server::AutoSaveInterval << std::endl;
}

void Config::ProcessV2toV3ConfigLoad()
{
	if (Exists(GetPath(PATH_SERVER_FOLDER)) && !Exists(GetPath(PATH_VERSION_FILE)))
	{
		std::string msg = "The server folder (v1/v2) is incompatible with this new version (v3)\n\n> You need to DELETE the '/server/' folder to continue\n(Don't forget to backup)\n\nServer folder at:\n> " + GetPath(PATH_SERVER_FOLDER) + "";
		MessageBoxA(NULL, msg.c_str(), "Incompatible config", MB_OK | MB_ICONERROR);

		exit(0);
	}
}

void Config::ProcessVersionChange(std::string oldVersion)
{
	std::cout << "[Config] Updating from " << oldVersion << " to " << Mod::Version << std::endl;

	/*
	* EXAMPLE PATCH
	* 
	if (oldVersion == "3.0")
	{
		std::cout << "Applying test patch 3.1" << std::endl;
		oldVersion = "3.1";
	}
	*/
}

/*
Version history
3.0
*/