#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:

	void setName(const std::string& str);
	std::string getName() const;
	void announce(void) const;

	Zombie();

	explicit Zombie(std::string& newName);

private:
	std::string name;
};

Zombie* zombieHorde(int n, std::string name);

#endif
