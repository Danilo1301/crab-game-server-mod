#pragma once

#include "pch.h"

class Config {
public:
	static std::string PATH_SERVER_FOLDER;
	static std::string PATH_PERMISSIONS_FOLDER;
	static std::string PATH_PERMISSION_GROUPS_FOLDER;

	static std::string PATH_CONFIG_FILE;
	static std::string PATH_PLAYERS_FILE;
	static std::string PATH_VERSION_FILE;

	static bool Exists(std::string path);
	static void CreatePath(std::string path);
	static std::string GetPath(std::string path);

	static void WriteToFile(std::string path, Json::Value value);
	static Json::Value ReadFile(std::string path);

	static void Save();
	static void Load();

private:
	static void ProcessV2toV3ConfigLoad();
	static void ProcessVersionChange(std::string oldVersion);
};