#pragma once

#include "Mod.h"
#include "Server.h"
#include "Chat.h"

auto HF_ServerSend_u10A1u1099u10A8u10A6u10A2u10A0u1099u10A4u10A4u10A6u10A1 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u10A1u1099u10A8u10A6u10A2u10A0u1099u10A4u10A4u10A6u10A1");
void Template_ServerSend_u10A1u1099u10A8u10A6u10A2u10A0u1099u10A4u10A4u10A6u10A1(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A1u1099u10A8u10A6u10A2u10A0u1099u10A4u10A4u10A6u10A1" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A1u1099u10A8u10A6u10A2u10A0u1099u10A4u10A4u10A6u10A1->original(a, method);
}

auto HF_ServerSend_GameOver = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::GameOver");
void Template_ServerSend_GameOver(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::GameOver" << " a=" << a << ", " << std::endl;

	HF_ServerSend_GameOver->original(a, method);
}

auto HF_ServerSend_PingPong = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::PingPong");
void Template_ServerSend_PingPong(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::PingPong" << " a=" << a << ", " << std::endl;

	HF_ServerSend_PingPong->original(a, method);
}

auto HF_ServerSend_DropMoney = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("ServerSend::DropMoney");
void Template_ServerSend_DropMoney(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::DropMoney" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_DropMoney->original(a, b, c, method);
}

auto HF_ServerSend_u1099u10A3u10A3u10A3u109Du10A6u10A7u109Du10A4u109Au10A4 = new HookFunction<void, List_1_System_ValueTuple_2_*, MethodInfo*>("ServerSend::u1099u10A3u10A3u10A3u109Du10A6u10A7u109Du10A4u109Au10A4");
void Template_ServerSend_u1099u10A3u10A3u10A3u109Du10A6u10A7u109Du10A4u109Au10A4(List_1_System_ValueTuple_2_* a, MethodInfo* method)
{
	std::cout << "ServerSend::u1099u10A3u10A3u10A3u109Du10A6u10A7u109Du10A4u109Au10A4" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u1099u10A3u10A3u10A3u109Du10A6u10A7u109Du10A4u109Au10A4->original(a, method);
}

auto HF_ServerSend_SetBomber = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::SetBomber");
void Template_ServerSend_SetBomber(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SetBomber" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SetBomber->original(a, b, method);
}

auto HF_ServerSend_u10A8u10A8u1099u10A3u109Du109Bu10A7u10A4u109Au109Bu10A2 = new HookFunction<void, int32_t, int32_t, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A8u10A8u1099u10A3u109Du109Bu10A7u10A4u109Au109Bu10A2");
void Template_ServerSend_u10A8u10A8u1099u10A3u109Du109Bu10A7u10A4u109Au109Bu10A2(int32_t a, int32_t b, uint64_t c, uint64_t d, MethodInfo* method)
{
	std::cout << "ServerSend::u10A8u10A8u1099u10A3u109Du109Bu10A7u10A4u109Au109Bu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_u10A8u10A8u1099u10A3u109Du109Bu10A7u10A4u109Au109Bu10A2->original(a, b, c, d, method);
}

auto HF_ServerSend_u10A2u10A0u109Bu109Au10A5u1099u109Du10A5u109Du109Au10A7 = new HookFunction<void, uint64_t, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A2u10A0u109Bu109Au10A5u1099u109Du10A5u109Du109Au10A7");
void Template_ServerSend_u10A2u10A0u109Bu109Au10A5u1099u109Du10A5u109Du109Au10A7(uint64_t a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A2u10A0u109Bu109Au10A5u1099u109Du10A5u109Du109Au10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A2u10A0u109Bu109Au10A5u1099u109Du10A5u109Du109Au10A7->original(a, b, c, method);
}

auto HF_ServerSend_PunchPlayer = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::PunchPlayer");
void Template_ServerSend_PunchPlayer(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::PunchPlayer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_PunchPlayer->original(a, b, c, method);
}

auto HF_ServerSend_u10A0u109Au109Au109Au10A6u109Du10A5u109Fu109Au1099u109A = new HookFunction<void, int32_t, float, int32_t, uint64_t, MethodInfo*>("ServerSend::u10A0u109Au109Au109Au10A6u109Du10A5u109Fu109Au1099u109A");
void Template_ServerSend_u10A0u109Au109Au109Au10A6u109Du10A5u109Fu109Au1099u109A(int32_t a, float b, int32_t c, uint64_t d, MethodInfo* method)
{
	std::cout << "ServerSend::u10A0u109Au109Au109Au10A6u109Du10A5u109Fu109Au1099u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_u10A0u109Au109Au109Au10A6u109Du10A5u109Fu109Au1099u109A->original(a, b, c, d, method);
}

auto HF_ServerSend_PlayerActiveItem = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::PlayerActiveItem");
void Template_ServerSend_PlayerActiveItem(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerActiveItem" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_PlayerActiveItem->original(a, b, method);
}

auto HF_ServerSend_SpectatorSpawn = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::SpectatorSpawn");
void Template_ServerSend_SpectatorSpawn(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::SpectatorSpawn" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SpectatorSpawn->original(a, method);
}

auto HF_ServerSend_RedLight = new HookFunction<void, uint64_t, bool, float, MethodInfo*>("ServerSend::RedLight");
void Template_ServerSend_RedLight(uint64_t a, bool b, float c, MethodInfo* method)
{
	std::cout << "ServerSend::RedLight" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_RedLight->original(a, b, c, method);
}

auto HF_ServerSend_CrabDifficulty = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::CrabDifficulty");
void Template_ServerSend_CrabDifficulty(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::CrabDifficulty" << " a=" << a << ", " << std::endl;

	HF_ServerSend_CrabDifficulty->original(a, method);
}

auto HF_ServerSend_LoadingSendAllIntoGame = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::LoadingSendAllIntoGame");
void Template_ServerSend_LoadingSendAllIntoGame(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::LoadingSendAllIntoGame" << " a=" << a << ", " << std::endl;

	HF_ServerSend_LoadingSendAllIntoGame->original(a, method);
}

auto HF_ServerSend_SendGameModeTimer = new HookFunction<void, uint64_t, float, int32_t, MethodInfo*>("ServerSend::SendGameModeTimer");
void Template_ServerSend_SendGameModeTimer(uint64_t a, float b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::SendGameModeTimer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendGameModeTimer->original(a, b, c, method);
}

auto HF_ServerSend_u10A0u109Eu109Du10A0u109Fu1099u109Fu10A3u109Eu10A5u10A3 = new HookFunction<void, List_1_System_UInt64_*, uint64_t, MethodInfo*>("ServerSend::u10A0u109Eu109Du10A0u109Fu1099u109Fu10A3u109Eu10A5u10A3");
void Template_ServerSend_u10A0u109Eu109Du10A0u109Fu1099u109Fu10A3u109Eu10A5u10A3(List_1_System_UInt64_* a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A0u109Eu109Du10A0u109Fu1099u109Fu10A3u109Eu10A5u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A0u109Eu109Du10A0u109Fu1099u109Fu10A3u109Eu10A5u10A3->original(a, b, method);
}

auto HF_ServerSend_StartGame = new HookFunction<void, MethodInfo*>("ServerSend::StartGame");
void Template_ServerSend_StartGame(MethodInfo* method)
{
	std::cout << "ServerSend::StartGame" << std::endl;

	HF_ServerSend_StartGame->original(method);
}

auto HF_ServerSend_ForceGiveItem = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("ServerSend::ForceGiveItem");
void Template_ServerSend_ForceGiveItem(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::ForceGiveItem" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_ForceGiveItem->original(a, b, c, method);
}

auto HF_ServerSend_SendButtonState = new HookFunction<void, u109Cu10A4u109Eu1099u10A7u109Fu109Fu109Du10A4u109Fu10A3_u109Bu10A7u109Fu10A8u10A3u10A4u109Du10A3u10A1u10A3u109A__Enum, MethodInfo*>("ServerSend::SendButtonState");
void Template_ServerSend_SendButtonState(u109Cu10A4u109Eu1099u10A7u109Fu109Fu109Du10A4u109Fu10A3_u109Bu10A7u109Fu10A8u10A3u10A4u109Du10A3u10A1u10A3u109A__Enum a, MethodInfo* method)
{
	std::cout << "ServerSend::SendButtonState" << " a=" << (int)a << ", " << std::endl;

	HF_ServerSend_SendButtonState->original(a, method);
}

auto HF_ServerSend_SyncObject = new HookFunction<void, uint64_t, int32_t, bool, MethodInfo*>("ServerSend::SyncObject");
void Template_ServerSend_SyncObject(uint64_t a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "ServerSend::SyncObject" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SyncObject->original(a, b, c, method);
}

auto HF_ServerSend_PlayerRotation = new HookFunction<void, uint64_t, float, float, MethodInfo*>("ServerSend::PlayerRotation");
void Template_ServerSend_PlayerRotation(uint64_t a, float b, float c, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerRotation" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_PlayerRotation->original(a, b, c, method);
}

auto HF_ServerSend__cctor = new HookFunction<void, MethodInfo*>("ServerSend::_cctor");
void Template_ServerSend__cctor(MethodInfo* method)
{
	std::cout << "ServerSend::_cctor" << std::endl;

	HF_ServerSend__cctor->original(method);
}

auto HF_ServerSend_UseItemAll = new HookFunction<void, uint64_t, int32_t, Vector3, int32_t, MethodInfo*>("ServerSend::UseItemAll");
void Template_ServerSend_UseItemAll(uint64_t a, int32_t b, Vector3 c, int32_t d, MethodInfo* method)
{
	std::cout << "ServerSend::UseItemAll" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_UseItemAll->original(a, b, c, d, method);
}

auto HF_ServerSend_u109Cu109Au1099u10A7u109Du10A7u10A1u10A1u10A5u109Du109D = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u109Cu109Au1099u10A7u109Du10A7u10A1u10A1u10A5u109Du109D");
void Template_ServerSend_u109Cu109Au1099u10A7u109Du10A7u10A1u10A1u10A5u109Du109D(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Cu109Au1099u10A7u109Du10A7u10A1u10A1u10A5u109Du109D" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Cu109Au1099u10A7u109Du10A7u10A1u10A1u10A5u109Du109D->original(a, method);
}

auto HF_ServerSend_SendSpectatingWho = new HookFunction<void, uint64_t, uint64_t, uint64_t, MethodInfo*>("ServerSend::SendSpectatingWho");
void Template_ServerSend_SendSpectatingWho(uint64_t a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "ServerSend::SendSpectatingWho" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendSpectatingWho->original(a, b, c, method);
}

auto HF_ServerSend_PlayerReload = new HookFunction<void, uint64_t, float, MethodInfo*>("ServerSend::PlayerReload");
void Template_ServerSend_PlayerReload(uint64_t a, float b, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerReload" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_PlayerReload->original(a, b, method);
}

auto HF_ServerSend_u109Du10A2u109Eu109Cu1099u109Du10A7u10A2u10A6u10A1u10A8 = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u109Du10A2u109Eu109Cu1099u109Du10A7u10A2u10A6u10A1u10A8");
void Template_ServerSend_u109Du10A2u109Eu109Cu1099u109Du10A7u10A2u10A6u10A1u10A8(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Du10A2u109Eu109Cu1099u109Du10A7u10A2u10A6u10A1u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Du10A2u109Eu109Cu1099u109Du10A7u10A2u10A6u10A1u10A8->original(a, b, method);
}

auto HF_ServerSend_GameStartedCooldown = new HookFunction<void, uint64_t, float, MethodInfo*>("ServerSend::GameStartedCooldown");
void Template_ServerSend_GameStartedCooldown(uint64_t a, float b, MethodInfo* method)
{
	std::cout << "ServerSend::GameStartedCooldown" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_GameStartedCooldown->original(a, b, method);
}

auto HF_ServerSend_u10A3u109Bu10A3u109Du10A3u10A1u109Du109Du109Bu10A5u10A0 = new HookFunction<void, uint64_t, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("ServerSend::u10A3u109Bu10A3u109Du10A3u10A1u109Du109Du109Bu10A5u10A0");
void Template_ServerSend_u10A3u109Bu10A3u109Du10A3u10A1u109Du109Du109Bu10A5u10A0(uint64_t a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u109Bu10A3u109Du10A3u10A1u109Du109Du109Bu10A5u10A0" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_ServerSend_u10A3u109Bu10A3u109Du10A3u10A1u109Du109Du109Bu10A5u10A0->original(a, b, c, d, e, f, g, method);
}

auto HF_ServerSend_u10A4u109Eu109Fu109Au10A8u10A8u109Bu10A6u109Eu109Du10A5 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u10A4u109Eu109Fu109Au10A8u10A8u109Bu10A6u109Eu109Du10A5");
void Template_ServerSend_u10A4u109Eu109Fu109Au10A8u10A8u109Bu10A6u109Eu109Du10A5(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A4u109Eu109Fu109Au10A8u10A8u109Bu10A6u109Eu109Du10A5" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A4u109Eu109Fu109Au10A8u10A8u109Bu10A6u109Eu109Du10A5->original(a, method);
}

auto HF_ServerSend_StandoffToggle = new HookFunction<void, bool, MethodInfo*>("ServerSend::StandoffToggle");
void Template_ServerSend_StandoffToggle(bool a, MethodInfo* method)
{
	std::cout << "ServerSend::StandoffToggle" << " a=" << a << ", " << std::endl;

	HF_ServerSend_StandoffToggle->original(a, method);
}

auto HF_ServerSend_PieceFall = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::PieceFall");
void Template_ServerSend_PieceFall(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::PieceFall" << " a=" << a << ", " << std::endl;

	HF_ServerSend_PieceFall->original(a, method);
}

auto HF_ServerSend_UseItem = new HookFunction<void, uint64_t, int32_t, Vector3, MethodInfo*>("ServerSend::UseItem");
void Template_ServerSend_UseItem(uint64_t a, int32_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::UseItem" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_UseItem->original(a, b, c, method);
}

auto HF_ServerSend_SendReadyPlayers = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::SendReadyPlayers");
void Template_ServerSend_SendReadyPlayers(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::SendReadyPlayers" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendReadyPlayers->original(a, method);
}

auto HF_ServerSend_PlayerDamage = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, MethodInfo*>("ServerSend::PlayerDamage");
void Template_ServerSend_PlayerDamage(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerDamage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	HF_ServerSend_PlayerDamage->original(a, b, c, d, e, method);
}

auto HF_ServerSend_u10A3u109Du1099u10A6u10A6u10A7u109Du109Au1099u10A0u109C = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::u10A3u109Du1099u10A6u10A6u10A7u109Du109Au1099u10A0u109C");
void Template_ServerSend_u10A3u109Du1099u10A6u10A6u10A7u109Du109Au1099u10A0u109C(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u109Du1099u10A6u10A6u10A7u109Du109Au1099u10A0u109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A3u109Du1099u10A6u10A6u10A7u109Du109Au1099u10A0u109C->original(a, b, method);
}

auto HF_ServerSend_u10A1u10A4u10A2u10A0u109Au10A5u10A0u109Fu10A2u1099u10A0 = new HookFunction<void, uint64_t, int32_t, Vector3, MethodInfo*>("ServerSend::u10A1u10A4u10A2u10A0u109Au10A5u10A0u109Fu10A2u1099u10A0");
void Template_ServerSend_u10A1u10A4u10A2u10A0u109Au10A5u10A0u109Fu10A2u1099u10A0(uint64_t a, int32_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A1u10A4u10A2u10A0u109Au10A5u10A0u109Fu10A2u1099u10A0" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A1u10A4u10A2u10A0u109Au10A5u10A0u109Fu10A2u1099u10A0->original(a, b, c, method);
}

auto HF_ServerSend_LoadMap = new HookFunction<void, int32_t, int32_t, uint64_t, MethodInfo*>("ServerSend::LoadMap");
void Template_ServerSend_LoadMap(int32_t a, int32_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "ServerSend::LoadMap" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_LoadMap->original(a, b, c, method);
}

auto HF_ServerSend_PlayerReceivedDrop = new HookFunction<void, uint64_t, int32_t, Dictionary_2_System_String_System_String_*, MethodInfo*>("ServerSend::PlayerReceivedDrop");
void Template_ServerSend_PlayerReceivedDrop(uint64_t a, int32_t b, Dictionary_2_System_String_System_String_* c, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerReceivedDrop" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_PlayerReceivedDrop->original(a, b, c, method);
}

auto HF_ServerSend_u109Eu109Cu10A2u10A0u109Eu10A8u10A5u109Eu10A6u10A3u109C = new HookFunction<void, float, int32_t, MethodInfo*>("ServerSend::u109Eu109Cu10A2u10A0u109Eu10A8u10A5u109Eu10A6u10A3u109C");
void Template_ServerSend_u109Eu109Cu10A2u10A0u109Eu10A8u10A5u109Eu10A6u10A3u109C(float a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Eu109Cu10A2u10A0u109Eu10A8u10A5u109Eu10A6u10A3u109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Eu109Cu10A2u10A0u109Eu10A8u10A5u109Eu10A6u10A3u109C->original(a, b, method);
}

auto HF_ServerSend_LobbyMapUpdate = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::LobbyMapUpdate");
void Template_ServerSend_LobbyMapUpdate(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::LobbyMapUpdate" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_LobbyMapUpdate->original(a, b, method);
}

auto HF_ServerSend_u10A4u1099u10A6u10A3u10A3u109Au109Eu109Cu109Fu10A8u1099 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::u10A4u1099u10A6u10A3u10A3u109Au109Eu109Cu109Fu10A8u1099");
void Template_ServerSend_u10A4u1099u10A6u10A3u10A3u109Au109Eu109Cu109Fu10A8u1099(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A4u1099u10A6u10A3u10A3u109Au109Eu109Cu109Fu10A8u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A4u1099u10A6u10A3u10A3u109Au109Eu109Cu109Fu10A8u1099->original(a, b, c, method);
}

auto HF_ServerSend_StartLobby = new HookFunction<void, List_1_System_UInt64_*, uint64_t, MethodInfo*>("ServerSend::StartLobby");
void Template_ServerSend_StartLobby(List_1_System_UInt64_* a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::StartLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_StartLobby->original(a, b, method);
}

auto HF_ServerSend_CrabHp = new HookFunction<void, float, MethodInfo*>("ServerSend::CrabHp");
void Template_ServerSend_CrabHp(float a, MethodInfo* method)
{
	std::cout << "ServerSend::CrabHp" << " a=" << a << ", " << std::endl;

	HF_ServerSend_CrabHp->original(a, method);
}

auto HF_ServerSend_SendTileUpdates = new HookFunction<void, List_1_System_ValueTuple_2_*, MethodInfo*>("ServerSend::SendTileUpdates");
void Template_ServerSend_SendTileUpdates(List_1_System_ValueTuple_2_* a, MethodInfo* method)
{
	std::cout << "ServerSend::SendTileUpdates" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendTileUpdates->original(a, method);
}

auto HF_ServerSend_u109Fu10A4u1099u10A0u109Au10A7u10A5u109Bu10A8u10A5u109C = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u109Fu10A4u1099u10A0u109Au10A7u10A5u109Bu10A8u10A5u109C");
void Template_ServerSend_u109Fu10A4u1099u10A0u109Au10A7u10A5u109Bu10A8u10A5u109C(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu10A4u1099u10A0u109Au10A7u10A5u109Bu10A8u10A5u109C" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Fu10A4u1099u10A0u109Au10A7u10A5u109Bu10A8u10A5u109C->original(a, method);
}

auto HF_ServerSend_u10A3u10A1u109Au109Fu10A1u1099u10A3u109Bu10A5u10A7u10A3 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::u10A3u10A1u109Au109Fu10A1u1099u10A3u109Bu10A5u10A7u10A3");
void Template_ServerSend_u10A3u10A1u109Au109Fu10A1u1099u10A3u109Bu10A5u10A7u10A3(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A1u109Au109Fu10A1u1099u10A3u109Bu10A5u10A7u10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A3u10A1u109Au109Fu10A1u1099u10A3u109Bu10A5u10A7u10A3->original(a, b, c, method);
}

auto HF_ServerSend_PhysicsObjectSnapshot = new HookFunction<void, uint64_t, int32_t, Vector3, Vector3, Vector3, Quaternion, MethodInfo*>("ServerSend::PhysicsObjectSnapshot");
void Template_ServerSend_PhysicsObjectSnapshot(uint64_t a, int32_t b, Vector3 c, Vector3 d, Vector3 e, Quaternion f, MethodInfo* method)
{
	std::cout << "ServerSend::PhysicsObjectSnapshot" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_ServerSend_PhysicsObjectSnapshot->original(a, b, c, d, e, f, method);
}

auto HF_ServerSend_u109Fu10A7u10A6u109Au10A1u10A6u1099u10A0u10A0u109Bu10A6 = new HookFunction<void, uint64_t, Vector3, MethodInfo*>("ServerSend::u109Fu10A7u10A6u109Au10A1u10A6u1099u10A0u10A0u109Bu10A6");
void Template_ServerSend_u109Fu10A7u10A6u109Au10A1u10A6u1099u10A0u10A0u109Bu10A6(uint64_t a, Vector3 b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu10A7u10A6u109Au10A1u10A6u1099u10A0u10A0u109Bu10A6" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Fu10A7u10A6u109Au10A1u10A6u1099u10A0u10A0u109Bu10A6->original(a, b, method);
}

auto HF_ServerSend_GameSpawnPlayer = new HookFunction<void, uint64_t, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("ServerSend::GameSpawnPlayer");
void Template_ServerSend_GameSpawnPlayer(uint64_t a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "ServerSend::GameSpawnPlayer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_ServerSend_GameSpawnPlayer->original(a, b, c, d, e, f, g, method);

	auto player = Server::GetPlayer(a);

	if (player->GetIsAlive()) return;

	Server::OnPlayerSpawn(Server::GetPlayer(b), c);
}

auto HF_ServerSend_LoadingState = new HookFunction<void, uint64_t, u10A3u10A5u109Eu10A6u109Au109Bu10A7u10A7u109Du109Bu109C_u10A7u109Cu10A2u10A8u10A6u109Fu109Eu10A6u109Du109Fu10A2__Enum, MethodInfo*>("ServerSend::LoadingState");
void Template_ServerSend_LoadingState(uint64_t a, u10A3u10A5u109Eu10A6u109Au109Bu10A7u10A7u109Du109Bu109C_u10A7u109Cu10A2u10A8u10A6u109Fu109Eu10A6u109Du109Fu10A2__Enum b, MethodInfo* method)
{
	std::cout << "ServerSend::LoadingState" << " a=" << a << ", " << " b=" << (int)b << ", " << std::endl;

	HF_ServerSend_LoadingState->original(a, b, method);
}

auto HF_ServerSend_CrabAnimation = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::CrabAnimation");
void Template_ServerSend_CrabAnimation(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::CrabAnimation" << " a=" << a << ", " << std::endl;

	HF_ServerSend_CrabAnimation->original(a, method);
}

auto HF_ServerSend_u10A5u10A3u10A5u10A7u10A4u10A1u109Au10A7u1099u10A0u10A4 = new HookFunction<void, Vector3, int32_t, MethodInfo*>("ServerSend::u10A5u10A3u10A5u10A7u10A4u10A1u109Au10A7u1099u10A0u10A4");
void Template_ServerSend_u10A5u10A3u10A5u10A7u10A4u10A1u109Au10A7u1099u10A0u10A4(Vector3 a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A5u10A3u10A5u10A7u10A4u10A1u109Au10A7u1099u10A0u10A4" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A5u10A3u10A5u10A7u10A4u10A1u109Au10A7u1099u10A0u10A4->original(a, b, method);
}

auto HF_ServerSend_u1099u109Bu109Cu109Fu10A4u1099u10A0u109Au10A5u10A0u109F = new HookFunction<void, List_1_System_UInt64_*, MethodInfo*>("ServerSend::u1099u109Bu109Cu109Fu10A4u1099u10A0u109Au10A5u10A0u109F");
void Template_ServerSend_u1099u109Bu109Cu109Fu10A4u1099u10A0u109Au10A5u10A0u109F(List_1_System_UInt64_* a, MethodInfo* method)
{
	std::cout << "ServerSend::u1099u109Bu109Cu109Fu10A4u1099u10A0u109Au10A5u10A0u109F" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u1099u109Bu109Cu109Fu10A4u1099u10A0u109Au10A5u10A0u109F->original(a, method);
}

auto HF_ServerSend_ToggleLights = new HookFunction<void, bool, MethodInfo*>("ServerSend::ToggleLights");
void Template_ServerSend_ToggleLights(bool a, MethodInfo* method)
{
	std::cout << "ServerSend::ToggleLights" << " a=" << a << ", " << std::endl;

	HF_ServerSend_ToggleLights->original(a, method);
}

auto HF_ServerSend_u10A3u10A2u109Du10A0u10A8u10A6u109Au10A2u10A1u10A4u1099 = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("ServerSend::u10A3u10A2u109Du10A0u10A8u10A6u109Au10A2u10A1u10A4u1099");
void Template_ServerSend_u10A3u10A2u109Du10A0u10A8u10A6u109Au10A2u10A1u10A4u1099(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A2u109Du10A0u10A8u10A6u109Au10A2u10A1u10A4u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A3u10A2u109Du10A0u10A8u10A6u109Au10A2u10A1u10A4u1099->original(a, b, c, method);
}

auto HF_ServerSend_u109Eu10A8u10A8u109Bu109Eu10A3u10A7u10A1u10A7u109Au109B = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u109Eu10A8u10A8u109Bu109Eu10A3u10A7u10A1u10A7u109Au109B");
void Template_ServerSend_u109Eu10A8u10A8u109Bu109Eu10A3u10A7u10A1u10A7u109Au109B(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Eu10A8u10A8u109Bu109Eu10A3u10A7u10A1u10A7u109Au109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Eu10A8u10A8u109Bu109Eu10A3u10A7u10A1u10A7u109Au109B->original(a, b, method);
}

auto HF_ServerSend_TagPlayer = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::TagPlayer");
void Template_ServerSend_TagPlayer(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::TagPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_TagPlayer->original(a, b, method);
}

auto HF_ServerSend_SendChatMessage = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::SendChatMessage");
void Template_ServerSend_SendChatMessage(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::SendChatMessage" << " a=" << a << ", " << " b=" << b->toCPPString() << ", " << std::endl;

	//HF_ServerSend_SendChatMessage->original(a, b, method);

	auto message = new Message((long long)a, b->toCPPString());

	if (Server::HasPlayer(a)) {
		message->m_Player = Server::GetPlayer(a);
		Chat::ProcessMessage(message);
	}
}

auto HF_ServerSend_RequestCosmetics = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::RequestCosmetics");
void Template_ServerSend_RequestCosmetics(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::RequestCosmetics" << " a=" << a << ", " << std::endl;

	HF_ServerSend_RequestCosmetics->original(a, method);
}

auto HF_ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5 = new HookFunction<void, uint64_t, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("ServerSend::u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5");
void Template_ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5(uint64_t a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "ServerSend::u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5->original(a, b, c, d, e, f, g, method);
}

auto HF_ServerSend_u10A3u10A1u10A1u10A8u109Fu10A6u10A2u1099u109Bu109Du1099 = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A3u10A1u10A1u10A8u109Fu10A6u10A2u1099u109Bu109Du1099");
void Template_ServerSend_u10A3u10A1u10A1u10A8u109Fu10A6u10A2u1099u109Bu109Du1099(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A1u10A1u10A8u109Fu10A6u10A2u1099u109Bu109Du1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A3u10A1u10A1u10A8u109Fu10A6u10A2u1099u109Bu109Du1099->original(a, b, method);
}

auto HF_ServerSend_GiveHat = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::GiveHat");
void Template_ServerSend_GiveHat(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::GiveHat" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_GiveHat->original(a, b, method);
}
/*
auto HF_ServerSend_Ping = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::Ping");
void Template_ServerSend_Ping(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::Ping" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_Ping->original(a, b, method);
}
*/
auto HF_ServerSend_u109Fu10A4u109Du10A4u109Fu10A6u109Bu10A0u109Au10A5u10A1 = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::u109Fu10A4u109Du10A4u109Fu10A6u109Bu10A0u109Au10A5u10A1");
void Template_ServerSend_u109Fu10A4u109Du10A4u109Fu10A6u109Bu10A0u109Au10A5u10A1(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu10A4u109Du10A4u109Fu10A6u109Bu10A0u109Au10A5u10A1" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Fu10A4u109Du10A4u109Fu10A6u109Bu10A0u109Au10A5u10A1->original(a, method);
}

auto HF_ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2 = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2");
void Template_ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2->original(a, b, method);
}

auto HF_ServerSend_LobbySettingsUpdate = new HookFunction<void, u109Fu109Du10A4u10A7u10A2u10A1u109Bu109Bu109Cu109Fu10A3*, uint64_t, MethodInfo*>("ServerSend::LobbySettingsUpdate");
void Template_ServerSend_LobbySettingsUpdate(u109Fu109Du10A4u10A7u10A2u10A1u109Bu109Bu109Cu109Fu10A3* a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::LobbySettingsUpdate" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_LobbySettingsUpdate->original(a, b, method);
}

auto HF_ServerSend_PlayerPosition = new HookFunction<void, uint64_t, Vector3, MethodInfo*>("ServerSend::PlayerPosition");
void Template_ServerSend_PlayerPosition(uint64_t a, Vector3 b, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerPosition" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_PlayerPosition->original(a, b, method);
}

auto HF_ServerSend_u10A4u109Du10A2u10A6u10A3u10A2u109Eu10A6u109Cu109Cu10A6 = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::u10A4u109Du10A2u10A6u10A3u10A2u109Eu10A6u109Cu109Cu10A6");
void Template_ServerSend_u10A4u109Du10A2u10A6u10A3u10A2u109Eu10A6u109Cu109Cu10A6(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A4u109Du10A2u10A6u10A3u10A2u109Eu10A6u109Cu109Cu10A6" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A4u109Du10A2u10A6u10A3u10A2u109Eu10A6u109Cu109Cu10A6->original(a, method);
}

auto HF_ServerSend_u10A3u109Du10A3u109Eu10A3u10A3u10A5u10A8u10A8u109Au10A6 = new HookFunction<void, List_1_System_ValueTuple_2__1*, MethodInfo*>("ServerSend::u10A3u109Du10A3u109Eu10A3u10A3u10A5u10A8u10A8u109Au10A6");
void Template_ServerSend_u10A3u109Du10A3u109Eu10A3u10A3u10A5u10A8u10A8u109Au10A6(List_1_System_ValueTuple_2__1* a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u109Du10A3u109Eu10A3u10A3u10A5u10A8u10A8u109Au10A6" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A3u109Du10A3u109Eu10A3u10A3u10A5u10A8u10A8u109Au10A6->original(a, method);
}

auto HF_ServerSend_SendSerializedInventory = new HookFunction<void, uint64_t, Byte__Array*, int32_t, MethodInfo*>("ServerSend::SendSerializedInventory");
void Template_ServerSend_SendSerializedInventory(uint64_t a, Byte__Array* b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::SendSerializedInventory" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendSerializedInventory->original(a, b, c, method);
}

auto HF_ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C");
void Template_ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C->original(a, b, method);
}

auto HF_ServerSend_SendCrabBall = new HookFunction<void, Vector3, int32_t, MethodInfo*>("ServerSend::SendCrabBall");
void Template_ServerSend_SendCrabBall(Vector3 a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SendCrabBall" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendCrabBall->original(a, b, method);
}
/*
auto HF_ServerSend__ctor = new HookFunction<void, ServerSend*, MethodInfo*>("ServerSend::_ctor");
void Template_ServerSend__ctor(ServerSend* a, MethodInfo* method)
{
	std::cout << "ServerSend::_ctor" << " a=" << a << ", " << std::endl;

	HF_ServerSend__ctor->original(a, method);
}
*/
auto HF_ServerSend_SendSerializedDrop = new HookFunction<void, uint64_t, Byte__Array*, int32_t, MethodInfo*>("ServerSend::SendSerializedDrop");
void Template_ServerSend_SendSerializedDrop(uint64_t a, Byte__Array* b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::SendSerializedDrop" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendSerializedDrop->original(a, b, c, method);
}

auto HF_ServerSend_RespawnPlayer = new HookFunction<void, uint64_t, Vector3, MethodInfo*>("ServerSend::RespawnPlayer");
void Template_ServerSend_RespawnPlayer(uint64_t a, Vector3 b, MethodInfo* method)
{
	std::cout << "ServerSend::RespawnPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_RespawnPlayer->original(a, b, method);
}

auto HF_ServerSend_SendKingScores = new HookFunction<void, List_1_System_ValueTuple_2__1*, MethodInfo*>("ServerSend::SendKingScores");
void Template_ServerSend_SendKingScores(List_1_System_ValueTuple_2__1* a, MethodInfo* method)
{
	std::cout << "ServerSend::SendKingScores" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendKingScores->original(a, method);
}

auto HF_ServerSend_u10A3u10A5u10A7u10A5u1099u109Eu10A8u109Bu10A1u10A0u109E = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A3u10A5u10A7u10A5u1099u109Eu10A8u109Bu10A1u10A0u109E");
void Template_ServerSend_u10A3u10A5u10A7u10A5u1099u109Eu10A8u109Bu10A1u10A0u109E(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A5u10A7u10A5u1099u109Eu10A8u109Bu10A1u10A0u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A3u10A5u10A7u10A5u1099u109Eu10A8u109Bu10A1u10A0u109E->original(a, b, method);
}
/*
auto HF_ServerSend_SendPlayerPings = new HookFunction<void, List_1_System_ValueTuple_2__1*, MethodInfo*>("ServerSend::SendPlayerPings");
void Template_ServerSend_SendPlayerPings(List_1_System_ValueTuple_2__1* a, MethodInfo* method)
{
	std::cout << "ServerSend::SendPlayerPings" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendPlayerPings->original(a, method);
}
*/
auto HF_ServerSend_ButtonSetNextPlayer = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::ButtonSetNextPlayer");
void Template_ServerSend_ButtonSetNextPlayer(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::ButtonSetNextPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_ButtonSetNextPlayer->original(a, b, method);
}

auto HF_ServerSend_SendPlayerReady = new HookFunction<void, uint64_t, bool, MethodInfo*>("ServerSend::SendPlayerReady");
void Template_ServerSend_SendPlayerReady(uint64_t a, bool b, MethodInfo* method)
{
	std::cout << "ServerSend::SendPlayerReady" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendPlayerReady->original(a, b, method);
}

auto HF_ServerSend_SpawnBoulder = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::SpawnBoulder");
void Template_ServerSend_SpawnBoulder(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::SpawnBoulder" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SpawnBoulder->original(a, method);
}

auto HF_ServerSend_LoadMap_1 = new HookFunction<void, int32_t, int32_t, MethodInfo*>("ServerSend::LoadMap_1");
void Template_ServerSend_LoadMap_1(int32_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::LoadMap_1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_LoadMap_1->original(a, b, method);
}

auto HF_ServerSend_SendFallingBlocks = new HookFunction<void, int32_t, float, int32_t, uint64_t, MethodInfo*>("ServerSend::SendFallingBlocks");
void Template_ServerSend_SendFallingBlocks(int32_t a, float b, int32_t c, uint64_t d, MethodInfo* method)
{
	std::cout << "ServerSend::SendFallingBlocks" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_SendFallingBlocks->original(a, b, c, d, method);
}

auto HF_ServerSend_u109Eu10A1u10A3u109Du10A8u10A1u10A8u10A3u10A8u10A2u10A8 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u109Eu10A1u10A3u109Du10A8u10A1u10A8u10A3u10A8u10A2u10A8");
void Template_ServerSend_u109Eu10A1u10A3u109Du10A8u10A1u10A8u10A3u10A8u10A2u10A8(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Eu10A1u10A3u109Du10A8u10A1u10A8u10A3u10A8u10A2u10A8" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Eu10A1u10A3u109Du10A8u10A1u10A8u10A3u10A8u10A2u10A8->original(a, method);
}

auto HF_ServerSend_u109Fu109Du1099u10A3u109Eu10A0u10A2u109Au10A2u109Du1099 = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::u109Fu109Du1099u10A3u109Eu10A0u10A2u109Au10A2u109Du1099");
void Template_ServerSend_u109Fu109Du1099u10A3u109Eu10A0u10A2u109Au10A2u109Du1099(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu109Du1099u10A3u109Eu10A0u10A2u109Au10A2u109Du1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Fu109Du1099u10A3u109Eu10A0u10A2u109Au10A2u109Du1099->original(a, b, method);
}

auto HF_ServerSend_u1099u10A6u109Au10A5u109Au1099u10A0u10A4u1099u10A0u10A1 = new HookFunction<void, u109Cu10A4u109Eu1099u10A7u109Fu109Fu109Du10A4u109Fu10A3_u109Bu10A7u109Fu10A8u10A3u10A4u109Du10A3u10A1u10A3u109A__Enum, MethodInfo*>("ServerSend::u1099u10A6u109Au10A5u109Au1099u10A0u10A4u1099u10A0u10A1");
void Template_ServerSend_u1099u10A6u109Au10A5u109Au1099u10A0u10A4u1099u10A0u10A1(u109Cu10A4u109Eu1099u10A7u109Fu109Fu109Du10A4u109Fu10A3_u109Bu10A7u109Fu10A8u10A3u10A4u109Du10A3u10A1u10A3u109A__Enum a, MethodInfo* method)
{
	std::cout << "ServerSend::u1099u10A6u109Au10A5u109Au1099u10A0u10A4u1099u10A0u10A1" << " a=" << (int)a << ", " << std::endl;

	HF_ServerSend_u1099u10A6u109Au10A5u109Au1099u10A0u10A4u1099u10A0u10A1->original(a, method);
}

auto HF_ServerSend_SendPieces = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::SendPieces");
void Template_ServerSend_SendPieces(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SendPieces" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendPieces->original(a, b, method);
}

auto HF_ServerSend_u109Eu109Du109Eu109Eu109Fu109Du10A5u10A5u1099u1099u10A3 = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::u109Eu109Du109Eu109Eu109Fu109Du10A5u10A5u1099u1099u10A3");
void Template_ServerSend_u109Eu109Du109Eu109Eu109Fu109Du10A5u10A5u1099u1099u10A3(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Eu109Du109Eu109Eu109Fu109Du10A5u10A5u1099u1099u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Eu109Du109Eu109Eu109Fu109Du10A5u10A5u1099u1099u10A3->original(a, b, method);
}

auto HF_ServerSend_SendStrobe = new HookFunction<void, MethodInfo*>("ServerSend::SendStrobe");
void Template_ServerSend_SendStrobe(MethodInfo* method)
{
	std::cout << "ServerSend::SendStrobe" << std::endl;

	HF_ServerSend_SendStrobe->original(method);
}

auto HF_ServerSend_u10A3u10A8u109Fu109Eu10A1u109Bu109Au1099u10A7u10A7u10A2 = new HookFunction<void, uint64_t, int32_t, Vector3, MethodInfo*>("ServerSend::u10A3u10A8u109Fu109Eu10A1u109Bu109Au1099u10A7u10A7u10A2");
void Template_ServerSend_u10A3u10A8u109Fu109Eu10A1u109Bu109Au1099u10A7u10A7u10A2(uint64_t a, int32_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A8u109Fu109Eu10A1u109Bu109Au1099u10A7u10A7u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A3u10A8u109Fu109Eu10A1u109Bu109Au1099u10A7u10A7u10A2->original(a, b, c, method);
}

auto HF_ServerSend_FreezePlayers = new HookFunction<void, bool, MethodInfo*>("ServerSend::FreezePlayers");
void Template_ServerSend_FreezePlayers(bool a, MethodInfo* method)
{
	std::cout << "ServerSend::FreezePlayers" << " a=" << a << ", " << std::endl;

	HF_ServerSend_FreezePlayers->original(a, method);
}

auto HF_ServerSend_u10A3u10A1u10A3u10A5u109Cu1099u10A2u109Eu10A7u109Bu10A4 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u10A3u10A1u10A3u10A5u109Cu1099u10A2u109Eu10A7u109Bu10A4");
void Template_ServerSend_u10A3u10A1u10A3u10A5u109Cu1099u10A2u109Eu10A7u109Bu10A4(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A1u10A3u10A5u109Cu1099u10A2u109Eu10A7u109Bu10A4" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A3u10A1u10A3u10A5u109Cu1099u10A2u109Eu10A7u109Bu10A4->original(a, method);
}

auto HF_ServerSend_SpectatorSpawn_1 = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::SpectatorSpawn_1");
void Template_ServerSend_SpectatorSpawn_1(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SpectatorSpawn_1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SpectatorSpawn_1->original(a, b, method);
}
/* packet
auto HF_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7 = new HookFunction<void, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7");
void Template_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7(u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7->original(a, method);
}
*/
auto HF_ServerSend_DropItem = new HookFunction<void, uint64_t, int32_t, int32_t, int32_t, MethodInfo*>("ServerSend::DropItem");
void Template_ServerSend_DropItem(uint64_t a, int32_t b, int32_t c, int32_t d, MethodInfo* method)
{
	std::cout << "ServerSend::DropItem" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_DropItem->original(a, b, c, d, method);
}

auto HF_ServerSend_SendModeState = new HookFunction<void, int32_t, MethodInfo*>("ServerSend::SendModeState");
void Template_ServerSend_SendModeState(int32_t a, MethodInfo* method)
{
	std::cout << "ServerSend::SendModeState" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendModeState->original(a, method);
}
/* packet
auto HF_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7_1 = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7_1");
void Template_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7_1(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7_1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A5u10A5u10A5u10A0u10A6u10A3u10A5u109Fu109Du109Au10A7_1->original(a, b, method);
}
*/
auto HF_ServerSend_u10A4u10A0u10A8u10A0u10A3u109Du109Cu109Fu1099u10A2u109E = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("ServerSend::u10A4u10A0u10A8u10A0u10A3u109Du109Cu109Fu1099u10A2u109E");
void Template_ServerSend_u10A4u10A0u10A8u10A0u10A3u109Du109Cu109Fu1099u10A2u109E(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A4u10A0u10A8u10A0u10A3u109Du109Cu109Fu1099u10A2u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A4u10A0u10A8u10A0u10A3u109Du109Cu109Fu1099u10A2u109E->original(a, b, c, method);
}

auto HF_ServerSend_SendBlockCrush = new HookFunction<void, float, int32_t, uint64_t, MethodInfo*>("ServerSend::SendBlockCrush");
void Template_ServerSend_SendBlockCrush(float a, int32_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "ServerSend::SendBlockCrush" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendBlockCrush->original(a, b, c, method);
}

auto HF_ServerSend_CrabTarget = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::CrabTarget");
void Template_ServerSend_CrabTarget(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::CrabTarget" << " a=" << a << ", " << std::endl;

	HF_ServerSend_CrabTarget->original(a, method);
}

auto HF_ServerSend_u10A6u10A1u10A0u109Bu10A7u10A3u109Au109Fu10A3u10A2u10A5 = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("ServerSend::u10A6u10A1u10A0u109Bu10A7u10A3u109Au109Fu10A3u10A2u10A5");
void Template_ServerSend_u10A6u10A1u10A0u109Bu10A7u10A3u109Au109Fu10A3u10A2u10A5(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::u10A6u10A1u10A0u109Bu10A7u10A3u109Au109Fu10A3u10A2u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u10A6u10A1u10A0u109Bu10A7u10A3u109Au109Fu10A3u10A2u10A5->original(a, b, c, method);
}

auto HF_ServerSend_MoneyUpdate = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::MoneyUpdate");
void Template_ServerSend_MoneyUpdate(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::MoneyUpdate" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_MoneyUpdate->original(a, b, method);
}

auto HF_ServerSend_PlayerDied = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::PlayerDied");
void Template_ServerSend_PlayerDied(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_PlayerDied->original(a, b, c, method);
}
/*
* ping
auto HF_ServerSend_u10A0u10A0u10A6u10A3u10A1u10A2u10A2u10A3u10A2u10A5u109E = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u10A0u10A0u10A6u10A3u10A1u10A2u10A2u10A3u10A2u10A5u109E");
void Template_ServerSend_u10A0u10A0u10A6u10A3u10A1u10A2u10A2u10A3u10A2u10A5u109E(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A0u10A0u10A6u10A3u10A1u10A2u10A2u10A3u10A2u10A5u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A0u10A0u10A6u10A3u10A1u10A2u10A2u10A3u10A2u10A5u109E->original(a, b, method);
}
*/
auto HF_ServerSend_SendToLobby = new HookFunction<void, MethodInfo*>("ServerSend::SendToLobby");
void Template_ServerSend_SendToLobby(MethodInfo* method)
{
	std::cout << "ServerSend::SendToLobby" << std::endl;

	HF_ServerSend_SendToLobby->original(method);
}

auto HF_ServerSend_u10A3u10A6u10A3u10A8u109Cu10A0u109Au109Au109Fu10A6u1099 = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::u10A3u10A6u10A3u10A8u109Cu10A0u109Au109Au109Fu10A6u1099");
void Template_ServerSend_u10A3u10A6u10A3u10A8u109Cu10A0u109Au109Au109Fu10A6u1099(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A3u10A6u10A3u10A8u109Cu10A0u109Au109Au109Fu10A6u1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A3u10A6u10A3u10A8u109Cu10A0u109Au109Au109Fu10A6u1099->original(a, b, method);
}

/*
auto HF_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F");
void Template_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F->original(a, b, method);
}
*/
	
auto HF_ServerSend_SendHatScores = new HookFunction<void, List_1_System_ValueTuple_2__1*, MethodInfo*>("ServerSend::SendHatScores");
void Template_ServerSend_SendHatScores(List_1_System_ValueTuple_2__1* a, MethodInfo* method)
{
	std::cout << "ServerSend::SendHatScores" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendHatScores->original(a, method);
}

auto HF_ServerSend_Interact = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::Interact");
void Template_ServerSend_Interact(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::Interact" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_Interact->original(a, b, method);
}

auto HF_ServerSend_PlayerAnimation = new HookFunction<void, uint64_t, int32_t, bool, MethodInfo*>("ServerSend::PlayerAnimation");
void Template_ServerSend_PlayerAnimation(uint64_t a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "ServerSend::PlayerAnimation" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_PlayerAnimation->original(a, b, c, method);
}

auto HF_ServerSend_LobbyClosed = new HookFunction<void, uint64_t, LobbyManager_u10A3u109Au10A4u10A1u10A8u10A8u10A3u10A0u10A6u10A5u10A3__Enum, MethodInfo*>("ServerSend::LobbyClosed");
void Template_ServerSend_LobbyClosed(uint64_t a, LobbyManager_u10A3u109Au10A4u10A1u10A8u10A8u10A3u10A0u10A6u10A5u10A3__Enum b, MethodInfo* method)
{
	std::cout << "ServerSend::LobbyClosed" << " a=" << a << ", " << " b=" << (int)b << ", " << std::endl;

	HF_ServerSend_LobbyClosed->original(a, b, method);
}

auto HF_ServerSend_StartLobby_1 = new HookFunction<void, List_1_System_UInt64_*, MethodInfo*>("ServerSend::StartLobby_1");
void Template_ServerSend_StartLobby_1(List_1_System_UInt64_* a, MethodInfo* method)
{
	std::cout << "ServerSend::StartLobby_1" << " a=" << a << ", " << std::endl;

	HF_ServerSend_StartLobby_1->original(a, method);
}

auto HF_ServerSend_u10A6u109Fu10A3u10A8u109Au10A6u109Bu109Fu10A0u109Du10A0 = new HookFunction<void, uint64_t, int32_t, int32_t, int32_t, MethodInfo*>("ServerSend::u10A6u109Fu10A3u10A8u109Au10A6u109Bu109Fu10A0u109Du10A0");
void Template_ServerSend_u10A6u109Fu10A3u10A8u109Au10A6u109Bu109Fu10A0u109Du10A0(uint64_t a, int32_t b, int32_t c, int32_t d, MethodInfo* method)
{
	std::cout << "ServerSend::u10A6u109Fu10A3u10A8u109Au10A6u109Bu109Fu10A0u109Du10A0" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_u10A6u109Fu10A3u10A8u109Au10A6u109Bu109Fu10A0u109Du10A0->original(a, b, c, d, method);
}

auto HF_ServerSend_u10A2u10A4u109Au10A7u109Au10A8u109Au10A5u109Fu109Cu10A5 = new HookFunction<void, uint64_t, String*, MethodInfo*>("ServerSend::u10A2u10A4u109Au10A7u109Au10A8u109Au10A5u109Fu109Cu10A5");
void Template_ServerSend_u10A2u10A4u109Au10A7u109Au10A8u109Au10A5u109Fu109Cu10A5(uint64_t a, String* b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A2u10A4u109Au10A7u109Au10A8u109Au10A5u109Fu109Cu10A5" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A2u10A4u109Au10A7u109Au10A8u109Au10A5u109Fu109Cu10A5->original(a, b, method);
}

auto HF_ServerSend_SendGameModeTimer_1 = new HookFunction<void, float, int32_t, MethodInfo*>("ServerSend::SendGameModeTimer_1");
void Template_ServerSend_SendGameModeTimer_1(float a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SendGameModeTimer_1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendGameModeTimer_1->original(a, b, method);
}

auto HF_ServerSend_u10A6u109Au10A7u10A0u109Du10A2u10A2u10A2u109Bu10A1u109A = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A6u109Au10A7u10A0u109Du10A2u10A2u10A2u109Bu10A1u109A");
void Template_ServerSend_u10A6u109Au10A7u10A0u109Du10A2u10A2u10A2u109Bu10A1u109A(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A6u109Au10A7u10A0u109Du10A2u10A2u10A2u109Bu10A1u109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A6u109Au10A7u10A0u109Du10A2u10A2u10A2u109Bu10A1u109A->original(a, b, method);
}

auto HF_ServerSend_u1099u10A6u109Du10A6u10A4u109Eu109Cu109Fu10A1u109Fu10A5 = new HookFunction<void, uint64_t, Byte__Array*, int32_t, MethodInfo*>("ServerSend::u1099u10A6u109Du10A6u10A4u109Eu109Cu109Fu10A1u109Fu10A5");
void Template_ServerSend_u1099u10A6u109Du10A6u10A4u109Eu109Cu109Fu10A1u109Fu10A5(uint64_t a, Byte__Array* b, int32_t c, MethodInfo* method)
{
	std::cout << "ServerSend::u1099u10A6u109Du10A6u10A4u109Eu109Cu109Fu10A1u109Fu10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u1099u10A6u109Du10A6u10A4u109Eu109Cu109Fu10A1u109Fu10A5->original(a, b, c, method);
}

auto HF_ServerSend_SendGlassPieces = new HookFunction<void, uint64_t, List_1_System_Int32_*, MethodInfo*>("ServerSend::SendGlassPieces");
void Template_ServerSend_SendGlassPieces(uint64_t a, List_1_System_Int32_* b, MethodInfo* method)
{
	std::cout << "ServerSend::SendGlassPieces" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendGlassPieces->original(a, b, method);
}

auto HF_ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D");
void Template_ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "ServerSend::u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D->original(a, b, c, method);
}

auto HF_ServerSend_ChangeColor = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::ChangeColor");
void Template_ServerSend_ChangeColor(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::ChangeColor" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_ChangeColor->original(a, b, method);
}

auto HF_ServerSend_ButtonPressed = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::ButtonPressed");
void Template_ServerSend_ButtonPressed(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::ButtonPressed" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_ButtonPressed->original(a, b, method);
}

auto HF_ServerSend_SendWinner = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::SendWinner");
void Template_ServerSend_SendWinner(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::SendWinner" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SendWinner->original(a, b, method);
}

auto HF_ServerSend_MakeSeeker = new HookFunction<void, uint64_t, bool, MethodInfo*>("ServerSend::MakeSeeker");
void Template_ServerSend_MakeSeeker(uint64_t a, bool b, MethodInfo* method)
{
	std::cout << "ServerSend::MakeSeeker" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_MakeSeeker->original(a, b, method);
}

auto HF_ServerSend_u10A8u10A6u10A5u10A5u109Bu109Bu109Cu109Eu10A4u10A6u10A4 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u10A8u10A6u10A5u10A5u109Bu109Bu109Cu109Eu10A4u10A6u10A4");
void Template_ServerSend_u10A8u10A6u10A5u10A5u109Bu109Bu109Cu109Eu10A4u10A6u10A4(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A8u10A6u10A5u10A5u109Bu109Bu109Cu109Eu10A4u10A6u10A4" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A8u10A6u10A5u10A5u109Bu109Bu109Cu109Eu10A4u10A6u10A4->original(a, method);
}

auto HF_ServerSend_u109Au10A1u10A4u10A8u10A0u10A0u10A8u10A4u10A8u1099u10A2 = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::u109Au10A1u10A4u10A8u10A0u10A0u10A8u10A4u10A8u1099u10A2");
void Template_ServerSend_u109Au10A1u10A4u10A8u10A0u10A0u10A8u10A4u10A8u1099u10A2(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Au10A1u10A4u10A8u10A0u10A0u10A8u10A4u10A8u1099u10A2" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Au10A1u10A4u10A8u10A0u10A0u10A8u10A4u10A8u1099u10A2->original(a, method);
}

auto HF_ServerSend_ForceRemoveItem = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::ForceRemoveItem");
void Template_ServerSend_ForceRemoveItem(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::ForceRemoveItem" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_ForceRemoveItem->original(a, b, method);
}

auto HF_ServerSend_SendProximityVoice = new HookFunction<void, uint64_t, int32_t, Byte__Array*, MethodInfo*>("ServerSend::SendProximityVoice");
void Template_ServerSend_SendProximityVoice(uint64_t a, int32_t b, Byte__Array* c, MethodInfo* method)
{
	std::cout << "ServerSend::SendProximityVoice" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_ServerSend_SendProximityVoice->original(a, b, c, method);
}

auto HF_ServerSend_StandoffUpdate = new HookFunction<void, int32_t, int32_t, uint64_t, uint64_t, MethodInfo*>("ServerSend::StandoffUpdate");
void Template_ServerSend_StandoffUpdate(int32_t a, int32_t b, uint64_t c, uint64_t d, MethodInfo* method)
{
	std::cout << "ServerSend::StandoffUpdate" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_ServerSend_StandoffUpdate->original(a, b, c, d, method);
}

auto HF_ServerSend_u109Fu109Du10A2u109Du10A8u109Bu109Du10A1u10A7u10A7u109F = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u109Fu109Du10A2u109Du10A8u109Bu109Du10A1u10A7u10A7u109F");
void Template_ServerSend_u109Fu109Du10A2u109Du10A8u109Bu109Du10A1u10A7u10A7u109F(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu109Du10A2u109Du10A8u109Bu109Du10A1u10A7u10A7u109F" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u109Fu109Du10A2u109Du10A8u109Bu109Du10A1u10A7u10A7u109F->original(a, b, method);
}

auto HF_ServerSend_u10A2u10A5u10A4u109Bu10A5u109Bu10A3u10A5u10A4u10A1u109E = new HookFunction<void, uint64_t, uint64_t, MethodInfo*>("ServerSend::u10A2u10A5u10A4u109Bu10A5u109Bu10A3u10A5u10A4u10A1u109E");
void Template_ServerSend_u10A2u10A5u10A4u109Bu10A5u109Bu10A3u10A5u10A4u10A1u109E(uint64_t a, uint64_t b, MethodInfo* method)
{
	std::cout << "ServerSend::u10A2u10A5u10A4u109Bu10A5u109Bu10A3u10A5u10A4u10A1u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_u10A2u10A5u10A4u109Bu10A5u109Bu10A3u10A5u10A4u10A1u109E->original(a, b, method);
}

auto HF_ServerSend_SyncClock = new HookFunction<void, uint64_t, float, MethodInfo*>("ServerSend::SyncClock");
void Template_ServerSend_SyncClock(uint64_t a, float b, MethodInfo* method)
{
	std::cout << "ServerSend::SyncClock" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_SyncClock->original(a, b, method);
}

auto HF_ServerSend_SendTeams = new HookFunction<void, List_1_System_ValueTuple_2__1*, MethodInfo*>("ServerSend::SendTeams");
void Template_ServerSend_SendTeams(List_1_System_ValueTuple_2__1* a, MethodInfo* method)
{
	std::cout << "ServerSend::SendTeams" << " a=" << a << ", " << std::endl;

	HF_ServerSend_SendTeams->original(a, method);
}

auto HF_ServerSend_GameModeAlert = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("ServerSend::GameModeAlert");
void Template_ServerSend_GameModeAlert(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "ServerSend::GameModeAlert" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerSend_GameModeAlert->original(a, b, method);
}

auto HF_ServerSend_u109Fu10A6u1099u10A3u1099u10A7u10A3u109Au109Bu10A8u10A4 = new HookFunction<void, List_1_System_UInt64_*, MethodInfo*>("ServerSend::u109Fu10A6u1099u10A3u1099u10A7u10A3u109Au109Bu10A8u10A4");
void Template_ServerSend_u109Fu10A6u1099u10A3u1099u10A7u10A3u109Au109Bu10A8u10A4(List_1_System_UInt64_* a, MethodInfo* method)
{
	std::cout << "ServerSend::u109Fu10A6u1099u10A3u1099u10A7u10A3u109Au109Bu10A8u10A4" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u109Fu10A6u1099u10A3u1099u10A7u10A3u109Au109Bu10A8u10A4->original(a, method);
}

auto HF_ServerSend_LoadingSendIntoGame = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::LoadingSendIntoGame");
void Template_ServerSend_LoadingSendIntoGame(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::LoadingSendIntoGame" << " a=" << a << ", " << std::endl;

	HF_ServerSend_LoadingSendIntoGame->original(a, method);
}
/*
* ping
auto HF_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F_1 = new HookFunction<void, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerSend::u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F_1");
void Template_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F_1(u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* a, MethodInfo* method)
{
	std::cout << "ServerSend::u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F_1" << " a=" << a << ", " << std::endl;

	HF_ServerSend_u10A2u10A5u109Bu10A5u10A2u109Au10A0u109Au10A5u1099u109F_1->original(a, method);
}
*/