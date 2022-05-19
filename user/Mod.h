#pragma once

#include "pch.h"
#include "Injector.h"

class Mod {
public:
	static std::string m_Version;
	static void Init();

	static void SendChatMessage(long long fromClient, std::string message);
	static void AppendLocalChatMessage(long long fromClient, std::string username, std::string message);
	static void SendDropItem(long long toClient, int objectId, int itemId, int ammo);
	static void ForceGiveItem(long long toClient, int objectId, int itemId);
	static void SendLocalInteract(int itemid);
	static void SendInteract(long long clientId, int itemid);
	static void KillPlayer(long long clientId);
	static void BanPlayer(long long clientId);
	static void KickPlayer(long long clientId);
	static void RespawnPlayer(long long clientId, Vector3 position);
	static void RestartGame();
	static void SetCurrentGameModeTime(float time);
	static void SetBomber(long long clientId);
	static void TagPlayer(long long clientId);
	static void ToggleLights(bool on);
	static void GiveHat(long long clientId);
	static void SendWinner(long long clientId, long long money);

	static u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A__Class* GetGameManager();
	static u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__Class* GetSteamManager();
	static u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1__Class* GetChatBox();

	static std::string FormatStringVector(std::vector<std::string> vector) {

		std::string result = "";

		for (size_t i = 0; i < vector.size(); i++)
		{
			auto s = vector[i];
			result += s + ";";
		}

		return result;
	}

	static std::string FormatVector(Vector3 vector) {
		char str[256];
		sprintf_s(str, "%.3f, %.3f, %.3f", vector.x, vector.y, vector.z);
		return std::string(str);
	}

	/*
		static std::string FormatVector(Vector3 vector) {
		return std::to_string(vector.x) + ", " + std::to_string(vector.y) + ", " + std::to_string(vector.z);
	*/

	static monoString* CreateMonoString(const char* str) {
		monoString* (*String_CreateString)(void* _this, const char* str) = (monoString * (*)(void*, const char*))(Injector::m_AssemblyBase + 8780720);
		return String_CreateString(NULL, str);
	}
};