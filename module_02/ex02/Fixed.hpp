#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	int rawBits;
	static const int fractionalBits = 8;

public:
	//constructor
	Fixed();

	//integer constructor
	Fixed(int num);

	//float constructor
	Fixed(float num);

	//copy constructor
	Fixed(const Fixed& other);

	//destructor
	~Fixed();

	//getters and setters
	int getRawBits(void) const;
	void setRawBits(int const raw);

	//conversions
	int toInt(void) const;
	float toFloat(void) const;

	//operator overload
	Fixed& operator=(const Fixed& other);
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;

	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	static const Fixed& max(const Fixed& n1, const Fixed& n2);
	static const Fixed& max(Fixed& n1, Fixed& n2);

	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static const Fixed& min(Fixed& n1, Fixed& n2);

	Fixed& operator++(void);
	Fixed operator++(int);

	Fixed& operator--(void);
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
