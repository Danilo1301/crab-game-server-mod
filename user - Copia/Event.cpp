#include "pch-il2cpp.h"
#include "Event.h"


/*
std::map<std::string, std::vector<EventFunction*>> Events::eventFunctions;

void Events::Listen(std::string eventName, std::string key, std::function<bool()> fn, bool runBefore)
{
	std::cout << "[TemplateEvent] Listen " << eventName << std::endl;

	if (GetEventFuctionsCount(eventName) == 0)
	{
		eventFunctions[eventName] = std::vector<EventFunction*>();
	}

	auto ef = new EventFunction({ key, fn, runBefore });

	eventFunctions[eventName].push_back(ef);
}

bool Events::RunBefore(std::string eventName)
{
	std::cout << "[TemplateEvent] RunBefore " << eventName << std::endl;

	bool result = true;

	if (GetEventFuctionsCount(eventName) != 0)
	{
		for (auto ef : eventFunctions[eventName])
		{
			if (!ef->runBefore) continue;

			std::cout << "[TemplateEvent] Testing '" << ef->key << "'" << std::endl;

			if (ef->fn() == false) result = false;
		}
	}

	return result;
}

bool Events::RunAfter(std::string eventName)
{
	std::cout << "[TemplateEvent] RunAfter " << eventName << std::endl;

	bool result = true;

	if (GetEventFuctionsCount(eventName) != 0)
	{
		for (auto ef : eventFunctions[eventName])
		{
			if (ef->runBefore) continue;

			std::cout << "[TemplateEvent] Testing '" << ef->key << "'" << std::endl;

			if (ef->fn() == false) result = false;
		}
	}

	return result;
}

int Events::GetEventFuctionsCount(std::string eventName)
{
	if (eventFunctions.find(eventName) == eventFunctions.end()) return 0;

	return eventFunctions[eventName].size();
}
*/