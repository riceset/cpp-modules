#include "ScalarConverter.hpp"

static bool detectChar(const std::string &value) {
    return (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]));
}

static bool detectInt(const std::string &value) {
    char *end;
    errno = 0;
    long intVal = strtol(value.c_str(), &end, 10);
    bool noError = (errno == 0);
    bool fullyConverted = (*end == '\0');
    bool withinMinLimit = (intVal >= std::numeric_limits<int>::min());
    bool withinMaxLimit = (intVal <= std::numeric_limits<int>::max());

    return (noError && fullyConverted && withinMinLimit && withinMaxLimit);
}

template<typename T>
static bool detectFloatingPoint(const std::string &value, bool checkForFloatSuffix) {
    std::string floatValue = value;

    if (checkForFloatSuffix) {
        if (value[value.size() - 1] != 'f' && value[value.size() - 1] != 'F')
            return (false);
        floatValue = value.substr(0, value.length() - 1);
    }

    char *end;
    errno = 0;
    T floatVal = (sizeof(T) == sizeof(float)) ? std::strtof(floatValue.c_str(), &end)
                                              : std::strtod(floatValue.c_str(), &end);
    bool noError = (errno == 0);
    bool fullyConverted = (*end == '\0');
    bool withinRange = (floatVal != HUGE_VAL && floatVal != -HUGE_VAL);

    bool validCharacters = true;
    bool hasDecimalPoint = false;
    bool hasExponent = false;
    for (size_t i = 0; i < floatValue.length(); ++i) {
        if (std::isdigit(floatValue[i]) || floatValue[i] == '+' || floatValue[i] == '-') {
            continue;
        }
        if (floatValue[i] == '.' && !hasDecimalPoint) {
            hasDecimalPoint = true;
            continue;
        }
        if ((floatValue[i] == 'e' || floatValue[i] == 'E') && !hasExponent) {
            hasExponent = true;
            continue;
        }
        validCharacters = false;
        break;
    }

    return (noError && fullyConverted && withinRange && validCharacters);
}

static bool detectFloat(const std::string &value) {
    return detectFloatingPoint<float>(value, true);
}

static bool detectDouble(const std::string &value) {
    return detectFloatingPoint<double>(value, false);
}

std::string detectType(const std::string &value) {
    if (detectChar(value))
        return ("char");
    if (detectInt(value))
        return ("int");
    if (detectFloat(value))
        return ("float");
    if (detectDouble(value))
        return ("double");
    throw std::invalid_argument("Unsupported Type");
}