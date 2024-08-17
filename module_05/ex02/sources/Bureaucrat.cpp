#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//Helpers
static void printMessage(const std::string &name, unsigned int grade, const std::string &action) {
    std::cout << "Bureaucrat (" << name << ") with grade " << grade << " was " << action + "!" << std::endl;
}

static void validateGrade(int _grade) {
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

//Orthodox Canonical Form
Bureaucrat::Bureaucrat() : _name("Anthony"), _grade(rand() % 150 + 1) {
    printMessage(_name, _grade, "created");
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : _name(_name), _grade(_grade) {
    validateGrade(_grade);
    printMessage(_name, _grade, "created");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()) {
    *this = copy;
    printMessage(_name, _grade, "copied");
}

Bureaucrat::~Bureaucrat() {
    printMessage(_name, _grade, "destroyed");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        _grade = other.getGrade();
    printMessage(_name, _grade, "assigned");
    return (*this);
}

//Getters
const std::string &Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

//Members
void Bureaucrat::incrementGrade(int amount) {
    if (amount < 1)
        throw std::invalid_argument("Amount must be positive!");
    if (_grade - amount < 1)
        throw GradeTooHighException();
    _grade -= amount;
    std::cout << _name << " grade was incremented by " << amount << ". Current grade is " << _grade << "." << std::endl;
}

void Bureaucrat::decrementGrade(int amount) {
    if (amount < 1)
        throw std::invalid_argument("Amount must be positive!");
    if (_grade + amount > 150)
        throw GradeTooLowException();
    _grade += amount;
    std::cout << _name << " grade was decremented by " << amount << ". Current grade is " << _grade << "." << std::endl;
}

void Bureaucrat::signForm(Form &f) {
	try {
		f.beSigned(*this);
	std::cout << _name << " signed " << f.getName() << "." << std::endl;
	} catch (std::exception &e) {
		std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

//Operator Overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << "Bureaucrat: " << b.getName() << ": " << b.getGrade() << std::endl;
    return (os);
}
