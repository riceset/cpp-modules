#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubberly Creation Form", 145, 137) {
    std::cout << "Shrubberly Creation Form default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubberly Creation Form", 145, 137) {
    _target = target;
    std::cout << "Shrubberly Creation Form parameterized constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
    std::cout << "Shrubberly Creation Form copy constructor called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        _isSigned = other.getIsSigned();
        _target = other.getTarget();
    }
    std::cout << "Shrubberly Creation Form assignment operator called!" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubberly Creation Form destructor called!" << std::endl;
}