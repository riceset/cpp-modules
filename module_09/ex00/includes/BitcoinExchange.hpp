#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct ExchangeRate {
    std::string date;
    double rate;
};

std::vector<ExchangeRate> readData(const std::string& filename);

#endif