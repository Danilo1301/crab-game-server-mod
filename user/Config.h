#pragma once

#include "pch.h"

class Config {
public:
	static std::string PATH_SERVER_FOLDER;
	static std::string PATH_DATA_FOLDER;
	static std::string PATH_PERMISSIONS_FOLDER;
	static std::string PATH_PERMISSION_GROUPS_FOLDER;

	static std::string PATH_CONFIG_FILE;
	static std::string PATH_PLAYERS_FILE;
	static std::string PATH_VERSION_FILE;

	static float AutoSaveTimeElapsed;
	static float AutoSaveInterval;

	static bool Exists(std::string path);
	static void CreatePath(std::string path);
	static std::string GetPath(std::string path);

	static void WriteToFile(std::string path, Json::Value value);
	static Json::Value ReadFile(std::string path);

	static void Save();
	static void Load();
	static void Reload();
	static void ProcessAutoSave(float dt);
	static void SaveConfigFile();
	static void LoadConfigFile();
	static void SavePlayers();
	static void LoadPlayers();

private:
	static void ProcessV2toV3ConfigLoad();
	//static bool ProcessVersionChange(std::string oldVersion);
	static void ApplyVersionChangePrePatch(std::string prevVersion, std::string currentVersion);
	static void ApplyVersionChangePostPatch(std::string prevVersion, std::string currentVersion);

	static void CreatePaths();
};