#include "Zombie.hpp"

void Zombie::setName(const std::string& newName) {
	name = newName;
}

std::string Zombie::getName() const {
	return (name);
}

void Zombie::announce(void) const {
	std::cout << name << ": " << ZOMBIE_MSG << std::endl;
}

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string& newName) : name(newName) {}

Zombie::~Zombie() {
	std::cout << this->name << " destroyed." << std::endl;
}
