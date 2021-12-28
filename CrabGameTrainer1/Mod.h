#pragma once

#include "pch.h"

class Mod {
public:
	static uintptr_t m_AssemblyBase;
	static uintptr_t m_CrabGameBase;

	static uintptr_t GetAssemblyOffset(uintptr_t offset) {
		return m_AssemblyBase + offset;
	}

	static monoString* CreateMonoString(const char* str) {
		monoString* (*String_CreateString)(void* _this, const char* str) = (monoString * (*)(void*, const char*))(Mod::GetAssemblyOffset(8787312));
		return String_CreateString(NULL, str);
	}

	static uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName)
    {
        uintptr_t modBaseAddr = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
        if (hSnap != INVALID_HANDLE_VALUE)
        {
            MODULEENTRY32 modEntry;
            modEntry.dwSize = sizeof(modEntry);
            if (Module32First(hSnap, &modEntry))
            {
                do
                {
                    if (!_wcsicmp(modEntry.szModule, modName))
                    {
                        modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                        break;
                    }
                } while (Module32Next(hSnap, &modEntry));
            }
        }
        CloseHandle(hSnap);
        return modBaseAddr;
    }
};
