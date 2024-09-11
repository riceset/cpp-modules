#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

#define ARRAY_POINTER_NULL "Array pointer is NULL."
#define ARRAY_LEN_INVALID "Array length must be positive."

template <typename T>
void iter(T *arr, std::size_t len, void (*f)(T&)) {
    if (!arr)
        throw std::invalid_argument(ARRAY_POINTER_NULL);
    if (len < 1)
        throw std::invalid_argument(ARRAY_LEN_INVALID);
    for (std::size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void increment(T &element) {
    element++;
}

template <typename T, std::size_t N>
std::size_t getSize(T (&arr)[N]) {
    (void)arr;
    return (N);
}

template <typename T>
void print(T *arr, std::size_t len) {
    if (!arr)
        throw std::invalid_argument(ARRAY_POINTER_NULL);
    for (std::size_t i = 0; i < len; i++) {
        std::cout << arr[i];
        if (i != len - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

#endif