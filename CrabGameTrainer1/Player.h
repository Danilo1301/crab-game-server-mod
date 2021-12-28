#pragma once

#include "pch.h"

class Player {
public:
	int m_PlayerId;
	int m_NumberId;
	long long m_ClientId;
	void* m_PlayerManager;
	std::string m_Username = "";
	bool m_IsAlive = false;
	bool m_HideMyMessages = false;
	std::vector<std::string> m_Permissions;

	Player(int playerId, int numberId, long long clientId, void* playerManager);

	bool GetIsAlive();
	std::string GetDisplayName();
	std::string GetSelector();
	void AddPermission(std::string permission);
};