#pragma once

#include "pch.h"

class PermissionGroup {
public:
	std::string m_Name = "";
	std::string m_InheritsFromGroup = "";
	std::vector<std::string> m_Permissions;

	bool HasPermission(std::string permission);
	bool ThisGroupHasPermission(std::string permission);
	bool AddPermission(std::string permission);
	bool RemovePermission(std::string permission);
	std::vector<std::string> GetPermissions();
};