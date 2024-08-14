#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//Helpers
static void printMessage(const std::string &name, unsigned int grade, const std::string &action) {
    std::cout << "Bureaucrat (" + name + ") with grade " + std::to_string(grade) + " was " + action + "!" << std::endl;
}

static void validateGrade(unsigned int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

//Orthodox Canonical Form
Bureaucrat::Bureaucrat() : name("Anthony"), grade(rand() % 150 + 1) {
    printMessage(name, grade, "created");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
    validateGrade(grade);
    printMessage(name, grade, "created");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()) {
    *this = copy;
    printMessage(name, grade, "copied");
}

Bureaucrat::~Bureaucrat() {
    printMessage(name, grade, "destroyed");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        grade = other.getGrade();
    printMessage(name, grade, "assigned");
    return (*this);
}

//Getters
const std::string &Bureaucrat::getName() const {
    return (name);
}

int Bureaucrat::getGrade() const {
    return (grade);
}

//Members
void Bureaucrat::incrementGrade(int amount) {
    if (amount < 1)
        throw std::invalid_argument("Amount must be positive!");
    if (grade - amount < 1)
        throw GradeTooHighException();
    grade -= amount;
}

void Bureaucrat::decrementGrade(int amount) {
    if (amount < 1)
        throw std::invalid_argument("Amount must be positive!");
    if (grade + amount > 150)
        throw GradeTooLowException();
    grade += amount;
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