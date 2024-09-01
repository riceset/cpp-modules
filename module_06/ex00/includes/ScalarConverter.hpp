#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
} Type;

struct ConversionValues {
    char charVal;
    int intVal;
    float floatVal;
    double doubleVal;
};

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
Type detectType(const std::string &value);

bool isCharPrintable(char c);
bool isIntConvertible(double d);
bool isFloatOverflow(float f);
bool isDoubleOverflow(double d);

void printChar(const ConversionValues &cv);
void printInt(const ConversionValues &cv);
void printFloat(const ConversionValues &cv);
void printDouble(const ConversionValues &cv);
void printAlignedValues(const ConversionValues &cv);

#endif