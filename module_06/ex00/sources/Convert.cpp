#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &value) {
    Type type;

    if (value.empty())
        throw std::invalid_argument("No Input"); 
    type = detectType(value);
    switch (type) {
        case CHAR: {

            break;
        }
        case INT: {

            break;
        }
        case FLOAT: {

            break;
        }
        case DOUBLE: {

            break;
        }
    }
}