#ifndef FORM_HPP
#define FORM_HPP

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
};

#endif
