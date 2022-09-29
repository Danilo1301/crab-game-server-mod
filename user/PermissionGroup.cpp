#include "pch-il2cpp.h"
#include "PermissionGroup.h"

#include "PermissionGroups.h"
#include "INIRead.h"

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
	auto permissions = Permissions;

	for (auto p : permissions)
	{
		//if (p.compare("*") == 0) return true;
		if (p.compare(permission) == 0) return true;
	}
	return false;
}

bool PermissionGroup::AddPermission(std::string permission) {
	if (ThisGroupHasPermission(permission)) return false;
	Permissions.push_back(permission);
	return true;
}

bool PermissionGroup::RemovePermission(std::string permission) {
	if (!ThisGroupHasPermission(permission)) return false;

	std::vector<std::string>::iterator itr = std::find(Permissions.begin(), Permissions.end(), permission);
	if (itr != Permissions.end()) Permissions.erase(itr);
	return true;
}

std::vector<std::string> PermissionGroup::GetPermissions()
{
	std::vector<std::string> allPerms;

	for (auto p : Permissions)
	{
		allPerms.push_back(p);
	}

	if (InheritsFromGroup.size() > 0)
	{
		if (PermissionGroups::HasGroup(InheritsFromGroup))
		{
			auto perms = PermissionGroups::GetGroup(InheritsFromGroup)->Permissions;

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


void PermissionGroup::LoadFromINIFile(std::string fileName)
{
	auto path = PermissionGroups::GetPermissionGroupsDirectory() + fileName;

	Name = INIRead::GetString(path, "Group", "name");
	
	auto permissions = INIRead::GetMultipleStrings(path, "Permissions");
	for (auto permission : permissions) Permissions.push_back(permission);
}

void PermissionGroup::SaveToINIFile(std::string fileName)
{
	auto path = PermissionGroups::GetPermissionGroupsDirectory() + fileName;

	INIWrite::CreateINIFile(path);
	INIWrite::AddLine("[Group]");
	INIWrite::AddString("name", Name);
	INIWrite::AddLine("");
	INIWrite::AddLine("[Permissions]");
	for (auto permission : Permissions) INIWrite::AddLine(permission);
	INIWrite::CloseINIFile();
}