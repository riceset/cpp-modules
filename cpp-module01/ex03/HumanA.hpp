#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	std::string getName() const;
	void setName(const std::string& newName);

	Weapon getWeapon() const;
	void setWeapon(const Weapon& newWeapon);

	void attack() const;

	HumanA() {
		this->name = "";
		this->weapon = Weapon();
	}

	HumanA(const std::string& name, const Weapon& weapon) {
		this->name = name;
		this->weapon = weapon;
	}

private:
	std::string name;
	Weapon weapon;
};

#endif
