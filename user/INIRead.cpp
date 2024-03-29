#include "pch-il2cpp.h"
#include "INIRead.h"

std::string INIRead::GetString(std::string path, std::string app, std::string key)
{
	char valueRead[320];

	GetPrivateProfileStringA(
		app.c_str(),
		key.c_str(),
		"",
		valueRead,
		320,
		path.c_str()
	);

	/*
	std::cout << "[INIRead] GetString '" << key << "' [" << app << "]" << std::endl;
	std::cout << "[INIRead] " << std::string(valueRead) << std::endl;
	std::cout << "[INIRead] " << path << std::endl;
	*/

	return std::string(valueRead);
}

int INIRead::GetInt(std::string path, std::string app, std::string key, int defaultValue)
{
	auto valueStr = GetString(path, app, key);

	if (valueStr.empty()) return defaultValue;

	return std::atoi(valueStr.c_str());
}

float INIRead::GetFloat(std::string path, std::string app, std::string key, float defaultValue)
{
	auto valueStr = GetString(path, app, key);

	if (valueStr.empty()) return defaultValue;

	return (float)std::atof(valueStr.c_str());
}

bool INIRead::GetBool(std::string path, std::string app, std::string key, bool defaultValue)
{
	auto valueStr = toLower(GetString(path, app, key));

	if (valueStr.empty()) return defaultValue;

	return valueStr.compare("true") == 0;
}

std::vector<std::string> INIRead::GetMultipleStrings(std::string path, std::string app)
{
	std::ifstream infile(path);

	std::vector<std::string> lines;

	bool canAdd = false;

	std::string line;
	while (std::getline(infile, line))
	{
		//std::cout << line << std::endl;
		//std::cout << line.front() << std::endl;

		std::string findApp = "[" + app + "]";
		if (strcmp(findApp.c_str(), line.c_str()) == 0)
		{
			canAdd = true;
			continue;
		}

		if (canAdd)
		{
			if (line.empty() || line.front() == '[') break; //line.front() == ' '
			
			lines.push_back(line);
		}
	}

	infile.close();
	
	return lines;
}





std::ofstream INIWrite::File;

void INIWrite::CreateINIFile(std::string path)
{
	File.open(path);
}

void INIWrite::AddLine(std::string value)
{
	File << value << std::endl;
}

void INIWrite::AddString(std::string key, std::string value)
{
	File << key << " = " << value << std::endl;
}

void INIWrite::AddInt(std::string key, int value)
{
	File << key << " = " << value << std::endl;
}

void INIWrite::AddFloat(std::string key, float value)
{
	File << key << " = " << value << std::endl;
}

void INIWrite::AddBool(std::string key, bool value)
{
	File << key << " = " << (value ? "true" : "false") << std::endl;
}

void INIWrite::CloseINIFile()
{
	File.close();
}