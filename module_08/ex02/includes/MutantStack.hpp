#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class MutantStack {
private:
    std::deque<T> elements;
public:
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    void push(const T& value);
    void pop();
    const T& top() const;
    bool empty() const;
    size_t size() const;
};

#include "MutantStack.tpp"

#endif