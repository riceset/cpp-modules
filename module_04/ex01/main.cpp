#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	delete dog;
	delete cat;

	return (0);
}
