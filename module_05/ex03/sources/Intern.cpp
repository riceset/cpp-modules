#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(const Intern &other) {
    *this = other;
    std::cout << "Intern parameterized constructor called!" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    std::cout << "Intern assignment operator called!" << std::endl;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Intern destructor called!" << std::endl;
}