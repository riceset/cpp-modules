#include "phonebook.hpp"

const std::string& Contact::getFirstName() const {
	return firstName;
}

const std::string& Contact::getLastName() const {
	return lastName;
}

const std::string& Contact::getNickname() const {
	return nickname;
}

const std::string& Contact::getPhoneNumber() const {
	return phoneNumber;
}
const std::string& Contact::getDarkestSecret() const {
	return darkestSecret;
}
