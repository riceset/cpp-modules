#include "ScalarConverter.hpp"

bool detectChar(const std::string &value) {
    return (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]));
}

std::string detectType(const std::string &value) {
    if (detectChar(value))
        return ("char");
    throw std::invalid_argument("Unsupported Type");
}

void ScalarConverter::convert(const std::string &value) {
    std::string type;

    type = detectType(value);
    std::cout << type << std::endl;
}