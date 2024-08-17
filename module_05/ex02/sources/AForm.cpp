#include "AForm.hpp"
#include <iostream>

AForm::AForm()
    : _name("Default AForm")
    , _isSigned(false)
    , _gradeToSign(150)
    , _gradeToExec(150) {
    std::cout << "Default form was created!" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExec)
    : _name(name)
    , _isSigned(false)
    , _gradeToSign(gradeToSign)
    , _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
    std::cout << "AForm " << _name << ": (grade to sign: " << _gradeToSign << ", grade to execute: " << _gradeToExec << ") was created!" << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name)
    , _isSigned(other._isSigned)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExec(other._gradeToExec) {
    std::cout << "AForm " << _name << " was copied!" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other.getIsSigned();
    }
    std::cout << "AForm " << _name << " was assigned!" << std::endl;
	return (*this);
}

AForm::~AForm() {
    std::cout << "AForm " << _name << " was destroyed!" << std::endl;
}

const std::string &AForm::getName() const {
    return (_name);
}

bool AForm::getIsSigned() const {
    return (_isSigned);
}

const std::string &AForm::getTarget() const {
    return (_target);
}

int AForm::getGradeToSign() const {
    return (_gradeToSign);
}

int AForm::getGradeToExec() const {
    return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
    std::string isSigned = f.getIsSigned() ? "signed" : "unsigned";

    os << "AForm " << f.getName() << " (status: " << isSigned << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExec() << ")" << std::endl;

    return (os);
}