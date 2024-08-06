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

	class GradeTooHigh : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("The grade is too high!");
		}
	};

	class GradeTooLow : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("The grade is too low!");
		}
	};
};

#endif
