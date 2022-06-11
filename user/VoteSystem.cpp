#include "pch-il2cpp.h"
#include "VoteSystem.h"

#include "Chat.h"
#include "Server.h"

float VoteSystem::m_TimeLeft = 0.0f;
std::string VoteSystem::m_Title = "";

std::vector<long long> VoteSystem::m_VotesYes;
std::vector<long long> VoteSystem::m_VotesNo;

std::function<void(void)> VoteSystem::m_FnOnPass = NULL;
std::function<void(void)> VoteSystem::m_FnOnFail = NULL;

bool VoteSystem::HasAnyVoting()
{
	return m_TimeLeft > 0;
}

void VoteSystem::Update(float dt)
{
	if (m_TimeLeft > 0)
	{
		m_TimeLeft -= dt;

		//std::cout << "[VoteSystem] time left " << m_TimeLeft << std::endl;

		if (m_TimeLeft <= 0)
		{
			EndVote();
		}
	}
}

void VoteSystem::StartVote(std::string title, float seconds, std::function<void(void)> onSuccess, std::function<void(void)> onFail)
{
	std::cout << "[VoteSystem] start vote " << title << std::endl;

	m_Title = title;
	m_TimeLeft = seconds;
	m_VotesYes.clear();
	m_VotesNo.clear();
	m_FnOnPass = onSuccess;
	m_FnOnFail = onFail;

	SendVoteMessage("Type (!yes) or (!no) to vote", "Ends in " + std::to_string((int)seconds) + " seconds");
}

void VoteSystem::Vote(bool yes, long long id)
{
	if (HasIdVoted(id))
	{
		Chat::SendServerMessage("already voted");
		return;
	}

	if (yes) m_VotesYes.push_back(id);
	else m_VotesNo.push_back(id);

	PrintVotationStatus();

	std::string playerName = Server::HasPlayer(id) ? Server::GetPlayer(id)->GetDisplayName() : std::to_string(id);

	int votesYes = (int)m_VotesYes.size();
	int votesNo = (int)m_VotesNo.size();

	SendVoteMessage(
		playerName + " voted " + (yes ? "YES" : "NO"),
		"(!yes): " + std::to_string(votesYes) + "  |  (!no): " + std::to_string(votesNo)
	);
}

bool VoteSystem::HasIdVoted(long long id)
{
	for (auto i : m_VotesYes) if (i == id) return true;
	for (auto i : m_VotesNo) if (i == id) return true;
	return false;
}

void VoteSystem::PrintVotationStatus()
{
	std::cout << "yes " << m_VotesYes.size() << ", no " << m_VotesNo.size() << std::endl;
}

void VoteSystem::EndVote()
{
	m_TimeLeft = 0;
	//std::cout << "[VoteSystem] vote ended" << std::endl;

	int votesYes = (int)m_VotesYes.size();
	int votesNo = (int)m_VotesNo.size();
	bool pass = GetVotePass(votesYes, votesNo);

	//std::cout << "[VoteSystem] " << (percent * 100) << "%" << std::endl;

	if (pass) m_FnOnPass();
	else m_FnOnFail();
}

bool VoteSystem::GetVotePass(int yes, int no)
{
	float passPercentage = 0.5f;

	int totalVotes = yes + no;
	float percent = (float)yes / (float)totalVotes;
	bool pass = percent > passPercentage;

	return pass;
}

void VoteSystem::SendVoteMessage(std::string message1, std::string message2)
{
	Chat::SendServerMessage("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- --");
	Chat::SendServerMessage("Voting: ( " + m_Title + " )");
	Chat::SendServerMessage(message1);
	if(message2.length() > 0) Chat::SendServerMessage(message2);
	Chat::SendServerMessage("---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- --");
}

void VoteSystem::SendEndVoteMessage()
{
	int votesYes = (int)m_VotesYes.size();
	int votesNo = (int)m_VotesNo.size();
	bool pass = GetVotePass(votesYes, votesNo);

	SendVoteMessage(
		"Vote " + std::string(pass ? "SUCCESS" : "FAIL"),
		"YES: " + std::to_string(votesYes) + "  |  NO: " + std::to_string(votesNo)
	);
}
