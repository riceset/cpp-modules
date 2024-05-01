#include "phonebook.hpp"

void Contact::promptContact(const std::string message, void (Contact::*set)(const std::string&)) {
	std::string input;

	prompt(input, message);
	(this->*set)(input);
}

void Contact::fillDetails() {
    promptContact("Enter First Name: ", &Contact::setFirstName);
    promptContact("Enter Last Name: ", &Contact::setLastName);
    promptContact("Enter Nickname: ", &Contact::setNickname);
    promptContact("Enter Phone Number: ", &Contact::setPhoneNumber);
    promptContact("Enter Darkest Secret: ", &Contact::setDarkestSecret);
}
