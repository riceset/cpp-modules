#include "phonebook.hpp"

std::string Contact::formatString(const std::string str) const {
	return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}
