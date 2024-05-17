#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		Brain *tmp = new Brain(*other.brain);
		delete brain;
		brain = tmp;
	}
	return (*this);
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bark!" << std::endl;
}
