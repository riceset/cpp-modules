#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form();
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat &b);

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

#endif
