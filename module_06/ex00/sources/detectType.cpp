#include "ScalarConverter.hpp"

static bool detectChar(const std::string &value) {
    return (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]));
}

static bool detectInt(const std::string &value) {
    std::stringstream ss(value);
    int intVal;
    ss >> intVal;
    return (!ss.fail() && ss.eof());
}

template<typename T>
static bool detectFloatingPoint(const std::string &value, bool checkForFloatSuffix) {
    std::string floatValue = value;

    if (checkForFloatSuffix) {
        if (value[value.length() - 1] != 'f' && value[value.length() - 1] != 'F')
            return (false);
        floatValue = value.substr(0, value.length() - 1);
    }

    if (floatValue == "nan" || floatValue == "+inf" || floatValue == "-inf" ||
        floatValue == "nanf" || floatValue == "+inff" || floatValue == "-inff") {
        return true;
    }

    std::stringstream ss(floatValue);
    T floatVal;
    ss >> floatVal;
    return (!ss.fail() && ss.eof());
}

static bool detectFloat(const std::string &value) {
    return detectFloatingPoint<float>(value, true);
}

static bool detectDouble(const std::string &value) {
    return detectFloatingPoint<double>(value, false);
}

Type detectType(const std::string &value) {
    if (detectChar(value))
        return (CHAR);
    if (detectInt(value))
        return (INT);
    if (detectFloat(value))
        return (FLOAT);
    if (detectDouble(value))
        return (DOUBLE);
    throw std::invalid_argument("Unsupported Type");
}