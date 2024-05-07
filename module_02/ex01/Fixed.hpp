#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();

	Fixed(int integer);

	Fixed(float floatingPoint);

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);

	int toInt(void) const;

	float toFloat(void) const;

private:
	int raw;
	static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
