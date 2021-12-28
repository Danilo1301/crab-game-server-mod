#pragma once

#include "pch.h"

class CommandData {
public:
	std::vector<std::string> m_RequiredPermissions;

	void AddRequiredPermission(std::string permission) {
		m_RequiredPermissions.push_back(permission);
	}
};

class ChatCommand {
public:
	static std::map<std::string, CommandData*> m_Commands;

	static CommandData* AddCommand(std::string cmd);
};