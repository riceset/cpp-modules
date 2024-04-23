#include "phonebook.hpp"

int prompt(std::string &input) {
	std::cout << "phonebook> ";
	if (!(std::getline(std::cin,input))) {
		if (std::cin.eof()) {
			std::cout << "EOF" << std::endl;
			return (PROMPT_ERROR);
		}
	}
	return (PROMPT_SUCCESS);
}
