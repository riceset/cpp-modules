#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie* z;

	z = newZombie(name);
	if (z == NULL) {
		return ;
	}
	z->announce();

	delete z;
}
