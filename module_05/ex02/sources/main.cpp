#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void generateRandomSeed() {
    std::srand((unsigned int) time(NULL));
}

void formException() {
    try {
        Form f1("Form", -1, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form f1("Form", 151, 1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form f1("Form", 150, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form f1("Form", 150, -2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void signException() {
    Bureaucrat b1("ABC", 6);
    Bureaucrat b2("XYZ", 2);

    Form f1("F1", 4, 7);

    try {
        f1.beSigned(b1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        f1.beSigned(b2);
        std::cout << b2.getName() << " signed " << f1.getName() << "!" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    b1.signForm(f1);

    Bureaucrat b3("DDD", 1);
    b3.signForm(f1);
}

int main(void) {
    generateRandomSeed();
    // formException();
    //signException();
}