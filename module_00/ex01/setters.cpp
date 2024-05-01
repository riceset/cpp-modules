#include "phonebook.hpp"

void Contact::setFirstName(const std::string &value) {
	firstName = formatString(value);
}

void Contact::setLastName(const std::string &value) {
	lastName = formatString(value);
}

void Contact::setNickname(const std::string &value) {
	nickname = formatString(value);
}

void Contact::setPhoneNumber(const std::string &value) {
	phoneNumber = formatString(value);
}

void Contact::setDarkestSecret(const std::string &value) {
	darkestSecret = formatString(value);
}
