#pragma once

#include "pch.h"

class AutoMessages {
public:
	static std::vector<std::string> Messages;

	static bool Enabled;
	static float SendInterval;
	static float SendTimeElapsed;

	static void Update(float dt);
	static void AddMessage(std::string text);
	static void ClearMessages();
	static void BroadcastNextMessage();

	static void SaveConfig();
	static void LoadConfig();
	static void ReloadConfig();

private:
	static void CreateFirstConfig();
};