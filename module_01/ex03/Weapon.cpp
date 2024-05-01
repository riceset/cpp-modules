#include "Weapon.hpp"

Weapon::Weapon(const std::string& newType) : type(newType) {
	return ;
}

Weapon::~Weapon() {
	return ;
}

const std::string& Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(const std::string& newType) {
	this->type = newType;
}
