#include "ScalarConverter.hpp"

void printAlignedValues(char charVal, int intVal, float floatVal, double doubleVal) {
    std::cout << std::left;
    if (intVal < 33 || intVal > 126) {
        std::cout << std::setw(8) << "char:" << "non printable" << std::endl;
    } else {
        std::cout << std::setw(8) << "char:" << charVal << std::endl;
    }
    if (doubleVal < std::numeric_limits<int>::min() || doubleVal > std::numeric_limits<int>::max()) {
        std::cout << std::setw(8) << "int:" << "impossible" << std::endl;
    } else {
        std::cout << std::setw(8) << "int:" << intVal << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << std::setw(8) << "float:" << floatVal << "f" << std::endl;
    std::cout << std::setw(8) << "double:" << doubleVal << std::endl;
}

void convertFromChar(const std::string &value) {
    char charVal = value[0];
    int intVal = static_cast<int>(charVal);
    float floatVal = static_cast<float>(charVal);
    double doubleVal = static_cast<double>(charVal);

    printAlignedValues(charVal, intVal, floatVal, doubleVal);
}

void convertFromInt(const std::string &value) {
    std::stringstream ss(value);
    int intVal;
    ss >> intVal;

    char charVal = static_cast<char>(intVal);
    float floatVal = static_cast<float>(intVal);
    double doubleVal = static_cast<double>(intVal);

    printAlignedValues(charVal, intVal, floatVal, doubleVal);
}

void convertFromFloat(const std::string &value) {
    std::stringstream ss(value);
    float floatVal;
    ss >> floatVal;

    char charVal = static_cast<char>(floatVal);
    int intVal = static_cast<int>(floatVal);
    double doubleVal = static_cast<double>(floatVal);

    printAlignedValues(charVal, intVal, floatVal, doubleVal);
}

void convertFromDouble(const std::string &value) {
    std::stringstream ss(value);
    double doubleVal;
    ss >> doubleVal;

    char charVal = static_cast<char>(doubleVal);
    int intVal = static_cast<int>(doubleVal);
    float floatVal = static_cast<float>(doubleVal);

    printAlignedValues(charVal, intVal, floatVal, doubleVal);
}

void ScalarConverter::convert(const std::string &value) {
    Type type;

    if (value.empty())
        throw std::invalid_argument("No Input"); 
    type = detectType(value);
    switch (type) {
        case CHAR: {
            convertFromChar(value);
            break;
        }
        case INT: {
            convertFromInt(value);
            break;
        }
        case FLOAT: {
            convertFromFloat(value);
            break;
        }
        case DOUBLE: {
            convertFromDouble(value);
            break;
        }
    }
}