#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
	Bureaucrat bureaucrat("A", 2);

	std::cout << bureaucrat;

	try {
		bureaucrat.incrementGrade();
		std::cout << "Incrementing grade by 1..." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat;

	try {
		bureaucrat.incrementGrade();
		std::cout << "Incrementing grade by 1..." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat;

	Bureaucrat bureaucrat2("B", 149);

	try {
		bureaucrat2.decrementGrade();
		std::cout << "Decrementing grade by 1..." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat2;

	try {
		bureaucrat2.decrementGrade();
		std::cout << "Decrementing grade by 1..." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << bureaucrat2;

	return (0);
}
