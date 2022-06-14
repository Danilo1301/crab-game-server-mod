#include "pch-il2cpp.h"
#include "MapSkip.h"

#include "Chat.h"
#include "Server.h"
#include "Mod.h"

bool MapSkip::m_CanSkip = false;
bool MapSkip::m_SkippingThisMap = false;
std::vector<long long> MapSkip::m_Votes;
int MapSkip::m_NumPlayersToVote = 0;

bool MapSkip::CanSkip()
{
	return m_CanSkip;
}

void MapSkip::VoteSkip(long long id)
{
	if (HasIdVoted(id))
	{
		Chat::SendServerMessage("already voted");
		return;
	}

	if (!CanIdVote(id))
	{
		Chat::SendServerMessage("you can't vote");
		return;
	}

	int playersInLobby = GetNumOfPlayersInLobby();

	//if (playersInLobby == 1) playersInLobby = 6; //test

	if (m_NumPlayersToVote == 0 || playersInLobby < m_NumPlayersToVote)
	{
		m_NumPlayersToVote = playersInLobby;
	}

	m_Votes.push_back(id);

	int minVotes = (int)std::floor((float)m_NumPlayersToVote / 2.0f);

	if (playersInLobby < 6) minVotes = playersInLobby;

	int totalVotes = (int)m_Votes.size();
	int left = minVotes - totalVotes;

	if (left <= 0)
	{
		SkipMap();
		return;
	}

	Chat::SendServerMessage("voted skip ( " + std::to_string(totalVotes) + " / " + std::to_string(minVotes) + " )");
}

bool MapSkip::HasIdVoted(long long id)
{
	for (auto i : m_Votes) if (i == id) return true;
	return false;
}

bool MapSkip::CanIdVote(long long id)
{
	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;

	if (!gameManager) return false;

	auto activePlayers = gameManager->fields.activePlayers;
	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto value = activePlayers->fields.entries->vector[i].value;

		if (key != id) continue;
		if (value->fields.dead) continue;

		return true;
	}
	return false;
}

void MapSkip::OnMapLoad(int map, int mode)
{
	Reset();

	m_CanSkip = mode != 0;
}

void MapSkip::SkipMap()
{
	Reset();
	m_SkippingThisMap = true;

	std::vector<long long> players;

	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
	auto activePlayers = gameManager->fields.activePlayers;
	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto value = activePlayers->fields.entries->vector[i].value;

		if (value->fields.dead) continue;

		players.push_back(key);
	}

	ServerSend_SendModeState(2, NULL);

	for (auto playerId : players)
	{
		auto player = Server::GetPlayer(playerId);
		player->m_IsAlive = true;

		Mod::RespawnPlayer(player->m_ClientId, player->m_RespawnPosition);
	}

	ServerSend_FreezePlayers(true, NULL);

	Chat::SendServerMessage("skipping!");
}

void MapSkip::Reset()
{
	m_NumPlayersToVote = 0;
	m_Votes.clear();
	m_CanSkip = false;
	m_SkippingThisMap = false;
}

int MapSkip::GetNumOfPlayersInLobby()
{
	int numPlayers = 0;

	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;

	if (!gameManager) return 0;

	auto activePlayers = gameManager->fields.activePlayers;
	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto value = activePlayers->fields.entries->vector[i].value;

		if (value->fields.dead) continue;

		numPlayers++;
	}

	//auto spectators = gameManager->fields.spectators;

	//numPlayers += activePlayers->fields.count;
	//numPlayers += spectators->fields.count;

	return numPlayers;
}