#include "ClapTrap.hpp"
#include <iostream>

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
	if (energy > 0 && hit > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!" << std::endl;
		energy--;

	} else {
		std::cout << "ClapTrap " << name << " is out of energy or hit points and cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit > 0) {
		hit = (amount > hit) ? 0 : (hit - amount);
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy > 0 && hit > 0) {
		unsigned int actualRecoveryAmount = (UINT_MAX - hit < amount) ? (UINT_MAX - hit) : amount;

        std::cout << "ClapTrap " << name << " repairs itself, recovering " << actualRecoveryAmount << " hit points!" << std::endl;

		hit += actualRecoveryAmount;
		energy--;
	} else {
		std::cout << "ClapTrap " << name << " is out of energy or hit points and cannot repair itself!" << std::endl;
	}
}
