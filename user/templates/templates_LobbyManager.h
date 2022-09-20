#pragma once

#include "pch.h"
#include "Injector.h"
#include "Server.h"

/*
INPUT

DO_APP_FUNC(0x004952A0, bool, LobbyManager_get_practiceMode, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17600, void, LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x00D16100, void, LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2, (LobbyManager * __this, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, bool u10A3u109Au10A1u109Cu10A2u10A7u10A2u109Cu109Cu1099u109B, MethodInfo * method));
DO_APP_FUNC(0x00D15930, void, LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D121C0, void, LobbyManager_RequestPracticeLobby, (LobbyManager * __this, Map * u109Eu10A5u10A8u10A7u10A1u10A6u10A6u109Au109Eu10A7u109A, GameModeData * u10A3u10A0u109Fu10A5u10A4u1099u10A6u10A0u10A6u109Eu109D, MethodInfo * method));
DO_APP_FUNC(0x00D15FD0, void, LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D13630, void, LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D15D10, String *, LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D165D0, void, LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x00D13450, void, LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B, (LobbyManager * __this, CSteamID u109Eu109Au109Fu10A6u109Bu109Bu10A0u10A0u109Fu109Au10A8, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x00D16A50, void, LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, CSteamID, LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D15DC0, void, LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6, (LobbyManager * __this, Map * u109Eu10A5u10A8u10A7u10A1u10A6u10A6u109Au109Eu10A7u109A, GameModeData * u10A3u10A0u109Fu10A5u10A4u1099u10A6u10A0u10A6u109Eu109D, MethodInfo * method));
DO_APP_FUNC(0x00268C40, CSteamID, LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D12A90, String *, LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D15380, String *, LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00495EA0, void, LobbyManager_set_practiceMode, (LobbyManager * __this, bool u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x00D16910, String *, LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D12A60, String *, LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F, (LobbyManager * __this, String * u109Fu109Du10A5u1099u109Bu109Cu10A4u10A4u10A1u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x00D16040, String *, LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1, (LobbyManager * __this, String * u109Fu109Du10A5u1099u109Bu109Cu10A4u10A4u10A1u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x00D15680, void, LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D, (LobbyManager * __this, CSteamID u109Eu109Au109Fu10A6u109Bu109Bu10A0u10A0u109Fu109Au10A8, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x00D16B00, void, LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, bool u1099u109Fu10A8u10A1u1099u10A7u10A7u10A7u109Fu10A6u109C, MethodInfo * method));
DO_APP_FUNC(0x00D17DB0, void, LobbyManager__ctor, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D136A0, void, LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D15010, void, LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D13E10, void, LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17C90, void, LobbyManager__cctor, (MethodInfo * method));
DO_APP_FUNC(0x00D11960, void, LobbyManager_KickPlayer, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x003C6E30, void, LobbyManager_set_serverName, (LobbyManager * __this, String * u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x0093C980, void, LobbyManager_SetLobby, (LobbyManager * __this, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x00D11DD0, void, LobbyManager_OnPlayerJoinLeaveUpdate, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, bool u1099u109Fu10A8u10A1u1099u10A7u10A7u10A7u109Fu10A6u109C, MethodInfo * method));
DO_APP_FUNC(0x00D11D00, void, LobbyManager_NewLobbySettings, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D14C90, void, LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x003C6E30, void, LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0, (LobbyManager * __this, String * u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x00D174A0, void, LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17310, String *, LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D157B0, void, LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16AA0, String *, LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11D60, void, LobbyManager_NewMuteList, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x0093C980, void, LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B, (LobbyManager * __this, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x003C6E00, String *, LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D128C0, void, LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17470, String *, LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x0093C980, void, LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0, (LobbyManager * __this, CSteamID u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, LobbyManager_SetServerVersion, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D10C00, void, LobbyManager_AddPlayerToLobby, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x003C6E00, String *, LobbyManager_get_serverName, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00268540, Boolean__Array *, LobbyManager_get_colorsTaken, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16A20, String *, LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D15B70, void, LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x002ECEC0, void, LobbyManager_set_colorsTaken, (LobbyManager * __this, Boolean__Array * u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x00268C40, CSteamID, LobbyManager_get_currentLobby, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17850, String *, LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16770, void, LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x00268C40, CSteamID, LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11710, void, LobbyManager_GameEnded, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11660, void, LobbyManager_CloseLobby, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11A90, void, LobbyManager_LobbyLoop, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11760, Client *, LobbyManager_GetClient, (LobbyManager * __this, uint64_t u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D168E0, String *, LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D, (LobbyManager * __this, String * u109Eu10A3u10A3u109Fu1099u109Fu10A8u10A1u10A8u1099u10A5, MethodInfo * method));
DO_APP_FUNC(0x00D14430, String *, LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B, (LobbyManager * __this, String * u109Eu10A3u10A3u109Fu1099u109Fu10A8u10A1u10A8u1099u10A5, MethodInfo * method));
DO_APP_FUNC(0x00D13880, String *, LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00268540, Boolean__Array *, LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00268C40, CSteamID, LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D14E80, void, LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x00D13580, String *, LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D123D0, void, LobbyManager_StartLobby, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17880, void, LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D168A0, int32_t, LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D14C40, int32_t, LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D155F0, void, LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7, (LobbyManager * __this, Map * u109Eu10A5u10A8u10A7u10A1u10A6u10A6u109Au109Eu10A7u109A, GameModeData * u10A3u10A0u109Fu10A5u10A4u1099u10A6u10A0u10A6u109Eu109D, MethodInfo * method));
DO_APP_FUNC(0x00D11FD0, void, LobbyManager_RemovePlayerFromLobby, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D11180, void, LobbyManager_Awake, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x002257B0, void, LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16940, String *, LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D12AC0, Client *, LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1, (LobbyManager * __this, uint64_t u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D12570, void, LobbyManager_StartNewLobby, (LobbyManager * __this, CSteamID u109Eu109Au109Fu10A6u109Bu109Bu10A0u10A0u109Fu109Au10A8, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x00D16070, void, LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C, (LobbyManager * __this, Map * u109Eu10A5u10A8u10A7u10A1u10A6u10A6u109Au109Eu10A7u109A, GameModeData * u10A3u10A0u109Fu10A5u10A4u1099u10A6u10A0u10A6u109Eu109D, MethodInfo * method));
DO_APP_FUNC(0x00D165A0, void, LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16D30, void, LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D114C0, void, LobbyManager_ChangeColor, (LobbyManager * __this, uint64_t u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, int32_t u10A3u10A5u10A2u10A3u10A8u10A3u109Au109Bu10A3u10A3u10A1, MethodInfo * method));
DO_APP_FUNC(0x00D11C50, String *, LobbyManager_NameVal, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D11320, void, LobbyManager_BanPlayer, (LobbyManager * __this, uint64_t u109Cu10A4u10A8u109Bu10A5u109Eu1099u109Cu109Bu10A6u1099, MethodInfo * method));
DO_APP_FUNC(0x00D14140, int32_t, LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x0093C980, void, LobbyManager_set_currentLobby, (LobbyManager * __this, CSteamID u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x00D153B0, void, LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, bool u1099u109Fu10A8u10A1u1099u10A7u10A7u10A7u109Fu10A6u109C, MethodInfo * method));
DO_APP_FUNC(0x00D125B0, void, LobbyManager_StartPracticeLobby, (LobbyManager * __this, CSteamID u109Eu109Au109Fu10A6u109Bu109Bu10A0u10A0u109Fu109Au10A8, CSteamID u10A5u109Cu1099u10A4u10A1u10A4u109Bu10A3u10A2u109Bu109B, MethodInfo * method));
DO_APP_FUNC(0x00D12250, void, LobbyManager_SetServerName, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D177A0, void, LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17BE0, void, LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D165A0, void, LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D155B0, void, LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2, (LobbyManager * __this, int32_t u10A3u10A5u10A2u10A3u10A8u10A3u109Au109Bu10A3u10A3u10A1, bool u10A4u109Eu10A8u109Fu109Eu10A2u1099u10A4u10A2u10A0u109C, MethodInfo * method));
DO_APP_FUNC(0x00D14E50, String *, LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16700, void, LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17550, String *, LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D126E0, void, LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16420, void, LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17340, void, LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D12C00, void, LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17C30, void, LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D17A60, void, LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16970, String *, LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16D00, String *, LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B, (LobbyManager * __this, String * u109Fu109Du10A5u1099u109Bu109Cu10A4u10A4u10A1u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x004952A0, bool, LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D138B0, void, LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D15E50, void, LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D16DB0, void, LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A, (LobbyManager * __this, CSteamID u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D133E0, void, LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D14460, void, LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D14170, Client *, LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C, (LobbyManager * __this, uint64_t u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00269060, Client__Array *, LobbyManager_GetClients, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D165A0, void, LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D142B0, void, LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x002ECEC0, void, LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D, (LobbyManager * __this, Boolean__Array * u109Du109Eu109Fu10A1u10A0u10A8u10A0u109Fu10A2u10A5u10A7, MethodInfo * method));
DO_APP_FUNC(0x00D118A0, int32_t, LobbyManager_GetPlayerColorId, (LobbyManager * __this, uint64_t u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8, MethodInfo * method));
DO_APP_FUNC(0x00D16AD0, String *, LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5, (LobbyManager * __this, String * u109Fu109Du10A5u1099u109Bu109Cu10A4u10A4u10A1u10A8u10A3, MethodInfo * method));
DO_APP_FUNC(0x00D159B0, void, LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x00D155B0, void, LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3, (LobbyManager * __this, int32_t u10A3u10A5u10A2u10A3u10A8u10A3u109Au109Bu10A3u10A3u10A1, bool u10A4u109Eu10A8u109Fu109Eu10A2u1099u10A4u10A2u10A0u109C, MethodInfo * method));
DO_APP_FUNC(0x00D14140, int32_t, LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C, (LobbyManager * __this, MethodInfo * method));
DO_APP_FUNC(0x004952A0, bool, LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A, (LobbyManager * __this, MethodInfo * method));
*/

static auto HF_LobbyManager_get_practiceMode = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::get_practiceMode");
static bool Template_LobbyManager_get_practiceMode(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_practiceMode" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_practiceMode->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C");
static void Template_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C->original(a, b, method);
}

static auto HF_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2 = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2");
static void Template_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E");
static void Template_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E->original(a, method);
}

static auto HF_LobbyManager_RequestPracticeLobby = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::RequestPracticeLobby");
static void Template_LobbyManager_RequestPracticeLobby(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::RequestPracticeLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_RequestPracticeLobby->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C");
static void Template_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C->original(a, method);
}

static auto HF_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6");
static void Template_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6->original(a, method);
}

static auto HF_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1");
static String* Template_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2");
static void Template_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2->original(a, b, method);
}

static auto HF_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B");
static void Template_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7");
static void Template_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7->original(a, method);
}

static auto HF_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B");
static CSteamID Template_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6 = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6");
static void Template_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0");
static CSteamID Template_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D");
static String* Template_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3");
static String* Template_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3->original(a, method);

	return ret;
}

static auto HF_LobbyManager_set_practiceMode = new HookFunction<void, LobbyManager*, bool, MethodInfo*>("LobbyManager::set_practiceMode");
static void Template_LobbyManager_set_practiceMode(LobbyManager* a, bool b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_practiceMode" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_practiceMode->original(a, b, method);
}

static auto HF_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B");
static String* Template_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F");
static String* Template_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1 = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1");
static String* Template_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D");
static void Template_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8 = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8");
static void Template_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8->original(a, b, c, method);
}

static auto HF_LobbyManager__ctor = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::_ctor");
static void Template_LobbyManager__ctor(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::_ctor" << " a=" << a << ", " << std::endl;

	HF_LobbyManager__ctor->original(a, method);
}

static auto HF_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C");
static void Template_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C->original(a, method);
}

static auto HF_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B");
static void Template_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B->original(a, method);
}

static auto HF_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7");
static void Template_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7->original(a, method);
}

static auto HF_LobbyManager__cctor = new HookFunction<void, MethodInfo*>("LobbyManager::_cctor");
static void Template_LobbyManager__cctor(MethodInfo* method)
{
	std::cout << "LobbyManager::_cctor" << std::endl;

	HF_LobbyManager__cctor->original(method);
}

static auto HF_LobbyManager_KickPlayer = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::KickPlayer");
static void Template_LobbyManager_KickPlayer(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::KickPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_KickPlayer->original(a, b, method);
}

static auto HF_LobbyManager_set_serverName = new HookFunction<void, LobbyManager*, String*, MethodInfo*>("LobbyManager::set_serverName");
static void Template_LobbyManager_set_serverName(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_serverName" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_serverName->original(a, b, method);
}

static auto HF_LobbyManager_SetLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::SetLobby");
static void Template_LobbyManager_SetLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::SetLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_SetLobby->original(a, b, method);
}

static auto HF_LobbyManager_OnPlayerJoinLeaveUpdate = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::OnPlayerJoinLeaveUpdate");
static void Template_LobbyManager_OnPlayerJoinLeaveUpdate(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::OnPlayerJoinLeaveUpdate" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_OnPlayerJoinLeaveUpdate->original(a, b, c, method);
}

static auto HF_LobbyManager_NewLobbySettings = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::NewLobbySettings");
static void Template_LobbyManager_NewLobbySettings(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NewLobbySettings" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_NewLobbySettings->original(a, method);
}

static auto HF_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F");
static void Template_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F->original(a, method);
}

static auto HF_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0 = new HookFunction<void, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0");
static void Template_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0->original(a, b, method);
}

static auto HF_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D");
static void Template_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D->original(a, method);
}

static auto HF_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8");
static String* Template_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D");
static void Template_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D->original(a, method);
}

static auto HF_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B");
static String* Template_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B->original(a, method);

	return ret;
}

static auto HF_LobbyManager_NewMuteList = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::NewMuteList");
static void Template_LobbyManager_NewMuteList(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NewMuteList" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_NewMuteList->original(a, method);
}

static auto HF_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B");
static void Template_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B->original(a, b, method);
}

static auto HF_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2");
static String* Template_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099");
static void Template_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099->original(a, method);
}

static auto HF_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E");
static String* Template_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A");
static void Template_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A->original(a, method);
}

static auto HF_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4");
static void Template_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4->original(a, method);
}

static auto HF_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0 = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0");
static void Template_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0->original(a, b, method);
}

static auto HF_LobbyManager_SetServerVersion = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::SetServerVersion");
static void Template_LobbyManager_SetServerVersion(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::SetServerVersion" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_SetServerVersion->original(a, method);
}

static auto HF_LobbyManager_AddPlayerToLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::AddPlayerToLobby");
static void Template_LobbyManager_AddPlayerToLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::AddPlayerToLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_AddPlayerToLobby->original(a, b, method);

	Server::OnAddPlayerToLobby(b.m_SteamID);
}

static auto HF_LobbyManager_get_serverName = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::get_serverName");
static String* Template_LobbyManager_get_serverName(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_serverName" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_serverName->original(a, method);

	return ret;
}

static auto HF_LobbyManager_get_colorsTaken = new HookFunction<Boolean__Array*, LobbyManager*, MethodInfo*>("LobbyManager::get_colorsTaken");
static Boolean__Array* Template_LobbyManager_get_colorsTaken(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_colorsTaken" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_colorsTaken->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C");
static String* Template_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4");
static void Template_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4->original(a, method);
}

static auto HF_LobbyManager_set_colorsTaken = new HookFunction<void, LobbyManager*, Boolean__Array*, MethodInfo*>("LobbyManager::set_colorsTaken");
static void Template_LobbyManager_set_colorsTaken(LobbyManager* a, Boolean__Array* b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_colorsTaken" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_colorsTaken->original(a, b, method);
}

static auto HF_LobbyManager_get_currentLobby = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::get_currentLobby");
static CSteamID Template_LobbyManager_get_currentLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::get_currentLobby" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_get_currentLobby->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C");
static String* Template_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3");
static void Template_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3->original(a, b, method);
}

static auto HF_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0");
static CSteamID Template_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0->original(a, method);

	return ret;
}

static auto HF_LobbyManager_GameEnded = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::GameEnded");
static void Template_LobbyManager_GameEnded(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::GameEnded" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_GameEnded->original(a, method);
}

static auto HF_LobbyManager_CloseLobby = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::CloseLobby");
static void Template_LobbyManager_CloseLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::CloseLobby" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_CloseLobby->original(a, method);
}

static auto HF_LobbyManager_LobbyLoop = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::LobbyLoop");
static void Template_LobbyManager_LobbyLoop(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::LobbyLoop" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_LobbyLoop->original(a, method);
}

static auto HF_LobbyManager_GetClient = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::GetClient");
static Client* Template_LobbyManager_GetClient(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::GetClient" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_GetClient->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D");
static String* Template_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B");
static String* Template_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5");
static String* Template_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A = new HookFunction<Boolean__Array*, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A");
static Boolean__Array* Template_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099 = new HookFunction<CSteamID, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099");
static CSteamID Template_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2 = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2");
static void Template_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2->original(a, b, method);
}

static auto HF_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099");
static String* Template_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099->original(a, method);

	return ret;
}

static auto HF_LobbyManager_StartLobby = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::StartLobby");
static void Template_LobbyManager_StartLobby(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::StartLobby" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_StartLobby->original(a, method);
}

static auto HF_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5");
static void Template_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5->original(a, method);
}

static auto HF_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B");
static int32_t Template_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F");
static int32_t Template_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7 = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7");
static void Template_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7->original(a, b, c, method);
}

static auto HF_LobbyManager_RemovePlayerFromLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::RemovePlayerFromLobby");
static void Template_LobbyManager_RemovePlayerFromLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::RemovePlayerFromLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_RemovePlayerFromLobby->original(a, b, method);

	Server::OnRemovePlayerFromLobby(b.m_SteamID);
}

static auto HF_LobbyManager_Awake = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::Awake");
static void Template_LobbyManager_Awake(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::Awake" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_Awake->original(a, method);
}

static auto HF_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D");
static void Template_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D->original(a, method);
}

static auto HF_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D");
static String* Template_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1 = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1");
static Client* Template_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_StartNewLobby = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::StartNewLobby");
static void Template_LobbyManager_StartNewLobby(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::StartNewLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_StartNewLobby->original(a, b, c, method);

	Server::OnLobbyStart((long long)c.m_SteamID);
}

static auto HF_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C = new HookFunction<void, LobbyManager*, Map*, GameModeData*, MethodInfo*>("LobbyManager::u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C");
static void Template_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C(LobbyManager* a, Map* b, GameModeData* c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C->original(a, b, c, method);
}

static auto HF_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F");
static void Template_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F->original(a, method);
}

static auto HF_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3");
static void Template_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3->original(a, method);
}

static auto HF_LobbyManager_ChangeColor = new HookFunction<void, LobbyManager*, uint64_t, int32_t, MethodInfo*>("LobbyManager::ChangeColor");
static void Template_LobbyManager_ChangeColor(LobbyManager* a, uint64_t b, int32_t c, MethodInfo* method)
{
	std::cout << "LobbyManager::ChangeColor" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_ChangeColor->original(a, b, c, method);
}

static auto HF_LobbyManager_NameVal = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::NameVal");
static String* Template_LobbyManager_NameVal(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::NameVal" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_NameVal->original(a, method);

	return ret;
}

static auto HF_LobbyManager_BanPlayer = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::BanPlayer");
static void Template_LobbyManager_BanPlayer(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::BanPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	//HF_LobbyManager_BanPlayer->original(a, b, method);
}

static auto HF_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D");
static int32_t Template_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D->original(a, method);

	return ret;
}

static auto HF_LobbyManager_set_currentLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::set_currentLobby");
static void Template_LobbyManager_set_currentLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::set_currentLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_set_currentLobby->original(a, b, method);
}

static auto HF_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E = new HookFunction<void, LobbyManager*, CSteamID, bool, MethodInfo*>("LobbyManager::u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E");
static void Template_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E(LobbyManager* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E->original(a, b, c, method);
}

static auto HF_LobbyManager_StartPracticeLobby = new HookFunction<void, LobbyManager*, CSteamID, CSteamID, MethodInfo*>("LobbyManager::StartPracticeLobby");
static void Template_LobbyManager_StartPracticeLobby(LobbyManager* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "LobbyManager::StartPracticeLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_StartPracticeLobby->original(a, b, c, method);
}

static auto HF_LobbyManager_SetServerName = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::SetServerName");
static void Template_LobbyManager_SetServerName(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::SetServerName" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_SetServerName->original(a, method);
}

static auto HF_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C");
static void Template_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C->original(a, method);
}

static auto HF_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8");
static void Template_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8->original(a, method);
}

static auto HF_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D");
static void Template_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D->original(a, method);
}

static auto HF_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2 = new HookFunction<void, LobbyManager*, int32_t, bool, MethodInfo*>("LobbyManager::u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2");
static void Template_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2(LobbyManager* a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2->original(a, b, c, method);
}

static auto HF_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A");
static String* Template_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7");
static void Template_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7->original(a, method);
}

static auto HF_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2");
static String* Template_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B");
static void Template_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B->original(a, method);
}

static auto HF_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099");
static void Template_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099->original(a, method);
}

static auto HF_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1");
static void Template_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1->original(a, method);
}

static auto HF_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3");
static void Template_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3->original(a, method);
}

static auto HF_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7");
static void Template_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7->original(a, method);
}

static auto HF_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F");
static void Template_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F->original(a, method);
}

static auto HF_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6 = new HookFunction<String*, LobbyManager*, MethodInfo*>("LobbyManager::u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6");
static String* Template_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B");
static String* Template_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B");
static bool Template_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099 = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099");
static void Template_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099->original(a, b, method);
}

static auto HF_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F");
static void Template_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F->original(a, method);
}

static auto HF_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A");
static void Template_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A->original(a, b, method);
}

static auto HF_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F");
static void Template_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F->original(a, method);
}

static auto HF_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7");
static void Template_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7->original(a, method);
}

static auto HF_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C = new HookFunction<Client*, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C");
static Client* Template_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_GetClients = new HookFunction<Client__Array*, LobbyManager*, MethodInfo*>("LobbyManager::GetClients");
static Client__Array* Template_LobbyManager_GetClients(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::GetClients" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_GetClients->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1");
static void Template_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1->original(a, method);
}

static auto HF_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D");
static void Template_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D->original(a, method);
}

static auto HF_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D = new HookFunction<void, LobbyManager*, Boolean__Array*, MethodInfo*>("LobbyManager::u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D");
static void Template_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D(LobbyManager* a, Boolean__Array* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D->original(a, b, method);
}

static auto HF_LobbyManager_GetPlayerColorId = new HookFunction<int32_t, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::GetPlayerColorId");
static int32_t Template_LobbyManager_GetPlayerColorId(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	std::cout << "LobbyManager::GetPlayerColorId" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_GetPlayerColorId->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5 = new HookFunction<String*, LobbyManager*, String*, MethodInfo*>("LobbyManager::u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5");
static String* Template_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5(LobbyManager* a, String* b, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5->original(a, b, method);

	return ret;
}

static auto HF_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5 = new HookFunction<void, LobbyManager*, MethodInfo*>("LobbyManager::u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5");
static void Template_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5" << " a=" << a << ", " << std::endl;

	HF_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5->original(a, method);
}

static auto HF_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3 = new HookFunction<void, LobbyManager*, int32_t, bool, MethodInfo*>("LobbyManager::u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3");
static void Template_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3(LobbyManager* a, int32_t b, bool c, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3->original(a, b, c, method);
}

static auto HF_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C = new HookFunction<int32_t, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C");
static int32_t Template_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C->original(a, method);

	return ret;
}

static auto HF_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A = new HookFunction<bool, LobbyManager*, MethodInfo*>("LobbyManager::u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A");
static bool Template_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A(LobbyManager* a, MethodInfo* method)
{
	std::cout << "LobbyManager::u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A" << " a=" << a << ", " << std::endl;

	auto ret = HF_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A->original(a, method);

	return ret;
}


static void Inject_Templates_LobbyManager()
{
	if (!Mod::LoadAllTemplates)
	{
		Injector::Inject(HF_LobbyManager_AddPlayerToLobby, LobbyManager_AddPlayerToLobby, &Template_LobbyManager_AddPlayerToLobby);
		Injector::Inject(HF_LobbyManager_RemovePlayerFromLobby, LobbyManager_RemovePlayerFromLobby, &Template_LobbyManager_RemovePlayerFromLobby);
		Injector::Inject(HF_LobbyManager_BanPlayer, LobbyManager_BanPlayer, &Template_LobbyManager_BanPlayer);
		Injector::Inject(HF_LobbyManager_StartNewLobby, LobbyManager_StartNewLobby, &Template_LobbyManager_StartNewLobby);
		return;
	}

	//Injector::Inject(HF_LobbyManager_get_practiceMode, LobbyManager_get_practiceMode, &Template_LobbyManager_get_practiceMode);
	Injector::Inject(HF_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C, LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C, &Template_LobbyManager_u10A7u109Du10A8u109Cu10A6u10A7u109Bu10A4u109Fu10A2u109C);
	Injector::Inject(HF_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2, LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2, &Template_LobbyManager_u10A2u109Au10A0u10A4u109Bu10A3u10A2u10A4u10A6u109Eu10A2);
	//Injector::Inject(HF_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E, LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E, &Template_LobbyManager_u10A0u10A4u10A1u10A3u109Bu109Du109Du10A6u10A3u1099u109E);
	Injector::Inject(HF_LobbyManager_RequestPracticeLobby, LobbyManager_RequestPracticeLobby, &Template_LobbyManager_RequestPracticeLobby);
	//Injector::Inject(HF_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C, LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C, &Template_LobbyManager_u10A1u10A8u10A2u109Cu10A8u10A0u109Bu10A2u10A8u10A5u109C);
	//Injector::Inject(HF_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6, LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6, &Template_LobbyManager_u109Bu10A8u10A0u109Bu109Fu10A3u10A7u10A2u10A8u109Au10A6);
	//Injector::Inject(HF_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1, LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1, &Template_LobbyManager_u10A1u109Eu10A5u10A3u10A0u10A8u10A7u10A2u10A4u109Bu10A1);
	Injector::Inject(HF_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2, LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2, &Template_LobbyManager_u10A2u10A3u109Du10A1u109Eu109Du109Eu10A4u109Bu10A2u10A2);
	Injector::Inject(HF_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B, LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B, &Template_LobbyManager_u109Bu10A1u10A8u10A3u1099u109Du10A3u10A2u109Cu10A5u109B);
	//Injector::Inject(HF_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7, LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7, &Template_LobbyManager_u10A4u10A5u10A6u10A1u1099u109Fu109Du10A2u10A1u10A7u10A7);
	//Injector::Inject(HF_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B, LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B, &Template_LobbyManager_u10A6u10A0u10A5u109Cu10A5u10A1u109Eu10A2u1099u10A4u109B);
	Injector::Inject(HF_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6, LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6, &Template_LobbyManager_u10A1u10A0u10A3u10A6u10A1u10A8u10A6u1099u1099u1099u10A6);
	//Injector::Inject(HF_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0, LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0, &Template_LobbyManager_u10A2u109Fu109Bu10A8u10A4u10A2u109Bu10A5u109Cu109Au10A0);
	//Injector::Inject(HF_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D, LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D, &Template_LobbyManager_u109Au10A8u109Fu10A8u10A0u109Cu10A6u109Au10A7u10A8u109D);
	//Injector::Inject(HF_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3, LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3, &Template_LobbyManager_u109Eu10A6u109Au10A2u109Cu10A2u109Cu109Au109Eu109Du10A3);
	//Injector::Inject(HF_LobbyManager_set_practiceMode, LobbyManager_set_practiceMode, &Template_LobbyManager_set_practiceMode);
	//Injector::Inject(HF_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B, LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B, &Template_LobbyManager_u10A3u10A6u10A6u1099u10A8u10A5u10A0u109Du10A8u10A0u109B);
	Injector::Inject(HF_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F, LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F, &Template_LobbyManager_u109Au109Bu10A2u109Du10A6u109Au10A0u109Bu109Au10A8u109F);
	Injector::Inject(HF_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1, LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1, &Template_LobbyManager_u10A1u10A8u10A8u109Eu109Du10A8u10A8u109Cu109Bu10A0u10A1);
	Injector::Inject(HF_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D, LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D, &Template_LobbyManager_u10A0u10A0u10A2u109Au109Fu10A3u10A6u10A8u10A8u10A6u109D);
	Injector::Inject(HF_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8, LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8, &Template_LobbyManager_u10A5u10A2u109Bu10A2u10A1u10A2u1099u109Bu109Fu10A5u10A8);
	//Injector::Inject(HF_LobbyManager__ctor, LobbyManager__ctor, &Template_LobbyManager__ctor);
	//Injector::Inject(HF_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C, LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C, &Template_LobbyManager_u109Cu109Au109Du10A7u10A0u10A1u109Eu10A5u10A5u109Bu109C);
	//Injector::Inject(HF_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B, LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B, &Template_LobbyManager_u109Eu10A5u109Eu109Cu10A8u10A7u10A0u10A0u10A5u109Bu109B);
	//Injector::Inject(HF_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7, LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7, &Template_LobbyManager_u109Cu10A5u109Fu109Au109Fu109Du10A0u109Fu109Au10A4u10A7);
	//Injector::Inject(HF_LobbyManager__cctor, LobbyManager__cctor, &Template_LobbyManager__cctor);
	Injector::Inject(HF_LobbyManager_KickPlayer, LobbyManager_KickPlayer, &Template_LobbyManager_KickPlayer);
	Injector::Inject(HF_LobbyManager_set_serverName, LobbyManager_set_serverName, &Template_LobbyManager_set_serverName);
	//Injector::Inject(HF_LobbyManager_SetLobby, LobbyManager_SetLobby, &Template_LobbyManager_SetLobby);
	Injector::Inject(HF_LobbyManager_OnPlayerJoinLeaveUpdate, LobbyManager_OnPlayerJoinLeaveUpdate, &Template_LobbyManager_OnPlayerJoinLeaveUpdate);
	Injector::Inject(HF_LobbyManager_NewLobbySettings, LobbyManager_NewLobbySettings, &Template_LobbyManager_NewLobbySettings);
	//Injector::Inject(HF_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F, LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F, &Template_LobbyManager_u109Eu10A3u1099u109Bu1099u109Bu109Au10A1u10A3u109Fu109F);
	Injector::Inject(HF_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0, LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0, &Template_LobbyManager_u10A0u10A6u10A7u109Cu10A0u109Cu109Bu10A2u10A4u10A1u10A0);
	//Injector::Inject(HF_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D, LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D, &Template_LobbyManager_u10A6u10A8u10A1u109Eu10A4u10A4u109Au10A6u109Du10A8u109D);
	//Injector::Inject(HF_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8, LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8, &Template_LobbyManager_u10A6u109Fu109Bu109Cu109Cu10A8u10A5u10A8u10A6u10A0u10A8);
	//Injector::Inject(HF_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D, LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D, &Template_LobbyManager_u10A0u10A2u109Fu10A5u10A7u10A6u1099u109Eu10A6u10A3u109D);
	//Injector::Inject(HF_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B, LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B, &Template_LobbyManager_u10A5u109Eu10A0u10A2u10A6u10A8u109Cu109Du10A0u10A2u109B);
	Injector::Inject(HF_LobbyManager_NewMuteList, LobbyManager_NewMuteList, &Template_LobbyManager_NewMuteList);
	Injector::Inject(HF_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B, LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B, &Template_LobbyManager_u109Cu109Eu109Bu10A8u109Au10A4u109Eu10A3u109Du109Bu109B);
	//Injector::Inject(HF_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2, LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2, &Template_LobbyManager_u1099u1099u109Cu109Eu109Eu10A7u10A0u109Bu109Bu109Au10A2);
	//Injector::Inject(HF_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099, LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099, &Template_LobbyManager_u1099u10A3u109Eu109Bu10A2u109Cu109Du10A7u109Eu109Cu1099);
	//Injector::Inject(HF_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E, LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E, &Template_LobbyManager_u10A6u10A3u10A7u10A4u109Au10A2u109Du10A5u10A8u10A4u109E);
	//Injector::Inject(HF_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A, LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A, &Template_LobbyManager_u10A7u10A3u1099u10A5u109Au10A1u1099u10A5u10A2u10A4u109A);
	//Injector::Inject(HF_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4, LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4, &Template_LobbyManager_u109Fu10A3u109Bu109Eu10A7u10A3u1099u109Eu109Bu10A7u10A4);
	//Injector::Inject(HF_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0, LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0, &Template_LobbyManager_u10A5u10A8u10A7u10A4u10A0u10A6u10A8u109Au109Fu109Du10A0);
	//Injector::Inject(HF_LobbyManager_SetServerVersion, LobbyManager_SetServerVersion, &Template_LobbyManager_SetServerVersion);
	Injector::Inject(HF_LobbyManager_AddPlayerToLobby, LobbyManager_AddPlayerToLobby, &Template_LobbyManager_AddPlayerToLobby);
	Injector::Inject(HF_LobbyManager_get_serverName, LobbyManager_get_serverName, &Template_LobbyManager_get_serverName);
	//Injector::Inject(HF_LobbyManager_get_colorsTaken, LobbyManager_get_colorsTaken, &Template_LobbyManager_get_colorsTaken);
	//Injector::Inject(HF_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C, LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C, &Template_LobbyManager_u10A4u10A4u109Au10A6u10A5u10A0u109Fu109Du10A5u10A0u109C);
	//Injector::Inject(HF_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4, LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4, &Template_LobbyManager_u10A1u1099u109Bu10A3u10A7u10A8u10A0u1099u109Fu109Fu10A4);
	//Injector::Inject(HF_LobbyManager_set_colorsTaken, LobbyManager_set_colorsTaken, &Template_LobbyManager_set_colorsTaken);
	//Injector::Inject(HF_LobbyManager_get_currentLobby, LobbyManager_get_currentLobby, &Template_LobbyManager_get_currentLobby);
	//Injector::Inject(HF_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C, LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C, &Template_LobbyManager_u10A7u10A7u10A3u10A0u109Au10A0u10A3u109Cu1099u109Du109C);
	Injector::Inject(HF_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3, LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3, &Template_LobbyManager_u10A2u10A8u109Bu10A2u109Fu10A6u1099u10A4u109Fu10A2u10A3);
	//Injector::Inject(HF_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0, LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0, &Template_LobbyManager_u109Du109Du1099u10A7u109Bu109Fu10A0u10A7u109Eu109Du10A0);
	Injector::Inject(HF_LobbyManager_GameEnded, LobbyManager_GameEnded, &Template_LobbyManager_GameEnded);
	Injector::Inject(HF_LobbyManager_CloseLobby, LobbyManager_CloseLobby, &Template_LobbyManager_CloseLobby);
	//Injector::Inject(HF_LobbyManager_LobbyLoop, LobbyManager_LobbyLoop, &Template_LobbyManager_LobbyLoop);
	//Injector::Inject(HF_LobbyManager_GetClient, LobbyManager_GetClient, &Template_LobbyManager_GetClient);
	Injector::Inject(HF_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D, LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D, &Template_LobbyManager_u10A3u10A5u10A5u10A0u10A5u10A4u10A8u10A8u1099u10A1u109D);
	Injector::Inject(HF_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B, LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B, &Template_LobbyManager_u109Du109Bu109Fu10A8u10A0u109Fu1099u10A3u109Au109Fu109B);
	//Injector::Inject(HF_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5, LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5, &Template_LobbyManager_u109Cu109Cu10A8u109Cu10A0u10A7u1099u10A6u109Du10A1u10A5);
	//Injector::Inject(HF_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A, LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A, &Template_LobbyManager_u10A5u10A8u10A8u109Au109Du109Fu10A0u1099u10A6u109Bu109A);
	//Injector::Inject(HF_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099, LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099, &Template_LobbyManager_u10A8u109Bu10A1u109Fu109Fu10A3u109Fu10A4u10A8u10A7u1099);
	Injector::Inject(HF_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2, LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2, &Template_LobbyManager_u109Eu10A5u109Au10A3u10A2u109Au10A2u10A5u109Du10A0u10A2);
	//Injector::Inject(HF_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099, LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099, &Template_LobbyManager_u109Bu10A7u10A2u10A5u109Fu10A5u10A3u109Bu109Au10A2u1099);
	Injector::Inject(HF_LobbyManager_StartLobby, LobbyManager_StartLobby, &Template_LobbyManager_StartLobby);
	//Injector::Inject(HF_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5, LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5, &Template_LobbyManager_u10A8u109Cu10A0u109Fu109Cu10A6u10A7u10A4u109Bu109Au10A5);
	//Injector::Inject(HF_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B, LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B, &Template_LobbyManager_u10A3u10A4u10A7u109Au10A8u109Fu10A3u10A5u109Du10A1u109B);
	//Injector::Inject(HF_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F, LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F, &Template_LobbyManager_u109Eu10A0u109Cu109Au109Fu1099u109Eu109Au10A2u1099u109F);
	Injector::Inject(HF_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7, LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7, &Template_LobbyManager_u10A0u10A0u10A1u10A8u10A6u10A2u1099u109Cu109Cu109Cu10A7);
	Injector::Inject(HF_LobbyManager_RemovePlayerFromLobby, LobbyManager_RemovePlayerFromLobby, &Template_LobbyManager_RemovePlayerFromLobby);
	//Injector::Inject(HF_LobbyManager_Awake, LobbyManager_Awake, &Template_LobbyManager_Awake);
	//Injector::Inject(HF_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D, LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D, &Template_LobbyManager_u10A4u109Bu109Bu109Fu109Eu109Eu10A3u10A3u109Cu109Fu109D);
	//Injector::Inject(HF_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D, LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D, &Template_LobbyManager_u10A4u10A0u109Au10A8u10A4u10A2u109Cu10A2u10A4u10A0u109D);
	Injector::Inject(HF_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1, LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1, &Template_LobbyManager_u109Bu1099u10A8u10A5u10A7u10A4u10A6u10A5u109Eu10A4u10A1);
	Injector::Inject(HF_LobbyManager_StartNewLobby, LobbyManager_StartNewLobby, &Template_LobbyManager_StartNewLobby);
	Injector::Inject(HF_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C, LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C, &Template_LobbyManager_u10A2u109Au109Cu10A2u10A7u109Au1099u109Au10A7u109Du109C);
	//Injector::Inject(HF_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F, LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F, &Template_LobbyManager_u10A2u10A0u109Cu10A3u10A6u109Au10A4u109Bu10A1u10A5u109F);
	//Injector::Inject(HF_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3, LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3, &Template_LobbyManager_u10A5u10A5u10A4u109Bu10A1u109Eu10A2u10A3u10A5u10A6u10A3);
	Injector::Inject(HF_LobbyManager_ChangeColor, LobbyManager_ChangeColor, &Template_LobbyManager_ChangeColor);
	//Injector::Inject(HF_LobbyManager_NameVal, LobbyManager_NameVal, &Template_LobbyManager_NameVal);
	Injector::Inject(HF_LobbyManager_BanPlayer, LobbyManager_BanPlayer, &Template_LobbyManager_BanPlayer);
	//Injector::Inject(HF_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D, LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D, &Template_LobbyManager_u109Cu10A8u109Bu10A5u10A2u109Eu109Bu10A6u10A5u10A3u109D);
	//Injector::Inject(HF_LobbyManager_set_currentLobby, LobbyManager_set_currentLobby, &Template_LobbyManager_set_currentLobby);
	Injector::Inject(HF_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E, LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E, &Template_LobbyManager_u109Fu10A2u109Cu10A2u109Fu10A8u10A1u10A3u109Cu10A8u109E);
	Injector::Inject(HF_LobbyManager_StartPracticeLobby, LobbyManager_StartPracticeLobby, &Template_LobbyManager_StartPracticeLobby);
	//Injector::Inject(HF_LobbyManager_SetServerName, LobbyManager_SetServerName, &Template_LobbyManager_SetServerName);
	//Injector::Inject(HF_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C, LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C, &Template_LobbyManager_u10A7u10A7u109Du109Au10A0u1099u10A8u109Fu10A4u1099u109C);
	//Injector::Inject(HF_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8, LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8, &Template_LobbyManager_u10A8u10A5u109Au109Du10A7u10A2u10A6u109Bu109Du1099u10A8);
	//Injector::Inject(HF_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D, LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D, &Template_LobbyManager_u10A4u109Bu109Du109Cu10A6u109Au10A5u10A4u109Bu109Cu109D);
	Injector::Inject(HF_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2, LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2, &Template_LobbyManager_u10A4u109Eu10A1u10A4u10A5u109Cu109Eu10A1u10A2u10A6u10A2);
	//Injector::Inject(HF_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A, LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A, &Template_LobbyManager_u109Eu10A3u1099u109Bu10A1u10A3u10A0u10A7u109Cu10A2u109A);
	//Injector::Inject(HF_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7, LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7, &Template_LobbyManager_u10A2u10A5u109Eu10A5u10A5u10A3u10A5u10A1u109Cu10A1u10A7);
	//Injector::Inject(HF_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2, LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2, &Template_LobbyManager_u10A7u109Du10A5u10A4u109Fu109Du109Fu10A5u109Au10A1u10A2);
	//Injector::Inject(HF_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B, LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B, &Template_LobbyManager_u1099u1099u10A3u10A3u1099u109Eu10A1u109Bu10A4u109Du109B);
	//Injector::Inject(HF_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099, LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099, &Template_LobbyManager_u10A2u109Cu10A7u109Cu10A3u109Eu10A8u10A4u109Bu10A6u1099);
	//Injector::Inject(HF_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1, LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1, &Template_LobbyManager_u10A6u109Fu109Cu109Au10A0u10A5u109Au10A0u1099u1099u10A1);
	//Injector::Inject(HF_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3, LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3, &Template_LobbyManager_u109Bu109Cu109Cu10A4u109Au10A1u109Eu10A6u10A5u10A8u10A3);
	//Injector::Inject(HF_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7, LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7, &Template_LobbyManager_u10A8u10A8u10A4u10A0u10A7u10A5u109Cu10A1u10A3u10A0u10A7);
	//Injector::Inject(HF_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F, LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F, &Template_LobbyManager_u10A8u10A0u10A1u109Eu109Au109Du10A5u10A6u109Du109Fu109F);
	//Injector::Inject(HF_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6, LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6, &Template_LobbyManager_u10A4u10A3u109Eu10A8u10A7u109Fu109Cu1099u109Cu10A3u10A6);
	Injector::Inject(HF_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B, LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B, &Template_LobbyManager_u10A5u10A2u109Eu10A6u109Fu10A5u10A1u109Fu109Fu10A4u109B);
	//Injector::Inject(HF_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B, LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B, &Template_LobbyManager_u10A8u109Eu10A0u10A1u10A8u10A7u109Fu10A8u10A3u109Bu109B);
	Injector::Inject(HF_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099, LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099, &Template_LobbyManager_u109Cu10A4u10A1u10A4u10A5u10A2u10A6u10A2u109Fu109Cu1099);
	//Injector::Inject(HF_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F, LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F, &Template_LobbyManager_u10A1u10A1u10A4u109Au10A3u109Du1099u10A0u109Eu109Du109F);
	Injector::Inject(HF_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A, LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A, &Template_LobbyManager_u10A6u109Du1099u10A1u10A7u1099u109Eu10A3u10A7u109Fu109A);
	//Injector::Inject(HF_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F, LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F, &Template_LobbyManager_u109Bu109Fu10A1u10A2u10A1u10A6u10A2u10A7u109Eu10A3u109F);
	//Injector::Inject(HF_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7, LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7, &Template_LobbyManager_u109Du10A0u10A7u10A2u10A7u10A7u10A8u109Bu10A8u10A4u10A7);
	Injector::Inject(HF_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C, LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C, &Template_LobbyManager_u109Cu10A8u10A1u10A2u109Cu10A1u109Au109Au10A1u109Fu109C);
	//Injector::Inject(HF_LobbyManager_GetClients, LobbyManager_GetClients, &Template_LobbyManager_GetClients);
	//Injector::Inject(HF_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1, LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1, &Template_LobbyManager_u10A7u109Eu109Du109Fu109Au109Au10A6u109Cu10A2u109Au10A1);
	//Injector::Inject(HF_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D, LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D, &Template_LobbyManager_u109Du109Bu109Bu10A5u10A3u109Fu10A2u10A7u10A8u109Cu109D);
	Injector::Inject(HF_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D, LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D, &Template_LobbyManager_u10A6u10A0u10A7u10A3u109Bu10A8u109Bu10A8u1099u10A0u109D);
	//Injector::Inject(HF_LobbyManager_GetPlayerColorId, LobbyManager_GetPlayerColorId, &Template_LobbyManager_GetPlayerColorId);
	Injector::Inject(HF_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5, LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5, &Template_LobbyManager_u10A5u109Fu109Bu10A7u10A7u10A4u109Fu109Fu109Au109Eu10A5);
	//Injector::Inject(HF_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5, LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5, &Template_LobbyManager_u10A0u10A5u109Eu10A4u109Fu1099u109Au10A5u10A8u10A3u10A5);
	//Injector::Inject(HF_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3, LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3, &Template_LobbyManager_u109Fu10A7u10A1u1099u109Au10A3u10A0u1099u1099u10A6u10A3);
	//Injector::Inject(HF_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C, LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C, &Template_LobbyManager_u109Fu10A8u10A4u109Fu10A0u109Cu109Au10A8u10A8u109Du109C);
	//Injector::Inject(HF_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A, LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A, &Template_LobbyManager_u109Fu109Cu109Fu109Du109Du10A1u109Cu10A7u10A1u10A2u109A);
}
