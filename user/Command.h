#pragma once

#include "pch.h"

#include "Message.h"

class Command {
public:
	std::string m_Cmd;
	std::vector<std::string> m_RequiredPermissions;
	std::vector<std::string> m_Aliases;

	bool m_IsAdminCommand = false;
	bool m_ShowOnHelpPage = true;

	Command();

	void SetCmd(std::string cmd);
	bool Check(std::string str);
	void AddRequiredPermission(std::string permission);
	void ShowOnHelpPage(bool show);
	void SetIsAdminCommand(bool state);
	void AddAlias(std::string cmd);

	virtual void Execute(Message* message);
	virtual bool CheckPermissions(Player* player);
	virtual void PrintSyntaxes();

	void WrongSyntax();
	void PlayerNotFound();
	void PrintSyntax(std::string syntax);
	void NoPermission();
};