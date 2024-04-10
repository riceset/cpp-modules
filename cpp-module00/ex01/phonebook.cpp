#include <iostream>
#include <iomanip>

#define PROMPT_ERROR 1
#define PROMPT_SUCCESS 0

class Contact {
public:
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const { return darkestSecret; }

	void setFirstName(const std::string &value) { firstName = value; }
	void setLastName(const std::string &value) { lastName = value; }
	void setNickname(const std::string &value) { nickname = value; }
	void setPhoneNumber(const std::string &value) { phoneNumber = value; }
	void setDarkestSecret(const std::string &value) { darkestSecret = value; }

	void fillDetails() {
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	setDarkestSecret(input);
	}

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class Phonebook {
public:
	Phonebook() : index(0) {}

	void add() {
		if (index < 8) {
			contacts[index].fillDetails();
			index++;
		} else {
			index = 0;
		}
	}
	void search() {
		for (int i = 0; i < index; ++i) {
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
private:
	int index;
	Contact contacts[8];
};

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
