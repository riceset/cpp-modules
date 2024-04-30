#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* z;

	z = new Zombie;
	if (z == NULL) {
		std::cout << "Error creating zombie!" << std::endl;
		return (NULL);
	}
	z->setName(name);

	return (z);
}
