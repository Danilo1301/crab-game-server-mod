#include "pch-il2cpp.h"
#include "Server.h"

#include "Chat.h"
#include "Mod.h"
#include "Weapon.h"
#include "Config.h"
#include "PermissionGroups.h"
#include "systems/ModeDeathMatch.h"
#include "systems/EquipItem.h"
#include "systems/UpdateCheck.h"
#include "systems/AutoStart.h"
#include "systems/Fly.h"
#include "systems/VoteSystem.h"
#include "systems/Hover.h"
#include "templates/templates.h"

std::map<long long, Player*> Server::Players;

int Server::MapId = -1;
int Server::MapModeId = -1;
long long Server::LobbyId = 0;

float Server::AutoSaveTimeLeft = 0.0f;
float Server::AutoSaveInterval = 20.0f;

void Server::Init()
{
	std::cout << "[Server] Init" << std::endl;

	Config::Load();

	if (!PermissionGroups::HasGroup("default"))
	{
		auto permissionGroup = PermissionGroups::AddGroup("default");
		permissionGroup->Name = "Default";
		permissionGroup->AddPermission("help");
		permissionGroup->AddPermission("ahelp");
		permissionGroup->AddPermission("w");
		permissionGroup->AddPermission("playerinfo");
		permissionGroup->AddPermission("tp");
		permissionGroup->AddPermission("kill");
		permissionGroup->AddPermission("respawn");
		permissionGroup->AddPermission("autorespawn");
		permissionGroup->AddPermission("hover");
		permissionGroup->AddPermission("jumppunch");
		permissionGroup->AddPermission("superpunch");
		permissionGroup->AddPermission("forcefield");
		permissionGroup->AddPermission("snowball2");
		permissionGroup->AddPermission("vote");
		permissionGroup->AddPermission("votekick");
		permissionGroup->AddPermission("skip");
		for (auto weapon : WeaponList) permissionGroup->AddPermission(toLower(weapon.name));
	}

	if (!PermissionGroups::HasGroup("mod"))
	{
		auto permissionGroup = PermissionGroups::AddGroup("mod");
		permissionGroup->Name = "Mod";
		permissionGroup->InheritsFromGroup = "default";
		permissionGroup->AddPermission("kick");
		permissionGroup->AddPermission("ban");
		permissionGroup->AddPermission("bc");
		permissionGroup->AddPermission("w.others");
		permissionGroup->AddPermission("respawn.others");
		permissionGroup->AddPermission("tp.others");
		permissionGroup->AddPermission("tp.others");
		permissionGroup->AddPermission("god");
		permissionGroup->AddPermission("god.others");
		permissionGroup->AddPermission("time");
		permissionGroup->AddPermission("r");
		permissionGroup->AddPermission("mute");
		permissionGroup->AddPermission("lobbyonly");
		permissionGroup->AddPermission("start");
	}

	if (!PermissionGroups::HasGroup("admin"))
	{
		auto permissionGroup = PermissionGroups::AddGroup("admin");
		permissionGroup->Name = "Admin";
		permissionGroup->AddPermission("*");
	}

	Config::Save();

	Chat::Init();
}

void Server::Update(float dt)
{
	if (!Mod::IsInAnyLobby()) return;

	//std::cout << "[Server] owner " << Mod::GetCurrentLobbyOwnerId() << " | lobby " << LobbyId << " | myid " << Mod::GetMySteamId() << std::endl;

	EquipItem::Update();

	if (!Mod::IsLobbyOwner()) return;

	UpdatePlayersPosition();

	VoteSystem::Update(dt);
	UpdateCheck::Check();
	ModeDeathMatch::Update(dt);
	AutoStart::Update(dt);
	Fly::Update(dt);
	Hover::Update(dt);

	//ProcessSpawnRequest
	for (auto pair : Players)
	{
		auto player = pair.second;

		if (!player->SpawnCallbackRequest) continue;
		player->SpawnCallbackRequest = false;

		Server::OnPlayerSpawn(player, player->Position);
	}

	//ProcessRespawn
	for (auto pair : Players)
	{
		auto player = pair.second;

		if (player->RespawnTime > 0)
		{
			player->RespawnTime -= dt;
			if (player->RespawnTime < 0)
			{
				player->RespawnTime = 0;
				RespawnPlayer(player);
			}
		}
	}

	Chat::Update(dt);

	ProcessAutoSave(dt);
}

void Server::UpdatePlayersPosition()
{
	/*
	for (auto pair : m_Players)
	{
		auto player = pair.second;
		player->m_PlayerManager = NULL;
	}
	*/

	if (!*GameManager__TypeInfo) return;

	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;

	if (!gameManager) return;

	auto activePlayers = gameManager->fields.activePlayers;

	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto playerManager = activePlayers->fields.entries->vector[i].value;

		if (!playerManager) continue;

		auto player = GetPlayer(key);

		if (!player) return;

		//player->PlayerManager = playerManager;

		auto transform = Component_get_transform((Component*)playerManager, nullptr);
		auto pos = Transform_get_position(transform, nullptr);

		if (!player->FlyEnabled) //otherwise players will fall slowly
			player->Position = pos;

		//auto headTransform = playerManager->fields.head;
		//auto headPos = Transform_get_position(headTransform, nullptr);
		//std::cout << "headPos" << headPos.toString() << std::endl;

		//auto euler = Transform_get_eulerAngles(headTransform, nullptr);
		//std::cout << "head euler" << euler.toString() << std::endl;

		//std::cout << "head forward" << player->m_FlyDir.toString() << std::endl;

		auto quat = PlayerManager_GetRotation(playerManager, NULL); //thank god (or thank Dani) this function exists lol
		auto forward = Quaternion_op_Multiply_1(quat, Vector3_get_forward(NULL), NULL);
		player->LookDir = Vector3_Normalize(forward, NULL);

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

void Server::ProcessAutoSave(float dt)
{
	//std::cout << "[Server] autosave " << AutoSaveTimeLeft << std::endl;

	AutoSaveTimeLeft -= dt;
	if (AutoSaveTimeLeft < 0)
	{
		AutoSaveTimeLeft = AutoSaveInterval;
		Config::Save();
	}
}

bool Server::HasPlayer(long long clientId)
{
	return Players.find(clientId) != Players.end();
}

Player* Server::GetPlayer(long long clientId)
{
	if (!HasPlayer(clientId)) return NULL;
	return Players.at(clientId);
}

Player* Server::AddPlayer(Player* player)
{
	std::cout << "[Server] AddPlayer " << player->GetDisplayNameExtra() << std::endl;

	Players.insert(std::pair<long long, Player*>(player->ClientId, player));
	return player;
}

void Server::RemovePlayer(Player* player)
{
	std::cout << "[Server] RemovePlayer " << player->GetDisplayNameExtra() << std::endl;

	Players.erase(player->ClientId);
	delete player;
}

std::vector<Player*> Server::GetPlayers()
{
	std::vector<Player*> players;
	for (auto pair : Players)
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
		if (!player->IsOnline) continue;
		players.push_back(player);
	}
	return players;
}

void Server::OnAddPlayerToLobby(long long clientId)
{
	bool firstJoin = !HasPlayer(clientId);

	if (firstJoin)
	{
		auto newPlayer = new Player(clientId);
		newPlayer->UpdateInfo();

		AddPlayer(newPlayer);
	}

	auto player = GetPlayer(clientId);
	player->UpdateInfo();
	player->IsOnline = true;

	OnPlayerJoin(player);

	if(firstJoin) OnPlayerFirstJoin(player);
}

void Server::OnRemovePlayerFromLobby(long long clientId)
{
	auto player = GetPlayer(clientId);
	player->IsOnline = false;

	OnPlayerLeave(player);
}

void Server::OnPlayerFirstJoin(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined for the first time" << std::endl;

	player->FirstEverSpawn = true;

	//if (player->IsLobbyOwner()) player->PermissionGroupId = "admin";
	//lobby owner hasnt been updated yet :/

	Config::Save();
}

void Server::OnPlayerJoin(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " joined" << std::endl;

	player->IsOnline = true;
	player->SpawnedThisRound = false; //alreay added at OnLeave
	player->DiedThisRound = false; //alreay added at OnLeave

	//alreay added at OnLeave
	//if he spawns (lobby example), alive is set to true
	//if this is set to true, it will spawn even if game is already running YEY
	player->IsAlive = false;

	ModeDeathMatch::OnPlayerJoin(player);
	
}

void Server::OnPlayerLeave(Player* player)
{
	std::cout << "[Server] " << player->GetDisplayNameExtra() << " left" << std::endl;

	player->Client = NULL;
	player->PlayerManager = NULL;
	player->IsAlive = false;
	player->Id = -1;
	player->IsOnline = false;
	player->SpawnedThisRound = false;
	player->DiedThisRound = false;
}

/*
Called when game sends an info that someone spawned
Can be called multiple times, so need to check its first time with .SpawnedThisRound
*/
void Server::OnGameSpawnPlayer(Player* player, Vector3 position)
{
	player->UpdateInfo();

	if (player->SpawnedThisRound)
	{
		//Chat::SendServerMessage(spawnedPlayer->GetDisplayNameExtra() + " already spawned, ignoring");
		return;
	}

	player->SpawnedThisRound = true;
	player->SpawnCallbackRequest = true;
	//Server::OnPlayerSpawn(player, player->Positon);
}

bool Server::OnPlayerTryToSpawnSpectator(Player* player)
{
	player->UpdateInfo();

	std::cout << "[Server] OnPlayerTryToSpawnSpectator: " << player->GetDisplayNameExtra() << std::endl;
	std::cout << "         IsAlive= " << (player->IsAlive ? "TRUE" : "FALSE") << std::endl;

	//wants to spawn spectator but IsAlive is set to true
	if (player->IsAlive)
	{
		if (!player->Client)
		{
			Chat::SendServerMessage("OnPlayerTryToSpawnSpectator: Client not found");
			return true;
		}

		auto byteArray = player->Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7;
		auto numberId = player->Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0;

		std::cout << "[Server] Sending GameServer_PlayerSpawnRequest byteArray=" << byteArray << ", numberId=" << numberId << std::endl;

		GameServer_PlayerSpawnRequest(
			player->ClientId,
			false,
			byteArray,
			numberId,
			NULL
		);

		//Chat::SendServerMessage("[try-spawn-spec] alive=true, spawning in game");

		return false;
	}

	//Chat::SendServerMessage("[try-spawn-spec] spawning spectator");

	std::cout << "[Server] Spawning spec" << std::endl;

	//player->PlayerManager = NULL; //why did I add this?

	return true;
}


/*
* Called after player spawns
*/
void Server::OnPlayerSpawn(Player* player, Vector3 position)
{
	player->IsAlive = true;

	std::cout << "[Server] OnPlayerSpawn " << player->GetDisplayNameExtra() << ", at " << position << std::endl;

	//Chat::SendServerMessage(player->GetDisplayNameExtra() + " spawned at " + position.format_3());

	if (player->FirstEverSpawn)
	{
		player->FirstEverSpawn = false;

		if (player->IsLobbyOwner()) player->PermissionGroupId = "admin";

		//Chat::SendServerMessage(player->GetDisplayName() + " is new here :)");
	}

	ModeDeathMatch::OnPlayerSpawn(player, position);
}

/*
return true - player dies
return false - player stays alive
*/
bool Server::OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir)
{
	if (deadPlayer->Godmode)
		return false;

	deadPlayer->IsAlive = false;
	deadPlayer->DiedThisRound = true;

	if (deadPlayer->ClientId == killerPlayer->ClientId)
	{
		Chat::SendServerMessage("" + deadPlayer->GetDisplayName() + " died");
		std::cout << "[Server] " << deadPlayer->GetDisplayNameExtra() << " died" << std::endl;
	}
	else
	{
		Chat::SendServerMessage("" + killerPlayer->GetDisplayName() + " killed " + deadPlayer->GetDisplayName());
		std::cout << "[Server] " << killerPlayer->GetDisplayNameExtra() << " killed " << deadPlayer ->GetDisplayNameExtra() << std::endl;

	}

	ModeDeathMatch::OnPlayerDied(deadPlayer, killerPlayer, damageDir);

	return true;
}

void Server::KillPlayer(Player* player)
{
	std::cout << "[Server] KillPlayer " << player->GetDisplayNameExtra() << std::endl;

	GameServer_PlayerDied(player->ClientId, player->ClientId, Vector3({ 0, 1, 0 }), NULL);
	//ServerSend_PlayerDied(clientId, clientId, Vector3({ 0, 1, 0 }), NULL);
}


/*
Wtf, actually fixed?
Bug: If host respawns with load, he won't see the players that were alive
*/
void Server::RespawnPlayer(Player* player)
{
	std::cout << "[Mod] RespawnPlayer " << player->GetDisplayNameExtra() << std::endl;

	//Chat::SendServerMessage("[respawn] trying to respawn");

	//not alive and not already spawned, usually when spawning as spec in next game, or when join already started game
	if (!player->IsAlive && !player->DiedThisRound)
	{
		//Chat::SendServerMessage("[respawn] send load game");

		RespawnSpectator(player);
	}
	else {
		auto gameServer = (*GameServer__TypeInfo)->static_fields->Instance;
		GameServer_QueueRespawn(gameServer, player->ClientId, 0.0f, NULL);

		Server::OnPlayerSpawn(player, player->Position);
	}

	player->IsAlive = true;

	//update playermanager
	player->PlayerManager = NULL;
	player->UpdateInfo();
}

/*
Old respawn, or now a set position/tp
*/
void Server::RespawnActivePlayerAtPos(long long clientId, Vector3 position)
{
	if (Server::HasPlayer(clientId))
	{
		//TESTHERE

		auto player = Server::GetPlayer(clientId);
		player->IsAlive = true;

		std::cout << "[Server] RespawnActivePlayerAtPos " << player->GetDisplayNameExtra() << std::endl;
	}

	//std::cout << "[Mod] RespawnPlayer clientId=" << clientId << formatVector3_full(position) << std::endl;

	ServerSend_RespawnPlayer(clientId, position, NULL);
}

void Server::RespawnSpectator(Player* player)
{
	std::cout << "[Server] RespawnSpectator " << player->GetDisplayNameExtra() << std::endl;

	//to get client
	player->UpdateInfo();

	if (!player->Client)
	{
		Chat::SendServerMessage("RespawnSpectator: client not found");
		return;
	}

	ServerSend_LoadMap(Server::MapId, Server::MapModeId, player->ClientId, NULL);
	ServerSend_LoadingSendIntoGame(player->ClientId, NULL);

	GameServer_PlayerSpawnRequest(
		player->ClientId,
		false,
		player->Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, //byteArray
		player->Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0, //numberId
		NULL
	);
}

std::vector<Player*> Server::FindPlayers(std::string selector)
{
	//add check for online

	std::vector<Player*> players;

	for (auto player : GetPlayers())
	{
		//contains only digits - "23" or "76561199219991380"
		if (std::all_of(selector.begin(), selector.end(), ::isdigit))
		{
			auto id = std::stoll(selector);

			// "76561199219991380" - dont need to be online
			if (player->ClientId == id)
			{
				players.push_back(player);
			}

			// "23"
			if (player->Id == id)
			{
				if (!player->IsOnline) continue;

				players.push_back(player);
			}
			continue;
		}

		if (!player->IsOnline) continue;

		// all - "*"
		if (selector == "*")
		{
			players.push_back(player);
			continue;
		}

		// all alive - "*a"
		if (selector == "*a")
		{
			if (!player->IsAlive) continue;

			players.push_back(player);
			continue;
		}

		// all dead - "*d"
		if (selector == "*d")
		{
			if (player->IsAlive) continue;

			players.push_back(player);
			continue;
		}

		// by id "#23"
		if (selector.rfind("#", 0) == 0)
		{
			std::string idstr;
			std::remove_copy(selector.begin(), selector.end(), std::back_inserter(idstr), '#');

			int id = std::atoi(idstr.c_str());

			if (player->Id == id)
			{
				players.push_back(player);
			}

			continue;
		}

		// any string
		std::string str1 = selector;
		std::transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) { return std::tolower(c); });
		std::string str2 = player->Username;
		std::transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) { return std::tolower(c); });

		if (str2.find(str1) != std::string::npos) {
			players.push_back(player);
		}
	}

	return players;
}

void Server::GiveWeapon(Player* player, int weaponId)
{
	std::cout << "[Server] GiveWeapon " << weaponId << " to " << player->GetDisplayNameExtra() << std::endl;

	//if (!player->IsAlive) return;

	Mod::ForceGiveItem(player->ClientId, weaponId, Mod::UniqueObjectId++);
}

void Server::DropWeapon(Player* player, int weaponId, int ammo)
{
	std::cout << "[Server] DropWeapon " << weaponId << " to " << player->GetDisplayNameExtra() << std::endl;

	//if (!player->IsAlive) return;

	//Mod::ForceGiveItem(player->ClientId, weaponId, Mod::UniqueObjectId++);
	Mod::SendDropItem(player->ClientId, weaponId, Mod::UniqueObjectId++, ammo);
}

void Server::OnMapLoad(int map, int mode)
{
	std::cout << "[Server] OnMapLoad" << std::endl;

	MapId = map;
	MapModeId = mode;

	AutoStart::OnMapLoad(map, mode);
}

void Server::OnMapStart()
{
	std::cout << "[Server] OnMapStart" << std::endl;

	for (auto player : GetOnlinePlayers())
	{
		player->DiedThisRound = false;
		player->SpawnedThisRound = false;
	}

	GameServer_ForceRemoveAllWeapons(NULL);

	AutoStart::OnMapStart();
}

void Server::OnLobbyStart(long long lobbyId)
{
	std::cout << "[Server] OnLobbyStart " << lobbyId << std::endl;

	LobbyId = lobbyId;
}

void Server::RestartGame()
{
	Mod::RestartGame();

	OnMapLoad(MapId, MapModeId);
	//OnMapStart(); ///gets called automatically by game
}

void Server::OnPunchPlayer(uint64_t playerId, uint64_t punchedPlayerId, Vector3 dir, MethodInfo* method)
{
	//HOW TF DOES THIS CRASH
	//normal punch
	//HF_ServerSend_PunchPlayer->original(playerId, punchedPlayerId, dir, method);

	if (Server::HasPlayer(playerId)) Fly::OnPunch(Server::GetPlayer(playerId));
}

bool Server::IsAtLobby()
{
	return MapModeId == 0;
}

Player* Server::GetLobbyOwner()
{
	for (auto player : GetOnlinePlayers())
	{
		if (player->Id == 1) return player;
	}
	return NULL;
}
