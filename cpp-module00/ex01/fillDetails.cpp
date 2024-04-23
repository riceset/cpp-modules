#include "phonebook.hpp"

void Contact::promptContact(const std::string prompt, void (Contact::*set)(const std::string&)) {
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	(this->*set)(input);
}

void Contact::fillDetails() {
    promptContact("Enter First Name: ", &Contact::setFirstName);
    promptContact("Enter Last Name: ", &Contact::setLastName);
    promptContact("Enter Nickname: ", &Contact::setNickname);
    promptContact("Enter Phone Number: ", &Contact::setPhoneNumber);
    promptContact("Enter Darkest Secret: ", &Contact::setDarkestSecret);
}
