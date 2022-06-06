#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class Player {
public:
	long long m_ClientId;
	bool m_IsOnline = false;
	int m_Id = -1;
	std::string m_Username;

	PlayerManager* m_PlayerManager = NULL;
	Client* m_Client = NULL;

	Player(long long clientId);

	bool GetIsAlive();

	std::string GetChatSuffix();
	std::string GetDisplayName();
	std::string GetDisplayNameExtra();
	void UpdateInfo();
};