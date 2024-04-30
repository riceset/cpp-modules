#include "HumanB.hpp"

std::string HumanB::getName() const {
	return (name);
}
void HumanB::setName(const std::string& newName) {
	name = newName;
}

Weapon HumanB::getWeapon() const {
	return (weapon);
}
void HumanB::setWeapon(const Weapon& newWeapon) {
	weapon = newWeapon;
}

void HumanB::attack() const {
	if (getName() == "") {
		std::cout << "Please provide a name!" << std::endl;

		return ;
	} else if (getWeapon().getType() == "") {
		std::cout << "Please provide a weapon!" << std::endl;

		return ;
	}
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}
