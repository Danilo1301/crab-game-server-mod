#pragma once

#define WIN32_LEAN_AND_MEAN
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

# define M_PI 3.14159265358979323846

#include "il2cpp-appdata.h"
#include "helpers.h"

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
#include <fstream>

#include "MinHook.h"
#include "sio_client.h"
#include "json/json.h"

#include <experimental/filesystem>

#pragma comment(lib, "libMinHook.x64.lib")
#pragma comment(lib, "sioclient.lib")

using namespace app;

static uintptr_t m_AssemblyBase = 0;

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

//template <typename Out>
static std::vector<std::string> split_1(const std::string& s, char delim) { //, Out result) {
	std::istringstream iss(s);
	std::string item;
	std::vector<std::string> parts;
	while (std::getline(iss, item, delim)) {
		//*result++ = item;
		parts.push_back(item);
	}
	return parts;
}

static std::string formatStringVector(std::vector<std::string> vector, std::string separator) {
	std::string result = "";
	for (size_t i = 0; i < vector.size(); i++)
	{
		auto s = vector[i];
		result += s + (i != vector.size()-1 ? separator : "");
	}

	return result;
}

static std::vector<std::string> formatStringVector_1(std::vector<std::string> vector, std::string separator, int maxLineChars) {
	std::string str = "";
	std::vector<std::string> lines;

	for (size_t i = 0; i < vector.size(); i++)
	{
		auto s = vector[i];

		if (str.length() + s.length() >= maxLineChars) {
			//std::cout << "LINE = (" << str << ")\n";
			lines.push_back(std::string(str));
			str = "";
		}

		str += (str.length() == 0 ? "" : separator) + s;
	}

	if (str.length() > 0) lines.push_back(std::string(str));

	return lines;
}

/*
static monoString* createMonoString(const char* str) {
	monoString* (*String_CreateString)(void* _this, const char* str) = (monoString * (*)(void*, const char*))(m_AssemblyBase + 8780720);
	return String_CreateString(NULL, str);
}
*/

static std::string toUpper(std::string data) {
	std::for_each(data.begin(), data.end(), [](char& c) {
		c = ::toupper(c);
		});
	return data;
}

static std::string toLower(std::string data) {
	std::for_each(data.begin(), data.end(), [](char& c) {
		c = ::tolower(c);
		});
	return data;
}

static bool is_float(std::string s)
{
	std::istringstream iss(s);
	float f;
	iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}

static bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}


static InteropHelp_UTF8StringHandle* stringToUTF8StringHandle(std::string str)
{
	auto h = new InteropHelp_UTF8StringHandle();
	InteropHelp_UTF8StringHandle__ctor(h, (String*)il2cpp_string_new(str.c_str()), NULL);
	return h;
}

static bool ends_with(std::string const& value, std::string const& ending)
{
	if (ending.size() > value.size()) return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

static bool starts_with(std::string const& value, std::string const& starting)
{
	if (starting.size() > value.size()) return false;
	return std::equal(starting.rend(), starting.rbegin(), value.rbegin());
}

static bool ConvertTimeStringToSeconds(std::string str, int* outSeconds)
{
	//std::cout << "ConvertStringTimeToSeconds (" << str << ")" << std::endl;

	if (str.length() <= 1) return false;

	//std::cout << ">1" << std::endl;

	bool endsWithTimeKey = ends_with(str, "d") ||
		ends_with(str, "h") ||
		ends_with(str, "m") ||
		ends_with(str, "s");

	if (!endsWithTimeKey) return false;

	//std::cout << "endsWithTimeKey" << std::endl;


	std::string timeStr = str.substr(0, str.size() - 1);

	//std::cout << "timeStr=" << timeStr << std::endl;

	if (!is_number(timeStr)) return false;

	//std::cout << "timeStr is number" << std::endl;

	int val = (int)floor(std::stof(str));
	if (val <= 0 && !starts_with(str, "0"))
	{
		*outSeconds = -1;
		return true;
	}

	//std::cout << "default val is" << val << std::endl;
	//std::cout << "comparing with " << str << std::endl;

	*outSeconds = val;
	if (ends_with(str, "m")) *outSeconds = val * 60;
	if (ends_with(str, "h")) *outSeconds = val * 60 * 60;
	if (ends_with(str, "d")) *outSeconds = val * 60 * 60 * 24;

	//std::cout << *outSeconds << std::endl;

	return true;
}