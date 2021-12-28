#pragma once


class VoteSystem {
public:
	static float m_TimeLeft;
	static void (*m_cbOnSuccess)();
	static void (*m_cbOnFail)();
	static std::map<long long, bool> m_Votes;
	static std::string m_FinalMessage;

	static void StartVoting(std::string message, void (*onSuccess)(), void (*onFail)()) {
		m_cbOnSuccess = onSuccess;
		m_cbOnFail = onFail;

		m_TimeLeft = 30000.0f;
	}

	static bool IsVotingOnGoing() {
		return m_TimeLeft != 0;
	}

	static bool RegisterVote(long long id, bool vote) {

		if(m_Votes.find(id) != m_Votes.end()) return false;

		m_Votes.insert(std::pair<long long, bool>(id, vote));

		return true;
	}

	static void Update(float dt) {

		//std::cout << m_TimeLeft << "\n";

		if (m_TimeLeft > 0) {
			m_TimeLeft -= dt;

			if (m_TimeLeft <= 0) {
				m_TimeLeft = 0;
				FinishVoting();
			}
		}
	}

	static void FinishVoting() {
		int totalVotes = (int)m_Votes.size();
		int yesVotes = 0;

		std::map<long long, bool>::iterator it;
		for (it = m_Votes.begin(); it != m_Votes.end(); it++)
		{
			std::cout << it->second << "\n";

			if (it->second) yesVotes++;
		}

		bool sucess = false;
		
		if (totalVotes > 1) {
			float p = (float)yesVotes / (float)totalVotes;

			m_FinalMessage = "Votacao finalizada";
			m_FinalMessage += " (sim: " + std::to_string(yesVotes) + ", nao: " + std::to_string(totalVotes - yesVotes) + ")";

			if (p >= 0.51) {
				sucess = true;
			}
		}
		else {
			m_FinalMessage = "Sem votos suficientes";
		}

		std::cout << m_FinalMessage << "\n";

		if (sucess) {
			m_cbOnSuccess();
		}
		else {
			m_cbOnFail();
		}



		m_cbOnSuccess = NULL;
		m_cbOnFail = NULL;
		m_Votes.clear();
	}
};
