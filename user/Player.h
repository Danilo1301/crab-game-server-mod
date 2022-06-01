#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class Player {
public:
	long long m_ClientId;
	int m_Id = -1;
	std::string m_Username = "";
	bool m_IsOnline = false;

	std::string m_PermissionGroup = "default";

	Vector3 m_Position = Vector3({ 0, 0, 0 });


	bool m_Godmode = false;
	bool m_IsAlive = false;
	bool m_JustSpawned = false;
	bool m_DiedInThisRound = false;
	bool m_HideMessages = false;
	float m_MuteTime = 0.0f;

	bool m_AutoRespawnEnabled = false;
	float m_RespawnTime = 0;
	Vector3 m_RespawnPosition = Vector3({ 0, 0, 0 });

	long long m_HoveringPlayer = -1;
	float m_HoveringAngle = -1;
	float m_HoveringRadius = 0;

	bool m_JumpPunchEnabled = false;
	bool m_SuperPunchEnabled = false;
	bool m_ForceFieldEnabled = false;
	bool m_MultiSnowballEnabled = false;

	//bool m_ParticleEnabled = true;
	//float m_ParticleTime = 0;

	Player(long long clientId);

	bool IsLobbyOwner();
	std::string GetDisplayNameExtra();
	std::string GetDisplayName();
	std::string GetChatSuffix();
	PermissionGroup* GetPermissionGroup();
	void SetAlive(bool alive);
};