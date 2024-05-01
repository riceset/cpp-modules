#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define ZOMBIE_MSG "BraiiiiiiinnnzzzZ..."

class Zombie {
public:
	void setName(const std::string& newName);
	std::string getName() const;

	void announce() const;

	Zombie();

	explicit Zombie(std::string& newName);

	~Zombie();

private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
