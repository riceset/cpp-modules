#include "HumanA.hpp"
#include <iostream>

const std::string& HumanA::getName() const {
	return (name);
}

void HumanA::setName(const std::string& newName) {
	this->name = newName;
}

const Weapon& HumanA::getWeapon() const {
	return (weapon);
}

void HumanA::setWeapon(const Weapon& newWeapon) {
	this->weapon = newWeapon;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(const std::string& newName, Weapon& newWeapon) : name(newName), weapon(newWeapon) {
	return ;
}

HumanA::~HumanA() {
	return ;
}
