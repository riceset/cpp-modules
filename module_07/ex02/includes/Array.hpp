#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

typedef unsigned int uint;

template <typename T>
class Array {
private:
    uint    _size;
    T       *_data;
public:
    Array();
    Array(uint size);
};

#include "Array.tpp"

#endif