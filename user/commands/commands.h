#pragma once

#include "Mod.h"
#include "Command.h"
#include "CommandArgs.h"
#include "PermissionGroups.h"
#include "Chat.h"
#include "Message.h"
#include "Server.h"

class CommandHelp : public Command {
public:
	CommandHelp()
	{
		Command::Command();

		SetCmd("help");
		AddAlias("page");
		AddRequiredPermission("help");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(page) - Help page");
		PrintSyntax("(command) - Command help");
	}
};