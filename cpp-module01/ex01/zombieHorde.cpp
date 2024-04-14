#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
	Zombie* horde;

	horde = new Zombie[n];

	for (int i = 0; i < n; i++) {
		horde[i].set(name);
	  }

	return (horde);
}
