#include "ChatCommand.h"

std::map<std::string, CommandData*> ChatCommand::m_Commands;

CommandData* ChatCommand::AddCommand(std::string cmd) {
	CommandData* cmdData = new CommandData();
	m_Commands.insert(std::pair<std::string, CommandData*>(cmd, cmdData));
	return cmdData;
}

