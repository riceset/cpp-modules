#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("") {
	hit = 100;
	energy = 100;
	damage = 30;
	std::cout << "Default FragTrap constructed!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hit = 100;
	energy = 100;
	damage = 30;
	std::string space = name.empty() ? "" : " ";
	std::cout << "FragTrap" << space << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::string space = name.empty() ? "" : " ";
	std::cout << "FragTrap" << space << name << " destructed!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	std::string space = name.empty() ? "" : " ";
	if (energy > 0 && hit > 0) {
		std::cout << "FragTrap" << space << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;

	} else {
		std::cout << "FragTrap" << space << name << " is out of energy or hit points and cannot attack!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	std::string space = name.empty() ? "" : " ";
	if (hit > 0) {
		hit = (amount > hit) ? 0 : (hit - amount);
		std::cout << "FragTrap" << space << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	std::string space = name.empty() ? "" : " ";
	if (energy > 0 && hit > 0) {
		unsigned int actualRecoveryAmount = (UINT_MAX - hit < amount) ? (UINT_MAX - hit) : amount;

        std::cout << "FragTrap" << space << name << " repairs itself, recovering " << actualRecoveryAmount << " hit points!" << std::endl;

		hit += actualRecoveryAmount;
		energy--;
	} else {
		std::cout << "FragTrap" << space << name << " is out of energy or hit points and cannot repair itself!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::string space = name.empty() ? "" : " ";
	std::cout << "FragTrap" << space << name << " requests a high five!" << std::endl;
}
