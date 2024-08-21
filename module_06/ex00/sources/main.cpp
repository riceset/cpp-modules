#include "ScalarConverter.hpp"

int main(void) {
    try {
        ScalarConverter::convert("3");
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    return (0);
}