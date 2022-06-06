#pragma once

#include "pch.h"
#include "Injector.h"

class Mod {
public:
	static bool m_DebugMode;
	static std::string m_Version;

	static void Init();

	static void AppendLocalChatMessage(long long fromClient, std::string username, std::string content);
	static void SendChatMessage(long long fromClient, std::string content);
};