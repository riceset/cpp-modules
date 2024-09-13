#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {
    std::cout << "An empty array was created!" << std::endl;
}

template <typename T>
Array<T>::Array(uint size) : _size(size), _data(new T[size]()) {
    std::cout << "An array of size " << size << " was created!" << std::endl;
}

#endif