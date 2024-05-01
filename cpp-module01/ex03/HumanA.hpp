#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	const std::string& getName() const;
	void setName(const std::string& newName);

	const Weapon& getWeapon() const;
	void setWeapon(const Weapon& newWeapon);

	void attack() const;

	HumanA();
	HumanA(const std::string& name, const Weapon& weapon);

private:
	std::string name;
	Weapon weapon;
};

#endif
