#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    printMessage("created");
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
    printMessage("copied");
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    printMessage("assigned");
    return (*this);
}

ScalarConverter::~ScalarConverter() {
    printMessage("destroyed");
}