#include "phonebook.hpp"

void Phonebook::searchID(void) {
	std::string input;
	int id;

	prompt(input, "ID> ");
	try {
		id = std::stoi(input);
	} catch (...) {
		std::cerr << "Please enter a valid ID." << std::endl;
		return ;
	}

	if (id <= contactIndex) {
		std::cout << "First name: " << contacts[id].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[id].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[id].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[id].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[id].getDarkestSecret() << std::endl;
	} else {
		std::cerr << "Contact does not exist!" << std::endl;
	}
}

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
	searchID();
}
