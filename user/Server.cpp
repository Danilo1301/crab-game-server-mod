#include "pch-il2cpp.h"
#include "Server.h"

#include "Mod.h"
#include "Chat.h"

std::vector<Weapon> Server::m_Weapons = {
	{ "Ak", 0 },
	{ "Glock", 1 },
	{ "Revolver", 2 },
	{ "Dual", 3 },
	{ "Bat", 4 },
	{ "Bomb", 5 },
	{ "Katana", 6 },
	{ "Knife", 7 },
	{ "Pipe", 8 },
	{ "Snowball", 9 },
	{ "Stick", 10 },
	{ "Milk", 11 },
	{ "Pizza", 12 },
	{ "Grenade", 13 }
};

std::map<long long, Player*> Server::m_Players;

void Server::Init()
{
	std::cout << "[Server] Init" << std::endl;

	Chat::Init();
}

void Server::Update(float dt)
{
	Chat::Update(dt);
}

bool Server::HasPlayer(long long clientId)
{
	return m_Players.find(clientId) != m_Players.end();
}

Player* Server::GetPlayer(long long clientId)
{
	return m_Players.at(clientId);
}

Player* Server::AddPlayer(Player* player)
{
	std::cout << "[Server] AddPlayer " << player->GetDisplayNameExtra() << std::endl;

	m_Players.insert(std::pair<long long, Player*>(player->m_ClientId, player));
	return player;
}

void Server::RemovePlayer(Player* player)
{
	std::cout << "[Server] RemovePlayer " << player->GetDisplayNameExtra() << std::endl;

	m_Players.erase(player->m_ClientId);
	delete player;
}

std::vector<Player*> Server::GetPlayers()
{
	std::vector<Player*> players;
	for (auto pair : m_Players)
	{
		auto player = pair.second;
		players.push_back(player);
	}
	return players;
}

std::vector<Player*> Server::GetOnlinePlayers()
{
	std::vector<Player*> players;
	auto allPlayers = GetPlayers();

	for (auto player : allPlayers)
	{
		if (!player->m_IsOnline) continue;

		players.push_back(player);
	}
	return players;
}

void Server::OnAddPlayerToLobby(long long clientId)
{
	if (!HasPlayer(clientId))
		OnPlayerFirstJoin(clientId);

	auto player = GetPlayer(clientId);
	player->m_IsOnline = true;
	player->UpdateInfo();

	OnPlayerJoin(player);
}

void Server::OnRemovePlayerFromLobby(long long clientId)
{
	auto player = GetPlayer(clientId);
	player->m_IsOnline = false;

	OnPlayerLeave(player);
}

void Server::OnPlayerFirstJoin(long long clientId)
{
	auto player = new Player(clientId);

	player->UpdateInfo();

	AddPlayer(player);

	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined for the first time" << std::endl;
}

void Server::OnPlayerJoin(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined" << std::endl;
}

void Server::OnPlayerLeave(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " left" << std::endl;
}

void Server::OnPlayerSpawn(Player* player, Vector3 position)
{
	player->UpdateInfo();

	std::cout << "[Server] " << player->GetDisplayNameExtra() << " spawned at " << position << std::endl;

	Chat::SendServerMessage("Player " + player->GetDisplayName() + " spawned");
}