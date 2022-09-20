#pragma once

#include "Mod.h"
#include "Command.h"
#include "CommandArgs.h"
#include "Chat.h"
#include "Message.h"
#include "Server.h"
#include "Weapon.h"
#include "PermissionGroups.h"
#include "EquipItem.h"

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

		std::vector<std::string> cmds;

		if (message->FromPlayer->GetPermissionGroup()->HasPermission("w"))
		{
			for (auto weapon : WeaponList)
			{
				if (!message->FromPlayer->GetPermissionGroup()->HasPermission(toLower(weapon.name))) continue;
				cmds.push_back("!" + toLower(weapon.name));
			}
		}

		for (auto command : Chat::Commands)
		{
			if (!command->CheckPermissions(message->FromPlayer)) continue;
			if (!command->ShowOnHelpPage) continue;
			cmds.push_back("!" + command->Cmd);
		}

		int page;
		if (sscanf_s(message->CmdArgs.c_str(), "%i", &page) == 1) {
			Chat::SendCommandsPage(cmds, page - 1);
			return;
		}

		char cmd[256];
		if (sscanf_s(message->CmdArgs.c_str(), "%s", &cmd, 256) == 1) {

			for (auto command : Chat::Commands) {
				if (!command->Check(cmd)) continue;
				command->PrintSyntaxes();
				//Chat::SendServerMessage("showing help for '" + command->m_Cmd + "'");
				return;
			}

			Chat::SendServerMessage("command '" + std::string(cmd) + "' not found");
			return;
		}

		Chat::SendCommandsPage(cmds, 0);
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(page) - Help page");
		PrintSyntax("(command) - Command help");
	}
};

class CommandAHelp : public Command {
public:
	CommandAHelp()
	{
		Command::Command();
		SetCmd("ahelp");
		AddRequiredPermission("ahelp");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		std::vector<std::string> cmds;
		for (auto command : Chat::Commands)
		{
			if (command->CheckPermissions(message->FromPlayer)) continue;
			if (!command->ShowOnHelpPage) continue;
			cmds.push_back("!" + command->Cmd);
		}

		int page;
		if (sscanf_s(message->CmdArgs.c_str(), "%i", &page) == 1) {
			Chat::SendCommandsPage(cmds, page - 1);
			return;
		}

		Chat::SendCommandsPage(cmds, 0);
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(page) - Help page");
	}
};

class CommandTeleport : public Command {
public:
	CommandTeleport()
	{
		Command::Command();

		SetCmd("tp");
		AddRequiredPermission("tp");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1) {
			//Chat::SendServerMessage("tp self to someone");

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			auto player = players[0];

			Server::RespawnActivePlayerAtPos(message->FromPlayer->ClientId, player->Positon);

			return;
		}

		if (args.size() == 2)
		{
			//Chat::SendServerMessage("tp someone to someone");

			auto players = Server::FindPlayers(args[0].str);
			auto toPlayer = Server::FindPlayers(args[1].str)[0];

			if (players.size() == 0 || !toPlayer)
			{
				PlayerNotFound();
				return;
			}

			auto position = toPlayer->Positon;

			for (auto player : players)
			{
				Server::RespawnActivePlayerAtPos(player->ClientId, position);
			}

			return;
		}

		if (args.size() == 3)
		{
			if (args[0].isNumber && args[1].isNumber && args[2].isNumber)
			{
				//Chat::SendServerMessage("tp to x y z");

				auto position = Vector3({ args[0].AsFloat(), args[1].AsFloat(), args[2].AsFloat() });

				Server::RespawnActivePlayerAtPos(message->FromPlayer->ClientId, position);

				return;
			}
		}

		if (args.size() == 4)
		{
			if (args[0].isString && args[1].isNumber && args[2].isNumber && args[3].isNumber)
			{
				//Chat::SendServerMessage("tp other to x y z");

				auto players = Server::FindPlayers(args[0].str);

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				auto position = Vector3({ args[1].AsFloat(), args[2].AsFloat(), args[3].AsFloat() });

				for (auto player : players)
				{
					Server::RespawnActivePlayerAtPos(player->ClientId, position);
				}

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(x) (y) (z)");
		PrintSyntax("(player)");
		PrintSyntax("(player) (toPlayer)");
		PrintSyntax("(player) (x) (y) (z)");
	}
};

class CommandTest : public Command {
public:
	CommandTest()
	{
		Command::Command();

		SetCmd("test");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto test = toLower(message->CmdArgs);

		if (test.compare("pinfo") == 0)
		{
			auto players = Server::GetPlayers();

			for (auto player : players)
			{
				Chat::SendServerMessage(
					"IsAlive=" + std::string(player->IsAlive ? "TRUE" : "FALSE") + ", " +
					"SpawnedThisRound=" + std::string(player->SpawnedThisRound ? "TRUE" : "FALSE") + ", " +
					"DiedThisRound=" + std::string(player->DiedThisRound ? "TRUE" : "FALSE")
				);
			}
			return;
		}

		if (test.compare("equip") == 0)
		{
			auto player = message->FromPlayer;

			EquipItem::Enabled = !EquipItem::Enabled;

			if (EquipItem::Enabled) Chat::SendServerMessage("on");
			else Chat::SendServerMessage("off");
			return;
		}
		
		if (test.compare("rcon") == 0)
		{
			if (message->FromPlayer->IsLobbyOwner())
			{
				message->FromPlayer->PermissionGroupId = "admin";
				return;
			}
		}

		if (test.compare("timer") == 0)
		{
			Chat::SendServerMessage("help: " + std::to_string(Chat::BroadcastHelpTimeLeft));
			Chat::SendServerMessage("save: " + std::to_string(Server::AutoSaveTimeLeft));
			return;
		}


		if (test.compare("name") == 0)
		{
			/*
			NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0B448A0,  d=000001BCE0B44840,
			[ key(LobbyName), value(cool name) ]
			
			//InteropHelp_UTF8StringHandle__Boxed* boxed = (Quaternion__Boxed*)il2cpp_object_new((Il2CppClass*)*Quaternion__TypeInfo);
			*/


			/*
			* add later
			
			CSteamID id;
			id.m_SteamID = Mod::ISteamMatchmaking_LobbyId;

			NativeMethods_ISteamMatchmaking_SetLobbyData(Mod::ISteamMatchmaking_Instance, id, stringToUTF8StringHandle("LobbyName"), stringToUTF8StringHandle("Random name"), NULL);

			Chat::SendServerMessage("Changing name to: Random name");
			*/

			return;
		}

		if (test.compare("playercount") == 0)
		{
			/*
			* add later
			
			CSteamID id;
			id.m_SteamID = Mod::ISteamMatchmaking_LobbyId;

			NativeMethods_ISteamMatchmaking_SetLobbyData(Mod::ISteamMatchmaking_Instance, id, stringToUTF8StringHandle("PlayersIn"), stringToUTF8StringHandle("1255"), NULL);
			*/

			return;
		}


		if (test.compare("players") == 0)
		{
			std::cout << std::endl;
			std::cout << std::endl;

			auto activePlayers = (*GameManager__TypeInfo)->static_fields->Instance->fields.activePlayers;
			for (size_t i = 0; i < activePlayers->fields.count; i++)
			{
				auto key = activePlayers->fields.entries->vector[i].key;
				auto value = activePlayers->fields.entries->vector[i].value;

				std::cout << "[activePlayers] " << key << " : " << value << std::endl;
			}

			auto spectators = (*GameManager__TypeInfo)->static_fields->Instance->fields.spectators;
			for (size_t i = 0; i < spectators->fields.count; i++)
			{
				auto key = spectators->fields.entries->vector[i].key;
				auto value = spectators->fields.entries->vector[i].value;

				std::cout << "[spectators] " << key << " : " << value << std::endl;
			}

			std::cout << std::endl;
			std::cout << std::endl;

			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(name)");
	}
};

class CommandKill : public Command {
public:
	CommandKill()
	{
		Command::Command();

		SetCmd("kill");
		AddRequiredPermission("kill");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 0)
		{
			Server::KillPlayer(message->FromPlayer);

			return;
		}

		if (args.size() == 1)
		{
			if (!message->FromPlayer->GetPermissionGroup()->HasPermission("kill.others"))
			{
				NoPermission();
				return;
			}

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				Server::KillPlayer(player);
			}
			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(player)");
	}
};

class CommandRestart : public Command {
public:
	CommandRestart()
	{
		Command::Command();

		SetCmd("r");
		AddRequiredPermission("r");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		Mod::RestartGame();
	}
};

class CommandTime : public Command {
public:
	CommandTime()
	{
		Command::Command();

		SetCmd("time");
		AddRequiredPermission("time");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto time = args[0].AsFloat();

				Mod::SetCurrentGameModeTime(time);

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(seconds)");
	}
};

class CommandWeapon : public Command {
public:
	CommandWeapon()
	{
		Command::Command();

		SetCmd("w");
		AddRequiredPermission("w");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();

				auto weapon = GetWeaponById(weaponId);

				//Chat::SendServerMessage("weapon self");
				//Chat::SendServerMessage(std::to_string(weapon->id) + ", " + weapon->name);

				if (!message->FromPlayer->GetPermissionGroup()->HasPermission(toLower(weapon->name)))
				{
					NoPermission();
					return;
				}

				Server::DropWeapon(message->FromPlayer, weaponId, 30);

				return;
			}
		}

		if (args.size() == 2)
		{
			if (args[1].isNumber)
			{
				if (!message->FromPlayer->GetPermissionGroup()->HasPermission("w.others"))
				{
					NoPermission();
					return;
				}

				auto selector = args[0].str;
				auto weaponId = args[1].AsInt();

				auto players = Server::FindPlayers(selector);

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				for (auto player : players)
				{
					Server::GiveWeapon(player, weaponId);
				}

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(weaponId)");
		PrintSyntax("(player) (weaponId)");
	}
};

class CommandHand : public Command {
public:
	CommandHand()
	{
		Command::Command();

		SetCmd("hand");
		AddRequiredPermission("hand");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();

				EquipItem::Equip(message->FromPlayer->ClientId, weaponId);

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(weaponId)");
	}
};

class CommandRespawn : public Command {
public:
	CommandRespawn()
	{
		Command::Command();

		SetCmd("respawn");
		AddAlias("revive");
		AddRequiredPermission("respawn");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 0)
		{
			/*
			if (message->FromPlayer->m_Spectating)
			{
				Chat::SendServerMessage("you will respawn next round");
				message->FromPlayer->m_IsAlive = true;
				return;
			}
			*/

			Server::RespawnPlayer(message->FromPlayer);

			return;
		}

		if (args.size() == 1)
		{
			if (!message->FromPlayer->GetPermissionGroup()->HasPermission("respawn.others"))
			{
				NoPermission();
				return;
			}

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				Server::RespawnPlayer(player);
			}
			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(player)");
	}
};

class CommandMap : public Command {
public:
	CommandMap()
	{
		Command::Command();

		SetCmd("map");
		AddRequiredPermission("map");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 2)
		{
			if (args[0].isNumber && args[1].isNumber)
			{
				auto map = args[0].AsInt();
				auto mode = args[1].AsInt();

				ServerSend_LoadMap_1(map, mode, NULL);

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(map) (mode)");
	}
};

class CommandPerm : public Command {
public:
	CommandPerm()
	{
		Command::Command();

		SetCmd("perm");
		AddRequiredPermission("perm");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() >= 1)
		{
			auto cmd = args[0].str;

			if (cmd.compare("list") == 0)
			{
				if (args.size() == 2 || args.size() == 3)
				{
					int page = 0;
					if (args.size() == 3)
					{
						if (args[2].isNumber) page = args[2].AsInt() - 1;
					}

					auto groupName = args[1].str;

					if (!PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("Group '" + groupName + "' not found");
						return;
					}

					auto group = PermissionGroups::GetGroup(groupName);

					std::vector<std::string> pms;
					for (auto perm : group->GetPermissions())
					{
						pms.push_back(perm);
					}
					Chat::SendCommandsPage(pms, page);

					return;
				}
			}

			if (cmd.compare("add") == 0)
			{
				if (args.size() == 3)
				{
					auto groupName = args[1].str;
					auto perms = args[2].SplitStr();

					if (!PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("Group '" + groupName + "' not found");
						return;
					}

					auto group = PermissionGroups::GetGroup(groupName);

					for (auto perm : perms)
					{
						bool result = group->AddPermission(perm);

						if (result) {
							Chat::SendServerMessage("Permission '" + perm + "' added");
							PermissionGroups::SaveConfig();
						}
						else Chat::SendServerMessage("Permission '" + perm + "' already added!");
					}

					return;
				}
			}

			if (cmd.compare("del") == 0)
			{
				if (args.size() == 3)
				{
					auto groupName = args[1].str;
					auto perms = args[2].SplitStr();

					if (!PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("group '" + groupName + "' not found");
						return;
					}

					auto group = PermissionGroups::GetGroup(groupName);

					for (auto perm : perms)
					{
						bool result = group->RemovePermission(perm);

						if (result) {
							Chat::SendServerMessage("Permission '" + perm + "' removed");
							PermissionGroups::SaveConfig();
						}
						else Chat::SendServerMessage("Permission '" + perm + "' already removed!");
					}
					return;
				}
			}

			if (cmd.compare("setgroup") == 0)
			{
				if (args.size() >= 3)
				{
					auto selector = args[1].str;
					auto groupName = args[2].str;

					auto players = Server::FindPlayers(selector);

					if (!PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("group '" + groupName + "' not found");
						return;
					}

					if (players.size() == 0)
					{
						PlayerNotFound();
						return;
					}

					for (auto player : players)
					{
						if (CheckOwnerIsTarget(player))
						{
							Chat::SendServerMessage("you can't change owner's group");
							continue;
						}

						player->PermissionGroupId = groupName;
						Chat::SendServerMessage(player->GetDisplayName() + "'s group set to: " + groupName);
					}

					return;
				}
			}

			if (cmd.compare("groups") == 0)
			{
				std::vector<std::string> groups;

				for (auto pair : PermissionGroups::Groups)
				{
					groups.push_back(pair.first + "(" + std::to_string(pair.second->GetPermissions().size()) + " perms)");
				}

				Chat::SendServerMessage(formatStringVector_1(groups, ", ", 256));
				return;
			}

			if (cmd.compare("creategroup") == 0)
			{
				if (args.size() == 2)
				{
					auto groupName = args[1].str;

					if (PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("group '" + groupName + "' already exists");
						return;
					}

					PermissionGroups::AddGroup(groupName);
					PermissionGroups::SaveConfig();

					Chat::SendServerMessage("group '" + groupName + "' added!");

					return;
				}
			}

			if (cmd.compare("removegroup") == 0)
			{
				if (args.size() == 2)
				{
					auto groupName = args[1].str;

					if (!PermissionGroups::HasGroup(groupName))
					{
						Chat::SendServerMessage("group '" + groupName + "' not found");
						return;
					}

					PermissionGroups::RemoveGroup(groupName);
					PermissionGroups::SaveConfig();

					Chat::SendServerMessage("group '" + groupName + "' removed!");

					return;
				}
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("add (group) (perm1,perm2,...)");
		PrintSyntax("del (group) (perm1,perm2,...)");
		PrintSyntax("setgroup (player) (group)");
		PrintSyntax("list (group) [page]");
		PrintSyntax("groups");
		PrintSyntax("creategroup (name)");
		PrintSyntax("removegroup (name)");
	}
};

class CommandPlayerInfo : public Command {
public:
	CommandPlayerInfo()
	{
		Command::Command();

		SetCmd("playerinfo");
		AddAlias("pinfo");
		AddRequiredPermission("playerinfo");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		char selector[256];
		if (sscanf_s(message->CmdArgs.c_str(), "%s", &selector, 256) == 1) {

			auto players = Server::FindPlayers(selector);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				Chat::SendServerMessage(player->GetDisplayNameExtra());
				Chat::SendServerMessage(
					"Group=" + player->GetPermissionGroup()->Name + ", " +
					"IsAlive=" + (player->IsAlive ? "TRUE" : "FALSE") + ", " +
					"Position=" + player->Positon.format_3()
				);
			}
			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player)");
	}
};

/*
class CommandAllCommands : public Command {
public:
	CommandAllCommands()
	{
		Command::Command();

		SetCmd("*");
		ShowOnHelpPage(false);
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto cmd = message->m_Cmd;
		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (cmd.compare("useitem") == 0)
		{
			Server::m_CanUseItem = !Server::m_CanUseItem;
			if (Server::m_CanUseItem) Chat::SendServerMessage("on");
			else Chat::SendServerMessage("off");
			//ServerSend_UseItem(message->m_Player->m_ClientId, 0, Vector3({ 0, 0, 1 }), NULL);
			return;
		}

		if (cmd.compare("players") == 0)
		{
			auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;

			Chat::SendServerMessage("Active:");

			auto activePlayers = gameManager->fields.activePlayers;
			for (size_t i = 0; i < activePlayers->fields.count; i++)
			{
				auto key = activePlayers->fields.entries->vector[i].key;
				auto playerManager = activePlayers->fields.entries->vector[i].value;

				Chat::SendServerMessage("#" + std::to_string(playerManager->fields.playerNumber));
			}

			Chat::SendServerMessage("Spec:");

			auto spectators = gameManager->fields.spectators;
			for (size_t i = 0; i < spectators->fields.count; i++)
			{
				auto key = spectators->fields.entries->vector[i].key;
				auto playerManager = spectators->fields.entries->vector[i].value;

				Chat::SendServerMessage("#" + std::to_string(playerManager->fields.playerNumber));
			}
		}

		if (cmd.compare("clearspec") == 0)
		{




		}
	}

	virtual void PrintSyntaxes()
	{

	}
};
*/

class CommandMute : public Command {
public:
	CommandMute()
	{
		Command::Command();

		SetCmd("mute");
		AddRequiredPermission("mute");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 2)
		{
			if (args[0].isString && args[1].isNumber)
			{
				auto players = Server::FindPlayers(args[0].str);

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				for (auto player : players)
				{
					if (CheckOwnerIsTarget(player))
					{
						Chat::SendServerMessage("can't mute this player");
						continue;
					}
					player->MuteTime = args[1].AsFloat();
					Chat::SendServerMessage(player->GetDisplayName() + " was muted for " + args[1].str + " seconds");
				}
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player) (seconds)");
	}
};


class CommandKick : public Command {
public:
	CommandKick()
	{
		Command::Command();

		SetCmd("kick");
		AddRequiredPermission("kick");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				if (player->IsLobbyOwner()) continue;

				Mod::KickPlayer(player->ClientId);
				Chat::SendServerMessage(player->GetDisplayName() + " was kicked");
			}

			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player)");
	}
};


class CommandBan : public Command {
public:
	CommandBan()
	{
		Command::Command();

		SetCmd("ban");
		AddRequiredPermission("ban");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				if (player->IsLobbyOwner()) continue;

				Mod::BanPlayer(player->ClientId);
				Chat::SendServerMessage(player->GetDisplayName() + " was banned");
			}

			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player)");
	}
};


class CommandGod : public Command {
public:
	CommandGod()
	{
		Command::Command();

		SetCmd("god");
		AddRequiredPermission("god");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 0)
		{
			auto player = message->FromPlayer;

			player->Godmode = !player->Godmode;

			if (player->Godmode) Chat::SendServerMessage("on");
			else Chat::SendServerMessage("off");

			return;
		}

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto enabled = args[0].AsBool();
				auto player = message->FromPlayer;

				player->Godmode = enabled;

				if (player->Godmode) Chat::SendServerMessage("on");
				else Chat::SendServerMessage("off");

				return;
			}
		}

		if (args.size() == 2)
		{
			if (!message->FromPlayer->GetPermissionGroup()->HasPermission("god.others"))
			{
				NoPermission();
				return;
			}

			if (args[1].isNumber)
			{
				auto players = Server::FindPlayers(args[0].str);
				auto enabled = args[1].AsBool();

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				for (auto player : players)
				{
					if (player->Godmode == enabled) continue;

					player->Godmode = enabled;

					if (player->Godmode) Chat::SendServerMessage(player->GetDisplayName() + " god: on");
					else Chat::SendServerMessage(player->GetDisplayName() + " god: off");
				}

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(0/1)");
		PrintSyntax("(player) (0/1)");
	}
};

class CommandVanish : public Command {
public:
	CommandVanish()
	{
		Command::Command();

		SetCmd("v");
		AddRequiredPermission("v");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->FromPlayer;

		player->HideMessages = !player->HideMessages;

		message->Content = "Vanish " + std::string(player->HideMessages ? "ENABLED" : "DISABLED");
		message->SendType = MessageSendType::FORCE_PRIVATE;
	}

	virtual void PrintSyntaxes()
	{

	}
};

/*

class CommandAutoRespawn : public Command {
public:
	CommandAutoRespawn()
	{
		Command::Command();

		SetCmd("autorespawn");
		AddRequiredPermission("autorespawn");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->m_Player;

		player->m_AutoRespawnEnabled = !player->m_AutoRespawnEnabled;

		if (player->m_AutoRespawnEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
	}
};

*/


/*
class CommandToggleWeapon : public Command {
public:
	CommandToggleWeapon()
	{
		Command::Command();
		SetCmd("toggleweapon");
		AddRequiredPermission("toggleweapon");
	}
	virtual void Execute(Message* message)
	{
		Command::Execute(message);
		auto args = CommandArg::GetArgs(message->m_CmdArgs);
		if (args.size() == 1)
		{
			auto weaponName = args[0].str;
			for (auto& weapon : Server::m_Weapons)
			{
				if (toLower(weapon.name).compare(weaponName) == 0)
				{
					weapon.enabled = !weapon.enabled;
					Chat::SendServerMessage("weapon '" + weapon.name + "' " + (weapon.enabled ? "enabled" : "disabled"));
					return;
				}
			}
			Chat::SendServerMessage("weapon not found");
			return;
		}
		WrongSyntax();
	}
	virtual void PrintSyntaxes()
	{
		PrintSyntax("(weaponName)");
	}
};
*/

class CommandDownload : public Command {
public:
	CommandDownload()
	{
		Command::Command();

		SetCmd("download");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		Chat::SendServerMessage("Download URL:  https://bit.ly/crabgame-mod");
	}
};

class CommandWin : public Command {
public:
	CommandWin()
	{
		Command::Command();

		SetCmd("win");
		AddRequiredPermission("win");
		SetShowOnHelpPage(false);
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 2)
		{
			if (args[1].isNumber)
			{
				auto players = Server::FindPlayers(args[0].str);
				long long money = args[1].AsULong();

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				ServerSend_SendWinner(players[0]->ClientId, money, NULL);
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player) (money)");
	}
};

class CommandStart : public Command {
public:
	CommandStart()
	{
		Command::Command();

		SetCmd("start");
		AddRequiredPermission("start");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		Mod::SetAllPlayersReady();
		Chat::SendServerMessage("Starting game in 3 seconds");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};

class CommandBroadcast : public Command {
public:
	CommandBroadcast()
	{
		Command::Command();

		SetCmd("bc");
		AddRequiredPermission("bc");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		if (message->CmdArgs.size() > 0)
		{
			message->SendType = MessageSendType::FORCE_PRIVATE;

			auto msg = Chat::SendServerMessage(message->CmdArgs);
			msg->SendType = MessageSendType::FORCE_SEND;

			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(message)");
	}
};

/*
class CommandAutoStart : public Command {
public:
	CommandAutoStart()
	{
		Command::Command();

		SetCmd("autostart");
		AddRequiredPermission("autostart");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isString)
			{
				if (args[0].str.compare("on") == 0)
				{
					Server::m_AutoStartEnabled = true;
					Chat::SendServerMessage("Auto start enabled");
					return;
				}

				if (args[0].str.compare("off") == 0)
				{
					Server::m_AutoStartEnabled = false;
					Chat::SendServerMessage("Auto start disabled");
					return;
				}
			}

			if (args[0].isNumber)
			{
				int time = args[0].AsInt();

				Server::m_AutoStartTime = time;

				Chat::SendServerMessage("Auto start time set to " + std::to_string(time));
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(on/off) - Enable/disable");
		PrintSyntax("(seconds)");
	}
};
*/


class CommandJumpPunch : public Command {
public:
	CommandJumpPunch()
	{
		Command::Command();

		SetCmd("jumppunch");
		AddRequiredPermission("jumppunch");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->FromPlayer;

		player->JumpPunchEnabled = !player->JumpPunchEnabled;

		if (player->JumpPunchEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};


class CommandSuperPunch : public Command {
public:
	CommandSuperPunch()
	{
		Command::Command();

		SetCmd("superpunch");
		AddRequiredPermission("superpunch");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->FromPlayer;

		player->SuperPunchEnabled = !player->SuperPunchEnabled;

		if (player->SuperPunchEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};

class CommandForceField : public Command {
public:
	CommandForceField()
	{
		Command::Command();

		SetCmd("forcefield");
		AddRequiredPermission("forcefield");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->FromPlayer;

		player->ForceFieldEnabled = !player->ForceFieldEnabled;

		if (player->ForceFieldEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};

/*
class CommandPunchDamage : public Command {
public:
	CommandPunchDamage()
	{
		Command::Command();

		SetCmd("punchdamage");
		AddRequiredPermission("punchdamage");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();
				auto weapon = Server::GetWeaponById(weaponId);

				if (!weapon)
				{
					Chat::SendServerMessage("id not found");
					return;
				}

				Server::m_PunchDamageId = weaponId;
				Chat::SendServerMessage("punch damage set to " + weapon->name + "'s base damage");
				return;
			}
		}

		if (args.size() == 1)
		{
			if (toLower(message->m_CmdArgs).rfind("off") == 0)
			{
				Chat::SendServerMessage("off");
				Server::m_PunchDamageId = -1;
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("off");
		PrintSyntax("(0-12)");
	}
};


class CommandMultiSnowball : public Command {
public:
	CommandMultiSnowball()
	{
		Command::Command();

		SetCmd("snowball2");
		AddRequiredPermission("snowball2");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->m_Player;

		player->m_MultiSnowballEnabled = !player->m_MultiSnowballEnabled;

		if (player->m_MultiSnowballEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};


class CommandLobbyOnly : public Command {
public:
	CommandLobbyOnly()
	{
		Command::Command();

		SetCmd("lobbyonly");
		AddRequiredPermission("lobbyonly");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			char cmd[256];
			if (sscanf_s(message->m_CmdArgs.c_str(), "%s", &cmd, 256) == 1) {

				for (auto command : Chat::m_Commands) {
					if (command->Check(cmd)) {

						command->m_LobbyOnly = !command->m_LobbyOnly;
						if (command->m_LobbyOnly) Chat::SendServerMessage("command '" + command->m_Cmd + "' is now lobby-only");
						else Chat::SendServerMessage("command '" + command->m_Cmd + "' is no longer lobby-only");

						return;
					}
				}

				Chat::SendServerMessage("command '" + std::string(cmd) + "' not found");
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(command)");
	}
};


class CommandConfig : public Command {
public:
	CommandConfig()
	{
		Command::Command();

		SetCmd("config");
		AddRequiredPermission("config");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() >= 1)
		{
			auto cmd = args[0].str;

			if (cmd.compare("save") == 0)
			{
				Server::SaveConfig();
				Chat::SendServerMessage("config saved");
				return;
			}

			if (cmd.compare("path") == 0)
			{
				Chat::SendServerMessage("Crab Game folder: C:\\Program Files (x86)\\Steam\\steamapps\\common\\Crab Game");
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("path");
		PrintSyntax("save");
		Chat::SendServerMessage("* Saves every 40 seconds");
		Chat::SendServerMessage("* To load config you must restart game");
	}
};


class CommandFly : public Command {
public:
	CommandFly()
	{
		Command::Command();

		SetCmd("fly");
		AddRequiredPermission("fly");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto player = message->m_Player;

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto speed = args[0].AsFloat();

				player->m_FlySpeed = speed;

				char str[256];
				sprintf_s(str, "fly speed set to %.2f", speed);
				Chat::SendServerMessage(str);
				return;
			}
		}

		player->m_FlyEnabled = !player->m_FlyEnabled;

		if (player->m_FlyEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(speed)");
	}
};
*/