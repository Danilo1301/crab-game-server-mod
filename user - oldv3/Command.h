#pragma once

#include "pch.h"

#include "Message.h"
#include "CommandArgs.h"

class Command {
public:
	std::string m_Cmd;
	std::vector<std::string> m_RequiredPermissions;
	std::vector<std::string> m_Aliases;

	bool m_ShowOnHelpPage = true;
	bool m_LobbyOnly = false;

	Message* m_CurrentMessage = NULL;
	std::vector<CommandArg> m_CurrentArgs;

	Command();

	void SetCmd(std::string cmd);
	bool Check(std::string str);
	void AddRequiredPermission(std::string permission);
	void ShowOnHelpPage(bool show);
	void SetLobbyOnly(bool state);
	void AddAlias(std::string cmd);

	virtual void Execute(Message* message);
	Player* GetPlayer();
	bool HasArg(int index);
	CommandArg GetArg(int index);

	std::string GetArgText(int index) {
		std::string s;

		int size = (int)m_CurrentArgs.size();
		for (int i = 1; i < size; i++) {
			s += m_CurrentArgs[i].str;
			if (i != size - 1) s += " ";
		}

		return s;
	}

	virtual bool CheckPermissions(Player* player);
	virtual void PrintSyntaxes();

	void WrongSyntax();
	void PlayerNotFound();
	void PrintSyntax(std::string syntax);
	void NoPermission();
};