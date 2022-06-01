#include "pch-il2cpp.h"
#include "PermissionGroup.h"

#include "PermissionGroups.h"

bool PermissionGroup::HasPermission(std::string permission) {
	auto permissions = GetPermissions();

	for (auto p : permissions)
	{
		if (p.compare("*") == 0) return true;
		if (p.compare(permission) == 0) return true;
	}
	return false;
}

bool PermissionGroup::ThisGroupHasPermission(std::string permission) {
	auto permissions = m_Permissions;

	for (auto p : permissions)
	{
		if (p.compare("*") == 0) return true;
		if (p.compare(permission) == 0) return true;
	}
	return false;
}

bool PermissionGroup::AddPermission(std::string permission) {
	if (HasPermission(permission)) return false;
	m_Permissions.push_back(permission);
	return true;
}

bool PermissionGroup::RemovePermission(std::string permission) {
	if (!HasPermission(permission)) return false;

	std::vector<std::string>::iterator itr = std::find(m_Permissions.begin(), m_Permissions.end(), permission);
	if (itr != m_Permissions.end()) m_Permissions.erase(itr);
	return true;
}

std::vector<std::string> PermissionGroup::GetPermissions()
{
	std::vector<std::string> allPerms;

	for (auto p : m_Permissions)
	{
		allPerms.push_back(p);
	}

	if (m_InheritsFromGroup.size() > 0)
	{
		if (PermissionGroups::HasGroup(m_InheritsFromGroup))
		{
			auto perms = PermissionGroups::GetGroup(m_InheritsFromGroup)->m_Permissions;

			for (auto p : perms)
			{
				if (!ThisGroupHasPermission(p))
				{
					allPerms.push_back(p);
				}
			}
		}
	}

	return allPerms;
}