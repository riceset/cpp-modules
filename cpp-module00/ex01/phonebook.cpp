#include <iostream>
#include <iomanip>

std::string promptUser(std::string prompt) {
	std::string result;

	std::cout << prompt;
	std::cin >> result;

	return (result);
}

class Contact {
public:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class Phonebook {
private:
	int		index;
	Contact contacts[8];

public:
	Phonebook() : index(0) {}

	void add() {
		if (index == 8) {
			index = 0;
		}

		contacts[index].firstName = promptUser("Enter first name: ");
		contacts[index].lastName = promptUser("Enter last name: ");
		contacts[index].nickname = promptUser("Enter nickname: ");
		contacts[index].phoneNumber = promptUser("Enter phone number: ");
		contacts[index].darkestSecret = promptUser("Enter darkest secret: ");
		std::cout << "Successfully added contact!" << std::endl;

		index++;
	}

	void search(void) {
		
		for (int i = 0; i < index; i++) {
			std::cout << std::setw(10) << i << " | ";
			std::cout << std::setw(10) << contacts[i].firstName << " | ";;
			std::cout << std::setw(10) << contacts[i].lastName << " | ";;
			std::cout << std::setw(10) << contacts[i].nickname << std::endl;
		}
	}
};

int main(void) {
	Phonebook book;
	std::string command;

	while (true) {
		command = promptUser("phonebook> ");

		if (command == "ADD")
			book.add();
		else if (command == "SEARCH") {
			book.search();
		}
		else if (command == "EXIT") {
			std::cout << "Exit." << std::endl;
			break ;
		}
		else {
			std::cout << "Invalid command." << std::endl;
		}
	}
}
