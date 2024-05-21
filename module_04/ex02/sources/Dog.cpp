#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	try {
		brain = new Brain();
	} catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
		throw ;
	}
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other.type) {
	try {
		brain = new Brain(*other.brain);
	} catch (const std::bad_alloc& e) {
		std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
		throw ;
	}
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
		try {
			Brain* newBrain = new Brain(*other.brain);
            delete brain;
            brain = newBrain;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Failed to allocate memory for brain: " << e.what() << std::endl;
            throw;
        }
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}
