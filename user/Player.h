#pragma once

#include "pch.h"

#include "PermissionGroup.h"

class Player {
public:
	long long ClientId;
	int Id = -1;
	std::string Username;
	bool IsOnline = false;
	bool IsAlive = false;
	bool SpawnedThisRound = false;
	bool SpawnCallbackRequest = false;
	bool DiedThisRound = false;

	bool FirstEverSpawn = false;

	bool Godmode = false;

	bool JumpPunchEnabled = false;

	bool SuperPunchEnabled = false;

	bool ForceFieldEnabled = false;

	bool MultiSnowballEnabled = false;

	bool HideMessages = false;

	float MuteTime = 0.0f;

	float RespawnTime = 0.0f;

	Vector3 LookDir = Vector3(0, 0, 1);
	Vector3 Position = Vector3(0, 0, 0);

	bool FlyEnabled = false;
	float FlyVelocity = 0;
	float FlySpeed = 15.0f;

	Player* HoveringPlayer = NULL;
	float HoveringRadius = 0;
	float HoveringAngle = -1;

	std::string PermissionGroupId = "default";

	PlayerManager* PlayerManager;
	Client* Client;

	Player(long long clientId);

	std::string GetChatSuffix();
	std::string GetDisplayName();
	std::string GetDisplayNameExtra();

private:
	bool TryUpdateID();
	bool TryUpdateClient();
	bool TryUpdatePlayerManager();
public:
	void UpdateInfo();

	PermissionGroup* GetPermissionGroup();

	bool IsLobbyOwner();
};