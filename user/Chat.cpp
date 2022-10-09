#include "pch-il2cpp.h"
#include "Chat.h"
#include "Server.h"
#include "Mod.h"
#include "commands/commands.h"

std::vector<Message*> Chat::Messages;
std::vector<Command*> Chat::Commands;

bool Chat::ShowPlayerIdsAfterName = true;
bool Chat::ShowDeathStateAfterName = false;

void Chat::Init()
{
	std::cout << "[Chat] Init" << std::endl;

	RegisterCommand((Command*)new CommandHelp());
	RegisterCommand((Command*)new CommandAHelp());
	RegisterCommand((Command*)new CommandTeleport());
	RegisterCommand((Command*)new CommandTest());
	RegisterCommand((Command*)new CommandKill());
	RegisterCommand((Command*)new CommandRestart());
	RegisterCommand((Command*)new CommandTime());
	RegisterCommand((Command*)new CommandWeapon());
	RegisterCommand((Command*)new CommandGiveWeapon());
	RegisterCommand((Command*)new CommandHand());
	RegisterCommand((Command*)new CommandRespawn());
	RegisterCommand((Command*)new CommandMap());
	RegisterCommand((Command*)new CommandPerm());
	RegisterCommand((Command*)new CommandPlayerInfo());
	//RegisterCommand((Command*)new CommandAllCommands());
	RegisterCommand((Command*)new CommandMute());
	RegisterCommand((Command*)new CommandKick());
	RegisterCommand((Command*)new CommandBan());
	RegisterCommand((Command*)new CommandUnban());
	RegisterCommand((Command*)new CommandGod());
	RegisterCommand((Command*)new CommandVanish());
	RegisterCommand((Command*)new CommandDownload());
	RegisterCommand((Command*)new CommandWin());
	RegisterCommand((Command*)new CommandStart());
	RegisterCommand((Command*)new CommandBroadcast());
	RegisterCommand((Command*)new CommandJumpPunch());
	RegisterCommand((Command*)new CommandSuperPunch());
	RegisterCommand((Command*)new CommandForceField());
	RegisterCommand((Command*)new CommandAutoStart());
	RegisterCommand((Command*)new CommandFly());
	RegisterCommand((Command*)new CommandLobbyOnly());
	RegisterCommand((Command*)new CommandDeathMatch());
	RegisterCommand((Command*)new CommandHover());
	RegisterCommand((Command*)new CommandVote());
	RegisterCommand((Command*)new CommandVoteKick());
	RegisterCommand((Command*)new CommandSkip());
	RegisterCommand((Command*)new CommandMultiSnowball());
	RegisterCommand((Command*)new CommandWhitelist());
	RegisterCommand((Command*)new CommandConfig());
	RegisterCommand((Command*)new CommandPunchDamage());
}

void Chat::Update(float dt)
{
	ProcessMute(dt);
}

void Chat::ProcessMute(float dt)
{
	for (auto pair : Server::Players)
	{
		auto player = pair.second;
		if (player->MuteTime > 0)
		{
			player->MuteTime -= dt;
			if (player->MuteTime < 0) player->MuteTime = 0;
		}
	}
}

void Chat::RegisterCommand(Command* command)
{
	std::cout << "[Chat] RegisterCommand '" << command->Cmd << "'" << std::endl;

	Commands.push_back(command);
}

Message* Chat::AddMessage(Message* message)
{
	//std::cout << "[Chat] Add Message from (" << message->FromClientId << ") '" << message->Content << "'" << std::endl;
	
	Messages.push_back(message);
	return message;
}

Message* Chat::AddMessageAndProcess(Message* message)
{
	AddMessage(message);
	ProcessMessage(message);
	return message;
}

void Chat::RemoveMessage(Message* message)
{
	auto it = std::find(Messages.begin(), Messages.end(), message);
	if (it == Messages.end()) return;
	Messages.erase(it);
	delete message;
}

void Chat::ProcessMessage(Message* message)
{
	std::cout << "[Chat] ProcessMessage from (" << (message->FromPlayer ? message->FromPlayer->GetDisplayNameExtra() : std::to_string(message->FromClientId)) << ") '" << message->Content << "'" << std::endl;

	bool isOwnerMessage = message->FromClientId == Server::GetLobbyOwner()->ClientId;

	if (message->FromPlayer != NULL)
	{
		if (message->FromPlayer->MuteTime > 0)
		{
			std::cout << "[Chat] Message removed. Muted for " << message->FromPlayer->MuteTime << " seconds" << std::endl;
			RemoveMessage(message);
			return;
		}
	}

	if (ProcessWeaponCommand(message))
	{
		message->IsCommand = false;
	}

	if (message->FromPlayer != NULL)
	{
		if (message->IsCommand)
		{
			ProcessCommandMessage(message);
		}

		if (message->FromPlayer->HideMessages)
		{
			message->SendType = MessageSendType::FORCE_PRIVATE;
		}
	}

	std::string newMessageContent = message->Content;

	if (message->FromPlayer)
	{
		newMessageContent = message->FromPlayer->GetChatSuffix() + " " + message->Content;
	}

	switch (message->SendType)
	{
	case MessageSendType::FORCE_PRIVATE:
		Mod::AppendLocalChatMessage(2, "[PRIVATE]", message->Content);
		break;
	case MessageSendType::FORCE_HIDE:
		//Mod::AppendLocalChatMessage(2, "[HIDDEN]", message->Content);
		break;
	default:
		Mod::SendChatMessage(message->FromClientId, newMessageContent);

		if (isOwnerMessage)
		{
			Mod::AppendLocalChatMessage(2, message->FromPlayer->Username, message->FromPlayer->GetChatSuffix() + " " + message->Content);
		}
		break;
	}

	RemoveMessage(message);

	//std::cout << "[Chat] Message sent (" << Messages.size() << " left)" << std::endl;
}

Command* Chat::FindCommand(std::string cmd)
{
	for (auto command : Commands)
	{
		if (command->Check(cmd)) return command;
	}
	return NULL;
}

/*
Called every Template_ChatBox_Update 
*/
void Chat::ProcessAllMessages()
{
	while (Messages.size() > 0)
	{
		ProcessMessage(Messages[0]);
	}
}

void Chat::ProcessCommandMessage(Message* message)
{
	Command* command = FindCommand(message->Cmd);

	if (!command)
	{
		SendServerMessage("unknown command '" + message->Cmd + "'");
		return;
	}

	if (!command->CheckPermissions(message->FromPlayer))
	{
		command->NoPermission();
		return;
	}

	if (command->LobbyOnly && !Server::IsAtLobby())
	{
		if (!message->FromPlayer->GetPermissionGroup()->HasPermission("lobbyonly.bypass"))
		{
			SendServerMessage("you must be on lobby");
			return;
		}
	}

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

bool Chat::ProcessWeaponCommand(Message* message)
{
	for (auto weapon : WeaponList)
	{
		if ((toLower(message->Cmd)).compare(toLower(weapon.name)) == 0)
		{
			Message* msg = new Message(message->FromPlayer, "!w " + std::to_string(weapon.id));
			msg->SendType = MessageSendType::FORCE_HIDE;

			AddMessage(msg);
			ProcessMessage(msg);

			return true;
		}
	}

	return false;
}

Message* Chat::SendServerMessage(std::string text)
{
	//std::cout << "[Chat] SendServerMessage: " << text << std::endl;

	return AddMessage(new Message((long long)1, text));
}

void Chat::SendServerMessage(std::vector<std::string> lines)
{
	for (auto message : lines)
	{
		SendServerMessage(message);
	}
}

void Chat::OnTrySendChatMessage(long long clientId, std::string content)
{
	if (Server::HasPlayer(clientId))
	{
		auto message = new Message(Server::GetPlayer(clientId), content);
		Chat::AddMessageAndProcess(message);
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

bool Chat::PrintCommanSyntaxes(std::string cmd)
{
	for (auto command : Chat::Commands)
	{
		if (!command->Check(cmd)) continue;

		command->PrintSyntaxes();
		//Chat::SendServerMessage("showing help for '" + command->m_Cmd + "'");

		return true;
	}
	return false;
}
