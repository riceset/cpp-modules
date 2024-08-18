#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) {
    std::cout << "Presidential Pardon Form default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5) {
    _target = target;
    std::cout << "Presidential Pardon Form parameterized constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
    std::cout << "Presidential Pardon Form copy constructor called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        _assignmentOperatorHelper(other);
    }
    std::cout << "Presidential Pardon Form assignment operator called!" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential Pardon Form was destroyed!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	_checkExecutionRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}