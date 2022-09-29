#pragma once

#include "pch.h"

class VoteSystem {
public:
	static float m_TimeLeft;
	static std::string m_Title;

	static std::vector<long long> m_VotesYes;
	static std::vector<long long> m_VotesNo;

	static std::function<void(void)> m_FnOnPass;
	static std::function<void(void)> m_FnOnFail;

	static bool HasAnyVoting();

	static void Update(float dt);

	static void StartVote(std::string title, float seconds, std::function<void(void)> onSuccess, std::function<void(void)> onFail);

	static void Vote(bool yes, long long id);

	static bool HasIdVoted(long long id);

	static void PrintVotationStatus();

	static void EndVote();

	static bool GetVotePass(int yes, int no);

	static void SendVoteMessage(std::string message1, std::string message2);
	static void SendEndVoteMessage();
};