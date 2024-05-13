#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& other);
	Animal(const std::string& newType);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	std::string getType() const;
	void setType(const std::string& newType);

	virtual void makeSound() const;
};

#endif
