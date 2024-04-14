#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:
	void set(std::string str) {
		name = str;
	}

	std::string get() {
		return (name);
	}

	void announce(void) {
		std::cout << name << ": " << ZOMBIE_MSG << std::endl;
	}

	Zombie() : name("Default") {}
	Zombie(std::string name) : name(name) {}

private:
	std::string name;
};

Zombie* zombieHorde(int n, std::string name);

#endif
