#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
	std::string name;
	unsigned int hit;
	unsigned int energy;
	unsigned int damage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	const std::string& getName();
	unsigned int getHit();
	unsigned int getEnergy();
	unsigned int getDamage();

	void setName(const std::string& newName);
	void setHit(unsigned int newHit);
	void setEnergy(unsigned int newEnergy);
	void setDamage(unsigned int newDamage);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
