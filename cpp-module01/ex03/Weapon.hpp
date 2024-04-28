#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
	std::string getType() const;
	void setType(const std::string& newType);

	Weapon() : type("Default") {}
	explicit Weapon(std::string &newType) : type(newType) {}

private:
	std::string type;
};

#endif
