#pragma once

#include "pch.h"

#include "Player.h"

class Server {
public:
	static std::map<long long, Player*> Players;
	static int MapId;
	static int MapModeId;
	static long long LobbyId;

	static int PunchDamageId;

	static void Init();

	//From Template_GameManager_Update  or  Template_ChatBox_Update
	static void Update(float dt); 

	static void UpdatePlayersPosition();

	static bool HasPlayer(long long clientId);
	static Player* GetPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static void RemovePlayer(Player* player);
	static std::vector<Player*> GetPlayers();
	static std::vector<Player*> GetOnlinePlayers();

	//From Template_LobbyManager_AddPlayerToLobby
	static void OnAddPlayerToLobby(long long clientId);

	//From Template_LobbyManager_RemovePlayerFromLobby
	static void OnRemovePlayerFromLobby(long long clientId);

	static void OnPlayerFirstJoin(Player* player);
	static void OnPlayerJoin(Player* player);
	static void OnPlayerLeave(Player* player);


	//From Template_ServerSend_GameSpawnPlayer
	static void OnGameSpawnPlayer(Player* player, Vector3 position);

	//From Template_ServerSend_SpectatorSpawn
	static bool OnPlayerTryToSpawnSpectator(Player* player);

	static void OnPlayerSpawn(Player* player, Vector3 position);


	//From Template_ServerSend_PlayerDied
	static bool OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir);

	static void KillPlayer(Player* player);
	static void RespawnPlayer(Player* player);
	static void RespawnActivePlayerAtPos(long long clientId, Vector3 position);

	static std::vector<Player*> FindPlayers(std::string selector);

	static void GiveWeapon(Player* player, int weaponId);
	static void DropWeapon(Player* player, int weaponId, int ammo);

	//From Template_ServerSend_LoadMap_1
	static void OnMapLoad(int map, int mode);

	static void OnMapStart();

	//From Template_LobbyManager_StartNewLobby
	static void OnLobbyStart(long long lobbyId);

private:
	static void RespawnSpectator(Player* player);

public:
	static void RestartGame();

	//From Template_ServerSend_PunchPlayer (only works inside template function wtf)
	static void OnPunchPlayer(uint64_t playerId, uint64_t punchedPlayerId, Vector3 dir, MethodInfo* method);

	static bool IsAtLobby();

	static Player* GetLobbyOwner();

	//From Template_ServerSend_UseItemAll
	static bool OnTryUseUseItemAll(Player* player, int itemId, Vector3 dir, int objectId, MethodInfo* method);
};