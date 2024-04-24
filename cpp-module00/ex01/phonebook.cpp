#include "phonebook.hpp"

int main(void) {
	Phonebook phonebook;
	std::string input;

	while (true) {
		prompt(input, "phonebook> ");

		if (input == "ADD") {
			phonebook.add();
		}
		if (input == "SEARCH") {
			phonebook.search();
		}
		if (input == "EXIT") {
			std::cout << "Exit" << std::endl;
			break ;
		}
	}
}
