#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	const std::string& getName() const;
	void setName(const std::string& newName);

	const Weapon& getWeapon() const;
	void setWeapon(Weapon& newWeapon);

	void attack();

	HumanB(const std::string& name);
	~HumanB();

private:
	std::string name;
	Weapon* weapon;
};

#endif
