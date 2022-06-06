#pragma once

#include "Mod.h"
#include "Server.h"

auto HF_GameManager_u109Fu1099u10A7u10A0u10A4u10A2u10A6u10A6u109Au10A6u10A2 = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u109Fu1099u10A7u10A0u10A4u10A2u10A6u10A6u109Au10A6u10A2");
IEnumerator* Template_GameManager_u109Fu1099u10A7u10A0u10A4u10A2u10A6u10A6u109Au10A6u10A2(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u109Fu1099u10A7u10A0u10A4u10A2u10A6u10A6u109Au10A6u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u109Fu1099u10A7u10A0u10A4u10A2u10A6u10A6u109Au10A6u10A2->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u10A4u10A6u109Eu10A1u109Du109Fu109Du10A4u10A1u109Du109E = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A4u10A6u109Eu10A1u109Du109Fu109Du10A4u10A1u109Du109E");
void Template_GameManager_u10A4u10A6u109Eu10A1u109Du109Fu109Du10A4u10A1u109Du109E(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A6u109Eu10A1u109Du109Fu109Du10A4u10A1u109Du109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A4u10A6u109Eu10A1u109Du109Fu109Du10A4u10A1u109Du109E->original(a, b, method);
}

auto HF_GameManager_SyncObject = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::SyncObject");
void Template_GameManager_SyncObject(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::SyncObject" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_SyncObject->original(a, b, method);
}

auto HF_GameManager_u109Au109Bu109Au10A0u109Fu10A1u10A6u1099u10A5u109Cu10A4 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Au109Bu109Au10A0u109Fu10A1u10A6u1099u10A5u109Cu10A4");
void Template_GameManager_u109Au109Bu109Au10A0u109Fu10A1u10A6u1099u10A5u109Cu10A4(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu109Au10A0u109Fu10A1u10A6u1099u10A5u109Cu10A4" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Au109Bu109Au10A0u109Fu10A1u10A6u1099u10A5u109Cu10A4->original(a, method);
}

auto HF_GameManager_u1099u1099u109Cu10A8u10A1u10A7u10A3u10A1u10A6u10A7u109A = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u1099u1099u109Cu10A8u10A1u10A7u10A3u10A1u10A6u10A7u109A");
void Template_GameManager_u1099u1099u109Cu10A8u10A1u10A7u10A3u10A1u10A6u10A7u109A(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u1099u1099u109Cu10A8u10A1u10A7u10A3u10A1u10A6u10A7u109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u1099u1099u109Cu10A8u10A1u10A7u10A3u10A1u10A6u10A7u109A->original(a, b, method);
}

auto HF_GameManager_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099 = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099");
void Template_GameManager_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099->original(a, b, c, d, method);
}

auto HF_GameManager_PunchPlayer = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::PunchPlayer");
void Template_GameManager_PunchPlayer(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::PunchPlayer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_PunchPlayer->original(a, b, c, d, method);
}

auto HF_GameManager_u10A7u10A2u109Au10A2u10A0u109Fu10A1u109Fu109Fu10A6u10A4 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A7u10A2u109Au10A2u10A0u109Fu10A1u109Fu109Fu10A6u10A4");
void Template_GameManager_u10A7u10A2u109Au10A2u10A0u109Fu10A1u109Fu109Fu10A6u10A4(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A7u10A2u109Au10A2u10A0u109Fu10A1u109Fu109Fu10A6u10A4" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A7u10A2u109Au10A2u10A0u109Fu10A1u109Fu109Fu10A6u10A4->original(a, b, method);
}
/*
auto HF_GameManager_u10A4u109Cu10A0u10A3u10A2u109Eu109Au10A0u109Eu10A0u1099 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A4u109Cu10A0u10A3u10A2u109Eu109Au10A0u109Eu10A0u1099");
void Template_GameManager_u10A4u109Cu10A0u10A3u10A2u109Eu109Au10A0u109Eu10A0u1099(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u109Cu10A0u10A3u10A2u109Eu109Au10A0u109Eu10A0u1099" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A4u109Cu10A0u10A3u10A2u109Eu109Au10A0u109Eu10A0u1099->original(a, method);
}

auto HF_GameManager_u10A1u10A7u10A6u109Bu10A3u109Au1099u109Du10A3u10A6u10A3 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A1u10A7u10A6u109Bu10A3u109Au1099u109Du10A3u10A6u10A3");
void Template_GameManager_u10A1u10A7u10A6u109Bu10A3u109Au1099u109Du10A3u10A6u10A3(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u10A7u10A6u109Bu10A3u109Au1099u109Du10A3u10A6u10A3" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A1u10A7u10A6u109Bu10A3u109Au1099u109Du10A3u10A6u10A3->original(a, method);
}
*/
auto HF_GameManager_u1099u10A7u109Du109Eu10A3u1099u109Cu10A6u10A7u10A6u10A8 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u1099u10A7u109Du109Eu10A3u1099u109Cu10A6u10A7u10A6u10A8");
void Template_GameManager_u1099u10A7u109Du109Eu10A3u1099u109Cu10A6u10A7u10A6u10A8(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u1099u10A7u109Du109Eu10A3u1099u109Cu10A6u10A7u10A6u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u1099u10A7u109Du109Eu10A3u1099u109Cu10A6u10A7u10A6u10A8->original(a, b, method);
}

auto HF_GameManager_u10A7u10A7u10A2u10A2u10A7u109Du1099u109Bu109Du109Bu10A7 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A7u10A7u10A2u10A2u10A7u109Du1099u109Bu109Du109Bu10A7");
void Template_GameManager_u10A7u10A7u10A2u10A2u10A7u109Du1099u109Bu109Du109Bu10A7(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A7u10A7u10A2u10A2u10A7u109Du1099u109Bu109Du109Bu10A7" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A7u10A7u10A2u10A2u10A7u109Du1099u109Bu109Du109Bu10A7->original(a, b, method);
}
/*
auto HF_GameManager_u10A6u109Fu10A4u109Du10A0u109Eu1099u10A4u10A8u109Fu109B = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A6u109Fu10A4u109Du10A0u109Eu1099u10A4u10A8u109Fu109B");
void Template_GameManager_u10A6u109Fu10A4u109Du10A0u109Eu1099u10A4u10A8u109Fu109B(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u109Fu10A4u109Du10A0u109Eu1099u10A4u10A8u109Fu109B" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A6u109Fu10A4u109Du10A0u109Eu1099u10A4u10A8u109Fu109B->original(a, method);
}
*/
auto HF_GameManager_u109Cu10A8u10A7u1099u10A0u10A5u10A4u10A5u109Bu10A8u10A1 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Cu10A8u10A7u1099u10A0u10A5u10A4u10A5u109Bu10A8u10A1");
void Template_GameManager_u109Cu10A8u10A7u1099u10A0u10A5u10A4u10A5u109Bu10A8u10A1(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu10A8u10A7u1099u10A0u10A5u10A4u10A5u109Bu10A8u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Cu10A8u10A7u1099u10A0u10A5u10A4u10A5u109Bu10A8u10A1->original(a, b, method);
}

auto HF_GameManager_u10A1u1099u10A8u1099u10A5u10A5u10A1u109Cu109Fu1099u10A3 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A1u1099u10A8u1099u10A5u10A5u10A1u109Cu109Fu1099u10A3");
void Template_GameManager_u10A1u1099u10A8u1099u10A5u10A5u10A1u109Cu109Fu1099u10A3(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u1099u10A8u1099u10A5u10A5u10A1u109Cu109Fu1099u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A1u1099u10A8u1099u10A5u10A5u10A1u109Cu109Fu1099u10A3->original(a, b, method);
}

auto HF_GameManager_u109Eu10A2u109Bu109Fu10A8u10A0u10A2u10A8u109Eu109Au10A0 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Eu10A2u109Bu109Fu10A8u10A0u10A2u10A8u109Eu109Au10A0");
void Template_GameManager_u109Eu10A2u109Bu109Fu10A8u10A0u10A2u10A8u109Eu109Au10A0(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu10A2u109Bu109Fu10A8u10A0u10A2u10A8u109Eu109Au10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Eu10A2u109Bu109Fu10A8u10A0u10A2u10A8u109Eu109Au10A0->original(a, b, method);
}

auto HF_GameManager_SpawnPlayer = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::SpawnPlayer");
void Template_GameManager_SpawnPlayer(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::SpawnPlayer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_SpawnPlayer->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u1099u10A2u109Du109Cu10A1u109Eu109Du109Cu109Fu109Au10A0 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u1099u10A2u109Du109Cu10A1u109Eu109Du109Cu109Fu109Au10A0");
void Template_GameManager_u1099u10A2u109Du109Cu10A1u109Eu109Du109Cu109Fu109Au10A0(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u1099u10A2u109Du109Cu10A1u109Eu109Du109Cu109Fu109Au10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u1099u10A2u109Du109Cu10A1u109Eu109Du109Cu109Fu109Au10A0->original(a, b, method);
}

auto HF_GameManager_u10A2u10A8u10A5u10A8u109Eu109Fu109Cu10A4u10A6u10A8u10A4 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A2u10A8u10A5u10A8u109Eu109Fu109Cu10A4u10A6u10A8u10A4");
void Template_GameManager_u10A2u10A8u10A5u10A8u109Eu109Fu109Cu10A4u10A6u10A8u10A4(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A2u10A8u10A5u10A8u109Eu109Fu109Cu10A4u10A6u10A8u10A4" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A2u10A8u10A5u10A8u109Eu109Fu109Cu10A4u10A6u10A8u10A4->original(a, b, method);
}
/*
auto HF_GameManager_u10A8u109Cu10A8u1099u109Cu109Bu10A7u10A5u10A5u10A5u10A6 = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u10A8u109Cu10A8u1099u109Cu109Bu10A7u10A5u10A5u10A5u10A6");
int32_t Template_GameManager_u10A8u109Cu10A8u1099u109Cu109Bu10A7u10A5u10A5u10A5u10A6(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A8u109Cu10A8u1099u109Cu109Bu10A7u10A5u10A5u10A5u10A6" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u10A8u109Cu10A8u1099u109Cu109Bu10A7u10A5u10A5u10A5u10A6->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_GameManager_RemovePlayer = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::RemovePlayer");
void Template_GameManager_RemovePlayer(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::RemovePlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_RemovePlayer->original(a, b, method);
}
/*
auto HF_GameManager_u10A2u10A6u109Du109Du10A4u109Du109Cu109Bu10A7u10A4u10A4 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A2u10A6u109Du109Du10A4u109Du109Cu109Bu10A7u10A4u10A4");
void Template_GameManager_u10A2u10A6u109Du109Du10A4u109Du109Cu109Bu10A7u10A4u10A4(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A2u10A6u109Du109Du10A4u109Du109Cu109Bu10A7u10A4u10A4" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A2u10A6u109Du109Du10A4u109Du109Cu109Bu10A7u10A4u10A4->original(a, method);
}
*/
auto HF_GameManager_SetPlayerRotation = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::SetPlayerRotation");
void Template_GameManager_SetPlayerRotation(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::SetPlayerRotation" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_SetPlayerRotation->original(a, b, method);
}

auto HF_GameManager_u109Au1099u109Cu10A8u109Bu1099u109Au109Eu10A5u10A7u109C = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Au1099u109Cu10A8u109Bu1099u109Au109Eu10A5u10A7u109C");
void Template_GameManager_u109Au1099u109Cu10A8u109Bu1099u109Au109Eu10A5u10A7u109C(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Au1099u109Cu10A8u109Bu1099u109Au109Eu10A5u10A7u109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Au1099u109Cu10A8u109Bu1099u109Au109Eu10A5u10A7u109C->original(a, b, method);
}

auto HF_GameManager_u10A8u109Cu10A1u10A4u1099u10A5u10A1u109Bu109Cu10A5u109E = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u10A8u109Cu10A1u10A4u1099u10A5u10A1u109Bu109Cu10A5u109E");
IEnumerator* Template_GameManager_u10A8u109Cu10A1u10A4u1099u10A5u10A1u109Bu109Cu10A5u109E(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u10A8u109Cu10A1u10A4u1099u10A5u10A1u109Bu109Cu10A5u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u10A8u109Cu10A1u10A4u1099u10A5u10A1u109Bu109Cu10A5u109E->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u10A3u10A7u109Bu10A5u10A2u10A1u10A6u1099u10A7u109Cu109B = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A3u10A7u109Bu10A5u10A2u10A1u10A6u1099u10A7u109Cu109B");
void Template_GameManager_u10A3u10A7u109Bu10A5u10A2u10A1u10A6u1099u10A7u109Cu109B(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u10A7u109Bu10A5u10A2u10A1u10A6u1099u10A7u109Cu109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A3u10A7u109Bu10A5u10A2u10A1u10A6u1099u10A7u109Cu109B->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u10A0u109Bu10A2u10A6u10A3u109Du10A5u109Cu10A2u10A5u1099 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A0u109Bu10A2u10A6u10A3u109Du10A5u109Cu10A2u10A5u1099");
void Template_GameManager_u10A0u109Bu10A2u10A6u10A3u109Du10A5u109Cu10A2u10A5u1099(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A0u109Bu10A2u10A6u10A3u109Du10A5u109Cu10A2u10A5u1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A0u109Bu10A2u10A6u10A3u109Du10A5u109Cu10A2u10A5u1099->original(a, b, method);
}

auto HF_GameManager_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E");
void Template_GameManager_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E->original(a, b, method);
}
/*
auto HF_GameManager_u109Cu10A2u109Cu10A4u1099u109Cu10A6u109Fu109Cu10A4u10A0 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Cu10A2u109Cu10A4u1099u109Cu10A6u109Fu109Cu10A4u10A0");
void Template_GameManager_u109Cu10A2u109Cu10A4u1099u109Cu10A6u109Fu109Cu10A4u10A0(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu10A2u109Cu10A4u1099u109Cu10A6u109Fu109Cu10A4u10A0" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Cu10A2u109Cu10A4u1099u109Cu10A6u109Fu109Cu10A4u10A0->original(a, method);
}
*/
auto HF_GameManager_u10A3u109Fu10A7u109Du109Cu10A6u10A2u10A7u10A7u10A5u10A2 = new HookFunction<void, GameManager*, uint64_t, Vector3, MethodInfo*>("GameManager::u10A3u109Fu10A7u109Du109Cu10A6u10A2u10A7u10A7u10A5u10A2");
void Template_GameManager_u10A3u109Fu10A7u109Du109Cu10A6u10A2u10A7u10A7u10A5u10A2(GameManager* a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u109Fu10A7u109Du109Cu10A6u10A2u10A7u10A7u10A5u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameManager_u10A3u109Fu10A7u109Du109Cu10A6u10A2u10A7u10A7u10A5u10A2->original(a, b, c, method);
}

auto HF_GameManager_u10A3u10A3u10A0u10A7u10A1u10A3u109Au10A2u1099u10A2u1099 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A3u10A3u10A0u10A7u10A1u10A3u109Au10A2u1099u10A2u1099");
void Template_GameManager_u10A3u10A3u10A0u10A7u10A1u10A3u109Au10A2u1099u10A2u1099(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u10A3u10A0u10A7u10A1u10A3u109Au10A2u1099u10A2u1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A3u10A3u10A0u10A7u10A1u10A3u109Au10A2u1099u10A2u1099->original(a, b, method);
}

auto HF_GameManager_u10A3u1099u10A1u10A3u10A1u10A0u109Au1099u109Du109Cu10A7 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A3u1099u10A1u10A3u10A1u10A0u109Au1099u109Du109Cu10A7");
void Template_GameManager_u10A3u1099u10A1u10A3u10A1u10A0u109Au1099u109Du109Cu10A7(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u1099u10A1u10A3u10A1u10A0u109Au1099u109Du109Cu10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A3u1099u10A1u10A3u10A1u10A0u109Au1099u109Du109Cu10A7->original(a, b, c, d, e, f, g, method);
}
/*
auto HF_GameManager_u109Cu109Bu109Du10A3u109Eu10A4u10A7u10A3u10A8u10A1u10A3 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u109Cu109Bu109Du10A3u109Eu10A4u10A7u10A3u10A8u10A1u10A3");
void Template_GameManager_u109Cu109Bu109Du10A3u109Eu10A4u10A7u10A3u10A8u10A1u10A3(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu109Bu109Du10A3u109Eu10A4u10A7u10A3u10A8u10A1u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Cu109Bu109Du10A3u109Eu10A4u10A7u10A3u10A8u10A1u10A3->original(a, b, method);
}
*/
auto HF_GameManager_u10A1u109Fu109Eu109Au109Cu1099u109Fu10A2u109Bu1099u10A8 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A1u109Fu109Eu109Au109Cu1099u109Fu10A2u109Bu1099u10A8");
void Template_GameManager_u10A1u109Fu109Eu109Au109Cu1099u109Fu10A2u109Bu1099u10A8(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u109Fu109Eu109Au109Cu1099u109Fu10A2u109Bu1099u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A1u109Fu109Eu109Au109Cu1099u109Fu10A2u109Bu1099u10A8->original(a, b, method);
}

auto HF_GameManager_Start = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::Start");
void Template_GameManager_Start(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::Start" << " a=" << a << ", " << std::endl;

	HF_GameManager_Start->original(a, method);
}
/*
auto HF_GameManager_u10A3u109Cu109Du1099u10A7u109Du10A0u10A5u10A6u109Cu10A5 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A3u109Cu109Du1099u10A7u109Du10A0u10A5u10A6u109Cu10A5");
void Template_GameManager_u10A3u109Cu109Du1099u10A7u109Du10A0u10A5u10A6u109Cu10A5(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u109Cu109Du1099u10A7u109Du10A0u10A5u10A6u109Cu10A5" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A3u109Cu109Du1099u10A7u109Du10A0u10A5u10A6u109Cu10A5->original(a, method);
}
*/
auto HF_GameManager_u10A3u109Bu10A2u10A7u109Eu109Eu10A1u10A7u109Du109Fu10A6 = new HookFunction<void, GameManager*, uint64_t, Vector3, MethodInfo*>("GameManager::u10A3u109Bu10A2u10A7u109Eu109Eu10A1u10A7u109Du109Fu10A6");
void Template_GameManager_u10A3u109Bu10A2u10A7u109Eu109Eu10A1u10A7u109Du109Fu10A6(GameManager* a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameManager::u10A3u109Bu10A2u10A7u109Eu109Eu10A1u10A7u109Du109Fu10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameManager_u10A3u109Bu10A2u10A7u109Eu109Eu10A1u10A7u109Du109Fu10A6->original(a, b, c, method);
}

auto HF_GameManager_u10A5u109Au1099u109Eu109Cu109Fu10A5u10A5u10A8u10A2u109B = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A5u109Au1099u109Eu109Cu109Fu10A5u10A5u10A8u10A2u109B");
void Template_GameManager_u10A5u109Au1099u109Eu109Cu109Fu10A5u10A5u10A8u10A2u109B(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u109Au1099u109Eu109Cu109Fu10A5u10A5u10A8u10A2u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A5u109Au1099u109Eu109Cu109Fu10A5u10A5u10A8u10A2u109B->original(a, b, method);
}

auto HF_GameManager_u10A1u10A6u10A6u109Bu10A8u10A7u1099u109Du10A6u109Cu109D = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A1u10A6u10A6u109Bu10A8u10A7u1099u109Du10A6u109Cu109D");
void Template_GameManager_u10A1u10A6u10A6u109Bu10A8u10A7u1099u109Du10A6u109Cu109D(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u10A6u10A6u109Bu10A8u10A7u1099u109Du10A6u109Cu109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A1u10A6u10A6u109Bu10A8u10A7u1099u109Du10A6u109Cu109D->original(a, b, method);
}

auto HF_GameManager_u10A7u10A6u109Cu10A3u10A5u10A4u109Fu109Fu10A6u109Du1099 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A7u10A6u109Cu10A3u10A5u10A4u109Fu109Fu10A6u109Du1099");
void Template_GameManager_u10A7u10A6u109Cu10A3u10A5u10A4u109Fu109Fu10A6u109Du1099(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A7u10A6u109Cu10A3u10A5u10A4u109Fu109Fu10A6u109Du1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A7u10A6u109Cu10A3u10A5u10A4u109Fu109Fu10A6u109Du1099->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u1099u109Au10A0u10A1u10A4u10A5u109Eu109Cu109Cu10A3u10A2 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u1099u109Au10A0u10A1u10A4u10A5u109Eu109Cu109Cu10A3u10A2");
void Template_GameManager_u1099u109Au10A0u10A1u10A4u10A5u109Eu109Cu109Cu10A3u10A2(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u1099u109Au10A0u10A1u10A4u10A5u109Eu109Cu109Cu10A3u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u1099u109Au10A0u10A1u10A4u10A5u109Eu109Cu109Cu10A3u10A2->original(a, b, method);
}

auto HF_GameManager__ctor = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::_ctor");
void Template_GameManager__ctor(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::_ctor" << " a=" << a << ", " << std::endl;

	HF_GameManager__ctor->original(a, method);
}

auto HF_GameManager_u10A6u10A1u10A6u109Cu109Du10A2u10A5u10A1u109Au10A3u1099 = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u10A6u10A1u10A6u109Cu109Du10A2u10A5u10A1u109Au10A3u1099");
IEnumerator* Template_GameManager_u10A6u10A1u10A6u109Cu109Du10A2u10A5u10A1u109Au10A3u1099(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u10A1u10A6u109Cu109Du10A2u10A5u10A1u109Au10A3u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u10A6u10A1u10A6u109Cu109Du10A2u10A5u10A1u109Au10A3u1099->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_SpawnSpectator = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::SpawnSpectator");
void Template_GameManager_SpawnSpectator(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::SpawnSpectator" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_SpawnSpectator->original(a, b, method);
}

auto HF_GameManager_u10A4u10A8u1099u10A8u10A3u109Eu10A7u10A2u10A3u10A5u10A6 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A4u10A8u1099u10A8u10A3u109Eu10A7u10A2u10A3u10A5u10A6");
void Template_GameManager_u10A4u10A8u1099u10A8u10A3u109Eu10A7u10A2u10A3u10A5u10A6(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A8u1099u10A8u10A3u109Eu10A7u10A2u10A3u10A5u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A4u10A8u1099u10A8u10A3u109Eu10A7u10A2u10A3u10A5u10A6->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_Update = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::Update");
void Template_GameManager_Update(GameManager* a, MethodInfo* method)
{
	//std::cout << "GameManager::Update" << " a=" << a << ", " << std::endl;

	float dt = Time_get_deltaTime(NULL);
	Server::Update(dt);

	HF_GameManager_Update->original(a, method);
}

auto HF_GameManager_u10A4u109Fu109Au10A0u10A8u10A6u10A1u109Bu10A6u109Au10A7 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A4u109Fu109Au10A0u10A8u10A6u10A1u109Bu10A6u109Au10A7");
void Template_GameManager_u10A4u109Fu109Au10A0u10A8u10A6u10A1u109Bu10A6u109Au10A7(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u109Fu109Au10A0u10A8u10A6u10A1u109Bu10A6u109Au10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A4u109Fu109Au10A0u10A8u10A6u10A1u109Bu10A6u109Au10A7->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_RespawnPlayer = new HookFunction<void, GameManager*, uint64_t, Vector3, MethodInfo*>("GameManager::RespawnPlayer");
void Template_GameManager_RespawnPlayer(GameManager* a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameManager::RespawnPlayer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameManager_RespawnPlayer->original(a, b, c, method);
}

auto HF_GameManager_u109Fu10A0u10A4u109Eu10A0u109Au10A2u10A3u10A8u109Bu10A4 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Fu10A0u10A4u109Eu10A0u109Au10A2u10A3u10A8u109Bu10A4");
void Template_GameManager_u109Fu10A0u10A4u109Eu10A0u109Au10A2u10A3u10A8u109Bu10A4(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Fu10A0u10A4u109Eu10A0u109Au10A2u10A3u10A8u109Bu10A4" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Fu10A0u10A4u109Eu10A0u109Au10A2u10A3u10A8u109Bu10A4->original(a, b, method);
}
/*
auto HF_GameManager_u109Fu10A8u10A6u10A3u10A7u109Au109Fu10A3u10A3u109Au109E = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Fu10A8u10A6u10A3u10A7u109Au109Fu10A3u10A3u109Au109E");
void Template_GameManager_u109Fu10A8u10A6u10A3u10A7u109Au109Fu10A3u10A3u109Au109E(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Fu10A8u10A6u10A3u10A7u109Au109Fu10A3u10A3u109Au109E" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Fu10A8u10A6u10A3u10A7u109Au109Fu10A3u10A3u109Au109E->original(a, method);
}

auto HF_GameManager_GetPlayersAlive = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::GetPlayersAlive");
int32_t Template_GameManager_GetPlayersAlive(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::GetPlayersAlive" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_GetPlayersAlive->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_GameManager_u10A6u10A3u109Eu109Fu10A7u109Fu109Au10A5u10A2u10A2u10A2 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A6u10A3u109Eu109Fu10A7u109Fu109Au10A5u10A2u10A2u10A2");
void Template_GameManager_u10A6u10A3u109Eu109Fu10A7u109Fu109Au10A5u10A2u10A2u10A2(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u10A3u109Eu109Fu10A7u109Fu109Au10A5u10A2u10A2u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A6u10A3u109Eu109Fu10A7u109Fu109Au10A5u10A2u10A2u10A2->original(a, b, method);
}

auto HF_GameManager_u109Eu1099u10A6u10A6u10A7u1099u10A1u10A3u10A7u10A2u10A6 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Eu1099u10A6u10A6u10A7u1099u10A1u10A3u10A7u10A2u10A6");
void Template_GameManager_u109Eu1099u10A6u10A6u10A7u1099u10A1u10A3u10A7u10A2u10A6(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu1099u10A6u10A6u10A7u1099u10A1u10A3u10A7u10A2u10A6" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Eu1099u10A6u10A6u10A7u1099u10A1u10A3u10A7u10A2u10A6->original(a, b, method);
}

auto HF_GameManager_u109Cu10A7u10A6u109Cu10A3u1099u10A7u1099u10A3u10A0u109A = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u109Cu10A7u10A6u109Cu10A3u1099u10A7u1099u10A3u10A0u109A");
IEnumerator* Template_GameManager_u109Cu10A7u10A6u109Cu10A3u1099u10A7u1099u10A3u10A0u109A(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu10A7u10A6u109Cu10A3u1099u10A7u1099u10A3u10A0u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u109Cu10A7u10A6u109Cu10A3u1099u10A7u1099u10A3u10A0u109A->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u10A2u109Au10A5u1099u10A0u10A3u109Eu109Fu109Bu109Cu10A8 = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u10A2u109Au10A5u1099u10A0u10A3u109Eu109Fu109Bu109Cu10A8");
int32_t Template_GameManager_u10A2u109Au10A5u1099u10A0u10A3u109Eu109Fu109Bu109Cu10A8(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A2u109Au10A5u1099u10A0u10A3u109Eu109Fu109Bu109Cu10A8" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u10A2u109Au10A5u1099u10A0u10A3u109Eu109Fu109Bu109Cu10A8->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Cu109Au10A7u109Au109Bu10A0u109Du10A0u109Cu10A4u10A6 = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u109Cu109Au10A7u109Au109Bu10A0u109Du10A0u109Cu10A4u10A6");
void Template_GameManager_u109Cu109Au10A7u109Au109Bu10A0u109Du10A0u109Cu10A4u10A6(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu109Au10A7u109Au109Bu10A0u109Du10A0u109Cu10A4u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u109Cu109Au10A7u109Au109Bu10A0u109Du10A0u109Cu10A4u10A6->original(a, b, c, d, method);
}

auto HF_GameManager_u10A0u10A0u109Bu10A2u10A5u10A6u109Au10A2u109Bu10A5u10A1 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A0u10A0u109Bu10A2u10A5u10A6u109Au10A2u109Bu10A5u10A1");
void Template_GameManager_u10A0u10A0u109Bu10A2u10A5u10A6u109Au10A2u109Bu10A5u10A1(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A0u10A0u109Bu10A2u10A5u10A6u109Au10A2u109Bu10A5u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A0u10A0u109Bu10A2u10A5u10A6u109Au10A2u109Bu10A5u10A1->original(a, b, method);
}

auto HF_GameManager_u10A6u109Au10A5u109Bu10A6u10A7u109Du109Fu109Du10A6u10A1 = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u10A6u109Au10A5u109Bu10A6u10A7u109Du109Fu109Du10A6u10A1");
void Template_GameManager_u10A6u109Au10A5u109Bu10A6u10A7u109Du109Fu109Du10A6u10A1(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u109Au10A5u109Bu10A6u10A7u109Du109Fu109Du10A6u10A1" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u10A6u109Au10A5u109Bu10A6u10A7u109Du109Fu109Du10A6u10A1->original(a, b, c, d, method);
}

auto HF_GameManager_u109Eu10A2u10A8u109Bu109Du10A7u10A0u10A5u109Eu109Fu10A1 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u109Eu10A2u10A8u109Bu109Du10A7u10A0u10A5u109Eu109Fu10A1");
void Template_GameManager_u109Eu10A2u10A8u109Bu109Du10A7u10A0u10A5u109Eu109Fu10A1(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu10A2u10A8u109Bu109Du10A7u10A0u10A5u109Eu109Fu10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Eu10A2u10A8u109Bu109Du10A7u10A0u10A5u109Eu109Fu10A1->original(a, b, method);
}
/*
auto HF_GameManager_u10A8u10A0u10A1u109Eu109Du10A1u10A7u10A5u10A5u109Bu109A = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u10A8u10A0u10A1u109Eu109Du10A1u10A7u10A5u10A5u109Bu109A");
int32_t Template_GameManager_u10A8u10A0u10A1u109Eu109Du10A1u10A7u10A5u10A5u109Bu109A(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A8u10A0u10A1u109Eu109Du10A1u10A7u10A5u10A5u109Bu109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u10A8u10A0u10A1u109Eu109Du10A1u10A7u10A5u10A5u109Bu109A->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Du109Cu10A5u109Cu109Bu10A3u10A4u109Au109Du10A7u10A0 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Du109Cu10A5u109Cu109Bu10A3u10A4u109Au109Du10A7u10A0");
void Template_GameManager_u109Du109Cu10A5u109Cu109Bu10A3u10A4u109Au109Du10A7u10A0(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Du109Cu10A5u109Cu109Bu10A3u10A4u109Au109Du10A7u10A0" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Du109Cu10A5u109Cu109Bu10A3u10A4u109Au109Du10A7u10A0->original(a, method);
}

auto HF_GameManager_u109Fu10A8u10A3u10A3u109Cu109Fu10A7u10A0u10A8u10A8u10A6 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Fu10A8u10A3u10A3u109Cu109Fu10A7u10A0u10A8u10A8u10A6");
void Template_GameManager_u109Fu10A8u10A3u10A3u109Cu109Fu10A7u10A0u10A8u10A8u10A6(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Fu10A8u10A3u10A3u109Cu109Fu10A7u10A0u10A8u10A8u10A6" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Fu10A8u10A3u10A3u109Cu109Fu10A7u10A0u10A8u10A8u10A6->original(a, method);
}
*/
auto HF_GameManager_SetPlayerAnimation = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::SetPlayerAnimation");
void Template_GameManager_SetPlayerAnimation(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::SetPlayerAnimation" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_SetPlayerAnimation->original(a, b, method);
}

auto HF_GameManager_u109Bu10A2u109Au10A7u10A2u10A1u10A2u10A0u10A6u10A2u10A3 = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u109Bu10A2u109Au10A7u10A2u10A1u10A2u10A0u10A6u10A2u10A3");
void Template_GameManager_u109Bu10A2u109Au10A7u10A2u10A1u10A2u10A0u10A6u10A2u10A3(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u109Bu10A2u109Au10A7u10A2u10A1u10A2u10A0u10A6u10A2u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Bu10A2u109Au10A7u10A2u10A1u10A2u10A0u10A6u10A2u10A3->original(a, b, method);
}

auto HF_GameManager_u1099u109Fu109Eu10A6u109Du10A1u109Fu109Eu10A1u10A8u10A6 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u1099u109Fu109Eu10A6u109Du10A1u109Fu109Eu10A1u10A8u10A6");
void Template_GameManager_u1099u109Fu109Eu10A6u109Du10A1u109Fu109Eu10A1u10A8u10A6(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u1099u109Fu109Eu10A6u109Du10A1u109Fu109Eu10A1u10A8u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u1099u109Fu109Eu10A6u109Du10A1u109Fu109Eu10A1u10A8u10A6->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u109Eu109Fu109Fu109Cu109Eu10A5u10A6u109Fu10A5u109Cu1099 = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u109Eu109Fu109Fu109Cu109Eu10A5u10A6u109Fu10A5u109Cu1099");
IEnumerator* Template_GameManager_u109Eu109Fu109Fu109Cu109Eu10A5u10A6u109Fu10A5u109Cu1099(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu109Fu109Fu109Cu109Eu10A5u10A6u109Fu10A5u109Cu1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u109Eu109Fu109Fu109Cu109Eu10A5u10A6u109Fu10A5u109Cu1099->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Cu10A3u109Fu10A5u10A6u109Eu1099u10A3u109Eu10A6u109D = new HookFunction<void, GameManager*, uint64_t, Vector3, MethodInfo*>("GameManager::u109Cu10A3u109Fu10A5u10A6u109Eu1099u10A3u109Eu10A6u109D");
void Template_GameManager_u109Cu10A3u109Fu10A5u10A6u109Eu1099u10A3u109Eu10A6u109D(GameManager* a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu10A3u109Fu10A5u10A6u109Eu1099u10A3u109Eu10A6u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameManager_u109Cu10A3u109Fu10A5u10A6u109Eu1099u10A3u109Eu10A6u109D->original(a, b, c, method);
}

auto HF_GameManager_u10A0u10A7u10A0u10A6u109Eu109Au10A5u10A7u10A5u10A0u10A3 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A0u10A7u10A0u10A6u109Eu109Au10A5u10A7u10A5u10A0u10A3");
void Template_GameManager_u10A0u10A7u10A0u10A6u109Eu109Au10A5u10A7u10A5u10A0u10A3(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A0u10A7u10A0u10A6u109Eu109Au10A5u10A7u10A5u10A0u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A0u10A7u10A0u10A6u109Eu109Au10A5u10A7u10A5u10A0u10A3->original(a, b, method);
}
/*
auto HF_GameManager_u10A8u109Fu109Cu10A6u1099u109Bu109Bu10A4u109Du10A3u10A6 = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u10A8u109Fu109Cu10A6u1099u109Bu109Bu10A4u109Du10A3u10A6");
int32_t Template_GameManager_u10A8u109Fu109Cu10A6u1099u109Bu109Bu10A4u109Du10A3u10A6(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A8u109Fu109Cu10A6u1099u109Bu109Bu10A4u109Du10A3u10A6" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u10A8u109Fu109Cu10A6u1099u109Bu109Bu10A4u109Du10A3u10A6->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_GameManager_u10A4u10A5u10A8u10A4u10A2u109Fu109Fu10A7u109Du10A1u10A5 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A4u10A5u10A8u10A4u10A2u109Fu109Fu10A7u109Du10A1u10A5");
void Template_GameManager_u10A4u10A5u10A8u10A4u10A2u109Fu109Fu10A7u109Du10A1u10A5(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A5u10A8u10A4u10A2u109Fu109Fu10A7u109Du10A1u10A5" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A4u10A5u10A8u10A4u10A2u109Fu109Fu10A7u109Du10A1u10A5->original(a, b, method);
}
/*
auto HF_GameManager_u109Du10A5u10A8u109Du10A4u109Fu109Au109Eu10A5u10A6u1099 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u109Du10A5u10A8u109Du10A4u109Fu109Au109Eu10A5u10A6u1099");
void Template_GameManager_u109Du10A5u10A8u109Du10A4u109Fu109Au109Eu10A5u10A6u1099(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Du10A5u10A8u109Du10A4u109Fu109Au109Eu10A5u10A6u1099" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Du10A5u10A8u109Du10A4u109Fu109Au109Eu10A5u10A6u1099->original(a, method);
}

auto HF_GameManager_u10A4u10A5u10A2u10A7u10A2u109Bu10A8u109Eu10A3u10A4u109E = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A4u10A5u10A2u10A7u10A2u109Bu10A8u109Eu10A3u10A4u109E");
void Template_GameManager_u10A4u10A5u10A2u10A7u10A2u109Bu10A8u109Eu10A3u10A4u109E(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A5u10A2u10A7u10A2u109Bu10A8u109Eu10A3u10A4u109E" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A4u10A5u10A2u10A7u10A2u109Bu10A8u109Eu10A3u10A4u109E->original(a, method);
}

auto HF_GameManager_u10A5u109Cu10A1u109Au10A6u109Du10A6u10A1u10A7u10A3u109D = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A5u109Cu10A1u109Au10A6u109Du10A6u10A1u10A7u10A3u109D");
void Template_GameManager_u10A5u109Cu10A1u109Au10A6u109Du10A6u10A1u10A7u10A3u109D(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u109Cu10A1u109Au10A6u109Du10A6u10A1u10A7u10A3u109D" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A5u109Cu10A1u109Au10A6u109Du10A6u10A1u10A7u10A3u109D->original(a, method);
}

auto HF_GameManager_u10A5u10A0u10A8u109Fu10A7u109Eu10A7u10A5u1099u109Du10A7 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A5u10A0u10A8u109Fu10A7u109Eu10A7u10A5u1099u109Du10A7");
void Template_GameManager_u10A5u10A0u10A8u109Fu10A7u109Eu10A7u10A5u1099u109Du10A7(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u10A0u10A8u109Fu10A7u109Eu10A7u10A5u1099u109Du10A7" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A5u10A0u10A8u109Fu10A7u109Eu10A7u10A5u1099u109Du10A7->original(a, method);
}
*/
auto HF_GameManager_SetPlayerPosition = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::SetPlayerPosition");
void Template_GameManager_SetPlayerPosition(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::SetPlayerPosition" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_SetPlayerPosition->original(a, b, method);
}
/*
auto HF_GameManager_u1099u10A5u10A5u10A1u10A1u10A5u10A1u10A7u10A0u109Eu109D = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u1099u10A5u10A5u10A1u10A1u10A5u10A1u10A7u10A0u109Eu109D");
void Template_GameManager_u1099u10A5u10A5u10A1u10A1u10A5u10A1u10A7u10A0u109Eu109D(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u1099u10A5u10A5u10A1u10A1u10A5u10A1u10A7u10A0u109Eu109D" << " a=" << a << ", " << std::endl;

	HF_GameManager_u1099u10A5u10A5u10A1u10A1u10A5u10A1u10A7u10A0u109Eu109D->original(a, method);
}
*/
/*
auto HF_GameManager_u10A5u109Eu1099u109Eu10A7u1099u109Au109Du10A7u109Au109A = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A5u109Eu1099u109Eu10A7u1099u109Au109Du10A7u109Au109A");
void Template_GameManager_u10A5u109Eu1099u109Eu10A7u1099u109Au109Du10A7u109Au109A(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u109Eu1099u109Eu10A7u1099u109Au109Du10A7u109Au109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A5u109Eu1099u109Eu10A7u1099u109Au109Du10A7u109Au109A->original(a, b, method);
}
*/
auto HF_GameManager_PlayerTookDamage = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::PlayerTookDamage");
void Template_GameManager_PlayerTookDamage(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::PlayerTookDamage" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_PlayerTookDamage->original(a, b, method);
}
/*
auto HF_GameManager_u10A6u109Du109Fu109Du10A4u10A5u10A1u109Au1099u109Au1099 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A6u109Du109Fu109Du10A4u10A5u10A1u109Au1099u109Au1099");
void Template_GameManager_u10A6u109Du109Fu109Du10A4u10A5u10A1u109Au1099u109Au1099(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u109Du109Fu109Du10A4u10A5u10A1u109Au1099u109Au1099" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A6u109Du109Fu109Du10A4u10A5u10A1u109Au1099u109Au1099->original(a, method);
}

auto HF_GameManager_u10A2u10A3u10A1u10A8u109Fu109Cu10A8u1099u109Du109Du10A4 = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A2u10A3u10A1u10A8u109Fu109Cu10A8u1099u109Du109Du10A4");
void Template_GameManager_u10A2u10A3u10A1u10A8u109Fu109Cu10A8u1099u109Du109Du10A4(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A2u10A3u10A1u10A8u109Fu109Cu10A8u1099u109Du109Du10A4" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A2u10A3u10A1u10A8u109Fu109Cu10A8u1099u109Du109Du10A4->original(a, method);
}

auto HF_GameManager_Awake = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::Awake");
void Template_GameManager_Awake(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::Awake" << " a=" << a << ", " << std::endl;

	HF_GameManager_Awake->original(a, method);
}
*/
auto HF_GameManager_u10A4u10A1u1099u10A6u10A2u10A2u10A1u109Cu109Bu109Fu109B = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A4u10A1u1099u10A6u10A2u10A2u10A1u109Cu109Bu109Fu109B");
void Template_GameManager_u10A4u10A1u1099u10A6u10A2u10A2u10A1u109Cu109Bu109Fu109B(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A1u1099u10A6u10A2u10A2u10A1u109Cu109Bu109Fu109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A4u10A1u1099u10A6u10A2u10A2u10A1u109Cu109Bu109Fu109B->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u10A4u10A8u10A0u10A6u10A6u109Bu10A2u10A8u10A5u10A8u10A7 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A4u10A8u10A0u10A6u10A6u109Bu10A2u10A8u10A5u10A8u10A7");
void Template_GameManager_u10A4u10A8u10A0u10A6u10A6u109Bu10A2u10A8u10A5u10A8u10A7(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A8u10A0u10A6u10A6u109Bu10A2u10A8u10A5u10A8u10A7" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A4u10A8u10A0u10A6u10A6u109Bu10A2u10A8u10A5u10A8u10A7->original(a, b, method);
}

auto HF_GameManager_PhysicsObjectSnapshot = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::PhysicsObjectSnapshot");
void Template_GameManager_PhysicsObjectSnapshot(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::PhysicsObjectSnapshot" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_PhysicsObjectSnapshot->original(a, b, method);
}

auto HF_GameManager_u10A6u109Bu109Eu10A1u10A8u10A3u10A4u10A5u1099u10A3u10A8 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A6u109Bu109Eu10A1u10A8u10A3u10A4u10A5u1099u10A3u10A8");
void Template_GameManager_u10A6u109Bu109Eu10A1u10A8u10A3u10A4u10A5u1099u10A3u10A8(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u109Bu109Eu10A1u10A8u10A3u10A4u10A5u1099u10A3u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A6u109Bu109Eu10A1u10A8u10A3u10A4u10A5u1099u10A3u10A8->original(a, b, method);
}

auto HF_GameManager_u10A8u109Bu10A8u109Cu10A7u10A2u10A7u10A4u10A8u10A3u10A1 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A8u109Bu10A8u109Cu10A7u10A2u10A7u10A4u10A8u10A3u10A1");
void Template_GameManager_u10A8u109Bu10A8u109Cu10A7u10A2u10A7u10A4u10A8u10A3u10A1(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A8u109Bu10A8u109Cu10A7u10A2u10A7u10A4u10A8u10A3u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A8u109Bu10A8u109Cu10A7u10A2u10A7u10A4u10A8u10A3u10A1->original(a, b, method);
}

auto HF_GameManager_u10A6u10A1u109Au109Fu10A4u109Du10A5u10A4u109Du10A4u109B = new HookFunction<void, GameManager*, uint64_t, MethodInfo*>("GameManager::u10A6u10A1u109Au109Fu10A4u109Du10A5u10A4u109Du10A4u109B");
void Template_GameManager_u10A6u10A1u109Au109Fu10A4u109Du10A5u10A4u109Du10A4u109B(GameManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u10A1u109Au109Fu10A4u109Du10A5u10A4u109Du10A4u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A6u10A1u109Au109Fu10A4u109Du10A5u10A4u109Du10A4u109B->original(a, b, method);
}

auto HF_GameManager_u10A4u10A2u10A8u10A5u10A4u10A3u109Du109Cu10A8u109Eu10A5 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A4u10A2u10A8u10A5u10A4u10A3u109Du109Cu10A8u109Eu10A5");
void Template_GameManager_u10A4u10A2u10A8u10A5u10A4u10A3u109Du109Cu10A8u109Eu10A5(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A4u10A2u10A8u10A5u10A4u10A3u109Du109Cu10A8u109Eu10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A4u10A2u10A8u10A5u10A4u10A3u109Du109Cu10A8u109Eu10A5->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_PlayerDied = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::PlayerDied");
void Template_GameManager_PlayerDied(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_PlayerDied->original(a, b, c, d, method);
}

auto HF_GameManager_u10A0u10A7u109Cu109Eu10A1u10A3u10A4u109Cu109Du109Fu10A6 = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u10A0u10A7u109Cu109Eu10A1u10A3u10A4u109Cu109Du109Fu10A6");
void Template_GameManager_u10A0u10A7u109Cu109Eu10A1u10A3u10A4u109Cu109Du109Fu10A6(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u10A0u10A7u109Cu109Eu10A1u10A3u10A4u109Cu109Du109Fu10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u10A0u10A7u109Cu109Eu10A1u10A3u10A4u109Cu109Du109Fu10A6->original(a, b, c, d, method);
}

auto HF_GameManager_u109Eu1099u10A0u109Au10A3u10A4u10A5u109Fu10A8u10A1u109E = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Eu1099u10A0u109Au10A3u10A4u10A5u109Fu10A8u10A1u109E");
void Template_GameManager_u109Eu1099u10A0u109Au10A3u10A4u10A5u109Fu10A8u10A1u109E(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu1099u10A0u109Au10A3u10A4u10A5u109Fu10A8u10A1u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Eu1099u10A0u109Au10A3u10A4u10A5u109Fu10A8u10A1u109E->original(a, b, method);
}

auto HF_GameManager_u10A6u10A2u109Eu10A4u109Bu10A7u10A8u109Du109Cu10A5u10A4 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A6u10A2u109Eu10A4u109Bu10A7u10A8u109Du109Cu10A5u10A4");
void Template_GameManager_u10A6u10A2u109Eu10A4u109Bu10A7u10A8u109Du109Cu10A5u10A4(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u10A2u109Eu10A4u109Bu10A7u10A8u109Du109Cu10A5u10A4" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A6u10A2u109Eu10A4u109Bu10A7u10A8u109Du109Cu10A5u10A4->original(a, b, method);
}

auto HF_GameManager_u109Fu10A0u10A1u10A7u109Cu10A4u10A3u109Du10A1u10A1u10A2 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u109Fu10A0u10A1u10A7u109Cu10A4u10A3u109Du10A1u10A1u10A2");
void Template_GameManager_u109Fu10A0u10A1u10A7u109Cu10A4u10A3u109Du10A1u10A1u10A2(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u109Fu10A0u10A1u10A7u109Cu10A4u10A3u109Du10A1u10A1u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u109Fu10A0u10A1u10A7u109Cu10A4u10A3u109Du10A1u10A1u10A2->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u10A5u10A1u1099u109Du109Eu109Du10A5u10A0u10A2u10A1u10A3 = new HookFunction<void, GameManager*, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameManager::u10A5u10A1u1099u109Du109Eu109Du10A5u10A0u10A2u10A1u10A3");
void Template_GameManager_u10A5u10A1u1099u109Du109Eu109Du10A5u10A0u10A2u10A1u10A3(GameManager* a, uint64_t b, Vector3 c, int32_t d, bool e, Byte__Array* f, int32_t g, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u10A1u1099u109Du109Eu109Du10A5u10A0u10A2u10A1u10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	HF_GameManager_u10A5u10A1u1099u109Du109Eu109Du10A5u10A0u10A2u10A1u10A3->original(a, b, c, d, e, f, g, method);
}

auto HF_GameManager_u109Bu10A2u10A0u109Du109Du10A6u10A5u10A3u109Cu10A2u109A = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u109Bu10A2u10A0u109Du109Du10A6u10A5u10A3u109Cu10A2u109A");
IEnumerator* Template_GameManager_u109Bu10A2u10A0u109Du109Du10A6u10A5u10A3u109Cu10A2u109A(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u109Bu10A2u10A0u109Du109Du10A6u10A5u10A3u109Cu10A2u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u109Bu10A2u10A0u109Du109Du10A6u10A5u10A3u109Cu10A2u109A->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}
/*
auto HF_GameManager_u10A1u10A8u10A6u10A6u10A5u10A6u109Au10A8u109Au10A4u109B = new HookFunction<void, GameManager*, MethodInfo*>("GameManager::u10A1u10A8u10A6u10A6u10A5u10A6u109Au10A8u109Au10A4u109B");
void Template_GameManager_u10A1u10A8u10A6u10A6u10A5u10A6u109Au10A8u109Au10A4u109B(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A1u10A8u10A6u10A6u10A5u10A6u109Au10A8u109Au10A4u109B" << " a=" << a << ", " << std::endl;

	HF_GameManager_u10A1u10A8u10A6u10A6u10A5u10A6u109Au10A8u109Au10A4u109B->original(a, method);
}
*/
auto HF_GameManager_u10A5u10A5u1099u109Cu109Au10A0u10A6u109Fu10A6u109Au109A = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u10A5u10A5u1099u109Cu109Au10A0u10A6u109Fu10A6u109Au109A");
void Template_GameManager_u10A5u10A5u1099u109Cu109Au10A0u10A6u109Fu10A6u109Au109A(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u10A5u10A5u1099u109Cu109Au10A0u10A6u109Fu10A6u109Au109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u10A5u10A5u1099u109Cu109Au10A0u10A6u109Fu10A6u109Au109A->original(a, b, c, d, method);
}

auto HF_GameManager_u109Eu109Cu10A7u10A0u10A8u10A8u109Cu109Cu109Fu109Au109C = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Eu109Cu10A7u10A0u10A8u10A8u109Cu109Cu109Fu109Au109C");
void Template_GameManager_u109Eu109Cu10A7u10A0u10A8u10A8u109Cu109Cu109Fu109Au109C(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Eu109Cu10A7u10A0u10A8u10A8u109Cu109Cu109Fu109Au109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Eu109Cu10A7u10A0u10A8u10A8u109Cu109Cu109Fu109Au109C->original(a, b, method);
}

auto HF_GameManager_u10A7u109Cu10A8u10A1u109Bu10A0u109Fu10A1u10A6u10A3u10A5 = new HookFunction<void, GameManager*, uint64_t, uint64_t, Vector3, MethodInfo*>("GameManager::u10A7u109Cu10A8u10A1u109Bu10A0u109Fu10A1u10A6u10A3u10A5");
void Template_GameManager_u10A7u109Cu10A8u10A1u109Bu10A0u109Fu10A1u10A6u10A3u10A5(GameManager* a, uint64_t b, uint64_t c, Vector3 d, MethodInfo* method)
{
	std::cout << "GameManager::u10A7u109Cu10A8u10A1u109Bu10A0u109Fu10A1u10A6u10A3u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameManager_u10A7u109Cu10A8u10A1u109Bu10A0u109Fu10A1u10A6u10A3u10A5->original(a, b, c, d, method);
}
/*
auto HF_GameManager_u109Cu109Eu109Du10A5u10A4u109Cu109Du10A4u109Au10A0u10A4 = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u109Cu109Eu109Du10A5u10A4u109Cu109Du10A4u109Au10A0u10A4");
int32_t Template_GameManager_u109Cu109Eu109Du10A5u10A4u109Cu109Du10A4u109Au10A0u10A4(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Cu109Eu109Du10A5u10A4u109Cu109Du10A4u109Au10A0u10A4" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u109Cu109Eu109Du10A5u10A4u109Cu109Du10A4u109Au10A0u10A4->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/
auto HF_GameManager_u10A7u109Fu10A1u10A0u109Bu109Du109Au10A7u10A2u1099u10A8 = new HookFunction<IEnumerator*, GameManager*, PlayerManager*, float, MethodInfo*>("GameManager::u10A7u109Fu10A1u10A0u109Bu109Du109Au10A7u10A2u1099u10A8");
IEnumerator* Template_GameManager_u10A7u109Fu10A1u10A0u109Bu109Du109Au10A7u10A2u1099u10A8(GameManager* a, PlayerManager* b, float c, MethodInfo* method)
{
	std::cout << "GameManager::u10A7u109Fu10A1u10A0u109Bu109Du109Au10A7u10A2u1099u10A8" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameManager_u10A7u109Fu10A1u10A0u109Bu109Du109Au10A7u10A2u1099u10A8->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Du10A5u10A2u109Au1099u109Fu109Eu10A3u10A2u109Cu10A8 = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u109Du10A5u10A2u109Au1099u109Fu109Eu10A3u10A2u109Cu10A8");
void Template_GameManager_u109Du10A5u10A2u109Au1099u109Fu109Eu10A3u10A2u109Cu10A8(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u109Du10A5u10A2u109Au1099u109Fu109Eu10A3u10A2u109Cu10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Du10A5u10A2u109Au1099u109Fu109Eu10A3u10A2u109Cu10A8->original(a, b, method);
}

auto HF_GameManager_u10A6u10A7u10A4u109Eu109Bu10A7u10A2u10A4u10A5u1099u109A = new HookFunction<void, GameManager*, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("GameManager::u10A6u10A7u10A4u109Eu109Bu10A7u10A2u10A4u10A5u1099u109A");
void Template_GameManager_u10A6u10A7u10A4u109Eu109Bu10A7u10A2u10A4u10A5u1099u109A(GameManager* a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	std::cout << "GameManager::u10A6u10A7u10A4u109Eu109Bu10A7u10A2u10A4u10A5u1099u109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u10A6u10A7u10A4u109Eu109Bu10A7u10A2u10A4u10A5u1099u109A->original(a, b, method);
}
/*
auto HF_GameManager_u10A2u10A4u109Au109Au10A0u10A2u109Au109Eu10A2u1099u10A8 = new HookFunction<int32_t, GameManager*, MethodInfo*>("GameManager::u10A2u10A4u109Au109Au10A0u10A2u109Au109Eu10A2u1099u10A8");
int32_t Template_GameManager_u10A2u10A4u109Au109Au10A0u10A2u109Au109Eu10A2u1099u10A8(GameManager* a, MethodInfo* method)
{
	std::cout << "GameManager::u10A2u10A4u109Au109Au10A0u10A2u109Au109Eu10A2u1099u10A8" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u10A2u10A4u109Au109Au10A0u10A2u109Au109Eu10A2u1099u10A8->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C__ctor = new HookFunction<void, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, int32_t, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C__ctor");
void Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C__ctor(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, int32_t b, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C__ctor" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C__ctor->original(a, b, method);
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_IDisposable_Dispose = new HookFunction<void, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_IDisposable_Dispose");
void Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_IDisposable_Dispose(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_IDisposable_Dispose" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_IDisposable_Dispose->original(a, method);
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_MoveNext = new HookFunction<bool, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_MoveNext");
bool Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_MoveNext(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_MoveNext" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_MoveNext->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_Generic_IEnumerator_System_Object__get_Current = new HookFunction<Object*, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_Generic_IEnumerator_System_Object__get_Current");
Object* Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_Generic_IEnumerator_System_Object__get_Current(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_Generic_IEnumerator_System_Object__get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_Generic_IEnumerator_System_Object__get_Current->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_Reset = new HookFunction<void, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_Reset");
void Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_Reset(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_Reset" << " a=" << a << ", " << std::endl;

	HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_Reset->original(a, method);
}

auto HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_get_Current = new HookFunction<Object*, GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C*, MethodInfo*>("GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_get_Current");
Object* Template_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_get_Current(GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C* a, MethodInfo* method)
{
	std::cout << "GameManager::u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameManager_u109Au109Bu10A2u10A0u109Au10A5u109Fu10A3u10A8u109Eu109C_System_Collections_IEnumerator_get_Current->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}
*/