#pragma once

#include "pch.h"

class PermissionGroup {
public:
	std::string Name = "";
	std::string InheritsFromGroup = "";
	std::vector<std::string> Permissions;

	bool HasPermission(std::string permission); //including inheritance
	bool ThisGroupHasPermission(std::string permission);
	bool AddPermission(std::string permission);
	bool RemovePermission(std::string permission);
	std::vector<std::string> GetPermissions();

	void LoadFromINIFile(std::string fileName);
	void SaveToINIFile(std::string fileName);
};