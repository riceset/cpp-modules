#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class MutantStack {
private:
    std::vector<T> elements;
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();
};

#include "MutantStack.tpp"

#endif