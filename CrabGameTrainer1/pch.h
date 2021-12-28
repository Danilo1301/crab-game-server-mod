#pragma once

#include "Windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <Psapi.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <chrono>

#include <MinHook.h>

#if _WIN64
#pragma comment(lib, "libMinHook.x64.lib")
#else
#pragma comment(lib, "libMinHook.x86.lib")
#endif

#include "il2cpp.h"

struct Vector3 {
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {};
	~Vector3() {};
};

typedef struct _monoString
{
	void* klass;
	void* monitor;
	int length;
	char chars[256];
	int getLength()
	{
		return length;
	}
	char* getChars()
	{
		return chars;
	}
	std::string toCPPString()
	{
		char* p = getChars();

		char fullStr[128];

		for (int i = 0; i < getLength(); i++) {

			int index = i * 2;
			char b = *(p + index);

			fullStr[i] = b;


		}

		fullStr[getLength()] = 0;

		return std::string(fullStr);
	}
} monoString;
