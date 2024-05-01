#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
	const std::string& getType() const;
	void setType(const std::string& newType);

	Weapon(const std::string& newType);
	~Weapon();

private:
	std::string type;
};

#endif
