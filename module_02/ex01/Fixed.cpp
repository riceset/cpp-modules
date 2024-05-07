#include "Fixed.hpp"
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = integer << fractionalBits;
}

Fixed::Fixed(float floatingPoint) {
	std::cout << "Float constructor called" << std::endl;
	this->raw = std::roundf(floatingPoint * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = other.getRawBits();

	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	return (this->raw);
}

void Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float Fixed::toFloat(void) const {
	    return static_cast<float>(this->raw) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	int res;

	res = raw >> fractionalBits;

	return (res);
}
