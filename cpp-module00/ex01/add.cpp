#include "phonebook.hpp"

void Phonebook::add(void) {
	if (contactIndex < MAX_CONTACTS) {
		contacts[contactIndex].fillDetails();
		contactIndex++;
	} else {
		contactIndex = 0;
	}
}
