#pragma once

#include "pch.h"

class Player {
public:
	long long m_ClientId;
	int m_PlayerId;
	std::string m_Username = "";

	bool m_IsAlive = true;
	
	float m_UnmuteTime = 0;
	bool m_Muted = false;
	bool m_HideMessages = false;
	bool m_JumpPunchEnabled = false;
	bool m_SuperPunchEnabled = false;
	bool m_ForceFieldEnabled = false;
	bool m_GodEnabled = false;

	Vector3 m_Position = Vector3({ 0, 0, 0 });

	std::vector<std::string> m_Permissions;

	Player(long long clientId, int playerId);

	bool HasPermission(std::string permission);
	void AddPermission(std::string permission);
	void RemovePermission(std::string permission);

	bool IsLobbyOwner();

	std::string GetDisplayName();
	std::string GetSelector();
};