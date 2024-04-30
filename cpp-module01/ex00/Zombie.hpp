#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:
	//Getters and Setters
	void setName(const std::string& newName);
	std::string getName() const;

	//Methods
	void announce() const;

	//Default Constructor
	Zombie() : name("Default") {}

	//Parameterized Constructor
	explicit Zombie(std::string& newName) : name(newName) {}

private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
