#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class Player {
public:
	long long m_ClientId;
	int m_Id;
	std::string m_Username = "";

	std::string m_PermissionGroup = "player";

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

	Player(long long clientId, int id);

	bool IsLobbyOwner();
	std::string GetDisplayNameExtra();
	std::string GetDisplayName();
	PermissionGroup* GetPermissionGroup();
	void SetAlive(bool alive);
};