#include "pch-il2cpp.h"
#include "pch.h"

//#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include <httplib.h>
//#include "stdafx.h"

#include "Mod.h"

extern const LPCWSTR LOG_FILE = L"CrabGameServerMod.log";

void Run()
{
    auto thread = il2cpp_thread_attach(il2cpp_domain_get());
    //il2cppi_log_write("Startup");
    il2cppi_new_console();

    Mod::Init();
}

int main()
{
    Mod::ConsoleMode = true;
    Mod::Init();
}
