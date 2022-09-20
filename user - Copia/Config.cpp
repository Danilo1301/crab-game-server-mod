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
}

void Config::LoadJSON()
{
	if (!Exists("server/"))
	{
		std::cout << "[Config] Config not found" << std::endl;
		return;
	}

	std::cout << "[Config] Loading config" << std::endl;
}