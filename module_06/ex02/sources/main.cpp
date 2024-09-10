#include "Base.hpp"
#include <iostream>

int main(void) {
    generateRandomSeed();

    Base *b = generate();
    identify(b);
    identify(*b);

    return (0);
}