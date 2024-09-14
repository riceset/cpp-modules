#ifndef EASY_FIND_TPP
#define EASY_FIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int target) {
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it != container.end())
        return (it);
    else
        throw std::runtime_error("ERROR: Target not found in container!");
}

#endif