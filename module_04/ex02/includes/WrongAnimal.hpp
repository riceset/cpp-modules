#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const std::string& newType);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& other);

	std::string getType() const;
	void setType(const std::string& newType);

	virtual void makeSound() const = 0;
};

#endif
