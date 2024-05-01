#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
	const std::string& getType() const;
	void setType(const std::string& newType);

	Weapon();

	Weapon(const std::string& newType);

private:
	std::string type;
};

#endif
