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
