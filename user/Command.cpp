#include "pch-il2cpp.h"
#include "Command.h"
#include "Chat.h"

Command::Command()
{
}

void Command::SetCmd(std::string cmd)
{
	m_Cmd = cmd;
}

bool Command::Check(std::string str)
{
	if (toLower(str).compare(toLower(m_Cmd)) == 0) return true;

	for(auto alias : m_Aliases)
		if (toLower(str).compare(toLower(alias)) == 0) return true;

	return false;
}

void Command::AddRequiredPermission(std::string permission)
{
	m_RequiredPermissions.push_back(permission);
}

void Command::ShowOnHelpPage(bool show)
{
	m_ShowOnHelpPage = show;
}

void Command::SetIsAdminCommand(bool state)
{
	m_IsAdminCommand = state;
}

void Command::AddAlias(std::string cmd)
{
	m_Aliases.push_back(cmd);
}

void Command::Execute(Message* message)
{
	//std::cout << "[Command : " << m_Cmd << "] Execute" << std::endl;
}

bool Command::CheckPermissions(Player* player)
{
	auto permissionGroup = player->GetPermissionGroup();
	auto permissions = permissionGroup->GetPermissions();

	if (permissionGroup->HasPermission("*"))
	{
		return true;
	}

	for (auto perm : m_RequiredPermissions)
	{
		if (!permissionGroup->HasPermission(perm))
		{
			//Chat::SendServerMessage(perm + " perm is required");
			return false;
		}
	}	

	//if (player->m_Id == 1) return true;
	return true;
}

void Command::PrintSyntaxes()
{
	//std::cout << "[Command : " << m_Cmd << "] PrintSyntaxes" << std::endl;
}

void Command::WrongSyntax()
{
	Chat::SendServerMessage("* wrong syntax, type: ( !help " + m_Cmd + " )");
}

void Command::PlayerNotFound()
{
	Chat::SendServerMessage("player not found");
}

void Command::PrintSyntax(std::string syntax)
{
	Chat::SendServerMessage("* !" + m_Cmd + " " + syntax);
}

void Command::NoPermission()
{
	Chat::SendServerMessage("no permission");
}