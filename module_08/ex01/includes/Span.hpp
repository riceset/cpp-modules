#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <ctime>

typedef unsigned int uint;

#define SIZE_ERROR "error: size must be at least 2"
#define FULL_ERROR "error: vector is already full"

class Span {
private:
    uint                _size;
    std::vector<int>    _vector;
    Span();
public:
    Span(uint size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

    void printVector();
};

#endif