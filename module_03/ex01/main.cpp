#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
	ScavTrap object("John");

	std::cout << object;

	object.guardGate();

	object.attack("Paul");

	std::cout << object;

	return (0);
}
