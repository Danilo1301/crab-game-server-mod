#pragma once

#include "Mod.h"
#include "Server.h"
#include "Injector.h"

auto HF_GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5");
void Template_GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5->original(a, method);
}

auto HF_GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8 = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8");
void Template_GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8->original(a, b, method);
}

auto HF_GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2");
IEnumerator* Template_GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_FindPlayersToKill = new HookFunction<int32_t, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::FindPlayersToKill");
int32_t Template_GameModeBlockDrop_FindPlayersToKill(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::FindPlayersToKill" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_FindPlayersToKill->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2");
IEnumerator* Template_GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8");
void Template_GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8->original(a, method);
}

auto HF_GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E");
void Template_GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E");
IEnumerator* Template_GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1");
void Template_GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1->original(a, method);
}

auto HF_GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0");
IEnumerator* Template_GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D");
void Template_GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D->original(a, method);
}

auto HF_GameModeBlockDrop_OnRoundOver = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::OnRoundOver");
void Template_GameModeBlockDrop_OnRoundOver(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::OnRoundOver" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_OnRoundOver->original(a, method);
}

auto HF_GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0");
void Template_GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0->original(a, method);
}

auto HF_GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F");
void Template_GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F->original(a, method);
}

auto HF_GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8");
void Template_GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8->original(a, method);
}

auto HF_GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6 = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6");
void Template_GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6->original(a, b, method);
}

auto HF_GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0");
void Template_GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0->original(a, method);
}

auto HF_GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E");
void Template_GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E->original(a, b, method);
}

auto HF_GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3");
IEnumerator* Template_GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B");
void Template_GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B->original(a, method);
}

auto HF_GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C");
void Template_GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C->original(a, method);
}

auto HF_GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D");
void Template_GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7");
void Template_GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8 = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8");
void Template_GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8->original(a, b, method);
}

auto HF_GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B");
void Template_GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B->original(a, b, method);
}

auto HF_GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099 = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099");
void Template_GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099->original(a, b, method);
}

auto HF_GameModeBlockDrop_OnFreezeOver = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::OnFreezeOver");
void Template_GameModeBlockDrop_OnFreezeOver(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::OnFreezeOver" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_OnFreezeOver->original(a, method);
}

auto HF_GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8");
void Template_GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8->original(a, method);
}

auto HF_GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5 = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5");
void Template_GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3");
void Template_GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3->original(a, method);
}

auto HF_GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B");
void Template_GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B->original(a, b, method);
}

auto HF_GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2 = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2");
void Template_GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B");
IEnumerator* Template_GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1 = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1");
void Template_GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B");
void Template_GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B->original(a, method);
}

auto HF_GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6");
void Template_GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6->original(a, method);
}

auto HF_GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B");
void Template_GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E");
void Template_GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E->original(a, b, method);
}

auto HF_GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D");
void Template_GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D->original(a, method);
}

auto HF_GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7");
void Template_GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0");
void Template_GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0->original(a, method);
}

auto HF_GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E");
void Template_GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E->original(a, method);
}

auto HF_GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3");
void Template_GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3->original(a, method);
}

auto HF_GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3 = new HookFunction<int32_t, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3");
int32_t Template_GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8");
void Template_GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8->original(a, method);
}

auto HF_GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B");
void Template_GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B->original(a, method);
}

auto HF_GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1");
void Template_GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1->original(a, method);
}

auto HF_GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6");
void Template_GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6->original(a, method);
}

auto HF_GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7");
void Template_GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A = new HookFunction<int32_t, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A");
int32_t Template_GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2");
IEnumerator* Template_GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E");
void Template_GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E->original(a, b, method);
}

auto HF_GameModeBlockDrop_PlayerDied = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::PlayerDied");
void Template_GameModeBlockDrop_PlayerDied(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_PlayerDied->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_InitMode = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::InitMode");
void Template_GameModeBlockDrop_InitMode(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::InitMode" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_InitMode->original(a, method);
}

auto HF_GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099");
void Template_GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099->original(a, method);
}

auto HF_GameModeBlockDrop_OnPlayerSpawnOrDespawn = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::OnPlayerSpawnOrDespawn");
void Template_GameModeBlockDrop_OnPlayerSpawnOrDespawn(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::OnPlayerSpawnOrDespawn" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_OnPlayerSpawnOrDespawn->original(a, b, method);
}

auto HF_GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D");
void Template_GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4");
void Template_GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4->original(a, method);
}

auto HF_GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099");
void Template_GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099->original(a, method);
}

auto HF_GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2 = new HookFunction<void, GameModeBlockDrop*, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2");
void Template_GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2(GameModeBlockDrop* a, uint64_t b, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2->original(a, b, method);
}

auto HF_GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B");
void Template_GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B->original(a, method);
}

auto HF_GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3");
void Template_GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3->original(a, method);
}

auto HF_GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2 = new HookFunction<int32_t, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2");
int32_t Template_GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099");
void Template_GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099->original(a, method);
}

auto HF_GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8");
void Template_GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8->original(a, method);
}

auto HF_GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6");
IEnumerator* Template_GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7");
void Template_GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F");
void Template_GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F->original(a, method);
}

auto HF_GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4 = new HookFunction<void, GameModeBlockDrop*, uint64_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4");
void Template_GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4(GameModeBlockDrop* a, uint64_t b, uint64_t c, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4->original(a, b, c, method);
}

auto HF_GameModeBlockDrop_InvokeSendFallingBlocks = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::InvokeSendFallingBlocks");
void Template_GameModeBlockDrop_InvokeSendFallingBlocks(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::InvokeSendFallingBlocks" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_InvokeSendFallingBlocks->original(a, method);
}

auto HF_GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7");
void Template_GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2");
void Template_GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2->original(a, method);
}

auto HF_GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5 = new HookFunction<int32_t, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5");
int32_t Template_GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3");
void Template_GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3->original(a, method);
}

auto HF_GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0 = new HookFunction<IEnumerator*, GameModeBlockDrop*, float, float, int32_t, uint64_t, MethodInfo*>("GameModeBlockDrop::u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0");
IEnumerator* Template_GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0(GameModeBlockDrop* a, float b, float c, int32_t d, uint64_t e, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E");
void Template_GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E->original(a, method);
}

auto HF_GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7 = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7");
void Template_GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7->original(a, method);
}

auto HF_GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E");
void Template_GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E->original(a, method);
}

auto HF_GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A = new HookFunction<void, GameModeBlockDrop*, MethodInfo*>("GameModeBlockDrop::u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A");
void Template_GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A(GameModeBlockDrop* a, MethodInfo* method)
{
	std::cout << "GameModeBlockDrop::u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A" << " a=" << a << ", " << std::endl;

	HF_GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A->original(a, method);
}

void Inject_GameModeBlockDrop()
{
	Injector::Inject(HF_GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5, GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5, &Template_GameModeBlockDrop_u109Au109Cu10A3u10A6u109Cu109Bu109Eu10A8u109Eu10A7u10A5);
	Injector::Inject(HF_GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8, GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8, &Template_GameModeBlockDrop_u109Du109Cu10A8u109Bu109Cu10A0u10A0u10A0u10A8u10A0u10A8);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2, GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2, &Template_GameModeBlockDrop_u109Bu10A8u10A0u10A2u10A4u10A8u109Cu10A1u10A0u109Cu10A2);
	Injector::Inject(HF_GameModeBlockDrop_FindPlayersToKill, GameModeBlockDrop_FindPlayersToKill, &Template_GameModeBlockDrop_FindPlayersToKill);
	Injector::Inject(HF_GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2, GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2, &Template_GameModeBlockDrop_u10A8u109Bu10A2u109Cu10A4u10A5u109Eu10A7u109Fu10A1u10A2);
	Injector::Inject(HF_GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8, GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8, &Template_GameModeBlockDrop_u10A7u10A1u109Du109Au10A0u10A8u10A6u10A0u10A2u10A7u10A8);
	Injector::Inject(HF_GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E, GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E, &Template_GameModeBlockDrop_u1099u109Fu10A4u10A5u10A7u109Du10A5u10A3u109Bu109Cu109E);
	Injector::Inject(HF_GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E, GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E, &Template_GameModeBlockDrop_u10A2u1099u109Du1099u10A5u109Du10A1u10A5u10A1u109Bu109E);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1, GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1, &Template_GameModeBlockDrop_u109Bu109Au10A5u10A0u10A2u10A8u10A6u109Eu109Cu10A3u10A1);
	Injector::Inject(HF_GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0, GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0, &Template_GameModeBlockDrop_u10A0u10A3u10A1u109Eu109Au10A0u109Au109Fu109Du10A1u10A0);
	Injector::Inject(HF_GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D, GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D, &Template_GameModeBlockDrop_u109Du109Eu109Cu10A8u10A3u1099u10A1u10A2u109Eu10A8u109D);
	Injector::Inject(HF_GameModeBlockDrop_OnRoundOver, GameModeBlockDrop_OnRoundOver, &Template_GameModeBlockDrop_OnRoundOver);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0, GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0, &Template_GameModeBlockDrop_u10A1u10A6u10A0u109Fu109Eu109Cu10A6u10A7u109Fu10A2u10A0);
	Injector::Inject(HF_GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F, GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F, &Template_GameModeBlockDrop_u109Eu10A1u10A2u109Cu10A8u109Fu10A5u109Au10A7u1099u109F);
	Injector::Inject(HF_GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8, GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8, &Template_GameModeBlockDrop_u109Cu109Au109Bu10A6u10A0u10A2u109Fu109Du10A0u10A5u10A8);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6, GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6, &Template_GameModeBlockDrop_u10A1u109Du10A3u10A0u109Eu10A0u10A2u109Cu10A1u10A3u10A6);
	Injector::Inject(HF_GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0, GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0, &Template_GameModeBlockDrop_u1099u10A1u109Cu109Eu10A4u109Cu10A0u109Cu10A0u10A8u10A0);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E, GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E, &Template_GameModeBlockDrop_u10A6u10A6u109Cu109Du10A5u1099u10A7u109Du109Du1099u109E);
	Injector::Inject(HF_GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3, GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3, &Template_GameModeBlockDrop_u10A5u109Eu10A6u10A7u1099u10A5u109Eu1099u109Fu109Du10A3);
	Injector::Inject(HF_GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B, GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B, &Template_GameModeBlockDrop_u109Du10A1u1099u1099u10A5u10A1u109Fu10A3u109Du10A7u109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C, GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C, &Template_GameModeBlockDrop_u10A6u10A5u10A2u10A8u10A3u10A5u10A7u10A2u10A8u10A2u109C);
	Injector::Inject(HF_GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D, GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D, &Template_GameModeBlockDrop_u10A5u10A0u10A4u10A7u10A5u1099u1099u10A8u10A6u1099u109D);
	Injector::Inject(HF_GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7, GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7, &Template_GameModeBlockDrop_u1099u1099u10A3u10A4u10A6u10A4u109Eu10A8u10A4u10A5u10A7);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8, GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8, &Template_GameModeBlockDrop_u10A6u10A6u109Eu10A1u10A4u10A4u10A4u109Fu1099u10A3u10A8);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B, GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B, &Template_GameModeBlockDrop_u109Fu10A4u10A0u10A5u1099u10A2u10A8u1099u10A2u10A5u109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099, GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099, &Template_GameModeBlockDrop_u10A4u10A2u109Cu109Fu10A8u109Du10A4u10A5u10A5u109Fu1099);
	Injector::Inject(HF_GameModeBlockDrop_OnFreezeOver, GameModeBlockDrop_OnFreezeOver, &Template_GameModeBlockDrop_OnFreezeOver);
	Injector::Inject(HF_GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8, GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8, &Template_GameModeBlockDrop_u109Du109Bu10A8u109Eu10A8u10A3u10A6u109Du109Eu10A7u10A8);
	Injector::Inject(HF_GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5, GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5, &Template_GameModeBlockDrop_u10A7u10A8u10A0u109Cu10A8u109Du109Du10A2u10A3u109Au10A5);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3, GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3, &Template_GameModeBlockDrop_u109Fu109Bu10A6u10A4u10A2u109Au109Cu10A6u109Fu10A1u10A3);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B, GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B, &Template_GameModeBlockDrop_u109Fu109Au109Du109Cu109Eu10A0u10A8u10A4u109Eu10A0u109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2, GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2, &Template_GameModeBlockDrop_u10A5u109Au109Du1099u10A3u10A7u109Bu1099u109Du10A8u10A2);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B, GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B, &Template_GameModeBlockDrop_u109Bu10A7u10A1u109Eu1099u10A4u10A8u1099u109Du109Du109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1, GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1, &Template_GameModeBlockDrop_u10A6u10A1u10A3u10A5u109Fu109Bu109Eu10A7u109Bu10A4u10A1);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B, GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B, &Template_GameModeBlockDrop_u10A6u1099u10A7u10A0u10A3u109Au10A6u109Du10A4u109Au109B);
	Injector::Inject(HF_GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6, GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6, &Template_GameModeBlockDrop_u1099u10A4u109Du10A2u10A5u10A5u109Bu109Eu109Fu10A3u10A6);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B, GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B, &Template_GameModeBlockDrop_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E, GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E, &Template_GameModeBlockDrop_u10A6u109Eu10A2u10A3u109Eu10A4u109Fu109Eu10A4u109Fu109E);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D, GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D, &Template_GameModeBlockDrop_u109Bu10A0u109Eu10A0u10A2u109Du109Eu109Du10A1u10A0u109D);
	Injector::Inject(HF_GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7, GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7, &Template_GameModeBlockDrop_u10A7u10A5u10A7u109Cu109Fu10A7u109Eu1099u10A0u10A0u10A7);
	Injector::Inject(HF_GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0, GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0, &Template_GameModeBlockDrop_u109Au10A4u10A2u10A8u109Cu109Du109Fu10A5u10A7u109Cu10A0);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E, GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E, &Template_GameModeBlockDrop_u10A1u10A3u109Fu10A7u10A6u109Au109Eu10A5u10A2u109Bu109E);
	Injector::Inject(HF_GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3, GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3, &Template_GameModeBlockDrop_u10A3u10A3u1099u109Bu10A0u109Au109Au10A1u10A0u109Fu10A3);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3, GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3, &Template_GameModeBlockDrop_u109Fu10A3u10A2u10A8u10A6u10A0u10A3u109Au10A5u109Du10A3);
	Injector::Inject(HF_GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8, GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8, &Template_GameModeBlockDrop_u10A5u109Du1099u10A8u109Cu10A1u109Du109Fu10A1u109Cu10A8);
	Injector::Inject(HF_GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B, GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B, &Template_GameModeBlockDrop_u1099u109Du109Bu109Bu10A3u10A2u109Cu10A0u10A2u109Fu109B);
	Injector::Inject(HF_GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1, GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1, &Template_GameModeBlockDrop_u109Au109Bu1099u10A8u10A3u10A5u10A5u10A4u109Fu10A3u10A1);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6, GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6, &Template_GameModeBlockDrop_u10A1u109Fu10A6u109Fu109Cu109Bu109Bu10A8u10A8u10A0u10A6);
	Injector::Inject(HF_GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7, GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7, &Template_GameModeBlockDrop_u109Au10A2u109Eu10A8u10A5u109Fu10A4u10A2u10A5u1099u10A7);
	Injector::Inject(HF_GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A, GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A, &Template_GameModeBlockDrop_u10A3u10A3u10A5u10A6u10A1u10A2u1099u109Du1099u10A4u109A);
	Injector::Inject(HF_GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2, GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2, &Template_GameModeBlockDrop_u10A0u10A8u10A2u10A0u10A6u10A2u10A0u10A2u10A1u10A8u10A2);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E, GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E, &Template_GameModeBlockDrop_u10A1u109Fu109Fu10A8u109Cu10A1u109Eu10A1u109Fu10A1u109E);
	Injector::Inject(HF_GameModeBlockDrop_PlayerDied, GameModeBlockDrop_PlayerDied, &Template_GameModeBlockDrop_PlayerDied);
	Injector::Inject(HF_GameModeBlockDrop_InitMode, GameModeBlockDrop_InitMode, &Template_GameModeBlockDrop_InitMode);
	Injector::Inject(HF_GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099, GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099, &Template_GameModeBlockDrop_u10A3u10A5u109Eu109Eu109Cu10A6u109Eu109Au109Eu10A4u1099);
	Injector::Inject(HF_GameModeBlockDrop_OnPlayerSpawnOrDespawn, GameModeBlockDrop_OnPlayerSpawnOrDespawn, &Template_GameModeBlockDrop_OnPlayerSpawnOrDespawn);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D, GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D, &Template_GameModeBlockDrop_u10A6u109Au109Eu10A2u10A6u109Eu10A6u109Bu10A4u109Du109D);
	Injector::Inject(HF_GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4, GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4, &Template_GameModeBlockDrop_u109Eu1099u109Fu109Eu1099u109Fu109Cu10A2u10A7u109Bu10A4);
	Injector::Inject(HF_GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099, GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099, &Template_GameModeBlockDrop_u109Au109Fu10A6u10A8u109Au10A8u109Eu10A4u109Fu10A5u1099);
	Injector::Inject(HF_GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2, GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2, &Template_GameModeBlockDrop_u109Eu10A4u109Bu109Eu1099u10A5u10A1u10A6u10A0u109Du10A2);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B, GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B, &Template_GameModeBlockDrop_u109Fu10A7u10A6u1099u109Au10A7u109Fu10A2u10A1u109Au109B);
	Injector::Inject(HF_GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3, GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3, &Template_GameModeBlockDrop_u10A8u10A3u10A7u109Du10A8u10A2u10A5u109Bu109Du10A2u10A3);
	Injector::Inject(HF_GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2, GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2, &Template_GameModeBlockDrop_u10A7u10A2u10A4u109Bu10A0u1099u109Bu10A4u109Bu109Fu10A2);
	Injector::Inject(HF_GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099, GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099, &Template_GameModeBlockDrop_u10A3u10A0u10A3u109Fu10A6u10A2u109Du10A3u10A8u10A3u1099);
	Injector::Inject(HF_GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8, GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8, &Template_GameModeBlockDrop_u10A1u10A7u109Eu10A5u109Cu10A1u10A4u10A2u10A7u109Au10A8);
	Injector::Inject(HF_GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6, GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6, &Template_GameModeBlockDrop_u109Eu109Fu10A6u1099u109Du109Au10A5u109Au10A6u10A2u10A6);
	Injector::Inject(HF_GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7, GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7, &Template_GameModeBlockDrop_u109Au10A6u109Fu1099u109Fu109Du10A1u10A8u10A2u109Eu10A7);
	Injector::Inject(HF_GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F, GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F, &Template_GameModeBlockDrop_u10A4u10A5u109Cu109Cu109Bu109Du10A5u10A4u109Au109Cu109F);
	Injector::Inject(HF_GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4, GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4, &Template_GameModeBlockDrop_u109Fu109Du10A1u10A8u10A4u10A7u109Fu10A5u109Eu10A2u10A4);
	Injector::Inject(HF_GameModeBlockDrop_InvokeSendFallingBlocks, GameModeBlockDrop_InvokeSendFallingBlocks, &Template_GameModeBlockDrop_InvokeSendFallingBlocks);
	Injector::Inject(HF_GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7, GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7, &Template_GameModeBlockDrop_u10A4u10A8u10A0u109Bu10A4u10A5u109Eu10A5u10A3u109Cu10A7);
	Injector::Inject(HF_GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2, GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2, &Template_GameModeBlockDrop_u1099u10A7u109Bu1099u10A4u10A0u10A0u10A8u10A6u10A7u10A2);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5, GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5, &Template_GameModeBlockDrop_u109Bu10A5u1099u10A1u10A0u10A7u10A3u10A3u109Cu10A2u10A5);
	Injector::Inject(HF_GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3, GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3, &Template_GameModeBlockDrop_u10A6u109Fu10A7u10A8u1099u10A3u1099u10A4u10A3u109Bu10A3);
	Injector::Inject(HF_GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0, GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0, &Template_GameModeBlockDrop_u10A8u10A4u10A4u10A8u109Cu10A2u109Au109Bu109Cu109Fu10A0);
	Injector::Inject(HF_GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E, GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E, &Template_GameModeBlockDrop_u109Bu109Fu10A3u10A7u10A8u10A0u10A4u10A4u10A6u1099u109E);
	Injector::Inject(HF_GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7, GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7, &Template_GameModeBlockDrop_u10A8u109Eu10A8u10A0u10A4u10A4u10A3u10A4u10A2u10A4u10A7);
	Injector::Inject(HF_GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E, GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E, &Template_GameModeBlockDrop_u109Eu10A3u1099u109Eu10A0u10A3u109Bu10A3u10A1u109Du109E);
	Injector::Inject(HF_GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A, GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A, &Template_GameModeBlockDrop_u109Cu1099u10A3u10A7u1099u10A0u109Bu109Eu109Au109Fu109A);
}