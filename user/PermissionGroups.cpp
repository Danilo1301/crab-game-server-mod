#include "pch-il2cpp.h"
#include "PermissionGroups.h"

#include "Config.h"
#include "Weapon.h"

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

	auto path = GetPermissionGroupsDirectory();

	int totalGroups = 0;

	for (const auto& entry : std::experimental::filesystem::directory_iterator(GetPermissionGroupsDirectory()))
	{
		auto id = entry.path().filename().replace_extension().string();
		auto fileName = entry.path().filename().string();
	
		std::cout << "[PermissionGroups] Loading permission group " << id << std::endl;

		auto permissionGroup = PermissionGroups::AddGroup(id);
		permissionGroup->LoadFromINIFile(fileName);

		std::cout << "                   - permissions: " << formatStringVector(permissionGroup->GetPermissions(), ", ") << std::endl;

		totalGroups++;
	}

	if (totalGroups == 0)
	{
		std::cout << "[PermissionGroups] permission groups not found" << std::endl;
		CreateDefaultGroups();
		SaveConfig();
		return;
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

void PermissionGroups::ReloadConfig()
{
	std::vector<std::string> keys;

	for (auto pair : Groups)
	{
		keys.push_back(pair.first);
	}

	for (auto key : keys)
	{
		RemoveGroup(key);
	}

	LoadConfig();
}

void PermissionGroups::CreateDefaultGroups()
{
	if (!HasGroup("default"))
	{
		auto permissionGroup = AddGroup("default");
		permissionGroup->Name = "Default";
		permissionGroup->AddPermission("help");
		permissionGroup->AddPermission("ahelp");
		permissionGroup->AddPermission("w");
		permissionGroup->AddPermission("playerinfo");
		permissionGroup->AddPermission("tp");
		permissionGroup->AddPermission("kill");
		permissionGroup->AddPermission("respawn");
		//permissionGroup->AddPermission("autorespawn");
		permissionGroup->AddPermission("hover");
		permissionGroup->AddPermission("jumppunch");
		permissionGroup->AddPermission("superpunch");
		permissionGroup->AddPermission("forcefield");
		permissionGroup->AddPermission("snowball2");
		permissionGroup->AddPermission("vote");
		permissionGroup->AddPermission("votekick");
		permissionGroup->AddPermission("hand");
		for (auto weapon : WeaponList) permissionGroup->AddPermission(toLower(weapon.name));
	}

	if (!HasGroup("mod"))
	{
		auto permissionGroup = AddGroup("mod");
		permissionGroup->Name = "Mod";
		permissionGroup->InheritsFromGroup = "default";
		permissionGroup->AddPermission("kick");
		permissionGroup->AddPermission("ban");
		permissionGroup->AddPermission("unban");
		permissionGroup->AddPermission("bc");
		permissionGroup->AddPermission("givew");
		permissionGroup->AddPermission("respawn.others");
		permissionGroup->AddPermission("kill.others");
		permissionGroup->AddPermission("tp.others");
		permissionGroup->AddPermission("god");
		permissionGroup->AddPermission("god.others");
		permissionGroup->AddPermission("time");
		permissionGroup->AddPermission("r");
		permissionGroup->AddPermission("mute");
		permissionGroup->AddPermission("lobbyonly");
		permissionGroup->AddPermission("start");
		permissionGroup->AddPermission("win");
		permissionGroup->AddPermission("dm");
		permissionGroup->AddPermission("fly");
		permissionGroup->AddPermission("autostart");
		permissionGroup->AddPermission("punchdamage");
		permissionGroup->AddPermission("whitelist");
	}
	
	if (!HasGroup("admin"))
	{
		auto permissionGroup = AddGroup("admin");
		permissionGroup->Name = "Admin";
		permissionGroup->AddPermission("*");
	}
}