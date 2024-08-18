#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <string>

class AForm;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    //Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    //Getters
    const std::string   &getName() const;
    int                 getGrade() const;

    //Member Functions
    void incrementGrade(int amount);
    void decrementGrade(int amount);
    void signForm(AForm &f);
    void executeForm(const AForm& form);

    //Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
