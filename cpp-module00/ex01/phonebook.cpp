#include <iostream>

#define PROMPT_ERROR 1
#define PROMPT_SUCCESS 0

int prompt(std::string &input) {
	std::cout << "phonebook> ";
	if (!(std::cin >> input)) {
		if (std::cin.eof()) {
			std::cout << "EOF" << std::endl;
			return (PROMPT_ERROR);
		}
	}
	return (PROMPT_SUCCESS);
}

int main(void) {
	std::string input;

	while (true) {
		if (prompt(input) == PROMPT_ERROR) {
			break ;
		}
		if (input == "ADD") {
			std::cout << "Adding!" << std::endl;
		}
		if (input == "SEARCH") {
			std::cout << "Searching!" << std::endl;
		}
		if (input == "EXIT") {
			std::cout << "Exit" << std::endl;
			break ;
		}
	}
}
