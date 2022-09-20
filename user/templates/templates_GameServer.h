#pragma once

#include "pch.h"
#include "Injector.h"

/*
INPUT

DO_APP_FUNC(0x0126A580, IEnumerator *, GameServer_CooldownChat, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x01269F00, void, GameServer_Awake, (GameServer * __this, MethodInfo * method));
DO_APP_FUNC(0x0126A010, void, GameServer_CooldownClientChat, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126AE60, void, GameServer_ForceRemoveItemItemId, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, MethodInfo * method));
DO_APP_FUNC(0x0126EB90, void, GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, bool u10A6u10A5u10A3u109Bu10A2u10A2u10A3u10A3u109Cu10A0u10A4, Byte__Array * u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, int32_t u10A1u10A6u1099u1099u109Cu10A6u109Au10A6u1099u10A5u10A6, MethodInfo * method));
DO_APP_FUNC(0x0126A970, void, GameServer_ForceGiveWeapon, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126B9D0, void, GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126D350, void, GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126BA90, void, GameServer_SnowballHit, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u1099u10A1u109Au109Au10A6u109Eu10A6u10A2u10A2u10A8u10A0, int32_t u109Bu10A2u109Bu10A2u10A0u109Au10A8u109Fu1099u10A2u10A0, Vector3 u109Eu10A4u10A5u10A0u10A3u10A2u10A0u10A6u109Du1099u10A5, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126A600, IEnumerator *, GameServer_CooldownPunch, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126E940, void, GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126C5A0, void, GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, bool u10A6u10A5u10A3u109Bu10A2u10A2u10A3u10A3u109Cu10A0u10A4, Byte__Array * u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, int32_t u10A1u10A6u1099u1099u109Cu10A6u109Au10A6u1099u10A5u10A6, MethodInfo * method));
DO_APP_FUNC(0x0126CE20, void, GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126E540, void, GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126DB00, void, GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u1099u10A1u109Au109Au10A6u109Eu10A6u10A2u10A2u10A8u10A0, int32_t u109Bu10A2u109Bu10A2u10A0u109Au10A8u109Fu1099u10A2u10A0, Vector3 u109Eu10A4u10A5u10A0u10A3u10A2u10A0u10A6u109Du1099u10A5, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126B210, void, GameServer_ForceRemoveItem, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126A040, void, GameServer_CheckHit, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126B2E0, void, GameServer_PlayerDied, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126A010, void, GameServer_ChatCooldown, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126C850, void, GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126E5E0, void, GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126CE50, void, GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8, (GameServer * __this, MethodInfo * method));
DO_APP_FUNC(0x00264FC0, void, GameServer__ctor, (GameServer * __this, MethodInfo * method));
DO_APP_FUNC(0x0126FC90, void, GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126DE80, void, GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126F250, void, GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126CB30, void, GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u1099u10A1u109Au109Au10A6u109Eu10A6u10A2u10A2u10A8u10A0, int32_t u109Bu10A2u109Bu10A2u10A0u109Au10A8u109Fu1099u10A2u10A0, Vector3 u109Eu10A4u10A5u10A0u10A3u10A2u10A0u10A6u109Du1099u10A5, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126E310, void, GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, bool u10A6u10A5u10A3u109Bu10A2u10A2u10A3u10A3u109Cu10A0u10A4, Byte__Array * u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, int32_t u10A1u10A6u1099u1099u109Cu10A6u109Au10A6u1099u10A5u10A6, MethodInfo * method));
DO_APP_FUNC(0x0126C2B0, void, GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u1099u10A1u109Au109Au10A6u109Eu10A6u10A2u10A2u10A8u10A0, int32_t u109Bu10A2u109Bu10A2u10A0u109Au10A8u109Fu1099u10A2u10A0, Vector3 u109Eu10A4u10A5u10A0u10A3u10A2u10A0u10A6u109Du1099u10A5, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126B9D0, void, GameServer_PunchCooldown, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126EB00, IEnumerator *, GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126BEC0, void, GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6, (GameServer * __this, MethodInfo * method));
DO_APP_FUNC(0x0126BDF0, void, GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126DDF0, IEnumerator *, GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126BFD0, void, GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126EF70, void, GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126BD60, IEnumerator *, GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126BA00, void, GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099, (GameServer * __this, uint64_t u10A7u10A4u109Bu109Fu109Bu10A2u109Eu109Cu10A2u109Cu109E, float u10A0u10A7u10A2u109Eu109Du10A7u10A2u1099u109Fu10A7u109D, MethodInfo * method));
DO_APP_FUNC(0x0126CF60, void, GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u10A0u109Du109Du10A1u10A6u10A7u10A1u10A0u10A5u109Au1099, Vector3 u10A5u10A6u10A1u10A0u109Bu109Bu109Bu109Eu109Cu109Fu10A6, MethodInfo * method));
DO_APP_FUNC(0x0126A430, void, GameServer_CheckPush, (PlayerManager * u10A4u10A2u10A6u10A7u109Cu10A1u10A0u10A5u10A2u10A6u109C, PlayerManager * u109Eu109Bu10A6u10A6u10A3u10A0u109Cu10A2u10A2u109Fu109F, MethodInfo * method));
DO_APP_FUNC(0x0126AB40, void, GameServer_ForceRemoveAllWeapons, (MethodInfo * method));
DO_APP_FUNC(0x0126BA00, void, GameServer_QueueRespawn, (GameServer * __this, uint64_t u10A7u10A4u109Bu109Fu109Bu10A2u109Eu109Cu10A2u109Cu109E, float u10A0u10A7u10A2u109Eu109Du10A7u10A2u1099u109Fu10A7u109D, MethodInfo * method));
DO_APP_FUNC(0x0126CE20, void, GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126A680, void, GameServer_ForceGiveAllWeapon, (int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, MethodInfo * method));
DO_APP_FUNC(0x0126BA00, void, GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F, (GameServer * __this, uint64_t u10A7u10A4u109Bu109Fu109Bu10A2u109Eu109Cu10A2u109Cu109E, float u10A0u10A7u10A2u109Eu109Du10A7u10A2u1099u109Fu10A7u109D, MethodInfo * method));
DO_APP_FUNC(0x0126F640, void, GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126FBF0, void, GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126C7C0, IEnumerator *, GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126D2D0, IEnumerator *, GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0126D810, void, GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3, (int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, MethodInfo * method));
DO_APP_FUNC(0x0126E8C0, IEnumerator *, GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099, (GameServer * __this, uint64_t u10A7u10A4u109Bu109Fu109Bu10A2u109Eu109Cu10A2u109Cu109E, float u10A0u10A7u10A2u109Eu109Du10A7u10A2u1099u109Fu10A7u109D, MethodInfo * method));
DO_APP_FUNC(0x0126FA30, void, GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D, (uint64_t u109Cu10A5u109Bu1099u1099u109Bu10A7u1099u109Du10A4u10A8, int32_t u109Du109Du10A6u10A4u10A7u10A0u109Du109Cu109Au10A3u10A1, int32_t u109Fu10A3u109Au109Du10A1u10A3u109Cu10A2u10A5u10A1u109C, MethodInfo * method));
DO_APP_FUNC(0x0126DF20, void, GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126B5C0, void, GameServer_PlayerSpawnRequest, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, bool u10A6u10A5u10A3u109Bu10A2u10A2u10A3u10A3u109Cu10A0u10A4, Byte__Array * u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, int32_t u10A1u10A6u1099u1099u109Cu10A6u109Au10A6u1099u10A5u10A6, MethodInfo * method));
DO_APP_FUNC(0x0126D420, void, GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3, (uint64_t u1099u10A8u109Du10A8u10A0u109Eu10A1u10A1u10A8u10A1u10A7, uint64_t u109Fu109Bu10A4u109Du10A3u109Fu109Bu10A3u10A1u10A5u10A0, int32_t u10A6u10A3u109Bu10A0u109Du10A8u109Eu109Cu10A4u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x0126D240, IEnumerator *, GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D, (GameServer * __this, Client * u109Fu10A3u10A7u10A7u10A8u109Du10A1u10A5u109Eu10A0u109F, float u109Fu109Du10A6u1099u10A1u10A5u109Bu10A6u109Eu10A5u10A8, MethodInfo * method));
DO_APP_FUNC(0x0028FA90, void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, int32_t __1__state, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, MethodInfo * method));
DO_APP_FUNC(0x00F799F0, bool, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, MethodInfo * method));
DO_APP_FUNC(0x00F79D50, void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current, (GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E * __this, MethodInfo * method));
DO_APP_FUNC(0x0028FA90, void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, int32_t __1__state, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, MethodInfo * method));
DO_APP_FUNC(0x00F80220, bool, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, MethodInfo * method));
DO_APP_FUNC(0x00F802D0, void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current, (GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099 * __this, MethodInfo * method));
DO_APP_FUNC(0x0028FA90, void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, int32_t __1__state, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, MethodInfo * method));
DO_APP_FUNC(0x00F83E70, bool, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, MethodInfo * method));
DO_APP_FUNC(0x00F83F20, void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, Object *, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current, (GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3 * __this, MethodInfo * method));
*/

static auto HF_GameServer_CooldownChat = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::CooldownChat");
static IEnumerator* Template_GameServer_CooldownChat(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownChat" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_CooldownChat->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_Awake = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::Awake");
static void Template_GameServer_Awake(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::Awake" << " a=" << a << ", " << std::endl;

	HF_GameServer_Awake->original(a, method);
}

static auto HF_GameServer_CooldownClientChat = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::CooldownClientChat");
static void Template_GameServer_CooldownClientChat(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownClientChat" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_CooldownClientChat->original(a, b, c, method);
}

static auto HF_GameServer_ForceRemoveItemItemId = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::ForceRemoveItemItemId");
static void Template_GameServer_ForceRemoveItemItemId(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveItemItemId" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_ForceRemoveItemItemId->original(a, b, method);
}

static auto HF_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6");
static void Template_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6->original(a, b, c, d, method);
}

static auto HF_GameServer_ForceGiveWeapon = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::ForceGiveWeapon");
static void Template_GameServer_ForceGiveWeapon(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::ForceGiveWeapon" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_ForceGiveWeapon->original(a, b, c, method);
}

static auto HF_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F");
static void Template_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D");
static void Template_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D->original(a, b, method);
}

static auto HF_GameServer_SnowballHit = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::SnowballHit");
static void Template_GameServer_SnowballHit(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::SnowballHit" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_SnowballHit->original(a, b, c, d, e, f, method);
}

static auto HF_GameServer_CooldownPunch = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::CooldownPunch");
static IEnumerator* Template_GameServer_CooldownPunch(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::CooldownPunch" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_CooldownPunch->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2 = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2");
static void Template_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2->original(a, b, c, method);
}

static auto HF_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5");
static void Template_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5->original(a, b, c, d, method);
}

static auto HF_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6 = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6");
static void Template_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6->original(a, b, c, method);
}

static auto HF_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2 = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2");
static void Template_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2->original(a, b, c, method);
}

static auto HF_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A");
static void Template_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A->original(a, b, c, d, e, f, method);
}

static auto HF_GameServer_ForceRemoveItem = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::ForceRemoveItem");
static void Template_GameServer_ForceRemoveItem(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveItem" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_ForceRemoveItem->original(a, b, method);
}

static auto HF_GameServer_CheckHit = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::CheckHit");
static void Template_GameServer_CheckHit(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::CheckHit" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_CheckHit->original(a, b, c, method);
}

static auto HF_GameServer_PlayerDied = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::PlayerDied");
static void Template_GameServer_PlayerDied(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_PlayerDied->original(a, b, c, method);
}

static auto HF_GameServer_ChatCooldown = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::ChatCooldown");
static void Template_GameServer_ChatCooldown(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::ChatCooldown" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_ChatCooldown->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6");
static void Template_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6->original(a, b, c, method);
}

static auto HF_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B");
static void Template_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8 = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8");
static void Template_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8->original(a, method);
}

static auto HF_GameServer__ctor = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::_ctor");
static void Template_GameServer__ctor(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::_ctor" << " a=" << a << ", " << std::endl;

	HF_GameServer__ctor->original(a, method);
}

static auto HF_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5");
static void Template_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5->original(a, b, c, method);
}

static auto HF_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4 = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4");
static void Template_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4->original(a, b, c, method);
}

static auto HF_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7");
static void Template_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E");
static void Template_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E->original(a, b, c, d, e, f, method);
}

static auto HF_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2 = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2");
static void Template_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2->original(a, b, c, d, method);
}

static auto HF_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2 = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, int32_t, MethodInfo*>("GameServer::u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2");
static void Template_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, int32_t f, MethodInfo* method)
{
	std::cout << "GameServer::u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	HF_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2->original(a, b, c, d, e, f, method);
}

static auto HF_GameServer_PunchCooldown = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::PunchCooldown");
static void Template_GameServer_PunchCooldown(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::PunchCooldown" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_PunchCooldown->original(a, b, c, method);
}

static auto HF_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5 = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5");
static IEnumerator* Template_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6 = new HookFunction<void, GameServer*, MethodInfo*>("GameServer::u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6");
static void Template_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6(GameServer* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6->original(a, method);
}

static auto HF_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C = new HookFunction<void, uint64_t, int32_t, MethodInfo*>("GameServer::u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C");
static void Template_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C(uint64_t a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C->original(a, b, method);
}

static auto HF_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D");
static IEnumerator* Template_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099");
static void Template_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099->original(a, b, c, method);
}

static auto HF_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B");
static void Template_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B->original(a, b, c, method);
}

static auto HF_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4 = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4");
static IEnumerator* Template_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099 = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099");
static void Template_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2 = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("GameServer::u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2");
static void Template_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2(uint64_t a, uint64_t b, Vector3 c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2->original(a, b, c, method);
}

static auto HF_GameServer_CheckPush = new HookFunction<void, PlayerManager*, PlayerManager*, MethodInfo*>("GameServer::CheckPush");
static void Template_GameServer_CheckPush(PlayerManager* a, PlayerManager* b, MethodInfo* method)
{
	std::cout << "GameServer::CheckPush" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_CheckPush->original(a, b, method);
}

static auto HF_GameServer_ForceRemoveAllWeapons = new HookFunction<void, MethodInfo*>("GameServer::ForceRemoveAllWeapons");
static void Template_GameServer_ForceRemoveAllWeapons(MethodInfo* method)
{
	std::cout << "GameServer::ForceRemoveAllWeapons" << std::endl;

	HF_GameServer_ForceRemoveAllWeapons->original(method);
}

static auto HF_GameServer_QueueRespawn = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::QueueRespawn");
static void Template_GameServer_QueueRespawn(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::QueueRespawn" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_QueueRespawn->original(a, b, c, method);
}

static auto HF_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1 = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1");
static void Template_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1->original(a, b, c, method);
}

static auto HF_GameServer_ForceGiveAllWeapon = new HookFunction<void, int32_t, MethodInfo*>("GameServer::ForceGiveAllWeapon");
static void Template_GameServer_ForceGiveAllWeapon(int32_t a, MethodInfo* method)
{
	std::cout << "GameServer::ForceGiveAllWeapon" << " a=" << a << ", " << std::endl;

	HF_GameServer_ForceGiveAllWeapon->original(a, method);
}

static auto HF_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F = new HookFunction<void, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F");
static void Template_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F->original(a, b, c, method);
}

static auto HF_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A");
static void Template_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A->original(a, b, c, method);
}

static auto HF_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4 = new HookFunction<void, GameServer*, Client*, float, MethodInfo*>("GameServer::u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4");
static void Template_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4->original(a, b, c, method);
}

static auto HF_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E");
static IEnumerator* Template_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A");
static IEnumerator* Template_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3 = new HookFunction<void, int32_t, MethodInfo*>("GameServer::u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3");
static void Template_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3(int32_t a, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3->original(a, method);
}

static auto HF_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099 = new HookFunction<IEnumerator*, GameServer*, uint64_t, float, MethodInfo*>("GameServer::u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099");
static IEnumerator* Template_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099(GameServer* a, uint64_t b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D = new HookFunction<void, uint64_t, int32_t, int32_t, MethodInfo*>("GameServer::u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D");
static void Template_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D(uint64_t a, int32_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D->original(a, b, c, method);
}

static auto HF_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E");
static void Template_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E->original(a, b, c, method);
}

static auto HF_GameServer_PlayerSpawnRequest = new HookFunction<void, uint64_t, bool, Byte__Array*, int32_t, MethodInfo*>("GameServer::PlayerSpawnRequest");
static void Template_GameServer_PlayerSpawnRequest(uint64_t a, bool b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "GameServer::PlayerSpawnRequest" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_GameServer_PlayerSpawnRequest->original(a, b, c, d, method);
}

static auto HF_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3 = new HookFunction<void, uint64_t, uint64_t, int32_t, MethodInfo*>("GameServer::u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3");
static void Template_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3(uint64_t a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "GameServer::u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3->original(a, b, c, method);
}

static auto HF_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D = new HookFunction<IEnumerator*, GameServer*, Client*, float, MethodInfo*>("GameServer::u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D");
static IEnumerator* Template_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D(GameServer* a, Client* b, float c, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D->original(a, b, c, method);

	return ret;
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor = new HookFunction<void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, int32_t, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor");
static void Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor->original(a, b, method);
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose = new HookFunction<void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose");
static void Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose->original(a, method);
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext = new HookFunction<bool, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext");
static bool Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext->original(a, method);

	return ret;
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current = new HookFunction<Object*, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current");
static Object* Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current->original(a, method);

	return ret;
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset = new HookFunction<void, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset");
static void Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset" << " a=" << a << ", " << std::endl;

	HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset->original(a, method);
}

static auto HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current = new HookFunction<Object*, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E*, MethodInfo*>("GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current");
static Object* Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current(GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E* a, MethodInfo* method)
{
	std::cout << "GameServer::u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor = new HookFunction<void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, int32_t, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor");
static void Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor->original(a, b, method);
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose = new HookFunction<void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose");
static void Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose->original(a, method);
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext = new HookFunction<bool, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext");
static bool Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current = new HookFunction<Object*, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current");
static Object* Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset = new HookFunction<void, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset");
static void Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset->original(a, method);
}

static auto HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current = new HookFunction<Object*, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099*, MethodInfo*>("GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current");
static Object* Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current(GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor = new HookFunction<void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, int32_t, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor");
static void Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, int32_t b, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor->original(a, b, method);
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose = new HookFunction<void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose");
static void Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose->original(a, method);
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext = new HookFunction<bool, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext");
static bool Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current = new HookFunction<Object*, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current");
static Object* Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current->original(a, method);

	return ret;
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset = new HookFunction<void, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset");
static void Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset" << " a=" << a << ", " << std::endl;

	HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset->original(a, method);
}

static auto HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current = new HookFunction<Object*, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3*, MethodInfo*>("GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current");
static Object* Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current(GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3* a, MethodInfo* method)
{
	std::cout << "GameServer::u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current" << " a=" << a << ", " << std::endl;

	auto ret = HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current->original(a, method);

	return ret;
}

static void Inject_Templates_GameServer()
{
	if (!Mod::LoadAllTemplates)
	{
		return;
	}

	/*
	Injector::Inject(HF_GameServer_CooldownChat, GameServer_CooldownChat, &Template_GameServer_CooldownChat);
	Injector::Inject(HF_GameServer_Awake, GameServer_Awake, &Template_GameServer_Awake);
	Injector::Inject(HF_GameServer_CooldownClientChat, GameServer_CooldownClientChat, &Template_GameServer_CooldownClientChat);
	Injector::Inject(HF_GameServer_ForceRemoveItemItemId, GameServer_ForceRemoveItemItemId, &Template_GameServer_ForceRemoveItemItemId);
	Injector::Inject(HF_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6, GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6, &Template_GameServer_u10A5u10A3u10A6u109Eu10A0u109Cu109Bu10A0u109Au10A4u10A6);
	Injector::Inject(HF_GameServer_ForceGiveWeapon, GameServer_ForceGiveWeapon, &Template_GameServer_ForceGiveWeapon);
	Injector::Inject(HF_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F, GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F, &Template_GameServer_u10A0u10A0u10A3u109Du109Du10A5u10A5u10A6u109Au10A4u109F);
	Injector::Inject(HF_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D, GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D, &Template_GameServer_u109Fu10A6u109Du109Bu10A3u109Au109Bu109Au1099u10A2u109D);
	Injector::Inject(HF_GameServer_SnowballHit, GameServer_SnowballHit, &Template_GameServer_SnowballHit);
	Injector::Inject(HF_GameServer_CooldownPunch, GameServer_CooldownPunch, &Template_GameServer_CooldownPunch);
	Injector::Inject(HF_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2, GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2, &Template_GameServer_u10A5u109Eu109Cu109Cu109Eu109Au10A5u10A7u10A0u109Eu10A2);
	Injector::Inject(HF_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5, GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5, &Template_GameServer_u109Eu109Bu10A5u10A1u109Bu10A3u109Fu109Fu109Du10A0u10A5);
	Injector::Inject(HF_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6, GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6, &Template_GameServer_u109Fu109Bu1099u1099u109Bu10A0u109Cu10A0u10A2u10A8u10A6);
	Injector::Inject(HF_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2, GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2, &Template_GameServer_u10A4u109Bu109Au10A2u10A3u109Fu1099u10A4u10A1u10A8u10A2);
	Injector::Inject(HF_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A, GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A, &Template_GameServer_u10A1u109Cu109Fu109Fu10A8u10A5u10A7u109Cu10A6u10A2u109A);
	Injector::Inject(HF_GameServer_ForceRemoveItem, GameServer_ForceRemoveItem, &Template_GameServer_ForceRemoveItem);
	Injector::Inject(HF_GameServer_CheckHit, GameServer_CheckHit, &Template_GameServer_CheckHit);
	Injector::Inject(HF_GameServer_PlayerDied, GameServer_PlayerDied, &Template_GameServer_PlayerDied);
	Injector::Inject(HF_GameServer_ChatCooldown, GameServer_ChatCooldown, &Template_GameServer_ChatCooldown);
	Injector::Inject(HF_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6, GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6, &Template_GameServer_u109Fu1099u109Eu109Eu109Au1099u10A8u109Bu109Du10A7u10A6);
	Injector::Inject(HF_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B, GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B, &Template_GameServer_u10A4u10A4u109Fu109Bu109Fu1099u10A1u10A2u109Cu10A7u109B);
	Injector::Inject(HF_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8, GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8, &Template_GameServer_u109Fu109Fu109Du109Cu109Fu1099u10A5u109Fu10A4u10A6u10A8);
	Injector::Inject(HF_GameServer__ctor, GameServer__ctor, &Template_GameServer__ctor);
	Injector::Inject(HF_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5, GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5, &Template_GameServer_u10A8u10A7u109Eu109Au1099u109Au10A0u10A5u109Eu109Au10A5);
	Injector::Inject(HF_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4, GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4, &Template_GameServer_u10A2u109Cu10A2u10A5u1099u109Fu109Cu109Du109Bu109Fu10A4);
	Injector::Inject(HF_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7, GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7, &Template_GameServer_u10A6u10A7u10A3u10A6u109Cu10A2u109Cu10A7u10A5u1099u10A7);
	Injector::Inject(HF_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E, GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E, &Template_GameServer_u109Fu109Au109Eu10A1u109Du10A7u10A4u109Bu10A7u109Eu109E);
	Injector::Inject(HF_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2, GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2, &Template_GameServer_u10A3u10A6u10A7u10A3u1099u109Au109Au109Bu10A4u10A1u10A2);
	Injector::Inject(HF_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2, GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2, &Template_GameServer_u109Du109Cu10A5u10A1u1099u10A6u10A3u1099u10A4u10A0u10A2);
	Injector::Inject(HF_GameServer_PunchCooldown, GameServer_PunchCooldown, &Template_GameServer_PunchCooldown);
	Injector::Inject(HF_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5, GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5, &Template_GameServer_u10A5u10A0u10A2u10A3u109Au10A0u10A2u10A3u10A7u10A3u10A5);
	Injector::Inject(HF_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6, GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6, &Template_GameServer_u109Au10A8u10A1u1099u10A3u10A3u109Cu10A7u109Du10A8u10A6);
	Injector::Inject(HF_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C, GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C, &Template_GameServer_u109Au10A1u10A2u10A1u109Au109Fu10A2u10A0u109Du109Cu109C);
	Injector::Inject(HF_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D, GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D, &Template_GameServer_u10A1u10A8u10A8u10A6u109Fu109Au10A5u109Du109Du109Cu109D);
	Injector::Inject(HF_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099, GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099, &Template_GameServer_u109Du1099u10A3u10A7u109Au109Eu10A3u10A6u10A1u10A4u1099);
	Injector::Inject(HF_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B, GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B, &Template_GameServer_u10A6u1099u109Cu1099u109Eu10A8u109Du1099u10A5u10A3u109B);
	Injector::Inject(HF_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4, GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4, &Template_GameServer_u1099u109Eu109Bu10A2u10A0u10A0u109Eu10A4u10A1u1099u10A4);
	Injector::Inject(HF_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099, GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099, &Template_GameServer_u10A6u109Eu10A7u1099u1099u10A1u109Bu109Au109Du109Bu1099);
	Injector::Inject(HF_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2, GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2, &Template_GameServer_u109Fu10A1u10A1u10A5u10A7u1099u109Eu109Cu10A7u109Bu10A2);
	Injector::Inject(HF_GameServer_CheckPush, GameServer_CheckPush, &Template_GameServer_CheckPush);
	Injector::Inject(HF_GameServer_ForceRemoveAllWeapons, GameServer_ForceRemoveAllWeapons, &Template_GameServer_ForceRemoveAllWeapons);
	Injector::Inject(HF_GameServer_QueueRespawn, GameServer_QueueRespawn, &Template_GameServer_QueueRespawn);
	Injector::Inject(HF_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1, GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1, &Template_GameServer_u10A3u10A7u109Eu109Eu109Du10A2u1099u10A0u10A1u10A7u10A1);
	Injector::Inject(HF_GameServer_ForceGiveAllWeapon, GameServer_ForceGiveAllWeapon, &Template_GameServer_ForceGiveAllWeapon);
	Injector::Inject(HF_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F, GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F, &Template_GameServer_u109Fu10A7u10A8u10A2u109Cu10A4u10A8u109Du10A4u10A6u109F);
	Injector::Inject(HF_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A, GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A, &Template_GameServer_u10A7u109Du1099u10A8u1099u109Cu10A7u10A3u109Au10A1u109A);
	Injector::Inject(HF_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4, GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4, &Template_GameServer_u10A8u109Cu109Du109Bu10A1u109Du1099u1099u10A7u109Cu10A4);
	Injector::Inject(HF_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E, GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E, &Template_GameServer_u109Eu10A1u109Au1099u109Fu10A7u10A5u109Au109Du10A2u109E);
	Injector::Inject(HF_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A, GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A, &Template_GameServer_u109Fu10A2u10A0u10A5u10A0u109Cu109Au10A4u10A3u10A6u109A);
	Injector::Inject(HF_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3, GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3, &Template_GameServer_u10A0u10A0u10A0u109Cu109Bu10A8u10A6u10A6u109Eu10A5u10A3);
	Injector::Inject(HF_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099, GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099, &Template_GameServer_u10A4u10A7u10A8u10A1u10A6u1099u10A6u10A1u109Fu109Fu1099);
	Injector::Inject(HF_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D, GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D, &Template_GameServer_u10A8u109Cu109Bu109Au10A5u10A7u10A2u10A6u10A5u10A3u109D);
	Injector::Inject(HF_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E, GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E, &Template_GameServer_u10A2u10A6u10A1u109Au10A1u10A1u10A8u10A0u10A3u10A6u109E);
	Injector::Inject(HF_GameServer_PlayerSpawnRequest, GameServer_PlayerSpawnRequest, &Template_GameServer_PlayerSpawnRequest);
	Injector::Inject(HF_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3, GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3, &Template_GameServer_u10A0u109Fu109Bu10A8u10A6u10A8u109Bu10A7u10A0u109Au10A3);
	Injector::Inject(HF_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D, GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D, &Template_GameServer_u109Fu10A1u10A5u10A1u10A5u10A3u10A6u1099u10A4u10A4u109D);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E__ctor);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_IDisposable_Dispose);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_MoveNext);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_Generic_IEnumerator_System_Object__get_Current);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_Reset);
	Injector::Inject(HF_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current, GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current, &Template_GameServer_u109Fu109Au10A6u109Cu10A7u10A5u109Fu109Cu109Eu10A6u109E_System_Collections_IEnumerator_get_Current);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099__ctor);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_IDisposable_Dispose);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_MoveNext);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_Generic_IEnumerator_System_Object__get_Current);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_Reset);
	Injector::Inject(HF_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current, GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current, &Template_GameServer_u10A1u10A4u109Fu10A2u109Fu109Cu109Du109Au109Cu10A7u1099_System_Collections_IEnumerator_get_Current);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3__ctor);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_IDisposable_Dispose);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_MoveNext);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_Generic_IEnumerator_System_Object__get_Current);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_Reset);
	Injector::Inject(HF_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current, GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current, &Template_GameServer_u10A4u10A7u1099u109Bu1099u109Cu109Eu109Au109Du10A2u10A3_System_Collections_IEnumerator_get_Current);
	*/
}
