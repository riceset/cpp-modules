#include <iostream>

class Weapon {
public:
	const std::string& getType() const {
		return (type);
	}
	void setType(const std::string& type) {
		this->type = type;
	}

	Weapon() : type("") {}
	Weapon(const std::string& type) : type(type) {}
private:
	std::string type;
};

class Human {
public:
	virtual const std::string& getName() const {
		return (name);
	}

	virtual const Weapon& getWeapon() const {
		return (weapon);
	}

	virtual void setName(const std::string& name) {
		this->name = name;
	}

	virtual void setWeapon(const Weapon& weapon) {
		this->weapon = weapon;
	}

	virtual void attack(void) = 0;

	Human() : name(""), weapon("") {}
	Human(const std::string& name, const Weapon& weapon)
	: name(name), weapon(weapon) {}

protected:
	std::string name;
	Weapon weapon;
};

class HumanA: public Human {
public:
	HumanA() : Human("", Weapon("")) {}
	HumanA(const std::string& name, const Weapon& weapon)
	: Human(name, weapon) {}

	void attack(void) {
	}
};

int main(void) {
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	return (0);
}
