/*
* 
#pragma once

#include "Injector.h"

template<class Ret, class... Args>
class HookFunctionEvent {
public:
	typedef Ret(__stdcall* T)(Args...);

	std::string name;
	T original = nullptr;

	HookFunctionEvent(std::string name)
	{
		this->name = name;

		std::cout << "[HookFunctionEvent : " << name << "] Created" << std::endl;
	}

	bool RunBefore(Args... args)
	{
		std::cout << "[HookFunctionEvent : " << name << "] RunBefore" << std::endl;

		return true;
	}

	bool RunAfter()
	{
		std::cout << "[HookFunctionEvent : " << name << "] RunAfter" << std::endl;

		return true;
	}
};
*/



/*
struct EventFunction
{
	std::string key;
	std::function<bool()> fn;
	bool runBefore;
};

class Events {
public:
	static std::map<std::string, std::vector<EventFunction*>> eventFunctions;

	static void Listen(std::string eventName, std::string functionKey, std::function<bool()> fn, bool runBefore);
	static bool RunBefore(std::string eventName);
	static bool RunAfter(std::string eventName);
	static int GetEventFuctionsCount(std::string eventName);
};
*/