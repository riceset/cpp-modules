#ifndef BUREAUCRAR_HPP
# define BUREAUCRAR_HPP

# include <string>

class Bureaucrat
{
  private:
	const std::string name;
	unsigned int grade;

  public:
	Bureaucrat();
	Bureaucrat(const std::string &newName, const int newGrade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;

	unsigned int getGrade() const;
	void setGrade(unsigned int newGrade);

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("The grade is too high!");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("The grade is too low!");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif
