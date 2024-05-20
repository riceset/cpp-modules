#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
    Brain *tmp = new(std::nothrow) Brain();
    if (tmp == NULL) {
        std::cerr << "Error allocating memory!" << std::endl;
        return;
    }
    brain = tmp;
    std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other.type) {
    Brain *tmp = new(std::nothrow) Brain(*other.brain);
    if (tmp == NULL) {
        std::cerr << "Error allocating memory!" << std::endl;
        return;
    }
    brain = tmp;
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        Brain *tmp = new(std::nothrow) Brain(*other.brain);
        if (tmp == NULL) {
            std::cerr << "Error allocating memory!" << std::endl;
            return *this;
        }
        delete brain;
        brain = tmp;
    }
    std::cout << "Dog assignment operator called!" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}
