#include "Form.hpp"
#include <iostream>

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form Default Constructor Called!" <<std::endl;
}
