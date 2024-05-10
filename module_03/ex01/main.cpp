#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	ScavTrap object("John");

	std::cout << object;

	object.guardGate();

	object.attack("Paul");

	object.takeDamage(33);

	std::cout << object;

	object.beRepaired(33);

	std::cout << object;

	return (0);
}
