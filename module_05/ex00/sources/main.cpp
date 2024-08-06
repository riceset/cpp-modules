#include "Bureaucrat.hpp"
#include <iostream>

void tryIncrement(Bureaucrat &b) {
	try {
		b.incrementGrade();
		std::cout << "Incrementing grade..." << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void tryDecrement(Bureaucrat &b) {
	try {
		b.decrementGrade();
		std::cout << "Decrementing grade..." << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main(void) {
	Bureaucrat b1;

	b1.setGrade(2);

	std::cout << b1;

	tryIncrement(b1);

	std::cout << b1;

	tryIncrement(b1);

	std::cout << b1;

	b1.setGrade(149);

	std::cout << b1;

	tryDecrement(b1);
	
	std::cout << b1;

	tryDecrement(b1);
	
	std::cout << b1;

	try {
		b1.setGrade(500);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << b1;

	return (0);
}
