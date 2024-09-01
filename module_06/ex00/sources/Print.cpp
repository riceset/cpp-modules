#include "ScalarConverter.hpp"

void printChar(const ConversionValues &cv) {
    std::cout << std::left << std::setw(8) << "char:";
    if (std::isnan(cv.doubleVal)) {
        std::cout << "impossible" << std::endl;
    } else if (!isCharPrintable(cv.charVal)) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << cv.charVal << "'" << std::endl;
    }
}

void printInt(const ConversionValues &cv) {
    std::cout << std::left << std::setw(8) << "int:";
    if (!isIntConvertible(cv.doubleVal) || std::isnan(cv.doubleVal)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << cv.intVal << std::endl;
    }
}

void printFloat(const ConversionValues &cv) {
    std::cout << std::left << std::setw(8) << "float:";
    if (std::isnan(cv.floatVal)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(cv.floatVal)) {
        std::cout << (cv.floatVal > 0 ? "+inff" : "-inff") << std::endl;
    } else if (std::fabs(cv.floatVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1) << cv.floatVal << "f" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << cv.floatVal << "f" << std::endl;
    }
}

void printDouble(const ConversionValues &cv) {
    std::cout << std::left << std::setw(8) << "double:";
    if (std::isnan(cv.doubleVal)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(cv.doubleVal)) {
        std::cout << (cv.doubleVal > 0 ? "+inf" : "-inf") << std::endl;
    } else if (std::fabs(cv.doubleVal) > 1e6) {
        std::cout << std::scientific << std::setprecision(1) << cv.doubleVal << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << cv.doubleVal << std::endl;
    }
}

void printAlignedValues(const ConversionValues &cv) {
    printChar(cv);
    printInt(cv);
    printFloat(cv);
    printDouble(cv);
}