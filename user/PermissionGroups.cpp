#include "pch-il2cpp.h"
#include "PermissionGroups.h"

#include "Config.h"

std::map<std::string, PermissionGroup*> PermissionGroups::Groups;

bool PermissionGroups::HasGroup(std::string id)
{
	return Groups.find(id) != Groups.end();
}

PermissionGroup* PermissionGroups::AddGroup(std::string id)
{
	if (HasGroup(id)) throw "Group " + id + " already exists";

	std::cout << "[PermissionGroups] AddGroup " << id << std::endl;

	PermissionGroup* group = new PermissionGroup();
	group->Name = id;
	Groups[id] = group;
	return group;
}

PermissionGroup* PermissionGroups::GetGroup(std::string id)
{
	if (!HasGroup(id)) throw "Group " + id + " not found";

	return Groups[id];
}

void PermissionGroups::RemoveGroup(std::string id)
{
	if (!HasGroup(id)) throw "Group " + id + " not found";

	std::cout << "[PermissionGroups] RemoveGroup " << id << std::endl;

	Groups.erase(id);
}

std::string PermissionGroups::GetPermissionGroupsDirectory()
{
	return Config::GetPath(Config::PATH_PERMISSION_GROUPS_FOLDER);
}

void PermissionGroups::LoadConfig()
{
	std::cout << "[PermissionGroups] LoadConfig" << std::endl;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(GetPermissionGroupsDirectory()))
	{
		auto id = entry.path().filename().replace_extension().string();
		auto fileName = entry.path().filename().string();
	
		std::cout << "[PermissionGroups] Loading permission group " << id << std::endl;

		auto permissionGroup = PermissionGroups::AddGroup(id);
		permissionGroup->LoadFromINIFile(fileName);

		std::cout << "[PermissionGroups] - permissions: " << formatStringVector(permissionGroup->GetPermissions(), ", ") << std::endl;
	}
}

void PermissionGroups::SaveConfig()
{
	std::cout << "[PermissionGroups] SaveConfig" << std::endl;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(GetPermissionGroupsDirectory()))
	{
		std::experimental::filesystem::remove_all(entry.path());
	}

	for (auto pair : Groups)
	{
		auto id = pair.first;
		auto group = pair.second;

		//std::cout << "[PermissionGroups] Saving permission group " << id << std::endl;

		group->SaveToINIFile(id + ".ini");
	}
}