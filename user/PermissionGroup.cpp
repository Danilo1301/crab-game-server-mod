#include "pch-il2cpp.h"
#include "PermissionGroup.h"

bool PermissionGroup::HasPermission(std::string permission) {
	auto permissions = GetPermissions();

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
	return m_Permissions;
}