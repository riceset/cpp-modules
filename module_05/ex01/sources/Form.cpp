#include "Form.hpp"
#include <iostream>

Form::Form() : name("Default"),
	isSigned(false),
	gradeToSign(0),
	gradeToExecute(0) {
	std::cout << "Form Default Constructor Called!" << std::endl;
}

Form::Form(const Form &other) : name(other.name),
	isSigned(other.isSigned),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute) {
	std::cout << "Form Copy Constructor Called!" << std::endl;
}

Form::~Form() {
	std::cout << "Form Destructor Called!" << std::endl;
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	std::cout << "Form Assignment Operator Called!" << std::endl;
	return (*this);
}

const std::string &Form::getName() const {
	return (name);
}

bool Form::getIsSigned() const {
	return (isSigned);
}

int Form::getGradeToSign() const {
	return (gradeToSign);
}

int Form::getGradeToExecute() const {
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() <= gradeToSign) {
		isSigned = true;
		std::cout << b.getName() << " signed " << name << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	if (form.getIsSigned())
		os << "Form " << form.getName() << ", is signed." << std::endl;
	else
		os << "Form " << form.getName() << ", is not signed." << std::endl;
	os << "Minimal Grade To Sign: " << form.getGradeToSign() << std::endl;
	os << "Minimal Grade To Execute: " << form.getGradeToExecute() << std::endl;
	return (os);
}
