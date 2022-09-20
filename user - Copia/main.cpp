#include "pch-il2cpp.h"
#include "pch.h"

//#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include <httplib.h>
//#include "stdafx.h"

#include "Mod.h"

extern const LPCWSTR LOG_FILE = L"CrabGameServerMod.log";

void Run()
{
    std::cout << "[main] Run" << std::endl;

    il2cpp_thread_attach(il2cpp_domain_get());

    //il2cppi_log_write("Startup");

    il2cppi_new_console();

    Mod::Init();
}

int main()
{
    std::cout << "[main] main" << std::endl;

    //try to make Release Console works
    Mod::m_ConsoleMode = true;
    Mod::Init();

    return 0;
}