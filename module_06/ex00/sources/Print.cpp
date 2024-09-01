#include "ScalarConverter.hpp"

void printChar(const ConversionValues &cv) {
    std::cout << std::left;
    if (std::isnan(cv.doubleVal)) {
        std::cout << std::setw(8) << "char:" << "impossible" << std::endl;
    } else if (!isCharPrintable(cv.charVal)) {
        std::cout << std::setw(8) << "char:" << "Non displayable" << std::endl;
    } else {
        std::cout << std::setw(8) << "char:" << "'" << cv.charVal << "'" << std::endl;
    }
}

void printInt(const ConversionValues &cv) {
    if (!isIntConvertible(cv.doubleVal) || std::isnan(cv.doubleVal)) {
        std::cout << std::setw(8) << "int:" << "impossible" << std::endl;
    } else {
        std::cout << std::setw(8) << "int:" << cv.intVal << std::endl;
    }
}

void printFloat(const ConversionValues &cv) {
    if (std::isnan(cv.floatVal)) {
        std::cout << std::setw(8) << "float:" << "nanf" << std::endl;
    } else if (std::isinf(cv.floatVal)) {
        if (cv.floatVal > 0) {
            std::cout << std::setw(8) << "float:" << "+inff" << std::endl;
        } else {
            std::cout << std::setw(8) << "float:" << "-inff" << std::endl;
        }
    } else if (std::fabs(cv.floatVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << std::setw(8) << "float:" << cv.floatVal << "f" << std::endl;
    }
}

void printDouble(const ConversionValues &cv) {
    if (std::isnan(cv.doubleVal)) {
        std::cout << std::setw(8) << "double:" << "nan" << std::endl;
    } else if (std::isinf(cv.doubleVal)) {
        if (cv.doubleVal > 0) {
            std::cout << std::setw(8) << "double:" << "+inf" << std::endl;
        } else {
            std::cout << std::setw(8) << "double:" << "-inf" << std::endl;
        }
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