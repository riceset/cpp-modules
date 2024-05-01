#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie* z;

	z = newZombie(name);
	if (z == nullptr) {
		return ;
	}
	z->announce();

	delete z;
}
