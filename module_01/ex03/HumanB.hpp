#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	const std::string& getName() const;
	void setName(const std::string& newName);

	const Weapon& getWeapon() const;
	void setWeapon(const Weapon& newWeapon);

	void attack() const;

	HumanB(const std::string& name);

private:
	std::string name;
	Weapon &weapon;
};

#endif
