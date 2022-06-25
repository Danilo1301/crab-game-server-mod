#pragma once

#include "Mod.h"
#include "Server.h"

/*
NativeMethods::ISteamMatchmaking_CreateLobby a=000001BCDD9A0AD0,  b=2,  c=40,
2233327373411562139
NativeMethods::ISteamMatchmaking_SetLobbyType a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=2,
1
NativeMethods::ISteamMatchmaking_SetLobbyJoinable a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=1,
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0B59DE0,  d=000001BCE0B59D20,
[ key(Version), value(1.362) ]
1
LobbyManager::StartNewLobby a=000001BADE3D9E40,  b=CSteamID(76561199219991370),  c=CSteamID(109775243075616573),
LobbyManager::AddPlayerToLobby a=000001BADE3D9E40,  b=CSteamID(76561199219991370),
[Player] UpdateInfo 76561199219991370
[Player] Uid found76561199219991370 : 1
[Server] AddPlayer Player76561199219991370[#1] (dead) (76561199219991370)
[Server] Player76561199219991370[#1] (dead) (76561199219991370) joined for the first time
[Player] UpdateInfo 76561199219991370
[Player] Uid found76561199219991370 : 1
[Player] UpdateInfo 76561199219991370
[Player] Uid found76561199219991370 : 1
[Server] Player76561199219991370[#1] (dead) (76561199219991370) joined
ServerSend::LoadMap_1 a=6,  b=0,
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0B448A0,  d=000001BCE0B44840,
[ key(LobbyName), value(cool name) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyType a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=2,
1
NativeMethods::ISteamMatchmaking_SetLobbyMemberLimit a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=19,
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCDD711330,  d=000001BCDD7112A0,
[ key(LobbyState), value(Lobby) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCDD75D210,  d=000001BCDD75D1B0,
[ key(PlayersIn), value(1) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCDD24C180,  d=000001BCE0C11FC0,
[ key(Voice Chat), value(True) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0C141B0,  d=000001BCE0C14150,
[ key(LobbyKeyId), value(LobbyValId) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0C188A0,  d=000001BCE0C18840,
[ key(Maps), value(11111111111111111111111111111111111111111111111111111111111111) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0C26810,  d=000001BCE0C267B0,
[ key(Modes), value(11111111111111111) ]
1
NativeMethods::ISteamMatchmaking_SetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0C89FC0,  d=000001BCE0C89F60,
[ key(AllMaps), value(False) ]
1
NativeMethods::ISteamMatchmaking_GetNumLobbyMembers a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),
1
NativeMethods::ISteamMatchmaking_GetLobbyData a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=000001BCE0C89A50,
[ key(Version), return(1.362) ]
NativeMethods::ISteamMatchmaking_GetLobbyOwner a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),
76561199219991370
NativeMethods::ISteamMatchmaking_GetNumLobbyMembers a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),
1
NativeMethods::ISteamMatchmaking_GetLobbyMemberByIndex a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=0,
76561199219991370
GameManager::Start a=000001BADE3DA8F0,
[Chat] SendServerMessage: Map started
NativeMethods::ISteamMatchmaking_GetNumLobbyMembers a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),
1
NativeMethods::ISteamMatchmaking_GetLobbyMemberByIndex a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),  c=0,
76561199219991370
ServerSend::GameSpawnPlayer a=76561199219991370,  b=76561199219991370,  c=Vector3(-20.821739, -18.500000, 4.291412),  d=0,  e=0,  f=000001BCE0C02050,  g=44,
NativeMethods::ISteamMatchmaking_GetLobbyMemberLimit a=000001BCDD9A0AD0,  b=CSteamID(109775243075616573),
19
*/

auto HF_NativeMethods_ISteamMatchmaking_GetFavoriteGameCount = new HookFunction<int32_t, void*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetFavoriteGameCount");
int32_t Template_NativeMethods_ISteamMatchmaking_GetFavoriteGameCount(void* a, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetFavoriteGameCount" << " a=" << a << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetFavoriteGameCount->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetFavoriteGame = new HookFunction<bool, void*, int32_t, AppId_t*, uint32_t*, uint16_t*, uint16_t*, uint32_t*, uint32_t*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetFavoriteGame");
bool Template_NativeMethods_ISteamMatchmaking_GetFavoriteGame(void* a, int32_t b, AppId_t* c, uint32_t* d, uint16_t* e, uint16_t* f, uint32_t* g, uint32_t* h, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetFavoriteGame" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << " h=" << h << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetFavoriteGame->original(a, b, c, d, e, f, g, h, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_AddFavoriteGame = new HookFunction<int32_t, void*, AppId_t, uint32_t, uint16_t, uint16_t, uint32_t, uint32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddFavoriteGame");
int32_t Template_NativeMethods_ISteamMatchmaking_AddFavoriteGame(void* a, AppId_t b, uint32_t c, uint16_t d, uint16_t e, uint32_t f, uint32_t g, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddFavoriteGame" << " a=" << a << ", " << " b=" << b.m_AppId << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_AddFavoriteGame->original(a, b, c, d, e, f, g, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_RemoveFavoriteGame = new HookFunction<bool, void*, AppId_t, uint32_t, uint16_t, uint16_t, uint32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_RemoveFavoriteGame");
bool Template_NativeMethods_ISteamMatchmaking_RemoveFavoriteGame(void* a, AppId_t b, uint32_t c, uint16_t d, uint16_t e, uint32_t f, MethodInfo* method)
{

	std::cout << "NativeMethods::ISteamMatchmaking_RemoveFavoriteGame" << " a=" << a << ", " << " b=" << b.m_AppId << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_RemoveFavoriteGame->original(a, b, c, d, e, f, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_RequestLobbyList = new HookFunction<uint64_t, void*, MethodInfo*>("NativeMethods::ISteamMatchmaking_RequestLobbyList");
uint64_t Template_NativeMethods_ISteamMatchmaking_RequestLobbyList(void* a, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_RequestLobbyList" << " a=" << a << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_RequestLobbyList->original(a, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter = new HookFunction<void, void*, InteropHelp_UTF8StringHandle*, InteropHelp_UTF8StringHandle*, ELobbyComparison__Enum, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListStringFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter(void* a, InteropHelp_UTF8StringHandle* b, InteropHelp_UTF8StringHandle* c, ELobbyComparison__Enum d, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListStringFilter" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << (int)d << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter->original(a, b, c, d, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter = new HookFunction<void, void*, InteropHelp_UTF8StringHandle*, int32_t, ELobbyComparison__Enum, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListNumericalFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter(void* a, InteropHelp_UTF8StringHandle* b, int32_t c, ELobbyComparison__Enum d, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListNumericalFilter" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << (int)d << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter->original(a, b, c, d, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter = new HookFunction<void, void*, InteropHelp_UTF8StringHandle*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListNearValueFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(void* a, InteropHelp_UTF8StringHandle* b, int32_t c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListNearValueFilter" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter->original(a, b, c, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable = new HookFunction<void, void*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(void* a, int32_t b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable->original(a, b, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter = new HookFunction<void, void*, ELobbyDistanceFilter__Enum, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListDistanceFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter(void* a, ELobbyDistanceFilter__Enum b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListDistanceFilter" << " a=" << a << ", " << " b=" << (int)b << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter->original(a, b, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter = new HookFunction<void, void*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListResultCountFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(void* a, int32_t b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListResultCountFilter" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter->original(a, b, method);
}

auto HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter = new HookFunction<void, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter");
void Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter->original(a, b, method);
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyByIndex = new HookFunction<uint64_t, void*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyByIndex");
uint64_t Template_NativeMethods_ISteamMatchmaking_GetLobbyByIndex(void* a, int32_t b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyByIndex" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyByIndex->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_CreateLobby = new HookFunction<uint64_t, void*, ELobbyType__Enum, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_CreateLobby");
uint64_t Template_NativeMethods_ISteamMatchmaking_CreateLobby(void* a, ELobbyType__Enum b, int32_t c, MethodInfo* method)
{

	std::cout << "NativeMethods::ISteamMatchmaking_CreateLobby" << " a=" << a << ", " << " b=" << (int)b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_CreateLobby->original(a, b, c, method);

	Mod::ISteamMatchmaking_Instance = a;
	Mod::ISteamMatchmaking_LobbyId = ret;

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_JoinLobby = new HookFunction<uint64_t, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_JoinLobby");
uint64_t Template_NativeMethods_ISteamMatchmaking_JoinLobby(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_JoinLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_JoinLobby->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_LeaveLobby = new HookFunction<void, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_LeaveLobby");
void Template_NativeMethods_ISteamMatchmaking_LeaveLobby(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_LeaveLobby" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_LeaveLobby->original(a, b, method);
}

auto HF_NativeMethods_ISteamMatchmaking_InviteUserToLobby = new HookFunction<bool, void*, CSteamID, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_InviteUserToLobby");
bool Template_NativeMethods_ISteamMatchmaking_InviteUserToLobby(void* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_InviteUserToLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_InviteUserToLobby->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetNumLobbyMembers = new HookFunction<int32_t, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetNumLobbyMembers");
int32_t Template_NativeMethods_ISteamMatchmaking_GetNumLobbyMembers(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetNumLobbyMembers" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetNumLobbyMembers->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex = new HookFunction<uint64_t, void*, CSteamID, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyMemberByIndex");
uint64_t Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex(void* a, CSteamID b, int32_t c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyMemberByIndex" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyData = new HookFunction<void*, void*, CSteamID, InteropHelp_UTF8StringHandle*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyData");
void* Template_NativeMethods_ISteamMatchmaking_GetLobbyData(void* a, CSteamID b, InteropHelp_UTF8StringHandle* c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyData" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyData->original(a, b, c, method);

	String* str = InteropHelp_PtrToStringUTF8(c->fields._._.handle, NULL);
	String* retStr = InteropHelp_PtrToStringUTF8(ret, NULL);

	std::cout << "[ key(" << str->toCPPString() << "), return(" << retStr->toCPPString() << ") ]" << std::endl;

	//std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyData = new HookFunction<bool, void*, CSteamID, InteropHelp_UTF8StringHandle*, InteropHelp_UTF8StringHandle*, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyData");
bool Template_NativeMethods_ISteamMatchmaking_SetLobbyData(void* a, CSteamID b, InteropHelp_UTF8StringHandle* c, InteropHelp_UTF8StringHandle* d, MethodInfo* method)
{
	String* str1 = InteropHelp_PtrToStringUTF8(c->fields._._.handle, NULL);
	String* str2 = InteropHelp_PtrToStringUTF8(d->fields._._.handle, NULL);

	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyData" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;
	std::cout << "[ key(" << str1->toCPPString() << "), value(" << str2->toCPPString() << ") ]" << std::endl;

	if (str1->toCPPString().find("LobbyName") != -1)
	{
		std::cout << "[ changed ]" << std::endl;
		d = stringToUTF8StringHandle("CUSTOM_NAME");
	}
	
	if (str1->toCPPString().find("PlayersIn") != -1)
	{
		std::cout << "[ changed ]" << std::endl;
		d = stringToUTF8StringHandle("475");
	}
	
	return HF_NativeMethods_ISteamMatchmaking_SetLobbyData->original(a, b, c, d, method);
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyDataCount = new HookFunction<int32_t, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyDataCount");
int32_t Template_NativeMethods_ISteamMatchmaking_GetLobbyDataCount(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyDataCount" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyDataCount->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex = new HookFunction<bool, void*, CSteamID, int32_t, void*, int32_t, void*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyDataByIndex");
bool Template_NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex(void* a, CSteamID b, int32_t c, void* d, int32_t e, void* f, int32_t g, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyDataByIndex" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex->original(a, b, c, d, e, f, g, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_DeleteLobbyData = new HookFunction<bool, void*, CSteamID, InteropHelp_UTF8StringHandle*, MethodInfo*>("NativeMethods::ISteamMatchmaking_DeleteLobbyData");
bool Template_NativeMethods_ISteamMatchmaking_DeleteLobbyData(void* a, CSteamID b, InteropHelp_UTF8StringHandle* c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_DeleteLobbyData" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_DeleteLobbyData->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberData = new HookFunction<void*, void*, CSteamID, CSteamID, InteropHelp_UTF8StringHandle*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyMemberData");
void* Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberData(void* a, CSteamID b, CSteamID c, InteropHelp_UTF8StringHandle* d, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyMemberData" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberData->original(a, b, c, d, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberData = new HookFunction<void, void*, CSteamID, InteropHelp_UTF8StringHandle*, InteropHelp_UTF8StringHandle*, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyMemberData");
void Template_NativeMethods_ISteamMatchmaking_SetLobbyMemberData(void* a, CSteamID b, InteropHelp_UTF8StringHandle* c, InteropHelp_UTF8StringHandle* d, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyMemberData" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberData->original(a, b, c, d, method);
}

auto HF_NativeMethods_ISteamMatchmaking_SendLobbyChatMsg = new HookFunction<bool, void*, CSteamID, Byte__Array*, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_SendLobbyChatMsg");
bool Template_NativeMethods_ISteamMatchmaking_SendLobbyChatMsg(void* a, CSteamID b, Byte__Array* c, int32_t d, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SendLobbyChatMsg" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SendLobbyChatMsg->original(a, b, c, d, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyChatEntry = new HookFunction<int32_t, void*, CSteamID, int32_t, CSteamID*, Byte__Array*, int32_t, EChatEntryType__Enum*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyChatEntry");
int32_t Template_NativeMethods_ISteamMatchmaking_GetLobbyChatEntry(void* a, CSteamID b, int32_t c, CSteamID* d, Byte__Array* e, int32_t f, EChatEntryType__Enum* g, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyChatEntry" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << " f=" << f << ", " << " g=" << g << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyChatEntry->original(a, b, c, d, e, f, g, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_RequestLobbyData = new HookFunction<bool, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_RequestLobbyData");
bool Template_NativeMethods_ISteamMatchmaking_RequestLobbyData(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_RequestLobbyData" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_RequestLobbyData->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyGameServer = new HookFunction<void, void*, CSteamID, uint32_t, uint16_t, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyGameServer");
void Template_NativeMethods_ISteamMatchmaking_SetLobbyGameServer(void* a, CSteamID b, uint32_t c, uint16_t d, CSteamID e, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyGameServer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	HF_NativeMethods_ISteamMatchmaking_SetLobbyGameServer->original(a, b, c, d, e, method);
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyGameServer = new HookFunction<bool, void*, CSteamID, uint32_t*, uint16_t*, CSteamID*, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyGameServer");
bool Template_NativeMethods_ISteamMatchmaking_GetLobbyGameServer(void* a, CSteamID b, uint32_t* c, uint16_t* d, CSteamID* e, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyGameServer" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << " e=" << e << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyGameServer->original(a, b, c, d, e, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit = new HookFunction<bool, void*, CSteamID, int32_t, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyMemberLimit");
bool Template_NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit(void* a, CSteamID b, int32_t c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyMemberLimit" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit = new HookFunction<int32_t, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyMemberLimit");
int32_t Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyMemberLimit" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyType = new HookFunction<bool, void*, CSteamID, ELobbyType__Enum, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyType");
bool Template_NativeMethods_ISteamMatchmaking_SetLobbyType(void* a, CSteamID b, ELobbyType__Enum c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyType" << " a=" << a << ", " << " b=" << b << ", " << " c=" << (int)c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SetLobbyType->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyJoinable = new HookFunction<bool, void*, CSteamID, bool, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyJoinable");
bool Template_NativeMethods_ISteamMatchmaking_SetLobbyJoinable(void* a, CSteamID b, bool c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyJoinable" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SetLobbyJoinable->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_GetLobbyOwner = new HookFunction<uint64_t, void*, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_GetLobbyOwner");
uint64_t Template_NativeMethods_ISteamMatchmaking_GetLobbyOwner(void* a, CSteamID b, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_GetLobbyOwner" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_GetLobbyOwner->original(a, b, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLobbyOwner = new HookFunction<bool, void*, CSteamID, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLobbyOwner");
bool Template_NativeMethods_ISteamMatchmaking_SetLobbyOwner(void* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLobbyOwner" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SetLobbyOwner->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

auto HF_NativeMethods_ISteamMatchmaking_SetLinkedLobby = new HookFunction<bool, void*, CSteamID, CSteamID, MethodInfo*>("NativeMethods::ISteamMatchmaking_SetLinkedLobby");
bool Template_NativeMethods_ISteamMatchmaking_SetLinkedLobby(void* a, CSteamID b, CSteamID c, MethodInfo* method)
{
	std::cout << "NativeMethods::ISteamMatchmaking_SetLinkedLobby" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	auto ret = HF_NativeMethods_ISteamMatchmaking_SetLinkedLobby->original(a, b, c, method);

	std::cout << ret << std::endl;

	return ret;
}

void Inject_ISteamMatchmaking()
{
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetFavoriteGameCount, NativeMethods_ISteamMatchmaking_GetFavoriteGameCount, &Template_NativeMethods_ISteamMatchmaking_GetFavoriteGameCount);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetFavoriteGame, NativeMethods_ISteamMatchmaking_GetFavoriteGame, &Template_NativeMethods_ISteamMatchmaking_GetFavoriteGame);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddFavoriteGame, NativeMethods_ISteamMatchmaking_AddFavoriteGame, &Template_NativeMethods_ISteamMatchmaking_AddFavoriteGame);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_RemoveFavoriteGame, NativeMethods_ISteamMatchmaking_RemoveFavoriteGame, &Template_NativeMethods_ISteamMatchmaking_RemoveFavoriteGame);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_RequestLobbyList, NativeMethods_ISteamMatchmaking_RequestLobbyList, &Template_NativeMethods_ISteamMatchmaking_RequestLobbyList);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListStringFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNumericalFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListNearValueFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable, NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListDistanceFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListResultCountFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter, NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter, &Template_NativeMethods_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyByIndex, NativeMethods_ISteamMatchmaking_GetLobbyByIndex, &Template_NativeMethods_ISteamMatchmaking_GetLobbyByIndex);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_CreateLobby, NativeMethods_ISteamMatchmaking_CreateLobby, &Template_NativeMethods_ISteamMatchmaking_CreateLobby);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_JoinLobby, NativeMethods_ISteamMatchmaking_JoinLobby, &Template_NativeMethods_ISteamMatchmaking_JoinLobby);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_LeaveLobby, NativeMethods_ISteamMatchmaking_LeaveLobby, &Template_NativeMethods_ISteamMatchmaking_LeaveLobby);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_InviteUserToLobby, NativeMethods_ISteamMatchmaking_InviteUserToLobby, &Template_NativeMethods_ISteamMatchmaking_InviteUserToLobby);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetNumLobbyMembers, NativeMethods_ISteamMatchmaking_GetNumLobbyMembers, &Template_NativeMethods_ISteamMatchmaking_GetNumLobbyMembers);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex, NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex, &Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberByIndex);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyData, NativeMethods_ISteamMatchmaking_GetLobbyData, &Template_NativeMethods_ISteamMatchmaking_GetLobbyData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyData, NativeMethods_ISteamMatchmaking_SetLobbyData, &Template_NativeMethods_ISteamMatchmaking_SetLobbyData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyDataCount, NativeMethods_ISteamMatchmaking_GetLobbyDataCount, &Template_NativeMethods_ISteamMatchmaking_GetLobbyDataCount);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex, NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex, &Template_NativeMethods_ISteamMatchmaking_GetLobbyDataByIndex);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_DeleteLobbyData, NativeMethods_ISteamMatchmaking_DeleteLobbyData, &Template_NativeMethods_ISteamMatchmaking_DeleteLobbyData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberData, NativeMethods_ISteamMatchmaking_GetLobbyMemberData, &Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberData, NativeMethods_ISteamMatchmaking_SetLobbyMemberData, &Template_NativeMethods_ISteamMatchmaking_SetLobbyMemberData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SendLobbyChatMsg, NativeMethods_ISteamMatchmaking_SendLobbyChatMsg, &Template_NativeMethods_ISteamMatchmaking_SendLobbyChatMsg);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyChatEntry, NativeMethods_ISteamMatchmaking_GetLobbyChatEntry, &Template_NativeMethods_ISteamMatchmaking_GetLobbyChatEntry);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_RequestLobbyData, NativeMethods_ISteamMatchmaking_RequestLobbyData, &Template_NativeMethods_ISteamMatchmaking_RequestLobbyData);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyGameServer, NativeMethods_ISteamMatchmaking_SetLobbyGameServer, &Template_NativeMethods_ISteamMatchmaking_SetLobbyGameServer);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyGameServer, NativeMethods_ISteamMatchmaking_GetLobbyGameServer, &Template_NativeMethods_ISteamMatchmaking_GetLobbyGameServer);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit, NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit, &Template_NativeMethods_ISteamMatchmaking_SetLobbyMemberLimit);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit, NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit, &Template_NativeMethods_ISteamMatchmaking_GetLobbyMemberLimit);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyType, NativeMethods_ISteamMatchmaking_SetLobbyType, &Template_NativeMethods_ISteamMatchmaking_SetLobbyType);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyJoinable, NativeMethods_ISteamMatchmaking_SetLobbyJoinable, &Template_NativeMethods_ISteamMatchmaking_SetLobbyJoinable);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_GetLobbyOwner, NativeMethods_ISteamMatchmaking_GetLobbyOwner, &Template_NativeMethods_ISteamMatchmaking_GetLobbyOwner);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLobbyOwner, NativeMethods_ISteamMatchmaking_SetLobbyOwner, &Template_NativeMethods_ISteamMatchmaking_SetLobbyOwner);
	Injector::Inject(HF_NativeMethods_ISteamMatchmaking_SetLinkedLobby, NativeMethods_ISteamMatchmaking_SetLinkedLobby, &Template_NativeMethods_ISteamMatchmaking_SetLinkedLobby);
}
