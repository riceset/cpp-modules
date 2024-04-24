#include "phonebook.hpp"

void prompt(std::string &input, std::string message) {
	std::cout << message;
	if (!(std::getline(std::cin,input))) {
		if (std::cin.eof()) {
			std::cout << "EOF" << std::endl;
			exit(1);
		}
	}
}
