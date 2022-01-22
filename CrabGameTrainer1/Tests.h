#pragma once

#include "Chat.h"

class Tests {
public:

	static void Test1() {
		auto player1 = Server::AddPlayer(new Player(11111111111, 1));
		auto player2 = Server::AddPlayer(new Player(22222222222, 2));

		player2->AddPermission("gay");
		player2->RemovePermission("gay");

		Chat::ProcessRawMessage(player1->m_ClientId, "!ctest ban");

		Chat::ProcessRawMessage(player2->m_ClientId, "!ban");

		Chat::ProcessRawMessage(player1->m_ClientId, "!cperm del ban ban.use");
		Chat::ProcessRawMessage(player1->m_ClientId, "!ctest ban");

		Chat::ProcessRawMessage(player2->m_ClientId, "!ban");
		//Chat::ProcessRawMessage(player1->m_ClientId, "!bc 123456");
		//Chat::ProcessRawMessage(player2->m_ClientId, "!respawn");

		/*
		while (true)
		{
			Server::Update(250);
			Sleep(250);
		}
		*/
	}

	static void Test2() {
		auto player1 = Server::AddPlayer(new Player(11111111111, 1));
		auto player2 = Server::AddPlayer(new Player(22222222222, 2));

		player2->AddPermission("gay");
		player2->RemovePermission("gay");

		Chat::ProcessRawMessage(player1->m_ClientId, "!win #1 17823");
	}
};