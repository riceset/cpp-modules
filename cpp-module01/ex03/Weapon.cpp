#include "Weapon.hpp"

const std::string& Weapon::getType() const {
	return (type);
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}

Weapon::Weapon() : type("") {}

Weapon::Weapon(const std::string& newType) : type(newType) {}
