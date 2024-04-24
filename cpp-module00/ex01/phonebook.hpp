#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>

#define PROMPT_ERROR 1
#define PROMPT_SUCCESS 0
#define MAX_CONTACTS 2

class Contact {
public:
	std::string formatString(const std::string str) const;

	//Getters
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickname() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;
	//Setters
	void setFirstName(const std::string &value);
	void setLastName(const std::string &value);
	void setNickname(const std::string &value);
	void setPhoneNumber(const std::string &value);
	void setDarkestSecret(const std::string &value);

	//Others
	void fillDetails(void);
	void promptContact(const std::string prompt, void (Contact::*set)(const std::string&));
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class Phonebook {
public:
	void add(void);
	void search(void);

	Phonebook() : contactID(0), contactIndex(0), contactsAddedCount(0) {}
private:
	Contact contacts[8];
	int contactID;
	int contactIndex;
	int contactsAddedCount;
};

int prompt(std::string &input);

#endif
