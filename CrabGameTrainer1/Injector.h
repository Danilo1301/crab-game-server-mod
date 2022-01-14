#pragma once

#include "pch.h"

template<class... Args>
class HookFunction {
private:

public:
	typedef void(__stdcall* T)(Args...);

	T original = nullptr;
	T target = nullptr;
	LPVOID detour = nullptr;
	uintptr_t address = 0;

	HookFunction(uintptr_t addr) {
		address = addr;
	}

	void SetTemplate(LPVOID pDetour) {
		detour = pDetour;
	}

	bool Hook(uintptr_t offset) {
		target = (T)(offset + address);
		LPVOID pTarget = reinterpret_cast<void**>(target);

		auto status = MH_CreateHook(
			pTarget,
			detour,
			reinterpret_cast<void**>(&original)
		);

		if (status == MH_OK) {
			MH_EnableHook(pTarget);
			return true;
		}

		MessageBox(NULL, L"HOOK ERROR", L"HOOK ERROR", NULL);
		return false;
	}
};

class Injector {
public:
	static uintptr_t m_AssemblyBase;
	//static uintptr_t m_CrabGameBase;

	static bool Init() {
		if (MH_Initialize() != MH_OK) {
			MessageBox(NULL, L"NOT INIT", L"HOOKED", NULL);
			return 0;
		}

		m_AssemblyBase = (uintptr_t)GetModuleHandleW(L"GameAssembly.dll");
		//m_CrabGameBase = (uintptr_t)GetModuleHandleW(L"Crab Game.exe");

		return 1;
	}

	template<class... T>
	static bool Inject(HookFunction<T...> *fn) {
		return fn->Hook(m_AssemblyBase);
	}
};