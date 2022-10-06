#pragma once

#include "Chat.h"

static void TestChat()
{
	Player* player = Server::AddPlayer(new Player(111111111111));
	player->Id = 1;
	player->Username = "Danilo";

	Chat::AddMessageAndProcess(new Message(player, "hi"));
}

static void TestChatPerms()
{
	Player* player = Server::AddPlayer(new Player(111111111111));
	player->Username = "Danilo";

	Chat::AddMessageAndProcess(new Message(player, "!help"));
	Chat::AddMessageAndProcess(new Message(player, "!help 2"));
	Chat::AddMessageAndProcess(new Message(player, "!help 3"));

	Chat::AddMessageAndProcess(new Message(player, "!test pinfo"));
}

static void TestArgText()
{
	Player* player = Server::AddPlayer(new Player(111111111111));
	player->Username = "Danilo";

	std::cout << Server::GetPlayers().size() << std::endl;
	std::cout << Server::GetLobbyOwner() << std::endl;

	Chat::AddMessageAndProcess(new Message(player, "!ban #1 0.3 random reason abc"));
}

static void Test()
{
	TestArgText();
	//TestChat();
	//TestChatPerms();
}
