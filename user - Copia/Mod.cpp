#include "pch-il2cpp.h"
#include "Mod.h"

#include "Injector.h"
#include "Config.h"
#include "Server.h"
#include "Event.h"
#include "templates/templates.h"

bool Mod::m_ConsoleMode = false;
bool Mod::m_DebugMode = true;
std::string Mod::m_Version = "3.0" + std::string(m_DebugMode ? "-dev" : "");

int eventTestInt = 0;

void Mod::Init()
{
	std::cout << "[Mod] Init v" << m_Version << std::endl;

	return;

	bool loadAllTemplates = false;

	if (m_ConsoleMode)
	{
		std::cout << "[Mod] Console mode" << std::endl;
	}
	else
	{
		Injector::Init();

		Inject_Templates();

		if (loadAllTemplates)
		{
			
		}
		else {

		}
	}

	Server::Init();

	/*
	start testing - in dll - the events
	option to remove eventfn

	future:
	permission group like  minecraft one, yml
	*/

	/*

	Events::Listen("ChatBox_AppendMessage", "test 1 bef", []() {
		std::cout << "[Mod] antes de dar append!" << std::endl;
		return true;
	}, true);


	Events::Listen("ChatBox_AppendMessage", "test 2 af", []() {
		if (eventTestInt > 5) return false;
		return true;

	
	float loopTime = 1000.0f;
	while (true)
	{
		Sleep(loopTime);

		std::cout << "[Mod] * Loop " << loopTime << std::endl;

		Server::Update(loopTime/100);

		std::cout << eventTestInt << std::endl;

		if (Events::RunBefore("ChatBox_AppendMessage") == false)
		{
			std::cout << "before cancel" << std::endl;
		}
		else {
			std::cout << "before pass" << std::endl;

			Events::RunAfter("ChatBox_AppendMessage");
		}
		
		eventTestInt++;
	}
	*/
}

void Mod::AppendLocalChatMessage(long long fromClient, std::string username, std::string content)
{
	auto chatBox = (*ChatBox__TypeInfo)->static_fields->Instance;
	ChatBox_AppendMessage(chatBox, fromClient, (String*)il2cpp_string_new(content.c_str()), (String*)il2cpp_string_new(username.c_str()), NULL);
}

void Mod::SendChatMessage(long long fromClient, std::string content)
{
	//HF_ServerSend_SendChatMessage->original((uint64_t)fromClient, (String*)il2cpp_string_new(content.c_str()), NULL);
}

void Mod::SendDropItem(long long toClient, int itemId, int objectId, int ammo)
{
	std::cout << "[Mod] SendDropItem toClient=" << toClient << ", itemId='" << itemId << "', objectId='" << objectId << "', ammo='" << ammo << "'" << std::endl;

	ServerSend_DropItem(toClient, itemId, objectId, ammo, NULL);
}

void Mod::ForceGiveItem(long long toClient, int itemId, int objectId)
{
	std::cout << "[Mod] ForceGiveItem toClient=" << toClient << ", itemId='" << itemId << "', objectId='" << objectId << "'" << std::endl;

	ServerSend_ForceGiveItem(toClient, itemId, objectId, NULL);
}

void Mod::SetCurrentGameModeTime(float time)
{
	auto gameMode = (*GameManager__TypeInfo)->static_fields->Instance->fields.gameMode;
	GameMode_SetGameModeTimer(gameMode, time, 0, NULL);
}

void Mod::RespawnSpectator(Player* player)
{
	ServerSend_LoadMap(Server::m_MapId, Server::m_MapModeId, player->m_ClientId, NULL);
	ServerSend_LoadingSendIntoGame(player->m_ClientId, NULL);

	GameServer_PlayerSpawnRequest(
		player->m_ClientId,
		false,
		player->m_Client->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, //byteArray
		player->m_Client->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0, //numberId
		NULL
	);
}