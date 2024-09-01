#include "ScalarConverter.hpp"

void convertFromChar(const std::string &value) {
    ConversionValues cv;

    cv.charVal = value[0];
    cv.intVal = static_cast<int>(cv.charVal);
    cv.floatVal = static_cast<float>(cv.charVal);
    cv.doubleVal = static_cast<double>(cv.charVal);

    printAlignedValues(cv);
}

void convertFromInt(const std::string &value) {
    std::stringstream ss(value);
    ConversionValues cv;

    ss >> cv.intVal;
    cv.charVal = static_cast<char>(cv.intVal);
    cv.floatVal = static_cast<float>(cv.intVal);
    cv.doubleVal = static_cast<double>(cv.intVal);

    printAlignedValues(cv);
}

void convertFromFloat(const std::string &value) {
    ConversionValues cv;

    if (value == "nanf") {
        cv.floatVal = std::numeric_limits<float>::quiet_NaN();
    } else if (value == "+inff") {
        cv.floatVal = std::numeric_limits<float>::infinity();
    } else if (value == "-inff") {
        cv.floatVal = -std::numeric_limits<float>::infinity();
    } else {
        std::stringstream ss(value);
        ss >> cv.floatVal;
    }

    cv.charVal = static_cast<char>(cv.floatVal);
    cv.intVal = static_cast<int>(cv.floatVal);
    cv.doubleVal = static_cast<double>(cv.floatVal);

    printAlignedValues(cv);
}

void convertFromDouble(const std::string &value) {
    ConversionValues cv;

    if (value == "nan") {
        cv.doubleVal = std::numeric_limits<double>::quiet_NaN();
    } else if (value == "+inf") {
        cv.doubleVal = std::numeric_limits<double>::infinity();
    } else if (value == "-inf") {
        cv.doubleVal = -std::numeric_limits<double>::infinity();
    } else {
        std::stringstream ss(value);
        ss >> cv.doubleVal;
    }

    cv.charVal = static_cast<char>(cv.doubleVal);
    cv.intVal = static_cast<int>(cv.doubleVal);
    cv.floatVal = static_cast<float>(cv.doubleVal);

    printAlignedValues(cv);
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