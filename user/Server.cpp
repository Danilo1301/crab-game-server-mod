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
int Server::m_UniqueObjectId = 100;

int Server::m_MapId = -1;
int Server::m_MapModeId = -1;

void Server::Init()
{
	std::cout << "[Server] Init" << std::endl;

	Chat::Init();
}

void Server::Update(float dt)
{
	Chat::Update(dt);

	/*
	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
	if (gameManager)
	{
		if (gameManager->fields.gameMode)
		{
			if (Server::m_MapModeId == 15)
			{
				auto gameMode = (GameModeBlockDrop*)gameManager->fields.gameMode;
				std::cout << "[gameMode - 1]" << gameMode->fields.u109Du10A7u10A4u10A2u109Du10A8u109Du109Eu1099u10A8u10A7 << std::endl;
			}
		}
	}

	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;
	if (lobbyManager)
	{
		if (lobbyManager->fields.gameMode)
		{
			auto gamemodeData = lobbyManager->fields.gameMode;
			std::cout << "[minPlayers]" << gamemodeData->fields.minPlayers << std::endl;
			std::cout << "[maxPlayers]" << gamemodeData->fields.maxPlayers << std::endl;
			std::cout << "[waitForRoundOverToDeclareSoloWinner ]" << gamemodeData->fields.waitForRoundOverToDeclareSoloWinner << std::endl;
		}
	}
	*/
}

bool Server::HasPlayer(long long clientId)
{
	return m_Players.find(clientId) != m_Players.end();
}

Player* Server::GetPlayer(long long clientId)
{
	if (!HasPlayer(clientId)) return NULL;
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

std::vector<Player*> Server::FindPlayers(std::string selector)
{
	std::vector<Player*> players;

	std::map<long long, Player*>::iterator it;
	for (it = m_Players.begin(); it != m_Players.end(); it++)
	{
		Player* player = it->second;

		if (!player->m_IsOnline) continue;

		if (selector == "*")
		{
			players.push_back(player);
			continue;
		}

		if (selector == "*a")
		{
			if (!player->GetIsAlive()) continue;

			players.push_back(player);
			continue;
		}

		if (selector == "*d")
		{
			if (player->GetIsAlive()) continue;

			players.push_back(player);
			continue;
		}

		if (selector.rfind("#", 0) == 0)
		{
			std::string idstr;
			std::remove_copy(selector.begin(), selector.end(), std::back_inserter(idstr), '#');

			int id = std::atoi(idstr.c_str());

			if (player->m_Id == id)
			{
				players.push_back(player);
			}

			continue;
		}

		std::string str1 = selector;
		std::transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) { return std::tolower(c); });
		std::string str2 = player->m_Username;
		std::transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) { return std::tolower(c); });

		if (str2.find(str1) != std::string::npos) {
			players.push_back(player);
		}
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
	player->UpdateInfo();

	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined" << std::endl;

	player->m_CanSpawnNextRound = true;
}

void Server::OnPlayerLeave(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " left" << std::endl;

	player->m_Client = NULL;
	player->m_PlayerManager = NULL;
}

void Server::OnPlayerSpawn(Player* player, Vector3 position)
{
	player->UpdateInfo();
	player->m_IsAlive = true;
	player->m_DiedThisRound = false;
	player->m_CanSpawnNextRound = false;

	std::cout << "[Server] " << player->GetDisplayNameExtra() << " spawned at " << position << std::endl;

	Chat::SendServerMessage("Player " + player->GetDisplayName() + " spawned");
}

bool Server::OnPlayerTryToSpawnSpectator(Player* player)
{
	std::cout << "[Server] OnPlayerTryToSpawnSpectator: " << player->GetDisplayNameExtra() << std::endl;

	player->UpdateInfo();

	if (player->m_CanSpawnNextRound)
	{
		auto byteArray = player->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7;
		auto numberId = player->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0;

		std::cout << "[Server] Sending GameServer_PlayerSpawnRequest byteArray=" << byteArray << ", numberId=" << numberId << std::endl;

		GameServer_PlayerSpawnRequest(
			player->m_ClientId,
			false,
			byteArray,
			numberId,
			NULL
		);

		Chat::SendServerMessage("Spawning, canceling spec");

		return false;
	}

	Chat::SendServerMessage("Spawning spec");

	std::cout << "[Server] Spawning spec" << std::endl;

	player->m_PlayerManager = NULL;

	return true;
}


void Server::OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir)
{
	deadPlayer->m_IsAlive = false;
	deadPlayer->m_DiedThisRound = true;

	std::cout << "[Server] " << deadPlayer->GetDisplayNameExtra() << " died" << std::endl;

	if (killerPlayer != NULL && killerPlayer != deadPlayer)
	{
		Chat::SendServerMessage(killerPlayer->GetDisplayName() + " killed " + deadPlayer->GetDisplayName());
	}
	else {
		Chat::SendServerMessage(deadPlayer->GetDisplayName() + " died");
	}
}

void Server::OnMapLoad(int map, int mode)
{
	m_MapId = map;
	m_MapModeId = mode;
}

void Server::OnMapStart()
{
	Chat::SendServerMessage("Map started");

	for (auto player : GetOnlinePlayers())
	{
		if (player->GetIsAlive())
		{
			player->m_CanSpawnNextRound = true;
		}

		player->m_PlayerManager = NULL;
		player->m_IsAlive = false;
		player->m_DiedThisRound = false;
	}
}

void Server::GiveWeapon(long long toClient, int weaponId)
{
	if (!GetPlayer(toClient)->GetIsAlive()) return;

	Mod::SendDropItem(toClient, weaponId, m_UniqueObjectId++, 30);
}

Weapon* Server::GetWeaponById(int weaponId)
{
	for (auto& weapon : Server::m_Weapons)
	{
		if (weaponId == weapon.id)
		{
			return &weapon;
		}
	}
	return NULL;
}

Player* Server::GetLobbyOwner()
{
	for (auto player : GetOnlinePlayers())
	{
		if (player->m_Id == 1) return player;
	}
	return NULL;
}


void Server::KillPlayer(long long clientId)
{
	std::cout << "[Mod] KillPlayer clientId=" << clientId << std::endl;

	GameServer_PlayerDied(clientId, clientId, Vector3({ 0, 1, 0 }), NULL);
	//ServerSend_PlayerDied(clientId, clientId, Vector3({ 0, 1, 0 }), NULL);
}

/*
Bug: If host respawns with load, he won't see the players that were alive
*/
void Server::RespawnPlayer(long long clientId)
{
	std::cout << "[Mod] RespawnPlayer clientId=" << clientId << std::endl;

	auto player = Server::GetPlayer(clientId);

	bool load = false;
	if (!player->GetIsAlive() && !player->m_DiedThisRound) load = true;

	if (load)
	{
		ServerSend_LoadMap(Server::m_MapId, Server::m_MapModeId, clientId, NULL);
		ServerSend_LoadingSendIntoGame(clientId, NULL);

		GameServer_PlayerSpawnRequest(
			clientId,
			false,
			player->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, //byteArray
			player->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0, //numberId
			NULL
		);
	}
	else {
		auto gameServer = (*GameServer__TypeInfo)->static_fields->Instance;
		GameServer_QueueRespawn(gameServer, clientId, 0.0f, NULL);
	}

	player->UpdateInfo();
}