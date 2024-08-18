#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137) {
    std::cout << "Shrubbery Creation Form default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137) {
    _target = target;
    std::cout << "Shrubbery Creation Form parameterized constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
    std::cout << "Shrubbery Creation Form copy constructor called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        _assignmentOperatorHelper(other);
    }
    std::cout << "Shrubbery Creation Form assignment operator called!" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery Creation Form was destroyed!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	_checkExecutionRequirements(executor);
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	std::string tree[11] = {
		"             ,@@@@@@@,                  ",
		"     ,,,.   ,@@@@@@/@@,  .oo8888o.      ",
		"  ,&%&&%&&%,@@@@@/@@@@@@,8888o88/8o     ",
		" ,%&*%&&%&&%,@@@*@@@/@@@88o88888/88'    ",
		" %&&%&%&/%&&%@@*@@/ /@@@88888o88888'    ",
		" %&&%/ %&%&&&@@\\ V /@@' `88o8 `/88'     ",
		" `&%\\ ` /%&'    |.|        \\ '|8'       ",
		"     |o|        | |         | |         ",
		"     |.|        | |         | |         ",
		"  \\|/ ._\\//_/__/  ,\\_//__\\|/.  \\_//__/_ "
	};

	for (int i = 0; i < 11; i++)
		outfile << tree[i] << std::endl;
	outfile.close();
	std::cout << "ASCII trees have been written to " << filename << std::endl;
}