#include "pch.h"
#include "VoteSystem.h"

float VoteSystem::m_TimeLeft = 0;
void (*VoteSystem::m_cbOnSuccess)() = NULL;
void (*VoteSystem::m_cbOnFail)() = NULL;
std::map<long long, bool> VoteSystem::m_Votes;
std::string VoteSystem::m_FinalMessage;