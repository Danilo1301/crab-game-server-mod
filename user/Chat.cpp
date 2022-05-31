#include "pch-il2cpp.h"
#include "Chat.h"

#include "Server.h"
#include "Mod.h"
#include "commands/commands.h"

std::vector<Message*> Chat::m_Messages;
std::vector<Command*> Chat::m_Commands;

bool Chat::m_ShowHelpMessage = true;
float Chat::m_BroadCastHelpTime = 0;

void Chat::Init()
{
	RegisterCommand((Command*)new CommandHelp());
	RegisterCommand((Command*)new CommandAHelp());
	RegisterCommand((Command*)new CommandWeapon());
	RegisterCommand((Command*)new CommandPlayerInfo());
	RegisterCommand((Command*)new CommandPerm());
	RegisterCommand((Command*)new CommandTeleport());
	RegisterCommand((Command*)new CommandAllCommands());
	RegisterCommand((Command*)new CommandMute());
	RegisterCommand((Command*)new CommandKick());
	RegisterCommand((Command*)new CommandBan());
	RegisterCommand((Command*)new CommandRestart());
	RegisterCommand((Command*)new CommandGod());
	RegisterCommand((Command*)new CommandKill());
	RegisterCommand((Command*)new CommandRespawn());
	RegisterCommand((Command*)new CommandTime());
	RegisterCommand((Command*)new CommandVanish());
	RegisterCommand((Command*)new CommandAutoRespawn());
	RegisterCommand((Command*)new CommandToggleWeapon());
	RegisterCommand((Command*)new CommandDownload());
	RegisterCommand((Command*)new CommandWin());
	RegisterCommand((Command*)new CommandHover());
	RegisterCommand((Command*)new CommandStart());
	RegisterCommand((Command*)new CommandBroadcast());
	RegisterCommand((Command*)new CommandAutoStart());
	RegisterCommand((Command*)new CommandJumpPunch());
	RegisterCommand((Command*)new CommandSuperPunch());
	RegisterCommand((Command*)new CommandForceField());
	RegisterCommand((Command*)new CommandShowHelp());
	RegisterCommand((Command*)new CommandPunchDamage());
	RegisterCommand((Command*)new CommandMultiSnowball());
	RegisterCommand((Command*)new CommandLobbyOnly());
}

void Chat::Update(float dt)
{
	for (auto pair : Server::m_Players)
	{
		auto player = pair.second;

		if (player->m_MuteTime > 0) {
			player->m_MuteTime -= dt;

			if (player->m_MuteTime < 0) player->m_MuteTime = 0;
		}
	}

	m_BroadCastHelpTime += dt;
	if (m_BroadCastHelpTime >= 60.0f && m_ShowHelpMessage) {
		m_BroadCastHelpTime = 0;
		Chat::SendServerMessage(" Type !help for a list of commands");
	}

	SendAllMessagesInQuery();

}

void Chat::ProcessRawMessage(long long clientId, std::string text, bool dontSend)
{
	if (Server::m_UpdateRequired)
	{
		std::cout << "[Chat] Update is required" << std::endl;
 		return;
	}

	std::cout << "[Chat] * Message from " << clientId << ": '" << text << std::endl;
	Message* message = new Message(clientId, text);

	if (Server::HasPlayer(clientId))
	{
		message->m_Player = Server::GetPlayer(clientId);
		if (message->m_Player->m_MuteTime > 0) {
			return;
		}
	}

	m_Messages.push_back(message);

	if (message->m_Player > 0) {
		try
		{
			ProcessMessage(message);
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

	//
	if (message->m_Player != NULL) {
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
	}
	//

	if (dontSend) RemoveMessage(message);

	SendAllMessagesInQuery();
}

void Chat::ProcessMessage(Message* message)
{
	Player* player = message->m_Player;
	std::string content = message->m_Content;
	//std::cout << "[Chat] ProcessMessage " << player->m_Username << " (" << player->m_ClientId << "): " << content << "'" << std::endl;

	if (message->m_IsCommand) {
		
		if (ProcessWeaponCommand(message)) return;

		bool commandFound = false;

		for (auto command : m_Commands) {
			if (command->Check("*")) {
				command->Execute(message);
				continue;
			}

			if (!command->Check(message->m_Cmd)) continue;

			commandFound = true;

			if (!command->CheckPermissions(message->m_Player)) {
				command->NoPermission();
				continue;
			}

			if (command->m_LobbyOnly)
			{
				if (!Server::m_IsAtLobby)
				{
					if (!message->m_Player->GetPermissionGroup()->HasPermission("lobbyonly.bypass"))
					{
						SendServerMessage("you must be on lobby");
						continue;
					}
				}

			}

			command->Execute(message);
		}

		if (!commandFound) {
			SendServerMessage("unknown command '" + message->m_Cmd + "'");
		}
	}
}

bool Chat::ProcessWeaponCommand(Message* message)
{

	for (auto weapon : Server::m_Weapons)
	{
		if ((toLower(message->m_Cmd)).compare(toLower(weapon.name)) == 0)
		{
			ProcessRawMessage(message->m_Player->m_ClientId, "!w " + std::to_string(weapon.id), true);
			return true;
		}
	}

	return false;
}

Message* Chat::SendServerMessage(std::string text)
{
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

void Chat::SendCommandsPage(std::vector<std::string> commands, int page)
{
	char buffer[512];
	int linesPerPage = 3;

	auto lines = formatStringVector_1(commands, ", ", 40);
	int maxPages = (int)ceil((float)lines.size() / (float)linesPerPage);

	int startLine = linesPerPage * page;

	sprintf_s(buffer, "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- --");
	Chat::SendServerMessage(buffer);

	for (int i = 0; i < (int)linesPerPage; i++)
	{
		int lineIndex = startLine + i;

		if (lineIndex < (int)lines.size()) {
			Chat::SendServerMessage(lines[lineIndex]);
		}
	}

	sprintf_s(buffer, "---- ---- ---- ---- ----  Page %d / %d ---- ---- ---- ---- ----", page + 1, maxPages);
	Chat::SendServerMessage(buffer);
}

void Chat::SendAllMessagesInQuery()
{
	if (m_Messages.size() > 0)
	{
		//std::cout << "sending " << m_Messages.size() << " messages" << std::endl;
	}

	while (m_Messages.size() > 0)
	{
		Message* message = m_Messages[0];
		std::string content = message->m_Content;

		/*
		if (message->m_Player != NULL) {
			auto player = message->m_Player;
			bool showAliveState = false;

			std::string str = "";
			if (showAliveState) str += player->m_IsAlive ? "" : "(dead) ";
			if (Server::m_ShowPlayerIds) str += "[" + std::to_string(player->m_PlayerId) + "] ";
			str += content;
			content = str;
		}
		*/

		//std::cout << "[Send Message : " << (int)message->m_SendType << "] from=" << message->m_FromClient << ", content='" << content << "'\n";

		if (message->m_SendType == MessageSendType::FORCE_PRIVATE) Mod::AppendLocalChatMessage(2, "[PRIVATE]", content);
		if (message->m_SendType == MessageSendType::NORMAL || message->m_SendType == MessageSendType::FORCE_SEND) Mod::SendChatMessage(message->m_FromClient, content);

		RemoveMessage(message);
	}
}

void Chat::RemoveMessage(Message* message)
{
	//std::cout << "Message removed " << message->m_Content << std::endl;

	auto it = std::find(m_Messages.begin(), m_Messages.end(), message);
	if (it == m_Messages.end()) return;
	m_Messages.erase(it);
	delete message;
}

void Chat::RemoveAllMessages()
{
	while (m_Messages.size() > 0) {
		RemoveMessage(Chat::m_Messages[0]);
	}
}

void Chat::RegisterCommand(Command* command)
{
	m_Commands.push_back(command);
	std::cout << "[Chat] RegisterCommand '" << command->m_Cmd << "'" << std::endl;
}