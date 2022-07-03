#pragma once

#include "Injector.h"

template<class Ret, class... Args>
class TemplateEvent {
public:
	std::vector<std::function<bool(Args...)>> before;
	std::vector<std::function<bool(Args...)>> after;

	TemplateEvent(HookFunction<Ret, Args...>* hf)
	{
		
	}

	void RunAll(Args... args)
	{
		std::cout << "[TemplateEvent]" << std::endl;

		for (auto fn : before)
		{
			bool a = fn(args);
		}
	}
};