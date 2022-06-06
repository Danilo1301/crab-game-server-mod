#pragma once

#include "pch.h"

template<class Ret, class... Args>
class HookFunction {
public:
	typedef Ret(__stdcall* T)(Args...);

	std::string name;
	T original = nullptr;
	LPVOID _target = nullptr;
	LPVOID _detour = nullptr;

	//std::function<void(std::function<void(Args...)> original)> testFn;

	//HookFunction(std::string name, std::function<void(std::function<void(Args...)> original)> fn) {
	HookFunction(std::string name)
	{
		this->name = name;
	}
};

class Injector {
public:
	template<class... T>
	static bool Inject(HookFunction<T...>* fn, LPVOID target, LPVOID detour)
	{
		fn->_target = target;
		fn->_detour = detour;

		std::string prefix = "[Injector - " + fn->name + "] ";

		if (MH_CreateHook(
			fn->_target, // u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1_Update,
			fn->_detour, // &Template
			reinterpret_cast<void**>(&fn->original)
		) != MH_OK) {
			std::cout << prefix << "Failed to create hook" << std::endl;
			return false;
		}

		if (MH_EnableHook(fn->_target) != MH_OK) {
			std::cout << prefix << "Enable hook failed" << std::endl;
			return false;
		}
		std::cout << prefix << "Hooked" << std::endl;

		return true;
	}

	static void Init()
	{
		if (MH_Initialize() != MH_OK) {
			std::cout << "[Injector] MinHook failed initialize" << std::endl;
			return;
		}

		//m_AssemblyBase = (uintptr_t)GetModuleHandleW(L"GameAssembly.dll");

		std::cout << "[Injector] MinHook initialized" << std::endl;
	}
};

