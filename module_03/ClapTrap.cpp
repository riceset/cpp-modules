#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name(""), hit(10), energy(10), damage(0) {}

ClapTrap::ClapTrap(const std::string& newName)
	: name(newName), hit(10), energy(10), damage(0) {}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hit(other.hit), energy(other.energy), damage(other.damage) {}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->name = other.name;
		this->hit = other.hit;
		this->energy = other.energy;
		this->damage = other.damage;
	}

	return (*this);
}

ClapTrap::~ClapTrap() {}
