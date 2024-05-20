#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain& other);
	virtual ~Brain();

	Brain& operator=(const Brain& other);

	std::string getIdea(const int pos) const;
	void setIdea(const int pos, const std::string& idea);
};

#endif
