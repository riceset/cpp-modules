#include "iter.hpp"

int main(void) {
    int int_arr[] = {1, 2, 3, 4};

    print<int>(int_arr, getSize(int_arr));
    iter<int>(int_arr, 4, increment);
    print<int>(int_arr, getSize(int_arr));

    return (0);
}