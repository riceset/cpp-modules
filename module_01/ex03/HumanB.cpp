#include "HumanB.hpp"
#include <iostream>

const std::string& HumanB::getName() const {
	return (this->name);
}

void HumanB::setName(const std::string& newName) {
	this->name = newName;
}

const Weapon& HumanB::getWeapon() const {
	return (*this->weapon);
}

void HumanB::setWeapon(Weapon& newWeapon) {
	this->weapon = &newWeapon;
}

void HumanB::attack() {
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(const std::string& newName) : name(newName), weapon(NULL) {
	return ;
}

HumanB::~HumanB() {
	return ;
}
