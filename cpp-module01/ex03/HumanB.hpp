#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	std::string getName() const;
	void setName(const std::string& newName);

	Weapon getWeapon() const;
	void setWeapon(const Weapon& newWeapon);

	void attack() const;

	HumanB() {
		this->name = "";
		this->weapon = Weapon();
	}

	HumanB(const std::string& name) {
		this->name = name;
	}

private:
	std::string name;
	Weapon weapon;
};

#endif
