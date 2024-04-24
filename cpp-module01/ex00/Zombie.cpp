#include "Zombie.hpp"

void Zombie::set(const std::string& str) {
	name = str;
}

std::string Zombie::get() const {
	return (name);
}

void Zombie::announce(void) const {
	std::cout << name << ": " << ZOMBIE_MSG << std::endl;
}
