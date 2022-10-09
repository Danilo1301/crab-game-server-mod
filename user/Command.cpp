#include "pch-il2cpp.h"
#include "Command.h"
#include "Chat.h"

bool Command::AutoShowHelp = true;

Command::Command()
{
	CurrentArgs.clear();
	CurrentMessage = NULL;
}

void Command::SetCmd(std::string cmd)
{
	Cmd = cmd;
}

bool Command::Check(std::string str)
{
	if (toLower(str).compare(toLower(Cmd)) == 0) return true;

	for (auto alias : Aliases)
		if (toLower(str).compare(toLower(alias)) == 0) return true;

	return false;
}

void Command::AddRequiredPermission(std::string permission)
{
	RequiredPermissions.push_back(permission);
}

void Command::SetShowOnHelpPage(bool show)
{
	ShowOnHelpPage = show;
}

void Command::SetLobbyOnly(bool state)
{
	LobbyOnly = state;
}

void Command::AddAlias(std::string cmd)
{
	Aliases.push_back(cmd);
}

void Command::Execute(Message* message)
{
	CurrentMessage = message;
	CurrentArgs = CommandArg::GetArgs(message->CmdArgs);

	//std::cout << "[Command : " << m_Cmd << "] Execute" << std::endl;
}

Player* Command::GetPlayer()
{
	return CurrentMessage->FromPlayer;
}

bool Command::HasArg(int index)
{
	return index < CurrentArgs.size();
}

CommandArg Command::GetArg(int index)
{
	return CurrentArgs[index];
}

bool Command::CheckPermissions(Player* player)
{
	auto permissionGroup = player->GetPermissionGroup();
	auto permissions = permissionGroup->GetPermissions();

	if (permissionGroup->HasPermission("*")) return true;
	//if (player->m_Id == 1) return true;

	for (auto perm : RequiredPermissions)
	{
		if (!permissionGroup->HasPermission(perm))
		{
			//Chat::SendServerMessage(perm + " perm is required");
			return false;
		}
	}

	return true;
}

void Command::PrintSyntaxes()
{
	//std::cout << "[Command : " << m_Cmd << "] PrintSyntaxes" << std::endl;
}

void Command::WrongSyntax()
{
	if (AutoShowHelp)
	{
		if(Chat::PrintCommanSyntaxes(Cmd)) return;
	}

	Chat::SendServerMessage("* wrong syntax, type: ( !help " + Cmd + " )");

}

void Command::PlayerNotFound()
{
	Chat::SendServerMessage("player not found");
}

void Command::PrintSyntax(std::string syntax)
{
	PrintSyntax(Cmd, syntax);
}

void Command::PrintSyntax(std::string command, std::string syntax)
{
	Chat::SendServerMessage("* !" + command + " " + syntax);
}

void Command::NoPermission()
{
	Chat::SendServerMessage("no permission");
}

bool Command::CheckOwnerIsTarget(Player* target)
{
	if (!target->IsLobbyOwner()) return false; //target is not owner, can execute

	if (CurrentMessage->FromPlayer->IsLobbyOwner()) return false; //player who ran command is owner, so ok

	return true; //blocks command execution
}