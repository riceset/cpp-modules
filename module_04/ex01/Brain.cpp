#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < IDEAS_COUNT; ++i) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < IDEAS_COUNT; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assignment operator called!" << std::endl;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called!" << std::endl;
}

std::string Brain::getIdea(const int pos) const {
	if (0 <= pos && pos <= IDEAS_COUNT) {
		return ideas[pos];
	}
	return ("");
}

void Brain::setIdea(const int pos, const std::string& idea) {
	if (0 <= pos && pos < IDEAS_COUNT) {
		ideas[pos] = idea;
	} else {
		std::cerr << "Index provided to Brain ideas is out of bounds!" << std::endl;
	}
}
