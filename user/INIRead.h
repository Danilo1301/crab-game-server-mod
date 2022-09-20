#pragma once

#include "pch.h"

class INIRead {
public:
	static std::string GetString(std::string path, std::string app, std::string key);
	static int GetInt(std::string path, std::string app, std::string key);
	static float GetFloat(std::string path, std::string app, std::string key);
	static bool GetBool(std::string path, std::string app, std::string key);

	static std::vector<std::string> GetMultipleStrings(std::string path, std::string app);
};

class INIWrite {
public:
	static std::ofstream File;
	static void CreateINIFile(std::string path);
	static void AddLine(std::string value);
	static void AddString(std::string key, std::string value);
	static void AddInt(std::string key, int value);
	static void AddFloat(std::string key, float value);
	static void AddBool(std::string key, bool value);
	static void CloseINIFile();
};