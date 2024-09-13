#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

typedef unsigned int uint;

template <typename T>
class Array {
private:
    uint    _size;
    T       *_data;

    inline bool validIndex(size_t index) const;
    inline void swap(Array &other);
public:
    Array();
    Array(uint size);
    Array(const Array &other);
    ~Array();

    Array &operator=(const Array &other);
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    uint size() const;
};

#endif