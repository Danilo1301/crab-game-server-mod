#pragma once

#include "pch.h"

class CrateBot {
public:
	static bool m_Enabled;
	static float m_Changetime;
	static std::vector<long long> m_SpawnedPlayers;

	static void OnSpawnPlayer(long long id);
	static void Update(float dt);
};