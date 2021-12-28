#include "CrateBot.h"

#include "Server.h"

bool CrateBot::m_Enabled = false;
float CrateBot::m_Changetime;
std::vector<long long> CrateBot::m_SpawnedPlayers;

void CrateBot::OnSpawnPlayer(long long id) {
	if (!m_Enabled) return;

	if (std::find(m_SpawnedPlayers.begin(), m_SpawnedPlayers.end(), id) == m_SpawnedPlayers.end()) {
		m_SpawnedPlayers.push_back(id);

		Server::SendServerMessage("spawned");
	}
}


void CrateBot::Update(float dt) {
	if (!m_Enabled) return;

	m_Changetime += dt;

	if (m_Changetime >= 3000 && !Server::m_IsAtLobby)
	{
		m_SpawnedPlayers.clear();
		m_Changetime = 0;

		Server::SendServerMessage("set time");
		Server::SetCurrentGameModeTime(2);
	}

	if ((int)m_SpawnedPlayers.size() >= 2)
	{
		m_SpawnedPlayers.clear();

		Server::SendServerMessage("ready");
		Server::SetAllReady();
	}
}