#include "MutantStack.hpp"
#include <iostream>

int main(void) {
    MutantStack<int> stack;

    std::cout << "Adding 1, 2, 3..." << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping one element..." << std::endl;

    stack.pop();

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Size: " << stack.size() << std::endl;

    std::cout << "Is empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

    std::cout << "---Testing iterator---" << std::endl;

    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "---Testing reverse iterator---" << std::endl;
    
    for (MutantStack<int>::reverse_iterator rit = stack.rbegin(); rit != stack.rend(); ++rit)
        std::cout << *rit << std::endl;

    std::cout << "---Testing constant iterator---" << std::endl;

    const MutantStack<int> cstack = stack;

    for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit)
        std::cout << *cit << std::endl;

    std::cout << "---Testing constant reverse iterator---" << std::endl;

    for (MutantStack<int>::const_reverse_iterator crit = cstack.rbegin(); crit != cstack.rend(); ++crit)
        std::cout << *crit << std::endl;

    return (0);
}