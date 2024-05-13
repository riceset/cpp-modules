#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
	: type("") {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type) {
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& newType)
	: type(newType) {
	std::cout << "WrongAnimal parameterized constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	std::cout << "WrongAnimal assignment operator called!" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::setType(const std::string& newType) {
	type = newType;
}

void WrongAnimal::makeSound() const {
	std::cout << "Undefined wrong animal sound..." << std::endl;
}
