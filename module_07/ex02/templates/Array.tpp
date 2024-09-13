#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(uint size) : _size(size), _data(new T[size]()) {}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _data(new T[other._size]()) {
    for (uint i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
inline void Array<T>::swap(Array &other) {
    size_t tmpSize = _size;
    _size = other._size;
    other._size = tmpSize;

    T* tmpData = _data;
    _data = other._data;
    other._data = tmpData;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this != &other) {
        Array tmp(other);
        swap(tmp);
    }
    return (*this);
}

template <typename T>
inline bool Array<T>::validIndex(size_t index) const {
    return (index < _size);
}

template <typename T>
T &Array<T>::operator[](size_t index) {
    if (!validIndex(index))
        throw std::out_of_range("Index out of range.");
    return _data[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const {
    if (!validIndex(index))
        throw std::out_of_range("Index out of range.");
    return _data[index];
}

template <typename T>
uint Array<T>::size() const {
    return (_size);
}

#endif