#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

static void printMessage(const std::string &name, unsigned int grade, const std::string &action) {
    std::cout << "Bureaucrat (" + name + ") with grade " + std::to_string(grade) + " was " + action + "!" << std::endl;
}

static void validateGrade(unsigned int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("Anthony"), grade(rand() % 150 + 1) {
    printMessage(name, grade, "created");
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name), grade(grade) {
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