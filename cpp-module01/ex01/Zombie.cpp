#include "Zombie.hpp"

void Zombie::setName(const std::string& str) {
	name = str;
}

std::string Zombie::getName() const {
	return (name);
}

void Zombie::announce(void) const {
	std::cout << name << ": " << ZOMBIE_MSG << std::endl;
}
