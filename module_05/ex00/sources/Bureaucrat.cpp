#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
	std::cout << "Bureaucrat Default Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
	std::cout << "Bureaucrat Copy Constructor Called!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor Called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		grade = other.grade;
	std::cout << "Bureaucrat Assignment Operator Called!" << std::endl;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::setGrade(int newGrade) {
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade = newGrade;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (os);
}
