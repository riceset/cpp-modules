#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name(""), grade(0) {
	std::cout << "Default Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
	std::cout << "Copy Constructor Called!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		grade = other.grade;
	std::cout << "Assignment Operator Called!" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::setGrade(int newGrade) {
	grade = newGrade;
}
