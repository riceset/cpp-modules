#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExec;
protected:
    std::string          _target;
    void                _assignmentOperatorHelper(const AForm &other);
    void                _checkExecutionRequirements(const Bureaucrat &executor) const;
public:
    //Orthodox Canonical Form
    AForm();
    AForm(const std::string &name, const int gradeToSign, const int gradeToExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    //Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    const std::string &getTarget() const;

    //Member Functions
    void beSigned(const Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0;

    //Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
