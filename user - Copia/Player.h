#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class Player {
public:
	long long m_ClientId;
	bool m_IsOnline = false;
	int m_Id = -1;
	std::string m_Username;

	bool m_IsAlive = false;
	bool m_SpawnedAsSpectator = false;
	bool m_CanRespawnNextRound = false;

	bool m_HideMessages = false;

	PlayerManager* m_PlayerManager = NULL;
	Client* m_Client = NULL;

	Vector3 m_Position = Vector3(0, 0, 0);
	Vector3 m_LookDir = Vector3(0, 0, 0);

	Player(long long clientId);

	bool GetIsAlive();

	std::string GetChatSuffix();
	std::string GetDisplayName();
	std::string GetDisplayNameExtra();
	void UpdateInfo();
	bool CheckIsAlive();
};