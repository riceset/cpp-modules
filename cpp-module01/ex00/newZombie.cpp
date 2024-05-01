#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* z;

	try {
		z = new Zombie;
		z->setName(name);
	} catch (const std::bad_alloc& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (nullptr);
	}

	return (z);
}
