#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

static void generateRandomSeed() {
    std::srand((unsigned int) time(NULL));
}

int main(void) {
    generateRandomSeed();
	Intern	someRandomIntern;
	AForm*	presidential;
	AForm*	robotomy;
	AForm*	shrubbery;
	AForm*	n;

	presidential = someRandomIntern.makeForm("presidential pardon", "Mark");
	robotomy = someRandomIntern.makeForm("robotomy request", "John");
	shrubbery = someRandomIntern.makeForm("shrubbery Creation", "Will");
	n = someRandomIntern.makeForm("abc", "Jacob");

	delete presidential;
	delete robotomy;
	delete shrubbery;
    (void)n;
    return (0);
}