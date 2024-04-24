#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:
	void set(const std::string& str);

	std::string get() const;

	void announce(void) const;

	Zombie() : name("Default") {}
	Zombie(std::string name) : name(name) {}

private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
