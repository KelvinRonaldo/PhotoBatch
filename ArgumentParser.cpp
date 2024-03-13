#include "ArgumentParser.h"
#include "Utils.h"


void ArgumentParser::registerFlag(const std::string& flag) {
	if (!flag.empty()) {
		m_Flags[flag] = false;
	}
}

void ArgumentParser::registerOption(const std::string& option) {
	if (!option.empty())
		m_Options[option];
}

bool ArgumentParser::getFlag(const std::string& flag) const {

	if (!flag.empty()) {
		auto flagIt = m_Flags.find(flag);
		if (flagIt != std::end(m_Flags)) {
			return flagIt->second;
		}
	}
	return false;
}

const std::string& ArgumentParser::getOption(const std::string& option) const
{
	if (!option.empty()) {
		auto optionIt = m_Options.find(option);
		if (optionIt != std::end(m_Options)) {
			optionIt->second;
		}
	}

	static std::string emptyOption = "";
	return emptyOption;
}

void ArgumentParser::parse(int argc, char* argv[]) {
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			std::string arg = Utils::toLower(argv[i]);
			if (arg.length() >= 3) {
				// Argumentos tem que ter ao menos 3 caractéres,
				// "--" seguido de algum outro
				if (arg.substr(0, 2) == "--") {
					// Remove -- da flag
					arg = arg.substr(2);
					if (arg.find_first_of('=') != std::string::npos) {
						// Isso é uma opção, se não uma flag
					}
					else
					{
						auto flagIt = m_Flags.find(arg);
						if (flagIt != std::end(m_Flags)) {
							flagIt->second = true;
						}
					}
				}
			}
		}
	}
}
