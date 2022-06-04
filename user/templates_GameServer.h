#pragma once

#include "Injector.h"
#include "Server.h"
#include "Chat.h"

auto HF_GameServer_CooldownChat = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::CooldownChat");
IEnumerator* Template_GameServer_CooldownChat(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownChat" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_CooldownChat->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_CooldownClientChat = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::CooldownClientChat");
void Template_GameServer_CooldownClientChat(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownClientChat" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_CooldownClientChat->original(a, b, c, method);
}

auto HF_GameServer_ForceRemoveItemItemId = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::ForceRemoveItemItemId");
void Template_GameServer_ForceRemoveItemItemId(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveItemItemId" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_ForceRemoveItemItemId->original(a, b, method);
}

auto HF_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6");
void Template_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6->original(a, b, c, d, method);
}

auto HF_GameServer_ForceGiveWeapon = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::ForceGiveWeapon");
void Template_GameServer_ForceGiveWeapon(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::ForceGiveWeapon" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_ForceGiveWeapon->original(a, b, c, method);
}

auto HF_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F");
void Template_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F->original(a, b, c, method);
}

auto HF_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D");
void Template_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D->original(a, b, method);
}

auto HF_GameServer_SnowballHit = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::SnowballHit");
void Template_GameServer_SnowballHit(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::SnowballHit" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d.toString() << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_SnowballHit->original(a, b, c, d, e, f, method);
}

auto HF_GameServer_CooldownPunch = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::CooldownPunch");
IEnumerator* Template_GameServer_CooldownPunch(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownPunch" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_CooldownPunch->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2 = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2");
void Template_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2->original(a, b, c, method);
}

auto HF_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5");
void Template_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5->original(a, b, c, d, method);
}

auto HF_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6 = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6");
void Template_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6->original(a, b, c, method);
}

auto HF_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2 = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2");
void Template_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2->original(a, b, c, method);
}

auto HF_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A");
void Template_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d.toString() << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A->original(a, b, c, d, e, f, method);
}

auto HF_GameServer_ForceRemoveItem = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::ForceRemoveItem");
void Template_GameServer_ForceRemoveItem(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveItem" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_ForceRemoveItem->original(a, b, method);
}

auto HF_GameServer_CheckHit = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::CheckHit");
void Template_GameServer_CheckHit(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::CheckHit" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_CheckHit->original(a, b, c, method);
}

auto HF_GameServer_PlayerDied = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::PlayerDied");
void Template_GameServer_PlayerDied(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_PlayerDied->original(a, b, c, method);
}

auto HF_GameServer_ChatCooldown = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::ChatCooldown");
void Template_GameServer_ChatCooldown(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::ChatCooldown" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_ChatCooldown->original(a, b, c, method);
}

auto HF_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6");
void Template_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6->original(a, b, c, method);
}

auto HF_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B");
void Template_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B->original(a, b, c, method);
}

auto HF_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8 = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8");
void Template_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8->original(a, method);
}

auto HF_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5");
void Template_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5->original(a, b, c, method);
}

auto HF_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4 = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4");
void Template_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4->original(a, b, c, method);
}

auto HF_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7");
void Template_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7->original(a, b, c, method);
}

auto HF_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E");
void Template_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d.toString() << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E->original(a, b, c, d, e, f, method);
}

auto HF_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2");
void Template_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2->original(a, b, c, d, method);
}

auto HF_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2 = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2");
void Template_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d.toString() << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2->original(a, b, c, d, e, f, method);
}

auto HF_GameServer_PunchCooldown = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::PunchCooldown");
void Template_GameServer_PunchCooldown(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::PunchCooldown" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_PunchCooldown->original(a, b, c, method);
}

auto HF_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5 = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5");
IEnumerator* Template_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6 = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6");
void Template_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6->original(a, method);
}

auto HF_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C");
void Template_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C->original(a, b, method);
}

auto HF_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D");
IEnumerator* Template_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099");
void Template_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099->original(a, b, c, method);
}

auto HF_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B");
void Template_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B->original(a, b, c, method);
}

auto HF_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4 = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4");
IEnumerator* Template_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099 = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099");
void Template_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099->original(a, b, c, method);
}

auto HF_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2");
void Template_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c.toString() << ", " << std::endl;

	HF_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2->original(a, b, c, method);
}

auto HF_GameServer_CheckPush = new HookFunction<void, PlayerManager*, PlayerManager*, MethodInfo*>("GameServer::CheckPush");
void Template_GameServer_CheckPush(PlayerManager* a, PlayerManager* b, MethodInfo* method)
{
	std::cout << "GameServer::CheckPush" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_CheckPush->original(a, b, method);
}

auto HF_GameServer_ForceRemoveAllWeapons = new HookFunction<void, MethodInfo*>("GameServer::ForceRemoveAllWeapons");
void Template_GameServer_ForceRemoveAllWeapons(MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveAllWeapons" << std::endl;

	HF_GameServer_ForceRemoveAllWeapons->original(method);
}

auto HF_GameServer_QueueRespawn = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::QueueRespawn");
void Template_GameServer_QueueRespawn(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::QueueRespawn" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_QueueRespawn->original(a, b, c, method);
}

auto HF_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1 = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1");
void Template_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1->original(a, b, c, method);
}

auto HF_GameServer_ForceGiveAllWeapon = new HookFunction<void, int32_t, MethodInfo*>("GameServer::ForceGiveAllWeapon");
void Template_GameServer_ForceGiveAllWeapon(int32_t a, MethodInfo* method)
{
	std::cout << "GameServer::ForceGiveAllWeapon" << " a=" << a << ", " << std::endl;

	HF_GameServer_ForceGiveAllWeapon->original(a, method);
}

auto HF_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F");
void Template_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F->original(a, b, c, method);
}

auto HF_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A");
void Template_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A->original(a, b, c, method);
}

auto HF_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4 = new HookFunction<void, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4");
void Template_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4->original(a, b, c, method);
}

auto HF_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E");
IEnumerator* Template_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A");
IEnumerator* Template_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3 = new HookFunction<void, int32_t, MethodInfo*>("GameServer::u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3");
void Template_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3(int32_t a, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3->original(a, method);
}

auto HF_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099 = new HookFunction<IEnumerator*, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099");
IEnumerator* Template_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099->original(a, b, c, method);

	return ret;
}

auto HF_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D");
void Template_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D->original(a, b, c, method);
}

auto HF_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E");
void Template_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E->original(a, b, c, method);
}

auto HF_GameServer_PlayerSpawnRequest = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::PlayerSpawnRequest");
void Template_GameServer_PlayerSpawnRequest(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::PlayerSpawnRequest" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_PlayerSpawnRequest->original(a, b, c, d, method);
}

auto HF_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3");
void Template_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3->original(a, b, c, method);
}

auto HF_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D = new HookFunction<IEnumerator*, GameServer*, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4*, float, MethodInfo*>("GameServer::u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D");
IEnumerator* Template_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D(GameServer* a, u1099u10A6u109Fu10A8u109Cu10A6u10A8u10A7u109Bu1099u10A4* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D->original(a, b, c, method);

	return ret;
}