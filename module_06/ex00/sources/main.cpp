#include "ScalarConverter.hpp"

int main(void) {
    try {
        ScalarConverter::convert("4.0");
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    return (0);
}