#include "Bureaucrat.hpp"
#include <iostream>

static void separator(std::string msg) {
    std::cout << std::endl << msg << std::endl;
}

static void generateRandomSeed() {
    std::srand((unsigned int) time(NULL));
}

int main(void) {
    generateRandomSeed();

    separator("CONSTRUCTORS");
    Bureaucrat anthony;
    Bureaucrat richarlison("Richarlison", 1);
    Bureaucrat mark("Mark", 150);
    Bureaucrat anthony2(anthony);

    separator("TRY ERRORS");
    try {
        Bureaucrat jacob("Jacob", -1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat jacob("Jacob", 151);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        richarlison.incrementGrade(1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        mark.decrementGrade(1);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    separator("TRY SUCCESS");
    std::cout << richarlison;
    richarlison.decrementGrade(130);

    std::cout << std::endl;

    std::cout << mark;
    mark.incrementGrade(130);

    separator("DESTRUCTORS");
}