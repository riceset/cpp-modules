#include "BitcoinExchange.hpp"
#include <iomanip>

static bool hasError(conversionError err, const std::string& date) {
    if (err == NEGATIVE) {
        std::cout << "Error: not a positive number." << std::endl;
        return (true);
    } else if (err == NO_ENTRY) {
        std::cout << "Error: bad input => " << date << std::endl;
        return (true);
    } else if (err == TOO_LARGE) {
        std::cout << "Error: too large a number." << std::endl;
        return (true);
    } else if (err == INVALID_DATE) {
        std::cout << "Error: invalid date => " << date << std::endl;
        return (true);
    }
    return (false);
}

double calculate(const ExchangeRate& value, const std::vector<ExchangeRate>& rates) {
    for (size_t i = 0; i < rates.size(); ++i) {
        if (rates[i].date == value.date) {
            return (value.rate * rates[i].rate);
        } else if (rates[i].date > value.date)
            return (value.rate * rates[i - 1].rate);
    }
    return (0);
}

void printRates(const std::vector<ExchangeRate>& values, const std::vector<ExchangeRate>& rates) {
    for (size_t i = 0; i < values.size(); ++i) {
        if (hasError(values[i].err, values[i].date))
            continue;

        std::cout << values[i].date << "=> " << values[i].rate << " = " << calculate(values[i], rates) << std::endl;
    }
}

std::string parseInfile(int argc, char **argv) {
    if (argc != 2)
        throw std::runtime_error("Error: could not open file.");
    return (std::string(argv[1]));
}

int main(int argc, char **argv) {
    try {
        std::string filename = parseInfile(argc, argv);
        std::vector<ExchangeRate> values = readData(filename, true);  // true for input file
        std::vector<ExchangeRate> rates = readData("data.csv", false); // false for data.csv
        printRates(values, rates);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}