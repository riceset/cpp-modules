#include "ScalarConverter.hpp"

bool isCharPrintable(char c) {
    return isprint(static_cast<unsigned char>(c));
}

bool isIntConvertible(double d) {
    return d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max();
}

bool isFloatOverflow(float f) {
    return std::isinf(f) || std::isnan(f);
}

bool isDoubleOverflow(double d) {
    return std::isinf(d) || std::isnan(d);
}

void printChar(const ConversionValues &cv) {
    std::cout << std::left;
    if (!isCharPrintable(cv.charVal)) {
        std::cout << std::setw(8) << "char:" << "non printable" << std::endl;
    } else {
        std::cout << std::setw(8) << "char:" << cv.charVal << std::endl;
    }
}

void printInt(const ConversionValues &cv) {
    if (!isIntConvertible(cv.doubleVal)) {
        std::cout << std::setw(8) << "int:" << "impossible" << std::endl;
    } else {
        std::cout << std::setw(8) << "int:" << cv.intVal << std::endl;
    }
}

void printFloat(const ConversionValues &cv) {
    if (isFloatOverflow(cv.floatVal)) {
        std::cout << std::setw(8) << "float:" << "overflow" << std::endl;
    } else if (std::fabs(cv.floatVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    }
}

void printDouble(const ConversionValues &cv) {
    if (isDoubleOverflow(cv.doubleVal)) {
        std::cout << std::setw(8) << "double:" << "overflow" << std::endl;
    } else if (std::fabs(cv.doubleVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1);
        std::cout << std::setw(8) << "double:" << cv.doubleVal << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << "double:" << cv.doubleVal << std::endl;
    }
}

void printAlignedValues(const ConversionValues &cv) {
    printChar(cv);
    printInt(cv);
    printFloat(cv);
    printDouble(cv);
}

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
    std::stringstream ss(value);
    ConversionValues cv;

    ss >> cv.floatVal;
    cv.charVal = static_cast<char>(cv.floatVal);
    cv.intVal = static_cast<int>(cv.floatVal);
    cv.doubleVal = static_cast<double>(cv.floatVal);

    printAlignedValues(cv);
}

void convertFromDouble(const std::string &value) {
    std::stringstream ss(value);
    ConversionValues cv;

    ss >> cv.doubleVal;
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