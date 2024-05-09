#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap object("Jacob");

	std::cout << object.getName() << " " << object.getHit() << " " << object.getEnergy() << " " << object.getDamage() << std::endl;

	object.attack("Paul");

	std::cout << object.getName() << " " << object.getHit() << " " << object.getEnergy() << " " << object.getDamage() << std::endl;

	object.beRepaired(UINT_MAX);

	std::cout << object.getName() << " " << object.getHit() << " " << object.getEnergy() << " " << object.getDamage() << std::endl;
	
	object.takeDamage(UINT_MAX - 1);

	std::cout << object.getName() << " " << object.getHit() << " " << object.getEnergy() << " " << object.getDamage() << std::endl;

	return (0);
}
