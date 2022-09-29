#pragma once

#include "pch.h"

#include "Message.h"
#include "CommandArgs.h"

class Command {
public:
	static bool AutoShowHelp;

	std::string Cmd;
	std::vector<std::string> RequiredPermissions;
	std::vector<std::string> Aliases;

	bool ShowOnHelpPage = true;
	bool LobbyOnly = false;
	

	Message* CurrentMessage = NULL;
	std::vector<CommandArg> CurrentArgs;

	Command();

	void SetCmd(std::string cmd);
	bool Check(std::string str);
	void AddRequiredPermission(std::string permission);
	void SetShowOnHelpPage(bool show);
	void SetLobbyOnly(bool state);
	void AddAlias(std::string cmd);

	virtual void Execute(Message* message);
	Player* GetPlayer();
	bool HasArg(int index);
	CommandArg GetArg(int index);

	std::string GetArgText(int index) {
		std::string s;

		int size = (int)CurrentArgs.size();
		for (int i = 1; i < size; i++) {
			s += CurrentArgs[i].str;
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

	bool CheckOwnerIsTarget(Player* target);
};