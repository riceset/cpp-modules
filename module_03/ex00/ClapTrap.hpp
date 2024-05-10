#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {
protected:
	std::string name;
	unsigned int hit;
	unsigned int energy;
	unsigned int damage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	const std::string& getName() const;
	unsigned int getHit() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;

	void setName(const std::string& newName);
	void setHit(unsigned int newHit);
	void setEnergy(unsigned int newEnergy);
	void setDamage(unsigned int newDamage);

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream &os, const ClapTrap &object);

#endif
