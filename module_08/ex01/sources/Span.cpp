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

int Span::shortestSpan() {
    if (_vector.size() < 2)
        throw std::out_of_range(SIZE_ERROR);
    
    std::vector<int> sorted = _vector;
    std::sort(sorted.begin(), sorted.end());
    
    std::vector<int> differences(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());

    return (*std::min_element(differences.begin() + 1, differences.end()));
}

int Span::longestSpan() {
    if (_vector.size() < 2)
        throw std::out_of_range(SIZE_ERROR);

    const int min = *std::min_element(_vector.begin(), _vector.end());
    const int max = *std::max_element(_vector.begin(), _vector.end());

    return (max - min);
}

void Span::printVector() {
    typedef std::vector<int>::iterator Iterator;
    for (Iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it;
        if (it != _vector.end() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}