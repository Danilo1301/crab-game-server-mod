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

	static void Init();
	static void Update(float dt);

	static bool HasPlayer(long long clientId);
	static Player* GetPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static void RemovePlayer(Player* player);
	static std::vector<Player*> GetPlayers();
	static std::vector<Player*> GetOnlinePlayers();

	static void OnAddPlayerToLobby(long long clientId);
	static void OnRemovePlayerFromLobby(long long clientId);
	static void OnPlayerFirstJoin(long long clientId);

	static void OnPlayerJoin(Player* player);
	static void OnPlayerLeave(Player* player);

	static void OnPlayerSpawn(Player* player, Vector3 position);
};