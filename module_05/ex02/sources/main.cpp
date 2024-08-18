#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
        bob.signForm(form);
        form.execute(bob);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testNotAbleToExecute() {
    Bureaucrat mark("mark", 136);
    ShrubberyCreationForm form("garden");

    try {
       mark.signForm(form);
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
        mark.signForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Robotomization() {
    Bureaucrat mark("mark", 44);
    RobotomyRequestForm form("robot");

    try {
        mark.signForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void RobotomizationError() {
    Bureaucrat mark("mark", 46);
    RobotomyRequestForm form("robot");

    try {
        mark.signForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

void Presidential() {
    Bureaucrat mark("mark", 1);
    PresidentialPardonForm form("presidential");

    try {
        mark.signForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void PresidentialError() {
    Bureaucrat mark("mark", 6);
    PresidentialPardonForm form("presidential");

    try {
        mark.signForm(form);
       form.execute(mark);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(void) {
    generateRandomSeed();

    Bureaucrat jason("jason", 1);
    PresidentialPardonForm form("presidential");
    jason.signForm(form);
    jason.executeForm(form);
    return (0);
}