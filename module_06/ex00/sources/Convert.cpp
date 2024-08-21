#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &value) {
    std::string type;

    type = detectType(value);
    std::cout << type << std::endl;
}