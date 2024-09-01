#include "ScalarConverter.hpp"

void printAlignedValues(const ConversionValues &cv) {
    std::cout << std::left;
    if (!isprint(static_cast<unsigned char>(cv.charVal))) {
        std::cout << std::setw(8) << "char:" << "non printable" << std::endl;
    } else {
        std::cout << std::setw(8) << "char:" << cv.charVal << std::endl;
    }

    if (cv.doubleVal < std::numeric_limits<int>::min() || cv.doubleVal > std::numeric_limits<int>::max()) {
        std::cout << std::setw(8) << "int:" << "impossible" << std::endl;
    } else {
        std::cout << std::setw(8) << "int:" << cv.intVal << std::endl;
    }

    if (std::isinf(cv.floatVal) || std::isnan(cv.floatVal)) {
        std::cout << std::setw(8) << "float:" << "overflow" << std::endl;
    } else if (std::fabs(cv.floatVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    }

    if (std::isinf(cv.doubleVal) || std::isnan(cv.doubleVal)) {
        std::cout << std::setw(8) << "double:" << "overflow" << std::endl;
    } else if (std::fabs(cv.doubleVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1);
        std::cout << std::setw(8) << "double:" << cv.doubleVal << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << "double:" << cv.doubleVal << std::endl;
    }
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