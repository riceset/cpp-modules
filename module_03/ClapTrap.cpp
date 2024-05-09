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

const std::string& ClapTrap::getName() {
	return (name);
}

unsigned int ClapTrap::getHit() {
	return (hit);
}

unsigned int ClapTrap::getEnergy() {
	return (energy);
}

unsigned int ClapTrap::getDamage() {
	return (damage);
}

void ClapTrap::setName(const std::string& newName) {
	name = newName;
}

void ClapTrap::setHit(unsigned int newHit) {
	hit = newHit;
}

void ClapTrap::setEnergy(unsigned int newEnergy) {
	energy = newEnergy;
}

void ClapTrap::setDamage(unsigned int newDamage) {
	damage = newDamage;
}

void ClapTrap::attack(const std::string& target) {
	(void)target;
}

void ClapTrap::takeDamage(unsigned int amount) {
	(void)amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	(void)amount;
}
