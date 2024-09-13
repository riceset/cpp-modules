#include "Array.hpp"
#include "Array.tpp"

#define SIZE 100

template <typename T>
static void populateArray(Array<T> &arr) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
}

template <typename T>
static void printArray(Array<T> arr) {
    std::cout << "Size: " << arr.size() << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i];
        if (i != SIZE - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
static void copyArray(Array<T> arr) {
    Array<int> copy(arr);

    std::cout << "copy" << std::endl;
    printArray(copy);
    std::cout << "original" << std::endl;
    printArray(arr);
}

int main(void) {
    Array<int> arr(SIZE);

    // printArray(arr);
    populateArray(arr);
    // printArray(arr);

    Array<int> copy;
    try {
        printArray(copy);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    copy = arr;
    printArray(copy);

    return (0);
}