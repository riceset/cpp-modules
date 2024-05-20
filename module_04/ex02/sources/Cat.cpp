#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	Brain *tmp;

	tmp = new(std::nothrow) Brain();
	if (tmp == NULL) {
		std::cerr << "Error allocating memory!" << std::endl;
		return ;
	}

	brain = tmp;

	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.type) {
	Brain *tmp;

	tmp = new(std::nothrow) Brain(*other.brain);
	if (tmp == NULL) {
		std::cerr << "Error allocating memory!" << std::endl;
		return ;
	}

	brain = tmp;

	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);

		Brain *tmp = new(std::nothrow) Brain(*other.brain);

		if (tmp == NULL) {
			std::cerr << "Error allocating memory!" << std::endl;
			return (*this);
		}

		delete brain;
		brain = tmp;
	}

	std::cout << "Cat assignment operator called!" << std::endl;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow ^•⩊•^" << std::endl;
}
