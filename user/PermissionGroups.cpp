#include "pch-il2cpp.h"
#include "PermissionGroups.h"

std::map<std::string, PermissionGroup*> PermissionGroups::m_Groups;

bool PermissionGroups::HasGroup(std::string name)
{
	return m_Groups.find(name) != m_Groups.end();
}

PermissionGroup* PermissionGroups::AddGroup(std::string name)
{
	PermissionGroup* group = new PermissionGroup();
	group->m_Name = name;
	m_Groups[name] = group;
	return group;
}

PermissionGroup* PermissionGroups::GetGroup(std::string name)
{
	if (!HasGroup(name)) return GetGroup("default");
	return m_Groups[name];
}

void PermissionGroups::RemoveGroup(std::string name)
{
	m_Groups.erase(name);
}

