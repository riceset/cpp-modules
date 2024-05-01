#include "Zombie.hpp"

int main(void) {
	Zombie* z;

	z = newZombie("Zedd");
	z->announce();

	delete z;

	randomChump("Hello");

	return (0);
}
