#include "Form.hpp"
#include <iostream>

Form::Form()
    : _name("Default Form")
    , _isSigned(false)
    , _gradeToSign(150)
    , _gradeToExec(150) {
    std::cout << "Default form was created!" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExec)
    : _name(name)
    , _isSigned(false)
    , _gradeToSign(gradeToSign)
    , _gradeToExec(gradeToExec) {
    std::cout << "Form " << _name << ": (grade to sign: " << _gradeToSign << ", grade to execute: " << _gradeToExec << ") was created!" << std::endl;
}

Form::Form(const Form &other)
    : _name(other._name)
    , _isSigned(other._isSigned)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExec(other._gradeToExec) {
    std::cout << "Form " << _name << "was copied!" << std::endl;
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other.getIsSigned();
    }
    std::cout << "Form " << _name << "was assigned!" << std::endl;
	return (*this);
}

Form::~Form() {
    std::cout << "Form " << _name << "was destroyed!" << std::endl;
}

const std::string &Form::getName() const {
    return (_name);
}
bool Form::getIsSigned() const {
    return (_isSigned);
}

int Form::getGradeToSign() const {
    return (_gradeToSign);
}

int Form::getGradeToExec() const {
    return (_gradeToExec);
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
    std::string isSigned = f.getIsSigned() ? "signed" : "unsigned";

    os << "Form" << f.getName() << " (status: " << isSigned << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExec() << ")" << std::endl;
}