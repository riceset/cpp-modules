#include "BitcoinExchange.hpp"

static std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

static void getlineCustom(std::stringstream& ss, std::string& result, char separator) {
    result.clear();
    char ch;
    bool foundSeparator = false;
    
    while (ss.get(ch)) {
        if (ch == separator) {
            foundSeparator = true;
            break;
        }
        result += ch;
    }
    
    if (foundSeparator) {
        // Skip any spaces after the separator
        while (ss.get(ch) && (ch == ' ' || ch == '\t'));
        if (ss.good()) {
            ss.unget(); // Put back the last character if it wasn't a space
        }
    }
    
    result = trim(result);
}

static void handleRateErrors(ExchangeRate& currentEntry, const std::string &sRate) {
    if (sRate.empty()) {
        currentEntry.err = NO_ENTRY;
    } else if (currentEntry.rate < 0) {
        currentEntry.err = NEGATIVE;
    } else if (currentEntry.rate > 1000) {
        currentEntry.err = TOO_LARGE;
    }
}

static void readRate(ExchangeRate& currentEntry, std::stringstream& ssLine, bool isInputFile) {
    std::string sRate;
    getlineCustom(ssLine, sRate, isInputFile ? '|' : ',');
    std::stringstream ssRate(sRate);
    ssRate >> currentEntry.rate;
    handleRateErrors(currentEntry, sRate);
}

static bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); ++i)
        if (!std::isdigit(yearStr[i])) return false;
    for (size_t i = 0; i < monthStr.length(); ++i)
        if (!std::isdigit(monthStr[i])) return false;
    for (size_t i = 0; i < dayStr.length(); ++i)
        if (!std::isdigit(dayStr[i])) return false;

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2009 || year > 2024)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

static void readDate(ExchangeRate& currentEntry, std::stringstream& ssLine, bool isInputFile) {
    getlineCustom(ssLine, currentEntry.date, isInputFile ? '|' : ',');
    if (!isValidDate(currentEntry.date)) {
        currentEntry.err = INVALID_DATE;
    }
}

static void skipHeader(std::ifstream& file, std::string& line) {
    std::getline(file, line);
}

std::vector<ExchangeRate> readData(const std::string& filename, bool isInputFile) {
    std::string sLine;
    std::vector<ExchangeRate> rates;
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    skipHeader(file, sLine);
    while (std::getline(file, sLine)) {
        std::stringstream ssLine(sLine);
        ExchangeRate currentEntry;
        
        readDate(currentEntry, ssLine, isInputFile);
        readRate(currentEntry, ssLine, isInputFile);
        rates.push_back(currentEntry);
    }
    return (rates);
}