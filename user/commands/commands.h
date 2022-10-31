#pragma once

#include "Mod.h"
#include "Command.h"
#include "CommandArgs.h"
#include "Chat.h"
#include "Message.h"
#include "Server.h"
#include "Weapon.h"
#include "Config.h"
#include "PermissionGroups.h"
#include "systems/EquipItem.h"
#include "systems/AutoStart.h"
#include "systems/ModeDeathMatch.h"
#include "systems/VoteSystem.h"
#include "systems/BanSystem.h"
#include "systems/MapSkip.h"
#include "systems/Whitelist.h"
#include "systems/AutoMessages.h"

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

			Server::RespawnActivePlayerAtPos(message->FromPlayer->ClientId, player->Position);

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

			auto position = toPlayer->Position;

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
			Chat::SendServerMessage("save: " + std::to_string(Config::AutoSaveTimeElapsed));
			Chat::SendServerMessage("automessage: " + std::to_string(AutoMessages::SendTimeElapsed));
			Chat::SendServerMessage("autostart: " + std::to_string(AutoStart::TimeUntilAutoStart - 0.001));
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

				TryGiveWeapon(message->FromPlayer, weaponId, 30);
				return;
			}
		}

		if (args.size() == 2)
		{
			if (args[0].isNumber && args[1].isNumber)
			{
				auto weaponId = args[0].AsInt();
				auto ammo = args[1].AsInt();

				TryGiveWeapon(message->FromPlayer, weaponId, ammo);
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(weaponId)");
		PrintSyntax("(weaponid) (ammo)");
		PrintSyntax("givew", "");
	}

	static void TryGiveWeapon(Player* player, int weaponId, int ammo)
	{
		auto weapon = GetWeaponById(weaponId);

		if (!weapon)
		{
			Chat::SendServerMessage("invalid weapon id");
			return;
		}

		if (!player->GetPermissionGroup()->HasPermission(toLower(weapon->name)))
		{
			NoPermission();
			return;
		}

		Server::DropWeapon(player, weaponId, ammo);
	}
};


class CommandGiveWeapon : public Command {
public:
	CommandGiveWeapon()
	{
		Command::Command();

		SetCmd("givew");
		AddRequiredPermission("givew");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 2)
		{
			if (args[1].isNumber)
			{
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

		if (args.size() == 3)
		{
			if (args[1].isNumber && args[2].isNumber)
			{
				auto selector = args[0].str;
				auto weaponId = args[1].AsInt();
				auto ammo = args[2].AsInt();

				auto players = Server::FindPlayers(selector);

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				for (auto player : players)
				{
					Server::DropWeapon(player, weaponId, ammo);
				}
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(toplayer) (weaponId)");
		PrintSyntax("(toplayer) (weaponId) (ammo)");
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
					"Position=" + player->Position.format_3()
				);

				if (BanSystem::IsPlayerBanned(player->ClientId))
				{
					auto banInfo = BanSystem::BannedPlayers[player->ClientId];
					Chat::SendServerMessage("BanReason=" + banInfo.reason + ", UnbanTime=" + std::to_string((int)BanSystem::GetUnbanTime(player->ClientId)) + "s");
				}

				if (player->MuteTime > 0)
				{
					Chat::SendServerMessage("Mute=" + std::to_string((int)player->MuteTime) + "s");
				}
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
			std::string selector = args[0].str;

			int seconds = 0;
			bool isTimeString = ConvertTimeStringToSeconds(args[1].str, &seconds);

			if (isTimeString)
			{
				auto players = Server::FindPlayers(args[0].str);

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				if (seconds < 0)
				{
					Chat::SendServerMessage("invalid time");
					return;
				}

				for (auto player : players)
				{
					if (CheckOwnerIsTarget(player))
					{
						Chat::SendServerMessage("can't mute this player");
						continue;
					}

					if (player == message->FromPlayer)
					{
						Chat::SendServerMessage("can't mute yourself");
						continue;
					}

					player->MuteTime = (float)seconds;
					Chat::SendServerMessage(player->GetDisplayName() + " was muted for " + std::to_string(seconds) + " seconds");
				}

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player) (time) - time: 1d / 2h / 3s");
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
				if (player->IsLobbyOwner())
				{
					Chat::SendServerMessage("can't kick owner");
					continue;
				}

				if (player == message->FromPlayer)
				{
					Chat::SendServerMessage("can't kick yourself");
					continue;
				}

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

		if (args.size() >= 1)
		{
			auto selector = args[0].str;

			int seconds = 0;
			auto banStr = args.size() >= 2 ? args[1].str : "";
			bool isTimeString = ConvertTimeStringToSeconds(banStr, &seconds);

			if (!isTimeString)
			{
				std::string reason = "None";

				if (args.size() >= 2) reason = CommandArg::GetArgText(args, 1);

				TryBan(selector, message->FromPlayer, reason, "", -1);
				return;
			}
			else {
				std::string reason = "None";

				if (seconds < 0)
				{
					Chat::SendServerMessage("invalid time");
					return;
				}

				if (args.size() >= 3) reason = CommandArg::GetArgText(args, 2);

				TryBan(selector, message->FromPlayer, reason, banStr, seconds);
				return;
			}
			
			return;
		}

		WrongSyntax();
	}

	void TryBan(std::string selector, Player* byPlayer, std::string reason, std::string timeStr, int seconds)
	{
		std::cout << "TryBan " << selector << ", for " << reason << ", time=" << seconds << "(" << timeStr << ")" << std::endl;

		auto players = Server::FindPlayers(selector);

		if (players.size() == 0)
		{
			PlayerNotFound();
			return;
		}

		for (auto player : players)
		{
			if (player->IsLobbyOwner())
			{
				Chat::SendServerMessage("can't ban owner");
				continue;
			}

			if (player == byPlayer)
			{
				Chat::SendServerMessage("can't ban yourself");
				continue;
			}

			std::cout << "BanPlayear" << std::endl;

			BanSystem::BanPlayer(player->ClientId, reason, seconds);

			if (seconds == -1)
			{
				Chat::SendServerMessage(player->GetDisplayNameExtra() + " was banned. Reason: " + reason);
			}
			else {
				Chat::SendServerMessage(player->GetDisplayNameExtra() + " was banned for " + timeStr + ". Reason: " + reason);
			}
		}
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player) [reason] - permanent ban");
		PrintSyntax("(player) (time) [reason] - time: 1d / 2h / 3s");
	}
};


class CommandUnban : public Command {
public:
	CommandUnban()
	{
		Command::Command();

		SetCmd("unban");
		AddRequiredPermission("unban");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto steamId = args[0].AsULong();

				if (!BanSystem::IsPlayerBanned(steamId))
				{
					Chat::SendServerMessage(std::to_string(steamId) + " is not banned");
					return;
				}

				BanSystem::UnbanPlayer(steamId);
				Chat::SendServerMessage(std::to_string(steamId) + " is now unbanned");

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(steamId)");
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


class CommandReady : public Command {
public:
	CommandReady()
	{
		Command::Command();

		SetCmd("ready");
		AddRequiredPermission("ready");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 0)
		{
			Mod::TogglePlayerReady(message->FromPlayer->ClientId);
			return;
		}

		if (args.size() == 1)
		{
			if (!message->FromPlayer->GetPermissionGroup()->HasPermission("ready.others"))
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
				Mod::TogglePlayerReady(player->ClientId, false);
			}
			Mod::SendReadyInteract();

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

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isString)
			{
				if (args[0].str.compare("on") == 0)
				{
					Chat::SendServerMessage("Auto start enabled");
					AutoStart::SetEnabled(true);
					return;
				}

				if (args[0].str.compare("off") == 0)
				{
					Chat::SendServerMessage("Auto start disabled");
					AutoStart::SetEnabled(false);
					return;
				}
			}

			if (args[0].isNumber)
			{
				float time = args[0].AsFloat();

				AutoStart::Time = time;

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

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();
				auto weapon = GetWeaponById(weaponId);

				if (!weapon)
				{
					Chat::SendServerMessage("id not found");
					return;
				}

				Server::PunchDamageId = weaponId;
				Chat::SendServerMessage("punch damage set to " + weapon->name + "'s base damage");
				return;
			}
		}

		if (args.size() == 1)
		{
			if (toLower(message->CmdArgs).rfind("off") == 0)
			{
				Chat::SendServerMessage("off");
				Server::PunchDamageId = -1;
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("off");
		PrintSyntax("(0-13)");

		auto weaponId = Server::PunchDamageId;
		if(weaponId == -1)
		{
			Chat::SendServerMessage("current damage: DEFAULT(-1)");
		}
		else {
			auto weapon = GetWeaponById(weaponId);
			Chat::SendServerMessage("current damage: " + weapon->name + "(" + std::to_string(weapon->id) + ")");
		}
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

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			char cmd[256];
			if (sscanf_s(message->CmdArgs.c_str(), "%s", &cmd, 256) == 1) {

				auto command = Chat::FindCommand(cmd);

				if (!command)
				{
					Chat::SendServerMessage("command '" + std::string(cmd) + "' not found");
					return;
				}

				command->LobbyOnly = !command->LobbyOnly;
				if (command->LobbyOnly) Chat::SendServerMessage("command '" + command->Cmd + "' is now lobby-only");
				else Chat::SendServerMessage("command '" + command->Cmd + "' is no longer lobby-only");

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

		auto player = message->FromPlayer;

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto speed = args[0].AsFloat();

				player->FlySpeed = speed;

				char str[256];
				sprintf_s(str, "fly speed set to %.2f", speed);
				Chat::SendServerMessage(str);
				return;
			}
		}

		player->FlyEnabled = !player->FlyEnabled;

		if (player->FlyEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
		PrintSyntax("(speed)");
	}
};

class CommandDeathMatch : public Command {
public:
	CommandDeathMatch()
	{
		Command::Command();

		SetCmd("dm");
		AddRequiredPermission("dm");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		ModeDeathMatch::Enabled = !ModeDeathMatch::Enabled;

		if (ModeDeathMatch::Enabled) Chat::SendServerMessage("DM mode on");
		else Chat::SendServerMessage("DM mode off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};


class CommandHover : public Command {
public:
	CommandHover()
	{
		Command::Command();

		SetCmd("hover");
		AddRequiredPermission("hover");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			if (toLower(message->CmdArgs).rfind("off") == 0)
			{
				message->FromPlayer->HoveringPlayer = NULL;
				Chat::SendServerMessage("off");
				return;
			}

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			message->FromPlayer->HoveringPlayer = players[0];
			message->FromPlayer->HoveringRadius = 0;

			Chat::SendServerMessage("hovering " + players[0]->GetDisplayName());

			return;
		}

		if (args.size() == 2)
		{
			if (args[1].isNumber)
			{
				auto players = Server::FindPlayers(args[0].str);
				auto radius = args[1].AsFloat();

				if (players.size() == 0)
				{
					PlayerNotFound();
					return;
				}

				message->FromPlayer->HoveringPlayer = players[0];
				message->FromPlayer->HoveringRadius = radius;

				Chat::SendServerMessage("hovering " + players[0]->GetDisplayName());

				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player)");
		PrintSyntax("(player) (radius)");
		PrintSyntax("off - To disable");
	}
};


class CommandVote : public Command {
public:
	CommandVote()
	{
		Command::Command();

		SetCmd("vote");
		AddAlias("yes");
		AddAlias("no");
		AddRequiredPermission("vote");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		std::string cmd = message->Cmd;

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			cmd = args[0].str;
		}

		if (VoteSystem::HasAnyVoting())
		{
			if (toLower(cmd).compare("yes") == 0)
			{
				VoteSystem::Vote(true, message->FromPlayer->ClientId);
				return;
			}

			if (toLower(cmd).compare("no") == 0)
			{
				VoteSystem::Vote(false, message->FromPlayer->ClientId);
				return;
			}
		}

		PrintSyntaxes();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(yes / no)");
		Chat::SendServerMessage("* !yes");
		Chat::SendServerMessage("* !no");
	}
};


class CommandVoteKick : public Command {
public:
	CommandVoteKick()
	{
		Command::Command();

		SetCmd("votekick");
		AddRequiredPermission("votekick");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		if (VoteSystem::HasAnyVoting())
		{
			Chat::SendServerMessage("wait until this votekick ends");
			return;
		}

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() == 1)
		{
			auto targetPlayers = Server::FindPlayers(args[0].str);

			if (targetPlayers.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			auto targetPlayer = targetPlayers[0];

			if (targetPlayer->IsLobbyOwner())
			{
				Chat::SendServerMessage("you cant kick owner");
				return;
			}

			long long clientId = targetPlayer->ClientId;

			VoteSystem::StartVote("Kick " + targetPlayer->Username + " [" + std::to_string(targetPlayer->Id) + "] ?", 20.0f, [clientId]()
			{
				VoteSystem::SendEndVoteMessage();
				Mod::KickPlayer(clientId);
			}, []()
			{
				VoteSystem::SendEndVoteMessage();
			});

			return;
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("(player)");
	}
};

class CommandSkip : public Command {
public:
	CommandSkip()
	{
		Command::Command();

		SetCmd("skip");
		AddRequiredPermission("skip");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		if (!MapSkip::CanSkip())
		{
			Chat::SendServerMessage("you can't skip now");
			return;
		}

		MapSkip::VoteSkip(message->FromPlayer->ClientId);
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
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

		auto player = message->FromPlayer;

		player->MultiSnowballEnabled = !player->MultiSnowballEnabled;

		if (player->MultiSnowballEnabled) Chat::SendServerMessage("on");
		else Chat::SendServerMessage("off");
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("");
	}
};



class CommandWhitelist : public Command {
public:
	CommandWhitelist()
	{
		Command::Command();

		SetCmd("whitelist");
		AddRequiredPermission("whitelist");
	}

	virtual void Execute(Message* message)
	{
		Command::Execute(message);

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() >= 1)
		{
			auto cmd = args[0].str;

			if (cmd.compare("on") == 0)
			{
				Chat::SendServerMessage("whitelist on");
				Whitelist::Enabled = true;
				return;
			}

			if (cmd.compare("off") == 0)
			{
				Chat::SendServerMessage("whitelist off");
				Whitelist::Enabled = false;
				return;
			}

			if (cmd.compare("add") == 0)
			{
				if (args[1].isNumber)
				{
					auto id = args[1].AsULong();

					std::string userName = std::to_string(id);
					auto targetPlayers = Server::FindPlayers(userName);
					if (targetPlayers.size() > 0)
					{
						auto targetPlayer = targetPlayers[0];
						userName = targetPlayer->Username + " (" + userName + ")";
					}

					if (Whitelist::HasId(id))
					{
						Chat::SendServerMessage(userName + " already added to whitelist");
						return;
					}

					Whitelist::AddId(id);
					Chat::SendServerMessage(userName + " added to whitelist");

					return;
				}
			}

			if (cmd.compare("remove") == 0)
			{
				if (args[1].isNumber)
				{
					auto id = args[1].AsULong();

					std::string userName = std::to_string(id);
					auto targetPlayers = Server::FindPlayers(userName);
					if (targetPlayers.size() > 0)
					{
						auto targetPlayer = targetPlayers[0];
						userName = targetPlayer->Username + "(" + userName + ")";
					}

					if (!Whitelist::HasId(id))
					{
						Chat::SendServerMessage(userName + " is not on whitelist");
						return;
					}

					Whitelist::RemoveId(id);
					Chat::SendServerMessage(userName + " removed from whitelist");

					return;
				}
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("on/off");
		PrintSyntax("add/remove (steamid)");
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

		auto args = CommandArg::GetArgs(message->CmdArgs);

		if (args.size() >= 1)
		{
			auto cmd = args[0].str;

			if (cmd.compare("reload") == 0)
			{
				Config::Reload();
				Chat::SendServerMessage("config reloaded");
				return;
			}
		}

		WrongSyntax();
	}

	virtual void PrintSyntaxes()
	{
		PrintSyntax("reload");
		Chat::SendServerMessage("* Auto saves every " + std::to_string((int)Config::AutoSaveInterval) + " seconds");
	}
};
