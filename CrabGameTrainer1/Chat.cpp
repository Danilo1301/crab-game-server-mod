#include "Chat.h"
#include "Server.h"
#include "Mod.h"
#include "Commands.h"

std::vector<Message*> Chat::m_Messages;

std::string Chat::m_HelpMessage = "!ak !glock !revolver !dual !bat !granada !bomb;!katana !knife !pipe !stick !pizza !milk;!jumppunch !forcefield !superpunch;Test: !hat !light !bomber !tag";

Message* Chat::SendServerMessage(std::string text) {
	Message* message = new Message((long long)1, text);

	m_Messages.push_back(message);

	return message;
}

void Chat::SendAllMessagesInQuery() {
	for (size_t i = 0; i < m_Messages.size(); i++)
	{
		Message* message = m_Messages[i];

		std::string content = message->m_Content;

		if (message->m_Player != NULL) {
			auto player = message->m_Player;

			char buffer[512];
			sprintf_s(buffer, "%s[%d] %s", player->m_IsAlive ? "" : "(dead) ", player->m_PlayerId, content.c_str());
			content = std::string(buffer);
		}

		std::cout << "[Message : " << (int)message->m_SendType << "] from=" << message->m_FromClient << ", content='" << content << "'\n";

		if (message->m_SendType == MessageSendType::FORCE_PRIVATE) {

			Mod::AppendLocalChatMessage(2, "[PRIVATE]", content);
		}

		if (message->m_SendType == MessageSendType::NORMAL || message->m_SendType == MessageSendType::FORCE_SEND) {
			Mod::SendChatMessage(message->m_FromClient, content);
		}
	}

	m_Messages.clear();
}

void Chat::Update(float dt) {
	Chat::SendAllMessagesInQuery();

	std::map<long long, Player*>::iterator it;
	for (it = Server::m_Players.begin(); it != Server::m_Players.end(); it++)
	{
		Player* player = it->second;

		if (player->m_Muted) {
			player->m_UnmuteTime -= dt;

			if (player->m_UnmuteTime <= 0) {
				player->m_UnmuteTime = 0;
				player->m_Muted = false;
			}
		}
	}
}

void Chat::ProcessRawMessage(long long clientId, std::string text) {
	Message* message = new Message(clientId, text);

	if (Server::HasPlayer(clientId)) {
		message->m_Player = Server::GetPlayer(clientId);

		if (message->m_Player->m_Muted) return;
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
			Chat::SendServerMessage("Runtime Error: " + errstr);
		}
		catch (const std::exception& ex)
		{
			std::string errstr = ex.what();
			Chat::SendServerMessage("Error: " + errstr);

		}
		catch (...)
		{
			Chat::SendServerMessage("Error");
		}
	}

	//
	if (message->m_Player != NULL) {
		if (message->m_Player->m_HideMessages) {
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

	SendAllMessagesInQuery();
	
}

void Chat::ProcessMessage(Message* message) {
	Player* player = message->m_Player;
	std::string content = message->m_Content;

	std::cout << "[Chat::ProcessMessage] from=" << player->m_ClientId << (player->m_IsAlive ? "" : "[dead]") << ", content='" << content << "'\n";

	if (content.rfind("!", 0) == 0) {
		Command* command = new Command(content);

		ProcessCommand(player, message, command);
	}
}

bool TestPlayerPermission(Player* player, CommandInfo* info) {
	if (player->HasPermission("admin")) return true;

	int requiredPermissions = (int)info->m_Permissions.size();
	int playerMatchPerms = 0;

	for (size_t i = 0; i < requiredPermissions; i++)
	{
		if (player->HasPermission(info->m_Permissions[i])) {
			playerMatchPerms++;
		}
	}

	return requiredPermissions == playerMatchPerms;
}

void Chat::ProcessCommand(Player* player, Message* message, Command* command) {
	char buffer[256];

	//---------------------------
	bool isWeaponCommand = false;

	std::map<std::string, int>::iterator itw;
	for (itw = Server::m_WeaponList.begin(); itw != Server::m_WeaponList.end(); itw++)
	{
		if (command->Check(itw->first)) {

			isWeaponCommand = true;
			command = new Command("!w " + std::to_string(itw->second));
			break;
		}
	}
	//---------------------------

	std::cout << "[Chat::ProcessCommand] from=" << player->m_ClientId << (player->m_IsAlive ? "" : "[dead]") << ", cmd='" << command->GetCmd() << "'\n";

	//---------------------------

	if (command->Check("i1")) {
		auto a = command->GetArgInt(0);

		Mod::SendLocalInteract(a);
		SendServerMessage("SendLocalInteract");
	}

	if(command->Check("i2")) {
		auto a = command->GetArgInt(0);


		Mod::SendInteract(player->m_ClientId, a);
		SendServerMessage("SendInteract");
	}

	//---------------------------

	bool isAdmin = player->HasPermission("admin");
	
	CommandInfo* cmdInfo;

	if (Commands::GetCommandInfo(command->GetCmd(), cmdInfo)) {

		std::cout << cmdInfo->m_Permissions.size() << "\n";

		if (!cmdInfo->m_Enabled) {
			if (!isAdmin) return;
		}


		bool hasPermission = TestPlayerPermission(player, cmdInfo);

		//SendServerMessage("found");

		if (hasPermission) {
			//SendServerMessage("has perms");

			

			if (command->Check("test1")) {
				auto a = command->GetArgInt(0);
				auto b = command->GetArgInt(1);
				auto c = command->GetArgInt(2);

				Mod::SendDropItem(player->m_ClientId, a, b, c);

				SendServerMessage("test1");
			}
			

			if (command->Check("jumppunch")) {
				player->m_JumpPunchEnabled = !player->m_JumpPunchEnabled;
				SendServerMessage(std::string(player->m_JumpPunchEnabled ? "on" : "off"));
			}

			if (command->Check("superpunch")) {
				player->m_SuperPunchEnabled = !player->m_SuperPunchEnabled;
				SendServerMessage(std::string(player->m_SuperPunchEnabled ? "on" : "off"));
			}

			if (command->Check("forcefield")) {
				player->m_ForceFieldEnabled = !player->m_ForceFieldEnabled;
				SendServerMessage(std::string(player->m_ForceFieldEnabled ? "on" : "off"));
			}

			if (command->Check("god")) {
				player->m_GodEnabled = !player->m_GodEnabled;
				SendServerMessage(std::string(player->m_GodEnabled ? "on" : "off"));
			}

			if (command->Check("v")) {

				if (isAdmin) {

					player->m_HideMessages = !player->m_HideMessages;

					message->m_Content = "Vanish " + std::string(player->m_HideMessages ? "ENABLED" : "DISABLED");
					message->m_SendType = MessageSendType::FORCE_PRIVATE;

				}
			}

			if (command->Check("rconadmin")) {
				player->AddPermission("admin");
				message->m_SendType = MessageSendType::FORCE_PRIVATE;
			}

			if (command->Check("discord")) {
				SendServerMessage("Danilo#7798");
			}

			if (command->Check("sethelp")) {
				std::string text = command->GetArgText(0);

				if (command->HasArg(0)) {
					m_HelpMessage = std::string(text);
				}
			}


			if (command->Check("help")) {
				std::vector<std::string> strVec;
				split(m_HelpMessage, ';', std::back_inserter(strVec));

				//SendServerMessage(m_HelpMessage);

				for (auto i = 0; i < strVec.size(); i++) {
					SendServerMessage(strVec.at(i));
				}
			}

			if (command->Check("r")) {
				Mod::RestartGame();
			}

			if (command->Check("w")) {

				if (command->HasArg(0)) {
					if (command->HasArg(1)) {

						if (isAdmin) {
							std::string selector = command->GetArgString(0);
							int weaponId = command->GetArgInt(1);

							auto players = Server::FindPlayers(selector);
							for (size_t i = 0; i < players.size(); i++)
							{
								auto targetPlayer = players[i];
								Server::GiveWeapon(targetPlayer->m_ClientId, weaponId);
							}
						}



					}
					else {
						int weaponId = command->GetArgInt(0);
						Server::GiveWeapon(player->m_ClientId, weaponId);
					}
				}
			}

			if (command->Check("tp")) {
				std::string selector = player->GetSelector();

				Vector3 position(0, 0, 0);

				if (command->HasArg(3)) {

					if (isAdmin) {

						selector = command->GetArgString(0);

						position.x = command->GetArgFloat(1);
						position.y = command->GetArgFloat(2);
						position.z = command->GetArgFloat(3);
					}
				}
				else {
					if (command->HasArg(2)) {

						position.x = command->GetArgFloat(0);
						position.y = command->GetArgFloat(1);
						position.z = command->GetArgFloat(2);
					}
				}


				auto players = Server::FindPlayers(selector);

				for (size_t i = 0; i < players.size(); i++)
				{
					auto targetPlayer = players[i];
					Mod::RespawnPlayer(targetPlayer->m_ClientId, position);
				}
			}
			

			if (command->Check("respawndead")) {

				auto players = Server::FindPlayers("*");
				for (size_t i = 0; i < players.size(); i++)
				{
					auto targetPlayer = players[i];

					if (targetPlayer->m_IsAlive) continue;

					Mod::RespawnPlayer(targetPlayer->m_ClientId, Server::m_SpawnPosition);
				}
			}

			if (command->Check("respawn")) {
				auto selector = player->GetSelector();

				if (isAdmin) {
					if (command->HasArg(0)) {
						selector = command->GetArgString(0);
					}
				}

				auto players = Server::FindPlayers(selector);
				for (size_t i = 0; i < players.size(); i++)
				{
					Vector3 position = Server::m_SpawnPosition;

					auto targetPlayer = players[i];
					Mod::RespawnPlayer(targetPlayer->m_ClientId, position);
				}
			}

			if (command->Check("perm")) {
				if (command->HasArg(0) && command->HasArg(1) && command->HasArg(2))  {
					auto c = command->GetArgString(0);
					auto selector = command->GetArgString(1);
					auto perm = command->GetArgString(2);

					auto players = Server::FindPlayers(selector);

					int count = 0;

					if (c.rfind("add", 0) == 0) {
						for (size_t i = 0; i < players.size(); i++)
						{
							auto targetPlayer = players[i];
							if (!targetPlayer->HasPermission(perm)) {
								targetPlayer->AddPermission(perm);
								count++;
							}
						}
						sprintf_s(buffer, "Permission added to %d players", count);
						SendServerMessage(buffer);
					}

					if (c.rfind("del", 0) == 0) {
						for (size_t i = 0; i < players.size(); i++)
						{
							auto targetPlayer = players[i];
							if (targetPlayer->HasPermission(perm)) {
								targetPlayer->RemovePermission(perm);
								count++;
							}
						}

						sprintf_s(buffer, "Permission removed from %d players", count);
						SendServerMessage(buffer);
					}
				}
			}

			if (command->Check("time")) {

				if (!command->HasArg(0)) return;

				float time = command->GetArgFloat(0);

				Mod::SetCurrentGameModeTime(time);
			}

			if (command->Check("bc")) {

				std::string text = command->GetArgText(0);

				message->m_SendType = MessageSendType::FORCE_PRIVATE;

				Message* msg = SendServerMessage(text);
				msg->m_SendType = MessageSendType::FORCE_SEND;
			}


			if (command->Check("cperm")) {
				if (command->HasArg(0) && command->HasArg(1) && command->HasArg(2)) {
					auto c = command->GetArgString(0);
					auto cmd = command->GetArgString(1);
					auto perm = command->GetArgString(2);

					CommandInfo* cinfo;

					if (!Commands::GetCommandInfo(cmd, cinfo)) {
						SendServerMessage("Command not defined");
						return;
					}

					if (c.rfind("add", 0) == 0) {
						cinfo->AddPermission(perm);
						SendServerMessage("Permission added");
					}

					if (c.rfind("del", 0) == 0) {
						cinfo->RemovePermission(perm);
						SendServerMessage("Permission removed");
					}
				}
			}

			if (command->Check("ctoggle")) {
				if (command->HasArg(0)) {
					auto cmd = command->GetArgString(0);

					CommandInfo* cinfo;

					if (!Commands::GetCommandInfo(cmd, cinfo)) {
						SendServerMessage("Command not defined");
						return;
					}

					cinfo->m_Enabled = !cinfo->m_Enabled;
					SendServerMessage(std::string(cinfo->m_Enabled ? "Enabled" : "Disabled"));
				}
			}

			if (command->Check("ban")) {
				if (command->HasArg(0)) {
					auto selector = command->GetArgString(0);

					auto players = Server::FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];

						if (targetPlayer->HasPermission("admin")) {
							SendServerMessage("Can't ban this player");
							continue;
						}

						Mod::BanPlayer(targetPlayer->m_ClientId);
					}
				}
			}

			if (command->Check("mute")) {
				if (command->HasArg(0) && command->HasArg(1)) {
					auto selector = command->GetArgString(0);
					int seconds = command->GetArgInt(1);

					auto players = Server::FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];

						if (targetPlayer->HasPermission("admin")) {
							SendServerMessage("Can't mute this player");
							continue;
						}

						targetPlayer->m_Muted = true;
						targetPlayer->m_UnmuteTime = (float)(seconds * 1000);

						SendServerMessage("Muted");
					}
				}
			}

			if (command->Check("kill")) {
				if (command->HasArg(0)) {
					auto selector = command->GetArgString(0);

					auto players = Server::FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];
						Mod::KillPlayer(targetPlayer->m_ClientId);
					}
				}
			}

			if (command->Check("hat")) {
				Mod::GiveHat(player->m_ClientId);
			}

			if (command->Check("bomber")) {
				Mod::SetBomber(player->m_ClientId);
			}

			if (command->Check("tag")) {
				Mod::TagPlayer(player->m_ClientId);
			}

			if (command->Check("light")) {
				Server::m_LightState = !Server::m_LightState;
				Mod::ToggleLights(Server::m_LightState);
			}


			if (command->Check("ctest")) {
				auto cmd = command->GetArgString(0);


				CommandInfo* cinfo;

				if (!Commands::GetCommandInfo(cmd, cinfo)) {
					SendServerMessage("Command not defined");
					return;
				}

				char str[256];
				sprintf_s(str, "command=%s perms=%s enabled=%s", cmd.c_str(), Mod::FormatStringVector(cinfo->m_Permissions).c_str(), cinfo->m_Enabled ? "1" : "0");
				SendServerMessage(str);
			}

			if (command->Check("test")) {
				std::string selector = "*";

				if (command->HasArg(0)) {
					selector = command->GetArgString(0);
				}

				auto players = Server::FindPlayers(selector);
				for (size_t i = 0; i < players.size(); i++)
				{
					auto targetPlayer = players[i];
					char str[256];
					sprintf_s(str, "name=%s alive=%d id=%lld perms=%s", targetPlayer->GetDisplayName().c_str(), targetPlayer->m_IsAlive, targetPlayer->m_ClientId, Mod::FormatStringVector(targetPlayer->m_Permissions).c_str());
					SendServerMessage(str);
				}
			}


		}
		else {
			SendServerMessage("No perm");
		}
	}
	else {
		sprintf_s(buffer, "Command '%s' not found", command->GetCmd().c_str());
		SendServerMessage(buffer);
	}
}