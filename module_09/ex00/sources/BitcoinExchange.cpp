#include "BitcoinExchange.hpp"

void skipHeader(std::ifstream& file, std::string& line) {
    std::getline(file, line);
}

void readRate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    std::string sRate;
    std::getline(ssLine, sRate, ',');
    std::stringstream ssRate(sRate);
    ssRate >> currentEntry.rate;
}

void readDate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    std::getline(ssLine, currentEntry.date, ',');
}

std::vector<ExchangeRate> readData(const std::string& filename) {
    std::vector<ExchangeRate> rates;
    std::ifstream file(filename.c_str());
    std::string sLine;

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