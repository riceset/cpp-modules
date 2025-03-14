#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>

enum conversionError {
    SUCCESS,
    NEGATIVE,
    NO_ENTRY,
    TOO_LARGE,
    INVALID_DATE
};

struct ExchangeRate {
    std::string date;
    double rate;
    conversionError err;

    ExchangeRate() : date(""), rate(0.0), err(SUCCESS) {}
};

std::vector<ExchangeRate> readData(const std::string& filename, bool isInputFile);

#endif