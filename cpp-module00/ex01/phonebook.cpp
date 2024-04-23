#include "phonebook.hpp"

void Phonebook::search() {
	for (int i = 0; i < contactsAddedCount; ++i) {
		std::cout << std::setw(10) << i;
		std::cout << "|";

		std::cout << std::setw(10) << contacts[i].getFirstName();
		std::cout << "|";

		std::cout << std::setw(10) << contacts[i].getLastName();
		std::cout << "|";

		std::cout << std::setw(10) << contacts[i].getNickname();
		std::cout << std::endl;
	}
}

int main(void) {
	Phonebook phonebook;
	std::string input;

	while (true) {
		if (prompt(input) == PROMPT_ERROR) {
			break ;
		}
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
