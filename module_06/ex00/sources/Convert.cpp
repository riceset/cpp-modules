#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &value) {
    std::string type;

    if (value.empty())
        throw std::invalid_argument("No Input"); 
    type = detectType(value);
    std::cout << type << std::endl;
}