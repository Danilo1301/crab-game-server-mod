#pragma once

#include "pch.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iterator>

class Command {
	std::string m_Text;
	std::string m_Cmd;
	std::vector<std::string> m_TextElems;
public:
	Command(std::string text) {

		m_Text = text;
		split(m_Text, ' ', std::back_inserter(m_TextElems));

		std::string str = m_TextElems.at(0);
		std::remove_copy(str.begin(), str.end(), std::back_inserter(m_Cmd), '!');
	}

	std::string GetCmd() {
		return m_Cmd;
	}

	std::string GetArgString(int index) {
		int i = index + 1;
		return m_TextElems.at(i);
	}

	std::string GetArgText(int index) {
		std::string s;

		int size = (int)m_TextElems.size();
		for (int i = 1; i < size; i++) {
			s += m_TextElems.at(i);
			if (i != size - 1) s += " ";
		}

		return s;
	}

	int GetArgInt(int index) {
		return std::stoi(GetArgString(index));
	}

	float GetArgFloat(int index) {
		return std::stof(GetArgString(index));
	}

	long long GetArgULong(int index) {
		return std::stoll(GetArgString(index));
	}

	bool Check(std::string str) {
		if (str.compare(m_Cmd) == 0) return true;
		return false;
	}

	bool HasArg(int index)
	{
		int i = index + 1;
		return (m_TextElems.size() - 1) >= i;
	}
};