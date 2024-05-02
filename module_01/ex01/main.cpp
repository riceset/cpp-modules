#include "Zombie.hpp"

#define ZOMBIE_COUNT 3

int main(void) {
	Zombie* horde;

	horde = zombieHorde(ZOMBIE_COUNT, "xxx");

	for (int i = 0; i < ZOMBIE_COUNT; i++) {
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}
