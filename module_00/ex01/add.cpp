#include "phonebook.hpp"

void Phonebook::add(void) {
	if (contactIndex < MAX_CONTACTS) {
		contacts[contactIndex].fillDetails();
		contactIndex++;
		if (contactsAddedCount <= MAX_CONTACTS - 1)
			contactsAddedCount++;
	} else {
		contactIndex = 0;
	}
}
