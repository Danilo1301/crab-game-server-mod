#include "pch-il2cpp.h"
#include "Mod.h"

#include "Injector.h"
#include "Config.h"
#include "Server.h"

#include "templates/templates.h"

bool Mod::m_ConsoleMode = false;
bool Mod::m_DebugMode = true;
std::string Mod::m_Version = "3.0" + std::string(m_DebugMode ? "-dev" : "");

void Mod::Init()
{
	std::cout << "[Mod] Init v" << m_Version << std::endl;

	if (!m_ConsoleMode) {

		Injector::Init();

		bool loadAllTemplates = false;

		//Injector::Inject(HF_ChatBox_Update, ChatBox_Update, &Template_ChatBox_Update);
		//Injector::Inject(HF_ChatBox_AppendMessage, ChatBox_AppendMessage, &Template_ChatBox_AppendMessage);

		if (!loadAllTemplates)
		{
			
		}
		else {

		}
	}

	Server::Init();
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