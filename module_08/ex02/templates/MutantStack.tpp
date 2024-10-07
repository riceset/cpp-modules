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

// template <typename T>
// void MutantStack::push(const T& value) {
//     stack.push_back(value);
// }

// template <typename T>
// void MutantStack::pop() {
//     if (!stack.empty())
//         stack.pop_back();
// }

#endif