#include "Zombie.hpp"

#define ZOMBIE_COUNT 3

int main(void) {
	Zombie* horde;

	horde = zombieHorde(ZOMBIE_COUNT, "FFF");

	for (int i = 0; i < ZOMBIE_COUNT; i++) {
		std::cout << horde[i].get() << std::endl;
	}

	delete[] horde;

	return (0);
}
