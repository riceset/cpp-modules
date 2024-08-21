#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <cmath>

class ScalarConverter {
public:
    static void convert(const std::string &value);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
};

void printMessage(const std::string &action);
std::string detectType(const std::string &value);

#endif