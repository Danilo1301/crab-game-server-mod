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

	for (auto player : GetOnlinePlayers())
	{
		bool wasAlive = player->GetIsAlive();
		bool isAlive = player->CheckIsAlive();

		if (!wasAlive && isAlive)
		{
			OnPlayerSpawn(player, player->m_Position);
			SendGameSpawnPlayerToAll(player);
		}
	}
}

void Server::UpdatePlayersPosition()
{
	for (auto player : GetOnlinePlayers())
	{
		player->m_PlayerManager = NULL;
	}

	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
	auto activePlayers = gameManager->fields.activePlayers;

	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto playerManager = activePlayers->fields.entries->vector[i].value;

		if (!playerManager) continue;

		auto player = GetPlayer(key);
		player->m_PlayerManager = playerManager;

		auto transform = Component_get_transform((Component*)playerManager, nullptr);
		auto pos = Transform_get_position(transform, nullptr);

		player->m_Position = pos;

		//auto headTransform = playerManager->fields.head;
		//auto headPos = Transform_get_position(headTransform, nullptr);
		//std::cout << "headPos" << headPos.toString() << std::endl;

		//auto euler = Transform_get_eulerAngles(headTransform, nullptr);
		//std::cout << "head euler" << euler.toString() << std::endl;

		//std::cout << "head forward" << player->m_FlyDir.toString() << std::endl;

		auto quat = PlayerManager_GetRotation(playerManager, NULL); //thank god (or thank Dani) this function exists lol
		auto forward = Quaternion_op_Multiply_1(quat, Vector3_get_forward(NULL), NULL);
		player->m_LookDir = Vector3_Normalize(forward, NULL);

		//Quaternion__Boxed* myQuat = (Quaternion__Boxed*)il2cpp_object_new((Il2CppClass*)*Quaternion__TypeInfo);
		//Quaternion__ctor(myQuat, quat.x, quat.y, quat.z, quat.w, NULL);


		/*
		auto quatEuler = Quaternion_get_eulerAngles(myQuat, NULL);
		auto pitch = -quatEuler.y * (M_PI / 180.0);
		auto yaw = quatEuler.x * (M_PI / 180.0);
		Vector3 direction(
			std::cos(yaw) * std::cos(pitch),
			std::sin(yaw) * std::cos(pitch),
			std::sin(pitch)
		);
		std::cout << "quatEuler" << quatEuler.toString() << std::endl;
		std::cout << "direction" << direction.toString() << std::endl;
		*/

		//Quaternion_

		//auto quatEuler = Quaternion_get_eulerAngles(quat, NULL);

		//boxed

		//targetRot * Vector3.forward;

		//Quaternion_iden


		//player->m_FlyDir = euler;

		// 
		//auto headTransform = playerManager->fields.head;
		//auto headPos = Transform_get_position(headTransform, nullptr);

		//std::cout << i << " : " << key << ", dead=" << playerManager->fields.dead << ", justdied=" << playerManager->fields.justDied << std::endl;
		//std::cout << key << " transform pos" << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
		//std::cout << "head pos" << headPos.x << ", " << headPos.y << ", " << headPos.z << std::endl;



			//std::cout << key << " transform pos" << Mod::FormatVector(GetPlayer(key)->m_Position) << std::endl;

	}
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

void Server::OnStartNewLobby(long long lobbyId, long long lobbyCodeId)
{
	std::cout << "[Server] OnStartNewLobby " << lobbyId << ", " << lobbyCodeId << std::endl;
}

bool Server::OnTryBanPlayer(Player* player)
{
	std::cout << "[Server] OnTryBanPlayer " << player->GetDisplayNameExtra() << std::endl;

	return false;
}


void Server::OnAddPlayerToLobby(long long clientId)
{
	if (!HasPlayer(clientId))
	{
		auto player = new Player(clientId);
		AddPlayer(player);

		OnPlayerFirstJoin(player);
	}

	auto player = GetPlayer(clientId);

	player->m_IsOnline = true;
	player->UpdateInfo();

	OnPlayerJoin(player);
}

void Server::OnRemovePlayerFromLobby(long long clientId)
{
	if (!HasPlayer(clientId)) return;

	auto player = GetPlayer(clientId);

	player->m_IsOnline = false;
	player->UpdateInfo();

	OnPlayerLeave(player);
}

void Server::OnPlayerFirstJoin(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined for the first time" << std::endl;
}

void Server::OnPlayerJoin(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined" << std::endl;

	//reset some stuff
	player->m_CanRespawnNextRound = false;
}

void Server::OnPlayerLeave(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " left" << std::endl;
}

void Server::OnGameSpawnPlayer(Player* player, Vector3 position)
{
	//Chat::SendServerMessage("game spawn player");

	std::cout << "[Server] OnGameSpawnPlayer: " << player->GetDisplayNameExtra() << std::endl;

	if (!player->m_IsAlive)
	{
		Server::OnPlayerSpawn(player, position);
	}
}

void Server::OnPlayerSpawn(Player* player, Vector3 position)
{
	player->UpdateInfo();
	player->m_IsAlive = true;
	player->m_SpawnedAsSpectator = false;

	player->m_CanRespawnNextRound = false;

	std::cout << "[Server] " << player->GetDisplayNameExtra() << " spawned at " << position << std::endl;
	Chat::SendServerMessage(player->GetDisplayNameExtra() + " spawned at ");
}

bool Server::OnPlayerTryToSpawnSpectator(Player* player)
{
	std::cout << "[Server] OnPlayerTryToSpawnSpectator: " << player->GetDisplayNameExtra() << std::endl;

	player->UpdateInfo();

	if (player->m_CanRespawnNextRound)
	{
		std::cout << "[Server] Cant spawn this round" << std::endl;

		player->m_IsAlive = true;
	}

	if (player->m_IsAlive)
	{
		std::cout << "[Server] Spec cancelled, spawnning" << std::endl;

		auto byteArray = player->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7;
		auto numberId = player->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0;

		GameServer_PlayerSpawnRequest(
			player->m_ClientId,
			false,
			byteArray,
			numberId,
			NULL
		);

		return false;
	}

	player->m_IsAlive = false;
	player->m_SpawnedAsSpectator = true;

	return true;
}

bool Server::OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir)
{
	std::cout << "[Server] " << deadPlayer->GetDisplayNameExtra() << " died" << std::endl;

	if (killerPlayer != NULL && killerPlayer != deadPlayer)
	{
		Chat::SendServerMessage(killerPlayer->GetDisplayName() + " killed " + deadPlayer->GetDisplayName());
	}
	else {
		Chat::SendServerMessage(deadPlayer->GetDisplayName() + " died");
	}

	deadPlayer->m_IsAlive = false;
	return true;
}

bool Server::OnSendModeState(int state)
{
	std::cout << "[Server] OnSendModeState " << state << std::endl;

	/*
	if (state == 2 || state == 1)
	{
		for (auto player : GetPlayers())
		{
			RespawnPlayer(player);
			//player->m_IsAlive = true;

			//Chat::SendServerMessage(player->GetDisplayName() + " set to ALIVE");
		}
	}
	*/

	return true;
}

void Server::OnMapLoad(int map, int mode)
{
	std::cout << "[Server] OnMapLoad" << std::endl;

	m_MapId = map;
	m_MapModeId = mode;

	for (auto player : GetOnlinePlayers())
	{
		if (player->m_IsAlive) player->m_CanRespawnNextRound = true;
		player->m_IsAlive = false;
	}
}

void Server::OnMapStart()
{
	std::cout << "[Server] OnMapStart" << std::endl;


}

void Server::GiveWeapon(Player* player, int weaponId)
{
	std::cout << "[Server] GiveWeapon " << player->GetDisplayNameExtra() << ", " << weaponId << std::endl;

	if (!player->GetIsAlive()) return;

	Mod::SendDropItem(player->m_ClientId, weaponId, m_UniqueObjectId++, 30);
}

Weapon* Server::GetWeaponById(int weaponId)
{
	for (auto& weapon : Server::m_Weapons)
	{
		if (weaponId == weapon.id) return &weapon;
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


void Server::KillPlayer(Player* player)
{
	std::cout << "[Server] KillPlayer " << player->GetDisplayNameExtra() << std::endl;

	GameServer_PlayerDied(player->m_ClientId, player->m_ClientId, Vector3({ 0, 1, 0 }), NULL);
	//ServerSend_PlayerDied(clientId, clientId, Vector3({ 0, 1, 0 }), NULL);
}

void Server::RespawnPlayer(Player* player)
{
	std::cout << "[Server] RespawnPlayer " << player->GetDisplayNameExtra() << std::endl;

	if (player->GetIsAlive())
	{
		std::cout << "[Server] Already alive" << std::endl;
	}

	if (player->m_SpawnedAsSpectator)
	{
		/*
		Bug: If host respawns with load, he won't see the players that were alive
		*/

		std::cout << "[Server] Trying to respawn spectator" << std::endl;

		Mod::RespawnSpectator(player);
	} else {
		std::cout << "[Server] Trying to normal respawn" << std::endl;

		auto gameServer = (*GameServer__TypeInfo)->static_fields->Instance;
		GameServer_QueueRespawn(gameServer, player->m_ClientId, 0.0f, NULL);
	}
}

void Server::RestartGame()
{
	std::cout << "[Server] RestartGame" << std::endl;

	OnMapLoad(m_MapId, m_MapModeId);

	ServerSend_StartGame(NULL);
}


void Server::SendGameSpawnPlayerToAll(Player* spawnedPlayer)
{
	std::cout << "[Server] SendGameSpawnPlayerToAll" << std::endl;
	Chat::SendServerMessage("SendGameSpawnPlayerToAll");

	UpdatePlayersPosition();

	auto players = Server::GetOnlinePlayers();

	for (auto player : players)
	{
		auto byteArray = spawnedPlayer->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7;
		auto numberId = spawnedPlayer->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0;

		ServerSend_GameSpawnPlayer(player->m_ClientId, spawnedPlayer->m_ClientId, spawnedPlayer->m_Position, 0, false, byteArray, numberId, NULL);
	}

	for (auto player : players)
	{
		if (!player->m_IsAlive) continue;

		auto byteArray = player->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7;
		auto numberId = player->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0;

		ServerSend_GameSpawnPlayer(spawnedPlayer->m_ClientId, player->m_ClientId, player->m_Position, 0, false, byteArray, numberId, NULL);
	}
}