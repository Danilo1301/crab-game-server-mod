#pragma once

#include "pch.h"

class CommandArg {
public:
	bool isNumber = false;
	bool isString = true;
	bool canSplit = false;
	std::string str;

	CommandArg(std::string s)
	{
		str = s;

		if (is_number(str) || is_float(str))
		{
			isNumber = true;
			isString = false;
		}

		canSplit = str.find(",") != -1;
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

	std::vector<std::string> SplitStr()
	{
		if (!canSplit)
		{
			std::vector<std::string> vec;
			vec.push_back(str);
			return vec;
		}
		return split_1(str, ',');
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