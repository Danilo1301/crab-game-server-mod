#pragma once

#include "pch.h"


class CommandInfo {
public:
	std::vector<std::string> m_Permissions;
	bool m_Enabled = true;

	bool HasPermission(std::string permission) {
		for (size_t i = 0; i < m_Permissions.size(); i++)
		{
			auto p = m_Permissions[i];

			if (p.compare(permission) == 0) {
				return true;
			}
		}
		return false;
	}

	void AddPermission(std::string permission) {
		if (HasPermission(permission)) return;

		m_Permissions.push_back(permission);
	}

	void RemovePermission(std::string permission) {
		if (!HasPermission(permission)) return;

		std::vector<std::string>::iterator itr = std::find(m_Permissions.begin(), m_Permissions.end(), permission);
		if (itr != m_Permissions.end()) m_Permissions.erase(itr);
	}
};

class Commands {
public:
	static std::map<std::string, CommandInfo*> m_CommandInfos;

	static bool GetCommandInfo(std::string cmd, CommandInfo*& info);
	static CommandInfo* RegisterCommand(std::string cmd, std::string perms);

};
