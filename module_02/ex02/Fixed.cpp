#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	: rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num)
	: rawBits(num << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
	: rawBits(std::roundf(num * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->rawBits = other.rawBits;
	}

	return (*this);
}

int Fixed::getRawBits(void) const {
	return (this->rawBits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const {
	return (this->rawBits >> fractionalBits);
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(rawBits) / (1 << fractionalBits));
}

Fixed Fixed::operator+(const Fixed& other) {
	Fixed dummy;

	dummy.rawBits = (this->rawBits + other.rawBits);
	return (dummy);
}

Fixed Fixed::operator-(const Fixed& other) {
	Fixed dummy;

	dummy = (this->rawBits - other.rawBits);
	return (dummy);
}

Fixed Fixed::operator*(const Fixed& other) {
	Fixed dummy;

	dummy.rawBits = (this->rawBits * other.rawBits >> fractionalBits);
	return (dummy);
}

Fixed Fixed::operator/(const Fixed& other) {
	Fixed dummy;

	if (other.rawBits == 0) {
		std::cerr << "Error: Division by zero." << std::endl;

		return (0);
	}

	dummy.rawBits = ((this->rawBits << fractionalBits) / other.rawBits);
	return (dummy);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->rawBits <= other.rawBits);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->rawBits != other.rawBits);
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
	return (n1.getRawBits() >= n2.getRawBits()) ? n1 : n2;
}

const Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	return (n1.getRawBits() >= n2.getRawBits()) ? n1 : n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
	return (n1.getRawBits() <= n2.getRawBits()) ? n1 : n2;
}

const Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
	return (n1.getRawBits() <= n2.getRawBits()) ? n1 : n2;
}

Fixed& Fixed::operator++(void) {
	++this->rawBits;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed dummy(*this);
	operator++();
	return (dummy);
}

Fixed& Fixed::operator--(void) {
	--this->rawBits;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed dummy(*this);
	operator--();
	return (dummy);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}
