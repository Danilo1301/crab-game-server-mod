#pragma once

#include "pch.h"
#include "Mod.h"



class Injector {
public:
	static bool Init() {
		if (MH_Initialize() != MH_OK) {
			MessageBox(NULL, L"NOT INIT", L"HOOKED", NULL);
			return 0;
		}

		Mod::m_AssemblyBase = (uintptr_t)GetModuleHandleW(L"GameAssembly.dll");
		Mod::m_CrabGameBase = (uintptr_t)GetModuleHandleW(L"Crab Game.exe");

		return 1;
	}

	static bool Hook(LPVOID pTarget, LPVOID pDetour, LPVOID* pOriginal) {
		if (MH_CreateHook(pTarget, pDetour, pOriginal) == MH_OK) {
			MH_EnableHook(pTarget);
			return 1;
		}

		return 0;
	}
};
