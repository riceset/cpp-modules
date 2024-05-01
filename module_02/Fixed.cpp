#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : number(other.number) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->number = other.number;
	}

	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void Fixed::setRawBits(int const newNumber)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = newNumber;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

