#pragma once

#include "pch.h"

/*
* todo:
Create vote system using   new VoteSystem()
*/

class MapSkip
{
public:
	static bool m_CanSkip;
	static bool m_SkippingThisMap;
	static std::vector<long long> m_Votes;
	static int m_NumPlayersToVote;

	static bool CanSkip();
	static void VoteSkip(long long id);
	static bool HasIdVoted(long long id);
	static bool CanIdVote(long long id);
	static void OnMapLoad(int map, int mode);

	static void SkipMap();

	static void Reset();

	static int GetNumOfPlayersInLobby();
};