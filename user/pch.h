#pragma once

#include "pch-il2cpp.h"

#include "Windows.h"
#include <iostream>
#include <tlhelp32.h>
#include <Psapi.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <sstream>
#include <chrono>
#include <functional>
#include <algorithm>
#include <cctype>
#include <string>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "il2cpp-appdata.h"
#include "helpers.h"

//delete file
//#include "il2cpp.h"

#include "MinHook.h"
#include "sio_client.h"
#include "json/json.h"

#pragma comment(lib, "libMinHook.x64.lib")
#pragma comment(lib, "sioclient.lib")

using namespace app;

/*
struct Vector3 {
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {};
	~Vector3() {};
};
*/

typedef struct _monoString {
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

template <typename Out>
void split(const std::string& s, char delim, Out result) {
	std::istringstream iss(s);
	std::string item;
	while (std::getline(iss, item, delim)) {
		*result++ = item;
	}
}