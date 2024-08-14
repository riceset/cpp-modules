#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
private:
    const std::string name;
    unsigned int grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string   &getName() const;
    int                 getGrade() const;

    void incrementGrade(unsigned int amount);
    void decrementGrade(unsigned int amount);

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