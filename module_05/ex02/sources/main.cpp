#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

static void generateRandomSeed() {
    std::srand((unsigned int) time(NULL));
}

void testFormNotSigned() {
    Bureaucrat bob("Bob", 1);
    ShrubberyCreationForm form("garden");
    try {
        form.execute(bob);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testNotAbleToSign() {
    Bureaucrat bob("Bob", 146);
    ShrubberyCreationForm form("garden");
    try {
        bob.signAForm(form);
        form.execute(bob);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testNotAbleToExecute() {
    Bureaucrat mark("mark", 136);
    ShrubberyCreationForm form("garden");

    try {
       mark.signAForm(form);
       mark.decrementGrade(10);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testAbleToExecute() {
    Bureaucrat mark("mark", 136);
    ShrubberyCreationForm form("garden");

    try {
        mark.signAForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Robotomization() {
    Bureaucrat mark("mark", 1);
    RobotomyRequestForm form("robot");

    try {
        mark.signAForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

int main(void) {
    generateRandomSeed();
    Robotomization();
    return 0;
}