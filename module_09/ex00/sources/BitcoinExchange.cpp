#include "BitcoinExchange.hpp"

static void getlineCustom(std::stringstream& ss, std::string& result) {
    result.clear();
    char ch;
    while (ss.get(ch)) {
        if (ch == ',' || ch == '|') {
            break;
        }
        result += ch;
    }
}

static void handleRateErrors(ExchangeRate& currentEntry, const std::string &sRate) {
    if (sRate.empty()) {
        currentEntry.err = NO_ENTRY;
    } else if (currentEntry.rate < 0) {
        currentEntry.err = NEGATIVE;
    } else if (currentEntry.rate > std::numeric_limits<int>::max()) {
        currentEntry.err = TOO_LARGE;
    }
}

static void readRate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    std::string sRate;
    getlineCustom(ssLine, sRate);
    std::stringstream ssRate(sRate);
    ssRate >> currentEntry.rate;
    handleRateErrors(currentEntry, sRate);
}

static void readDate(ExchangeRate& currentEntry, std::stringstream& ssLine) {
    getlineCustom(ssLine, currentEntry.date);
}

static void skipHeader(std::ifstream& file, std::string& line) {
    std::getline(file, line);
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