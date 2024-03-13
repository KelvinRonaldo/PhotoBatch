#pragma once

#include <string>
#include <map>

class ArgumentParser {
public:
	void registerFlag(const std::string& flag);
	void registerOption(const std::string& option);
	bool getFlag(const std::string& flag) const;
	const std::string& getOption(const std::string& option) const;
	void parse(int argc, char* argv[]);

private:
	std::map<std::string, bool> m_Flags;
	std::map<std::string, std::string> m_Options;
};
