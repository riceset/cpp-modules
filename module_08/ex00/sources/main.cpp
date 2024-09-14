#include "easyfind.hpp"
#include "easyfind.tpp"

#include <vector>
#include <iostream>
#include <stdexcept>

int main(void) {
    std::vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    try {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "Value: " << *it << " was found!" << std::endl;
        std::cout << "Index: " << std::distance(v.begin(), it) << std::endl;

        it = easyfind(v, 42);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}