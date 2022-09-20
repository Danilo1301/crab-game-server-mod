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

#include "MinHook.h"
#include "sio_client.h"
#include "json/json.h"

#pragma comment(lib, "libMinHook.x64.lib")
#pragma comment(lib, "sioclient.lib")

using namespace app;

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

static std::string formatStringVector(std::vector<std::string> vector) {
	std::string result = "";
	for (size_t i = 0; i < vector.size(); i++)
	{
		auto s = vector[i];
		result += s + ";";
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
