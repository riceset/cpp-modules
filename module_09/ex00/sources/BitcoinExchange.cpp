#include "BitcoinExchange.hpp"

void skipHeader(std::ifstream& file, std::string& line) {
    std::getline(file, line);
}

void getlineCustom(std::stringstream& ss, std::string& result) {
    result.clear();
    char ch;
    while (ss.get(ch)) {
        if (ch == ',' || ch == '|') {
            break;
        }
        result += ch;
    }
}

void readRate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    std::string sRate;
    getlineCustom(ssLine, sRate);
    std::stringstream ssRate(sRate);
    ssRate >> currentEntry.rate;
}

void readDate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    getlineCustom(ssLine, currentEntry.date);
}

std::vector<ExchangeRate> readData(const std::string& filename) {
    std::string sLine;
    std::vector<ExchangeRate> rates;
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    skipHeader(file, sLine);
    while (std::getline(file, sLine)) {
        std::stringstream ssLine(sLine);
        ExchangeRate currentEntry;
        
        readDate(currentEntry, ssLine);
        readRate(currentEntry, ssLine);
        rates.push_back(currentEntry);
    }
    return (rates);
}