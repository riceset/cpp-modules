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

static bool detectFloat(const std::string &value) {
    (void)value;
    return (false);
}

static bool detectDouble(const std::string &value) {
    (void)value;
    return (false);
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