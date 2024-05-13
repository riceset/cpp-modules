#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other) {
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark!" << std::endl;
}
