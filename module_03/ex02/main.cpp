#include "FragTrap.hpp"
#include <iostream>

int main(void) {
	FragTrap object("Jacob");

	std::cout << object;

	object.attack("Paul");

	std::cout << object;

	object.beRepaired(UINT_MAX);

	std::cout << object;

	object.takeDamage(UINT_MAX - 1);

	std::cout << object;

	object.highFivesGuys();

	return (0);
}
