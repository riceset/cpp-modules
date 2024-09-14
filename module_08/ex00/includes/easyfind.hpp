#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int target);

#endif