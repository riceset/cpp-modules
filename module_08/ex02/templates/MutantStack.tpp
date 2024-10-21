#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : elements(other.elements) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
    if (this != &other)
        elements = other.elements;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
void MutantStack<T>::push(const T& value) {
    elements.push_back(value);
}

template <typename T>
void MutantStack<T>::pop() {
    elements.pop_back();
}

template <typename T>
T& MutantStack<T>::top() {
    return (elements.back());
}

template <typename T>
const T& MutantStack<T>::top() const {
    return (elements.back());
}

template <typename T>
bool MutantStack<T>::empty() const {
    return (elements.empty());
}

template <typename T>
size_t MutantStack<T>::size() const {
    return (elements.size());
}

// Iterator functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return (elements.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return (elements.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return (elements.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return (elements.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return (elements.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
    return (elements.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return (elements.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
    return (elements.rend());
}

#endif