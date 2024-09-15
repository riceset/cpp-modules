#include "Span.hpp"

Span::Span(uint size) : _size(size) {
    if (size < 2)
        throw std::out_of_range(SIZE_ERROR);
}

Span::Span(const Span& other) : _size(other._size), _vector(other._vector) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _size = other._size;
        _vector = other._vector;
    }
    return (*this);
}

void Span::addNumber(int number) {
    if (_vector.size() > _size)
        throw std::out_of_range(FULL_ERROR);
    _vector.push_back(number);
}