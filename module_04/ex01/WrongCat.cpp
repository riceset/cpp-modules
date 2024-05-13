#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow!" << std::endl;
}
