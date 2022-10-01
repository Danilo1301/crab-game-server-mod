#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class PermissionGroups {
public:
	static std::map<std::string, PermissionGroup*> Groups;

	static bool HasGroup(std::string id);
	static PermissionGroup* AddGroup(std::string id);
	static PermissionGroup* GetGroup(std::string id);
	static void RemoveGroup(std::string id);

	static std::string GetPermissionGroupsDirectory();

	static void LoadConfig();
	static void SaveConfig();
	static void ReloadConfig();
};