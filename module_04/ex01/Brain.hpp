#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define IDEAS_COUNT 100

class Brain {
	std::string ideas[IDEAS_COUNT];
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	virtual ~Brain();

	std::string getIdea(const int pos) const;
	void setIdea(const int pos, const std::string& idea);
};

#endif
