#include "pch-il2cpp.h"
#include "pch.h"

//#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include <httplib.h>
//#include "stdafx.h"

#include "Mod.h"

extern const LPCWSTR LOG_FILE = L"CrabGameServerMod.log";

void Run()
{
    il2cpp_thread_attach(il2cpp_domain_get());

    //il2cppi_log_write("Startup");

    il2cppi_new_console();

    Mod::Init();
}

int main()
{
    Mod::InitConsole();
}

/*
Properties -> Linker -> System -> SubSystem
(/SUBSYSTEM:WINDOWS) dll
(/SUBSYSTEM:CONSOLE)

Change extension
*/

/*
u10A5u109Au109Eu109Eu1099u10A8u10A8u109Au109Du109Fu109C PlayerManager
u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1 ChatBox
u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A GameManager
u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F SteamManager
u109Bu10A2u10A4u10A6u109Du10A3u109Cu1099u109Du109Cu10A4 LobbyManager
u10A0u10A8u10A0u10A4u10A8u10A0u109Au10A5u10A7u10A7u109C ServerSend
u1099u10A5u109Fu10A8u1099u10A4u10A4u109Du109Du10A1u10A0 ServerHandle
u109Du10A8u10A0u109Bu109Bu10A0u109Cu109Cu10A6u109Au10A7 ClientSend
u109Du10A8u10A4u109Bu1099u109Du10A2u10A1u10A3u10A0u10A3 GameServer

[01/06 - v2.2-dev]
Todo:

add cinfo, pinfo(alias)
[ok]change perm (multiple perms at once)
add pperm
[ok] remove toggleweapon
[ok] add permissions for weapons
[ok]save config
[ok] perm create/remove group

Test:
[ok] player ids and death in chat
[ok] perm
[ok] perm list (page)
[ok] perm groups
[ok] permissions for weapons
[ok] config
[ok] perm create/remove group

[11/06 - v2.3-dev]
*/