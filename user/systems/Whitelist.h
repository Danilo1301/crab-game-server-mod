#pragma once

#include "pch.h"

class Whitelist {
private:
	static std::vector<long long> PlayerIds;
public:
	static bool Enabled;

	static bool HasId(long long id);
	static void AddId(long long id);
	static void RemoveId(long long id);
	static bool CanIdJoin(long long id);

	static void SaveToFile();
	static void LoadFromFile();
};