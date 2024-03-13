#include <iostream>
#include <iomanip>

#include "ArgumentParser.h"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "pt_BR");

	ArgumentParser argParser;
	argParser.registerFlag("rename");
	argParser.registerFlag("convert");
	argParser.registerFlag("resize");
	argParser.registerFlag("scale");
	argParser.registerOption("folder");
	argParser.registerOption("amount");

	argParser.parse(argc, argv);

	std::cout << std::boolalpha << "Rename: " << argParser.getFlag("rename") << std::endl;
	std::cout << std::boolalpha << "Convert: " << argParser.getFlag("convert") << std::endl;
	std::cout << std::boolalpha << "Resize: " << argParser.getFlag("resize") << std::endl;
	std::cout << std::boolalpha << "Scale: " << argParser.getFlag("scale") << std::endl;
	std::cout << "Folder: " << argParser.getOption("folder") << std::endl;
	std::cout << "Amount: " << argParser.getOption("amount") << std::endl;

	return 0;
} 

