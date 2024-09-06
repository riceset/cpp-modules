#include "Base.hpp"
#include <iostream>

int main(void) {
    generateRandomSeed();

    Base *generatedType = generate();

    identify(generatedType);
    identify(*generatedType);

    return (0);
}