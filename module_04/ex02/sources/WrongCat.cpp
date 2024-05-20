#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.type) {
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}

	std::cout << "WrongCat assignment operator called!" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "Meow ^•ﻌ•^" << std::endl;
}
