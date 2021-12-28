#pragma once

#include "pch.h"
#include "Player.h"
#include "Message.h"
#include "CrateBot.h"

class Server {
public:
	static std::map<long long, Player*> m_Players;
	static std::vector<Message*> m_Messages;
	static int m_UniqueObjectId;
	static bool m_IsAtLobby;
	static bool m_NextRoundGunsEnabled;
	static bool m_GunsEnabled;
	static bool m_RespawnEnabled;
	static bool m_HideMyMessages;
	static bool m_SkipCurrentMessage;
	static float m_BroadCastHelpTime;
	static float m_SendWeaponCommandTime;
	static std::chrono::system_clock::time_point m_LastUpdatedTime;


	static bool Inject();
	static void Init();
	static void Update(float dt);
	static void SendAllMessagesInQuery();
	static void ProcessRawMessage(long long fromClient, std::string message);
	static bool ProcessMessage(Message* message);
	static void GiveWeapon(long long toClient, int weaponId);
	static void RespawnPlayer(long long clientId, Vector3 spawnPos);
	static void BanPlayer(long long toClient);
	static void KillPlayer(long long toClient);
	static Message* SendServerMessage(std::string message);
	static void SendLocalMessage(std::string tag, std::string message);
	static void ChangePlayerIsAliveState(Player* player, bool isAlive);
	
	static void SetAllReady();
	static std::map<long long, ____________452_o*> GetActivePlayers();
	static ____________430_c* GetGameManager();
	static bool IsPlayerAlive(long long clientId);
	static void SetCurrentGameModeTime(float time);

	static bool HasPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static Player* GetPlayer(long long clientId);
	static std::vector<Player*> FindPlayers(std::string selector, bool isAlive = false);

};

