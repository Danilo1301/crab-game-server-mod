#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class PermissionGroups {
public:
	static std::map<std::string, PermissionGroup*> m_Groups;

	static bool HasGroup(std::string name);
	static PermissionGroup* AddGroup(std::string name);
	static PermissionGroup* GetGroup(std::string name);
};