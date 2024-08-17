#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExec;
public:
    //Orthodox Canonical Form
    Form();
    Form(const std::string &name, const int gradeToSign, const int gradeToExec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    //Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    //Member Functions
    void beSigned(const Bureaucrat &b);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
