#pragma once

#include "pch.h"

class Config {
public:
	static std::string m_ServerDir;
	static std::string m_ConfigFile;
	static std::string m_PermissionsFile;
	static std::string m_UsersFile;
	static bool m_FirstTimeConfig;

	static bool Exists(std::string path);
	static void CreatePath(std::string path);

	static void WriteToFile(std::string path, Json::Value value);
	static Json::Value ReadFile(std::string path);

	static void SaveJSON();
	static void LoadJSON();

	
};