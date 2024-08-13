#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
private:
    const std::string name;
    int grade;
public:
    //Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    //Getters
    std::string getName() const;
    int getGrade() const;

    //Required
    void incrementGrade();
    void decrementGrade();

    //Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("The grade is too high!");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("The grade is too low!");
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif