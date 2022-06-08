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

		auto test = toLower(message->m_CmdArgs);

		Chat::SendServerMessage("Test:" + test);

		if (test.compare("players") == 0)
		{
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
		}



		/*
		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args[0].isNumber)
		{
			auto i = args[0].AsInt();

			Chat::SendServerMessage("Test " + std::to_string(i));

			if (i == 1)
			{

			}

			return;
		}
		*/

		//WrongSyntax();
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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 0)
		{
			Server::KillPlayer(message->m_Player->m_ClientId);

			return;
		}

		if (args.size() == 1)
		{
			/*
			if (!message->m_Player->GetPermissionGroup()->HasPermission("kill.others"))
			{
				NoPermission();
				return;
			}
			*/

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				Server::KillPlayer(player->m_ClientId);
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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();

				auto weapon = Server::GetWeaponById(weaponId);

				/*
				if (!message->m_Player->GetPermissionGroup()->HasPermission(toLower(weapon->name)))
				{
					NoPermission();
					return;
				}
				*/

				Server::GiveWeapon(message->m_Player->m_ClientId, weaponId);

				return;
			}
		}

		if (args.size() == 2)
		{
			if (args[1].isNumber)
			{
				/*
				if (!message->m_Player->GetPermissionGroup()->HasPermission("w.others"))
				{
					NoPermission();
					return;
				}
				*/

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
					Server::GiveWeapon(player->m_ClientId, weaponId);
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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 1)
		{
			if (args[0].isNumber)
			{
				auto weaponId = args[0].AsInt();

				ServerSend_PlayerActiveItem(message->m_Player->m_ClientId, weaponId, NULL);

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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

		if (args.size() == 0)
		{
			/*
			if (message->m_Player->m_Spectating)
			{
				Chat::SendServerMessage("you will respawn next round");
				message->m_Player->m_IsAlive = true;
				return;
			}
			*/

			Server::RespawnPlayer(message->m_Player->m_ClientId);

			return;
		}

		if (args.size() == 1)
		{
			/*
			if (!message->m_Player->GetPermissionGroup()->HasPermission("respawn.others"))
			{
				NoPermission();
				return;
			}
			*/

			auto players = Server::FindPlayers(args[0].str);

			if (players.size() == 0)
			{
				PlayerNotFound();
				return;
			}

			for (auto player : players)
			{
				Server::RespawnPlayer(player->m_ClientId);
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

		auto args = CommandArg::GetArgs(message->m_CmdArgs);

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

