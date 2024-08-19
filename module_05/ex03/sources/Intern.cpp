#include "Intern.hpp"
#include <iostream>
#include <algorithm>

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

int Intern::mapFormNameToInt(const std::string &name) {
    FormNameMapping mappings[] = {
        {"presidential pardon", 1},
        {"robotomy request", 2},
        {"shrubbery creation", 3}
    };

    for (int i = 0; i < 3; ++i) {
        if (name == mappings[i].name) {
            return (mappings[i].id);
        }
    }
    return (-1);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    std::string lowerName = name;
    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    switch (mapFormNameToInt(lowerName)) {
        case 1:
            return new PresidentialPardonForm(target);
        case 2:
            return new RobotomyRequestForm(target);
        case 3:
            return new ShrubberyCreationForm(target);
        default:
            std::cout << "The intern says the form \"" << name << "\" does not exist!" << std::endl;
            return NULL;
    }
}