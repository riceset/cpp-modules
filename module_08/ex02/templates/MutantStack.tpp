#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : stack(other.stack) {}

template <typename T>
MutantStack& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other)
        stack = other.stack;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
void MutantStack<T>::push(const T& value) {
    stack.push_back(value);
}

template <typename T>
void MutantStack<T>::pop() {
    stack.pop_back();
}

template <typename T>
const T& MutantStack<T>::top() const {
    return (stack.back());
}

template <typename T>
bool MutantStack<T>::empty() {
    return (stack.empty());
}

template <typename T>
size_t MutantStack<T>::size() {
    return (stack.size());
}

#endif