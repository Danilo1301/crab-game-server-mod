#pragma once

#include "pch.h"

#include "Player.h"

using namespace app;

struct Weapon {
	std::string name;
	int id;
};

class Server {
public:
	static std::vector<Weapon> m_Weapons;
	static std::map<long long, Player*> m_Players;
	static int m_UniqueObjectId;

	static int m_MapId;
	static int m_MapModeId;

	static void Init();
	static void Update(float dt);

	static bool HasPlayer(long long clientId);
	static Player* GetPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static void RemovePlayer(Player* player);
	static std::vector<Player*> GetPlayers();
	static std::vector<Player*> GetOnlinePlayers();
	static std::vector<Player*> FindPlayers(std::string selector);

	static void OnAddPlayerToLobby(long long clientId);
	static void OnRemovePlayerFromLobby(long long clientId);
	static void OnPlayerFirstJoin(long long clientId);

	static void OnPlayerJoin(Player* player);
	static void OnPlayerLeave(Player* player);

	static void OnPlayerSpawn(Player* player, Vector3 position);
	static bool OnPlayerTryToSpawnSpectator(Player* player);
	static void OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir);

	static void OnMapLoad(int map, int mode);
	static void OnMapStart();

	static void GiveWeapon(long long toClient, int weaponId);
	static Weapon* GetWeaponById(int weaponId);

	static Player* GetLobbyOwner();

	static void KillPlayer(long long clientId);
	static void RespawnPlayer(long long clientId);
};