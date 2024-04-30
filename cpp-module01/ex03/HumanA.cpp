#include "HumanA.hpp"

std::string HumanA::getName() const {
	return (name);
}
void HumanA::setName(const std::string& newName) {
	name = newName;
}

Weapon HumanA::getWeapon() const {
	return (weapon);
}
void HumanA::setWeapon(const Weapon& newWeapon) {
	weapon = newWeapon;
}

void HumanA::attack() const {
	if (getName() == "") {
		std::cout << "Please provide a name!" << std::endl;

		return ;
	} else if (getWeapon().getType() == "") {
		std::cout << "Please provide a weapon!" << std::endl;

		return ;
	}
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}
