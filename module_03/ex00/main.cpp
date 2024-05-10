#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
	ClapTrap object("Jacob");

	std::cout << object;

	object.attack("Paul");

	std::cout << object;

	object.beRepaired(UINT_MAX);

	std::cout << object;

	object.takeDamage(UINT_MAX - 1);

	std::cout << object;

	return (0);
}
