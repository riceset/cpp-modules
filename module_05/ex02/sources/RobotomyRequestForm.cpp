#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45) {
    std::cout << "Robotomy Request Form default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45) {
    _target = target;
    std::cout << "Robotomy Request Form parameterized constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
    std::cout << "Robotomy Request Form copy constructor called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        _assignmentOperatorHelper(other);
    }
    std::cout << "Robotomy Request Form assignment operator called!" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy Request Form was destroyed!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	_checkExecutionRequirements(executor);
	if (rand() % 2)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << _target << "has not been robotomized..." << std::endl;
}