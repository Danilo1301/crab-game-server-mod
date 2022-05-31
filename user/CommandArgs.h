#pragma once

#include "pch.h"

class CommandArg {
public:
	bool isNumber = false;
	bool isString = true;
	std::string str;

	CommandArg(std::string s)
	{
		str = s;

		if (is_number(str) || is_float(str))
		{
			isNumber = true;
			isString = false;
		}
	}

	int AsInt() {
		return std::stoi(str);
	}

	bool AsBool() {
		return AsInt() == 1;
	}

	float AsFloat() {
		return std::stof(str);
	}

	long long AsULong() {
		return std::stoll(str);
	}

	static std::vector<CommandArg> GetArgs(std::string s)
	{
		std::vector<CommandArg> cmdArgs;
		auto parts = split_1(s, ' ');

		for (auto part : parts)
		{
			cmdArgs.push_back(CommandArg(part));
		}
		return cmdArgs;
	}
};