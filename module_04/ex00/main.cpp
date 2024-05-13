#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void animalTest() {
	const Animal* meta;

	meta = new Animal;
	meta->makeSound();
	delete meta;
}

static void catTest() {
	const Cat* c;

	c = new Cat;
	c->makeSound();
	delete c;
}

static void dogTest() {
	const Dog* d;

	d = new Dog;
	d->makeSound();
	delete d;
}

static void wrongAnimalTest() {
	const WrongAnimal* meta;

	meta = new WrongAnimal;
	meta->makeSound();
	delete meta;
}

static void wrongCatTest() {
	const WrongCat* wc;

	wc = new WrongCat;
	wc->makeSound();
	delete wc;
}

static void separator() {
	std::cout << "---" << std::endl;
}

static void test() {
	animalTest();
	separator();
	catTest();
	separator();
	dogTest();
	separator();

	wrongAnimalTest();
	separator();
	wrongCatTest();
}

int main(void) {
	test();
	return (0);
}
