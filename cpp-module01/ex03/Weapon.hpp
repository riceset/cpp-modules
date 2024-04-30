#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
	std::string getType() const;
	void setType(const std::string& newType);

	Weapon() : type("") {}
	Weapon(const std::string& newType) : type(newType) {}

private:
	std::string type;
};

#endif
