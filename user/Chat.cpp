#include "pch-il2cpp.h"
#include "Chat.h"

#include "Server.h"
#include "Mod.h"
#include "commands/commands.h"

std::vector<Message*> Chat::m_Messages;
std::vector<Command*> Chat::m_Commands;

void Chat::Init()
{
	std::cout << "[Chat] Init" << std::endl;

	RegisterCommand((Command*)new CommandHelp());
	RegisterCommand((Command*)new CommandTest());
	RegisterCommand((Command*)new CommandRestart());
	RegisterCommand((Command*)new CommandKill());
	RegisterCommand((Command*)new CommandTime());
	RegisterCommand((Command*)new CommandWeapon());
	RegisterCommand((Command*)new CommandHand());
	RegisterCommand((Command*)new CommandRespawn());
	RegisterCommand((Command*)new CommandMap());
}

void Chat::Update(float dt)
{

}

void Chat::RegisterCommand(Command* command)
{
	std::cout << "[Chat] RegisterCommand '" << command->m_Cmd << "'" << std::endl;

	m_Commands.push_back(command);
}

void Chat::ProcessMessage(Message* message)
{
	//std::cout << "[Chat] Process Message from (" << message->m_FromClient << ") '" << message->m_Content << "'" << std::endl;

	m_Messages.push_back(message);

	if (message->m_IsCommand)
	{
		ProcessCommandMessage(message);
	}

	/*
	if (message->m_Player->m_HideMessages) {
		std::cout << "hide messages" << std::endl;

		for (size_t i = 0; i < m_Messages.size(); i++)
		{
			Message* message = m_Messages[i];

			if (message->m_SendType == MessageSendType::NORMAL) {
				message->m_SendType = MessageSendType::FORCE_PRIVATE;
			}
		}
	}
	*/
}

void Chat::ProcessCommandMessage(Message* message)
{
	bool commandFound = false;

	for (auto command : m_Commands)
	{
		if (!command->Check(message->m_Cmd)) continue;

		commandFound = true;

		if (!command->CheckPermissions(message->m_Player))
		{
			command->NoPermission();
			continue;
		}

		/*
		if (command->m_LobbyOnly && !Server::m_IsAtLobby)
		{
			if (!message->m_Player->GetPermissionGroup()->HasPermission("lobbyonly.bypass"))
			{
				SendServerMessage("you must be on lobby");
				continue;
			}
		}
		*/

		try
		{
			command->Execute(message);
		}
		catch (const std::runtime_error& re)
		{
			std::string errstr = re.what();
			SendServerMessage("runtime Error: " + errstr);
		}
		catch (const std::exception& ex)
		{
			std::string errstr = ex.what();
			SendServerMessage("error: " + errstr);

		}
		catch (...)
		{
			SendServerMessage("error");
		}
	}

	if (!commandFound) SendServerMessage("unknown command '" + message->m_Cmd + "'");
	
}


void Chat::SendAllMessagesInQuery()
{
	while (m_Messages.size() > 0)
	{
		//std::cout << "[Chat] Messages: " << m_Messages.size() << std::endl;

		auto message = m_Messages[0];
		auto content = message->m_Content;

		
		auto fromStr = std::to_string(message->m_FromClient);

		if (message->m_Player != NULL) {
			auto player = message->m_Player;

			content = player->GetChatSuffix() + " " + content;
			fromStr = player->GetDisplayName();
		}

		std::cout << "[Chat] Message from (" << fromStr << ") '" << message->m_Content << "'" << std::endl;

		if (message->m_SendType == MessageSendType::FORCE_PRIVATE) Mod::AppendLocalChatMessage(2, "[PRIVATE]", content);
		if (message->m_SendType == MessageSendType::NORMAL || message->m_SendType == MessageSendType::FORCE_SEND) Mod::SendChatMessage(message->m_FromClient, content);

		RemoveMessage(message);

		std::cout << "[Chat] Messages left: " << m_Messages.size() << std::endl;

	}
}

void Chat::RemoveMessage(Message* message)
{
	auto it = std::find(m_Messages.begin(), m_Messages.end(), message);
	if (it == m_Messages.end()) return;
	m_Messages.erase(it);
	delete message;
}

Message* Chat::SendServerMessage(std::string text)
{
	std::cout << "[Chat] SendServerMessage: " << text << std::endl;

	Message* message = new Message((long long)1, text);
	m_Messages.push_back(message);
	return message;
}

void Chat::SendServerMessage(std::vector<std::string> lines)
{
	for (auto message : lines)
	{
		SendServerMessage(message);
	}
}