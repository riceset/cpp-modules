#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("") {
	hit = 100;
	energy = 50;
	damage = 20;
	std::cout << "Default ScavTrap constructed!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	hit = 100;
	energy = 50;
	damage = 20;
	std::string space = name.empty() ? "" : " ";
	std::cout << "ScavTrap" << space << name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::string space = name.empty() ? "" : " ";
	std::cout << "ScavTrap" << space << name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::string space = name.empty() ? "" : " ";
	if (energy > 0 && hit > 0) {
		std::cout << "ScavTrap" << space << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;

	} else {
		std::cout << "ScavTrap " << name << " is out of energy or hit points and cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::string space = name.empty() ? "" : " ";
	std::cout << "ScavTrap" << space << name << " is now guarding the gate." << std::endl;
}
