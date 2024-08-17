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

static void draw_tree(int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < (2 * i + 1); ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < height - 1; ++i) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    std::cout << "tree" << std::endl;
}