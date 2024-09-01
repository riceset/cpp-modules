#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data obj;
    obj.id = 4;

    std::cout << "obj raw val :" << obj.id << std::endl;

    uintptr_t ptr = Serializer::serialize(&obj);
    std::cout << "serialized val:" << ptr << std::endl;

    std::cout << "deserialized val: " << (Serializer::deserialize(ptr))->id << std::endl;

    (void)ptr;

    return (0);
}