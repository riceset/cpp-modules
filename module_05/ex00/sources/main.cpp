#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>

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

void incrementMax(Bureaucrat &b) {
    for (int i = 0; i < 150; i++) {
        tryIncrement(b);
        std::cout << b << std::endl;
    }
}

void normalTest(Bureaucrat &b) {
    std::cout << b << std::endl;
    tryDecrement(b);
    std::cout << b << std::endl;
    tryIncrement(b);
    std::cout << b << std::endl;
}

int main(void) {
    // Bureaucrat b1;
    // normalTest(b1);

    Bureaucrat b2;
    incrementMax(b2);

    return (EXIT_SUCCESS);
}