#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void printInBox(const std::string& text, const std::string& color) {
    int length = text.length() + 2;

    std::cout << color << "╭";
    for (int i = 0; i < length; i++) {
        std::cout << "─";
    }
    std::cout << "╮" << ANSI_COLOR_RESET << std::endl;

    std::cout << color << "│ " << text << " │" << ANSI_COLOR_RESET << std::endl;

    std::cout << color << "╰";
    for (int i = 0; i < length; i++) {
        std::cout << "─";
    }
    std::cout << "╯" << ANSI_COLOR_RESET << std::endl;
}

void animalDefaultConstructorTest() {
	printInBox("Testing Animal Default Constructor", ANSI_COLOR_GREEN);
	Animal animal;
}

void animalCopyConstructorTest() {
	printInBox("Testing Animal Copy Constructor", ANSI_COLOR_YELLOW);

	Animal animal;
	animal.setType("Meta");

	Animal copy(animal);

	std::cout << "Original: " << animal.getType() << std::endl;
	std::cout << "Copied: " << copy.getType() << std::endl;
}

void animalAssignmentOperatorTest() {
	printInBox("Testing Animal Assignment Operator", ANSI_COLOR_RED);

	Animal a1;
	Animal a2;

	a1.setType("A1");
	a2.setType("A2");

	std::cout << "A1 before copy: " << a1.getType() << std::endl;
	std::cout << "A2 before copy: " << a2.getType() << std::endl;

	a1 = a2;

	std::cout << "A1 after copy: " << a1.getType() << std::endl;
	std::cout << "A2 after copy: " << a2.getType() << std::endl;
}

void animalMakeSoundTest() {
	printInBox("Testing Animal makeSound() Method", ANSI_COLOR_BLUE);

	Animal animal;

	animal.makeSound();
}

/* ---------------------------------------------------------------------- */

void dynamicAnimalDefaultConstructorTest() {
	printInBox("Dynamic Animal Default Constructor", ANSI_COLOR_GREEN);

	Animal* animal = new Animal();

	delete animal;
}

void dynamicAnimalCopyConstructorTest() {
	printInBox("Dynamic Animal Copy Constructor", ANSI_COLOR_YELLOW);

	Animal *animal = new Animal("Meta");
	Animal *copy = new Animal(*animal);

	std::cout << "Original: " << animal->getType() << std::endl;
	std::cout << "Copied: " << copy->getType() << std::endl;

	delete animal;
	delete copy;
}

void dynamicAnimalAssignmentOperatorTest() {
	printInBox("Dynamic Animal Assignment Operator", ANSI_COLOR_RED);

    Animal* a1 = new Animal();
    Animal* a2 = new Animal();

    a1->setType("A1");
    a2->setType("A2");

    std::cout << "A1 before copy: " << a1->getType() << std::endl;
    std::cout << "A2 before copy: " << a2->getType() << std::endl;

    *a1 = *a2;

    std::cout << "A1 after copy: " << a1->getType() << std::endl;
    std::cout << "A2 after copy: " << a2->getType() << std::endl;

    delete a1;
    delete a2;
}

void dynamicAnimalMakeSoundTest() {
	printInBox("Dynamic Animal makeSound() Method", ANSI_COLOR_BLUE);

    Animal* animal = new Animal();

    animal->makeSound();

    delete animal;
}

void animalTests() {
	animalDefaultConstructorTest();
	animalCopyConstructorTest();
	animalAssignmentOperatorTest();
	animalMakeSoundTest();
	dynamicAnimalDefaultConstructorTest();
	dynamicAnimalCopyConstructorTest();
	dynamicAnimalAssignmentOperatorTest();
	dynamicAnimalMakeSoundTest();
}

/* ---------------------------------------------------------------------- */

void dogDefaultConstructorTest() {
    printInBox("Testing Dog Default Constructor", ANSI_COLOR_GREEN);
    Dog dog;
}

void dogCopyConstructorTest() {
    printInBox("Testing Dog Copy Constructor", ANSI_COLOR_YELLOW);
    Dog dog;
    Dog copy(dog);
    std::cout << "Original: " << dog.getType() << std::endl;
    std::cout << "Copied: " << copy.getType() << std::endl;
}

void dogAssignmentOperatorTest() {
    printInBox("Testing Dog Assignment Operator", ANSI_COLOR_RED);
    Dog d1;
    Dog d2;

    d1.setType("DOG1");
    d2.setType("DOG2");

    std::cout << "D1 before copy: " << d1.getType() << std::endl;
    std::cout << "D2 before copy: " << d2.getType() << std::endl;

    d1 = d2;

    std::cout << "D1 after copy: " << d1.getType() << std::endl;
    std::cout << "D2 after copy: " << d2.getType() << std::endl;
}

void dogMakeSoundTest() {
    printInBox("Testing Dog makeSound() Method", ANSI_COLOR_BLUE);
    Dog dog;
    dog.makeSound();
}

/* ---------------------------------------------------------------------- */

void dynamicDogDefaultConstructorTest() {
    printInBox("Dynamic Dog Default Constructor", ANSI_COLOR_GREEN);
    Dog* dog = new Dog();
    delete dog;
}

void dynamicDogCopyConstructorTest() {
    printInBox("Dynamic Dog Copy Constructor", ANSI_COLOR_YELLOW);
    Dog* dog = new Dog();
    Dog* copy = new Dog(*dog);
    std::cout << "Original: " << dog->getType() << std::endl;
    std::cout << "Copied: " << copy->getType() << std::endl;
    delete dog;
    delete copy;
}

void dynamicDogAssignmentOperatorTest() {
    printInBox("Dynamic Dog Assignment Operator", ANSI_COLOR_RED);
    Dog* d1 = new Dog();
    Dog* d2 = new Dog();
    d1->setType("DOG1");
    d2->setType("DOG2");

    std::cout << "D1 before copy: " << d1->getType() << std::endl;
    std::cout << "D2 before copy: " << d2->getType() << std::endl;

    *d1 = *d2;

    std::cout << "D1 after copy: " << d1->getType() << std::endl;
    std::cout << "D2 after copy: " << d2->getType() << std::endl;
    delete d1;
    delete d2;
}

void dynamicDogMakeSoundTest() {
    printInBox("Dynamic Dog makeSound() Method", ANSI_COLOR_BLUE);
    Dog* dog = new Dog();
    dog->makeSound();
    delete dog;
}

void dogTests() {
	dogDefaultConstructorTest();
	dogCopyConstructorTest();
	dogAssignmentOperatorTest();
	dogMakeSoundTest();
	dynamicDogDefaultConstructorTest();
	dynamicDogCopyConstructorTest();
	dynamicDogAssignmentOperatorTest();
	dynamicDogMakeSoundTest();
}

/* ---------------------------------------------------------------------- */

void catDefaultConstructorTest() {
    printInBox("Testing Cat Default Constructor", ANSI_COLOR_GREEN);
    Cat cat;
}

void catCopyConstructorTest() {
    printInBox("Testing Cat Copy Constructor", ANSI_COLOR_YELLOW);
    Cat cat;
    Cat copy(cat);
    std::cout << "Original: " << cat.getType() << std::endl;
    std::cout << "Copied: " << copy.getType() << std::endl;
}

void catAssignmentOperatorTest() {
    printInBox("Testing Cat Assignment Operator", ANSI_COLOR_RED);
    Cat c1;
    Cat c2;

    c1.setType("CAT1");
    c2.setType("CAT2");

    std::cout << "c1 before copy: " << c1.getType() << std::endl;
    std::cout << "C2 before copy: " << c2.getType() << std::endl;

    c1 = c2;

    std::cout << "c1 after copy: " << c1.getType() << std::endl;
    std::cout << "C2 after copy: " << c2.getType() << std::endl;
}

void catMakeSoundTest() {
    printInBox("Testing Cat makeSound() Method", ANSI_COLOR_BLUE);
    Cat cat;
    cat.makeSound();
}

/* ---------------------------------------------------------------------- */

void dynamicCatDefaultConstructorTest() {
    printInBox("Dynamic Cat Default Constructor", ANSI_COLOR_GREEN);
    Cat* cat = new Cat();
    delete cat;
}

void dynamicCatCopyConstructorTest() {
    printInBox("Dynamic Cat Copy Constructor", ANSI_COLOR_YELLOW);
    Cat* cat = new Cat();
    Cat* copy = new Cat(*cat);
    std::cout << "Original: " << cat->getType() << std::endl;
    std::cout << "Copied: " << copy->getType() << std::endl;
    delete cat;
    delete copy;
}

void dynamicCatAssignmentOperatorTest() {
    printInBox("Dynamic Cat Assignment Operator", ANSI_COLOR_RED);
    Cat* c1 = new Cat();
    Cat* c2 = new Cat();
    c1->setType("CAT1");
    c2->setType("CAT2");

    std::cout << "c1 before copy: " << c1->getType() << std::endl;
    std::cout << "C2 before copy: " << c2->getType() << std::endl;

    *c1 = *c2;

    std::cout << "c1 after copy: " << c1->getType() << std::endl;
    std::cout << "C2 after copy: " << c2->getType() << std::endl;
    delete c1;
    delete c2;
}

void dynamicCatMakeSoundTest() {
    printInBox("Dynamic Cat makeSound() Method", ANSI_COLOR_BLUE);
    Cat* cat = new Cat();
    cat->makeSound();
    delete cat;
}


void catTests() {
	catDefaultConstructorTest();
	catCopyConstructorTest();
	catAssignmentOperatorTest();
	catMakeSoundTest();
	dynamicCatDefaultConstructorTest();
	dynamicCatCopyConstructorTest();
	dynamicCatAssignmentOperatorTest();
	dynamicCatMakeSoundTest();
}

/* ---------------------------------------------------------------------- */

void wrongAnimalDefaultConstructorTest() {
	printInBox("Testing WrongAnimal Default Constructor", ANSI_COLOR_GREEN);
	WrongAnimal animal;
}

void wrongAnimalCopyConstructorTest() {
	printInBox("Testing Wrong Animal Copy Constructor", ANSI_COLOR_YELLOW);

	WrongAnimal animal;
	animal.setType("Meta");

	WrongAnimal copy(animal);

	std::cout << "Original: " << animal.getType() << std::endl;
	std::cout << "Copied: " << copy.getType() << std::endl;
}

void wrongAnimalAssignmentOperatorTest() {
	printInBox("Testing WrongAnimal Assignment Operator", ANSI_COLOR_RED);

	WrongAnimal a1;
	WrongAnimal a2;

	a1.setType("A1");
	a2.setType("A2");

	std::cout << "A1 before copy: " << a1.getType() << std::endl;
	std::cout << "A2 before copy: " << a2.getType() << std::endl;

	a1 = a2;

	std::cout << "A1 after copy: " << a1.getType() << std::endl;
	std::cout << "A2 after copy: " << a2.getType() << std::endl;
}

void wrongAnimalMakeSoundTest() {
	printInBox("Testing WrongAnimal makeSound() Method", ANSI_COLOR_BLUE);

	WrongAnimal animal;

	animal.makeSound();
}

/* ---------------------------------------------------------------------- */

void dynamicWrongAnimalDefaultConstructorTest() {
	printInBox("Dynamic WrongAnimal Default Constructor", ANSI_COLOR_GREEN);

	WrongAnimal* animal = new WrongAnimal();

	delete animal;
}

void dynamicWrongAnimalCopyConstructorTest() {
	printInBox("Dynamic WrongAnimal Copy Constructor", ANSI_COLOR_YELLOW);

	WrongAnimal *animal = new WrongAnimal("Meta");
	WrongAnimal *copy = new WrongAnimal(*animal);

	std::cout << "Original: " << animal->getType() << std::endl;
	std::cout << "Copied: " << copy->getType() << std::endl;

	delete animal;
	delete copy;
}

void dynamicWrongAnimalAssignmentOperatorTest() {
	printInBox("Dynamic WrongAnimal Assignment Operator", ANSI_COLOR_RED);

    WrongAnimal* a1 = new WrongAnimal();
    WrongAnimal* a2 = new WrongAnimal();

    a1->setType("A1");
    a2->setType("A2");

    std::cout << "A1 before copy: " << a1->getType() << std::endl;
    std::cout << "A2 before copy: " << a2->getType() << std::endl;

    *a1 = *a2;

    std::cout << "A1 after copy: " << a1->getType() << std::endl;
    std::cout << "A2 after copy: " << a2->getType() << std::endl;

    delete a1;
    delete a2;
}

void dynamicWrongAnimalMakeSoundTest() {
	printInBox("Dynamic WrongAnimal makeSound() Method", ANSI_COLOR_BLUE);

    WrongAnimal* animal = new WrongAnimal();

    animal->makeSound();

    delete animal;
}

void wrongAnimalTests() {
	wrongAnimalDefaultConstructorTest();
	wrongAnimalCopyConstructorTest();
	wrongAnimalAssignmentOperatorTest();
	wrongAnimalMakeSoundTest();
	dynamicWrongAnimalDefaultConstructorTest();
	dynamicWrongAnimalCopyConstructorTest();
	dynamicWrongAnimalAssignmentOperatorTest();
	dynamicWrongAnimalMakeSoundTest();
}

/* ---------------------------------------------------------------------- */

void wrongCatDefaultConstructorTest() {
    printInBox("Testing WrongCat Default Constructor", ANSI_COLOR_GREEN);
    WrongCat cat;
}

void wrongCatCopyConstructorTest() {
    printInBox("Testing WrongCat Copy Constructor", ANSI_COLOR_YELLOW);
    WrongCat cat;
    WrongCat copy(cat);
    std::cout << "Original: " << cat.getType() << std::endl;
    std::cout << "Copied: " << copy.getType() << std::endl;
}

void wrongCatAssignmentOperatorTest() {
    printInBox("Testing WrongCat Assignment Operator", ANSI_COLOR_RED);
    WrongCat c1;
    WrongCat c2;

    c1.setType("CAT1");
    c2.setType("CAT2");

    std::cout << "c1 before copy: " << c1.getType() << std::endl;
    std::cout << "C2 before copy: " << c2.getType() << std::endl;

    c1 = c2;

    std::cout << "c1 after copy: " << c1.getType() << std::endl;
    std::cout << "C2 after copy: " << c2.getType() << std::endl;
}

void wrongCatMakeSoundTest() {
    printInBox("Testing WrongCat makeSound() Method", ANSI_COLOR_BLUE);
    WrongCat cat;
    cat.makeSound();
}

/* ---------------------------------------------------------------------- */

void dynamicWrongCatDefaultConstructorTest() {
    printInBox("Dynamic WrongCat Default Constructor", ANSI_COLOR_GREEN);
    WrongCat* cat = new WrongCat();
    delete cat;
}

void dynamicWrongCatCopyConstructorTest() {
    printInBox("Dynamic WrongCat Copy Constructor", ANSI_COLOR_YELLOW);
    WrongCat* cat = new WrongCat();
    WrongCat* copy = new WrongCat(*cat);
    std::cout << "Original: " << cat->getType() << std::endl;
    std::cout << "Copied: " << copy->getType() << std::endl;
    delete cat;
    delete copy;
}

void dynamicWrongCatAssignmentOperatorTest() {
    printInBox("Dynamic WrongCat Assignment Operator", ANSI_COLOR_RED);
    WrongCat* c1 = new WrongCat();
    WrongCat* c2 = new WrongCat();
    c1->setType("CAT1");
    c2->setType("CAT2");

    std::cout << "c1 before copy: " << c1->getType() << std::endl;
    std::cout << "C2 before copy: " << c2->getType() << std::endl;

    *c1 = *c2;

    std::cout << "c1 after copy: " << c1->getType() << std::endl;
    std::cout << "C2 after copy: " << c2->getType() << std::endl;
    delete c1;
    delete c2;
}

void dynamicWrongCatMakeSoundTest() {
    printInBox("Dynamic WrongCat makeSound() Method", ANSI_COLOR_BLUE);
    WrongCat* cat = new WrongCat();
    cat->makeSound();
    delete cat;
}


void wrongCatTests() {
	wrongCatDefaultConstructorTest();
	wrongCatCopyConstructorTest();
	wrongCatAssignmentOperatorTest();
	wrongCatMakeSoundTest();
	dynamicWrongCatDefaultConstructorTest();
	dynamicWrongCatCopyConstructorTest();
	dynamicWrongCatAssignmentOperatorTest();
	dynamicWrongCatMakeSoundTest();
}

/* ---------------------------------------------------------------------- */

void ftAnimalTest() {
    printInBox("42 Animal Test", ANSI_COLOR_MAGENTA);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void ftWrongAnimalTest() {
    printInBox("42 WrongAnimal Test", ANSI_COLOR_CYAN);
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
}

void ftTestSuite() {
	ftAnimalTest();
	ftWrongAnimalTest();
}

void basicBrainTest() {
    printInBox("Basic Brain Test", ANSI_COLOR_GREEN);
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	delete dog;
	delete cat;
}

void arrayTest() {
    printInBox("Array Test", ANSI_COLOR_YELLOW);
	Animal	*arr[10];

	for (int i = 0; i < 5; i++)
		arr[i] = new Dog();
	for (int i = 5; i < 10; i++)
		arr[i] = new Cat();

	for(int i = 0; i < 10; i++)
   		delete arr[i];
}

void brainTestSuite() {
	basicBrainTest();
	arrayTest();
}

int main(void) {
	animalTests();
	dogTests();
	catTests();
	wrongAnimalTests();
	wrongCatTests();
	ftTestSuite();

	brainTestSuite();
}
