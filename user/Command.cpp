#include "pch-il2cpp.h"
#include "Command.h"
#include "Chat.h"

Command::Command()
{
	m_CurrentArgs.clear();
	m_CurrentMessage = NULL;
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

void Command::SetLobbyOnly(bool state)
{
	m_LobbyOnly = state;
}

void Command::AddAlias(std::string cmd)
{
	m_Aliases.push_back(cmd);
}

void Command::Execute(Message* message)
{
	m_CurrentMessage = message;
	m_CurrentArgs = CommandArg::GetArgs(message->m_CmdArgs);

	//std::cout << "[Command : " << m_Cmd << "] Execute" << std::endl;
}

Player* Command::GetPlayer()
{
	return m_CurrentMessage->m_Player;
}

bool Command::HasArg(int index)
{
	return index < m_CurrentArgs.size();
}

CommandArg Command::GetArg(int index)
{
	return m_CurrentArgs[index];
}

bool Command::CheckPermissions(Player* player)
{
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