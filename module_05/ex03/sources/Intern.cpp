#include "Intern.hpp"
#include <iostream>

static void printMessage(const std::string &action) {
    std::cout << "Intern was " << action + "!" << std::endl;
}

Intern::Intern() {
    printMessage("created");
}

Intern::Intern(const Intern &other) {
    *this = other;
    printMessage("copied");
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    printMessage("assigned");
    return (*this);
}

Intern::~Intern() {
    printMessage("destroyed");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    
}