#pragma once

#include "Mod.h"
#include "Server.h"

/*
auto HF_LobbyManager_get_practiceMode = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::get_practiceMode");
bool Template_LobbyManager_get_practiceMode(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_practiceMode" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_practiceMode->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C");
void Template_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C->original(a, b, method);
}

auto HF_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2 = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2");
void Template_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E");
void Template_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E->original(a, method);
}
*/
auto HF_LobbyManager_RequestPracticeLobby = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::RequestPracticeLobby");
void Template_LobbyManager_RequestPracticeLobby(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::RequestPracticeLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_RequestPracticeLobby->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C");
void Template_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6");
void Template_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1");
String* Template_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2");
void Template_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2->original(a, b, method);
}

auto HF_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B");
void Template_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7");
void Template_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B");
CSteamID Template_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6 = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6");
void Template_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0");
CSteamID Template_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D");
String* Template_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3");
String* Template_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_set_practiceMode = new HookFunction<void, LobbyManager*, bool, MethodInfo*>("LobbyManager::set_practiceMode");
void Template_LobbyManager_set_practiceMode(LobbyManager* a, bool b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_practiceMode" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_practiceMode->original(a, b, method);
}
*/
/*
auto HF_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B");
String* Template_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F");
String* Template_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1 = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1");
String* Template_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D");
void Template_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D->original(a, b, c, method);
}

auto HF_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8 = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8");
void Template_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8->original(a, b, c, method);
}
/*
auto HF_LobbyManager__ctor = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::_ctor");
void Template_LobbyManager__ctor(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::_ctor" << " a=" << a << ", " << std::endl;

	HF_LobbyManager__ctor->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C");
void Template_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B");
void Template_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7");
void Template_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7->original(a, method);
}
*/
/*
auto HF_LobbyManager__cctor = new HookFunction<void, MethodInfo*>("LobbyManager::_cctor");
void Template_LobbyManager__cctor(MethodInfo* method)
{
	std::cout << "LobbyManager::_cctor" << std::endl;

	HF_LobbyManager__cctor->original(method);
}
*/
auto HF_LobbyManager_KickPlayer = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::KickPlayer");
void Template_LobbyManager_KickPlayer(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::KickPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_KickPlayer->original(a, b, method);
}
/*
auto HF_LobbyManager_set_serverName = new HookFunction<void, LobbyManager*, String*, MethodInfo*>("LobbyManager::set_serverName");
void Template_LobbyManager_set_serverName(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_serverName" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_serverName->original(a, b, method);
}
*/
/*
auto HF_LobbyManager_SetLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::SetLobby");
void Template_LobbyManager_SetLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::SetLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_SetLobby->original(a, b, method);
}
*/
auto HF_LobbyManager_OnPlayerJoinLeaveUpdate = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::OnPlayerJoinLeaveUpdate");
void Template_LobbyManager_OnPlayerJoinLeaveUpdate(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::OnPlayerJoinLeaveUpdate" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_OnPlayerJoinLeaveUpdate->original(a, b, c, method);
}

auto HF_LobbyManager_NewLobbySettings = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::NewLobbySettings");
void Template_LobbyManager_NewLobbySettings(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NewLobbySettings" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_NewLobbySettings->original(a, method);
}
/*
auto HF_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F");
void Template_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F->original(a, method);
}
*/
auto HF_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0 = new HookFunction<void, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0");
void Template_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0->original(a, b, method);
}
/*
auto HF_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D");
void Template_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8");
String* Template_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D");
void Template_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B");
String* Template_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_NewMuteList = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::NewMuteList");
void Template_LobbyManager_NewMuteList(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NewMuteList" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_NewMuteList->original(a, method);
}

auto HF_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B");
void Template_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B->original(a, b, method);
}
/*
auto HF_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2");
String* Template_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099");
void Template_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E");
String* Template_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A");
void Template_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4");
void Template_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4->original(a, method);
}
*/
/*
auto HF_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0 = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0");
void Template_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0->original(a, b, method);
}
*/
/*
auto HF_LobbyManager_SetServerVersion = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::SetServerVersion");
void Template_LobbyManager_SetServerVersion(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::SetServerVersion" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_SetServerVersion->original(a, method);
}
*/
auto HF_LobbyManager_AddPlayerToLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::AddPlayerToLobby");
void Template_LobbyManager_AddPlayerToLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::AddPlayerToLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_AddPlayerToLobby->original(a, b, method);

	Server::OnAddPlayerToLobby(b.m_SteamID);
}
/*
auto HF_LobbyManager_get_serverName = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::get_serverName");
String* Template_LobbyManager_get_serverName(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_serverName" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_serverName->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_get_colorsTaken = new HookFunction<Boolean__Array*, LobbyManager*, MethodInfo*>("LobbyManager::get_colorsTaken");
Boolean__Array* Template_LobbyManager_get_colorsTaken(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_colorsTaken" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_colorsTaken->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
/*
auto HF_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C");
String* Template_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4");
void Template_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4->original(a, method);
}

auto HF_LobbyManager_set_colorsTaken = new HookFunction<void, LobbyManager*, Boolean__Array*, MethodInfo*>("LobbyManager::set_colorsTaken");
void Template_LobbyManager_set_colorsTaken(LobbyManager* a, Boolean__Array* b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_colorsTaken" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_colorsTaken->original(a, b, method);
}

auto HF_LobbyManager_get_currentLobby = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::get_currentLobby");
CSteamID Template_LobbyManager_get_currentLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_currentLobby" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_currentLobby->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C");
String* Template_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3");
void Template_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3->original(a, b, method);
}
/*
auto HF_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0");
CSteamID Template_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_GameEnded = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::GameEnded");
void Template_LobbyManager_GameEnded(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::GameEnded" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_GameEnded->original(a, method);
}

auto HF_LobbyManager_CloseLobby = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::CloseLobby");
void Template_LobbyManager_CloseLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::CloseLobby" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_CloseLobby->original(a, method);
}

auto HF_LobbyManager_LobbyLoop = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::LobbyLoop");
void Template_LobbyManager_LobbyLoop(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::LobbyLoop" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_LobbyLoop->original(a, method);
}
/*
auto HF_LobbyManager_GetClient = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::GetClient");
Client* Template_LobbyManager_GetClient(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::GetClient" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_GetClient->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D");
String* Template_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B");
String* Template_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
/*
auto HF_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5");
String* Template_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A = new HookFunction<Boolean__Array*, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A");
Boolean__Array* Template_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099");
CSteamID Template_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2");
void Template_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2->original(a, b, method);
}
/*
auto HF_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099");
String* Template_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_StartLobby = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::StartLobby");
void Template_LobbyManager_StartLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::StartLobby" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_StartLobby->original(a, method);
}
/*
auto HF_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5");
void Template_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5->original(a, method);
}

auto HF_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B");
int32_t Template_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F");
int32_t Template_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7 = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7");
void Template_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7->original(a, b, c, method);
}

auto HF_LobbyManager_RemovePlayerFromLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::RemovePlayerFromLobby");
void Template_LobbyManager_RemovePlayerFromLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::RemovePlayerFromLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_RemovePlayerFromLobby->original(a, b, method);

	//Server::OnRemovePlayerFromLobby(b.m_SteamID);
}
/*
auto HF_LobbyManager_Awake = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::Awake");
void Template_LobbyManager_Awake(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::Awake" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_Awake->original(a, method);
}

auto HF_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D");
void Template_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D->original(a, method);
}

auto HF_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D");
String* Template_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1 = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1");
Client* Template_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_StartNewLobby = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::StartNewLobby");
void Template_LobbyManager_StartNewLobby(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::StartNewLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_StartNewLobby->original(a, b, c, method);
}

auto HF_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C");
void Template_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F");
void Template_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F->original(a, method);
}

auto HF_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3");
void Template_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3->original(a, method);
}
*/
auto HF_LobbyManager_ChangeColor = new HookFunction<void, LobbyManager*, uint64_t, int32_t, MethodInfo*>("LobbyManager::ChangeColor");
void Template_LobbyManager_ChangeColor(LobbyManager* a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "LobbyManager::ChangeColor" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_ChangeColor->original(a, b, c, method);
}
/*
auto HF_LobbyManager_NameVal = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::NameVal");
String* Template_LobbyManager_NameVal(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NameVal" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_NameVal->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_BanPlayer = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::BanPlayer");
void Template_LobbyManager_BanPlayer(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::BanPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_BanPlayer->original(a, b, method);
}
/*
auto HF_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D");
int32_t Template_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_set_currentLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::set_currentLobby");
void Template_LobbyManager_set_currentLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_currentLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_currentLobby->original(a, b, method);
}
*/
auto HF_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E");
void Template_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E->original(a, b, c, method);
}

auto HF_LobbyManager_StartPracticeLobby = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::StartPracticeLobby");
void Template_LobbyManager_StartPracticeLobby(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::StartPracticeLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_StartPracticeLobby->original(a, b, c, method);
}
/*
auto HF_LobbyManager_SetServerName = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::SetServerName");
void Template_LobbyManager_SetServerName(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::SetServerName" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_SetServerName->original(a, method);
}

auto HF_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C");
void Template_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C->original(a, method);
}

auto HF_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8");
void Template_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8->original(a, method);
}

auto HF_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D");
void Template_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D->original(a, method);
}
*/
auto HF_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2 = new HookFunction<void, LobbyManager*, int32_t, bool, MethodInfo*>("LobbyManager::u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2");
void Template_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2(LobbyManager* a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2->original(a, b, c, method);
}
/*
auto HF_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A");
String* Template_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7");
void Template_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7->original(a, method);
}

auto HF_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2");
String* Template_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B");
void Template_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B->original(a, method);
}

auto HF_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099");
void Template_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099->original(a, method);
}

auto HF_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1");
void Template_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1->original(a, method);
}

auto HF_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3");
void Template_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3->original(a, method);
}

auto HF_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7");
void Template_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7->original(a, method);
}

auto HF_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F");
void Template_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F->original(a, method);
}

auto HF_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6");
String* Template_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B");
String* Template_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
/*
auto HF_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B");
bool Template_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099 = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099");
void Template_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099->original(a, b, method);
}
/*
auto HF_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F");
void Template_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F->original(a, method);
}
*/
auto HF_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A");
void Template_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A->original(a, b, method);
}
/*
auto HF_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F");
void Template_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F->original(a, method);
}

auto HF_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7");
void Template_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7->original(a, method);
}
*/
auto HF_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C");
Client* Template_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
/*
auto HF_LobbyManager_GetClients = new HookFunction<Client__Array*, LobbyManager*, MethodInfo*>("LobbyManager::GetClients");
Client__Array* Template_LobbyManager_GetClients(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::GetClients" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_GetClients->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1");
void Template_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1->original(a, method);
}

auto HF_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D");
void Template_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D->original(a, method);
}
*/
auto HF_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D = new HookFunction<void, LobbyManager*, Boolean__Array*, MethodInfo*>("LobbyManager::u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D");
void Template_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D(LobbyManager* a, Boolean__Array* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D->original(a, b, method);
}
/*
auto HF_LobbyManager_GetPlayerColorId = new HookFunction<int32_t, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::GetPlayerColorId");
int32_t Template_LobbyManager_GetPlayerColorId(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::GetPlayerColorId" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_GetPlayerColorId->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5 = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5");
String* Template_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}
/*
auto HF_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5");
void Template_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5->original(a, method);
}
*/
/*
auto HF_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3 = new HookFunction<void, LobbyManager*, int32_t, bool, MethodInfo*>("LobbyManager::u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3");
void Template_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3(LobbyManager* a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3->original(a, b, c, method);
}
*/
/*
auto HF_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C");
int32_t Template_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A");
bool Template_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/