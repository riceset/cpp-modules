#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	const std::string& getName() const;
	void setName(const std::string& newName);

	const Weapon& getWeapon() const;
	void setWeapon(const Weapon& newWeapon);

	void attack();

	HumanA(const std::string& name, Weapon& newWeapon);
	~HumanA();

private:
	std::string name;
	Weapon& weapon;
};

#endif
