#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;

	void setGrade(int newGrade);

	void incrementGrade();
	void decrementGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif
