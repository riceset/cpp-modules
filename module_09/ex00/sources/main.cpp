#include "BitcoinExchange.hpp"
#include <iomanip>

void printRates(const std::vector<ExchangeRate>& rates) {
    for (size_t i = 0; i < rates.size(); ++i) {
        if (rates[i].err == NEGATIVE)
            std::cout << "Error: not a positive number." << std::endl;
        else if (rates[i].err == NO_ENTRY) {
            std::cout << "Error: bad input => " << rates[i].date << std::endl;
        }
        else if (rates[i].err == TOO_LARGE)
            std::cout << "Error: too large a number." << std::endl;
        else
            std::cout << "Date: " << rates[i].date << ", Rate: " << std::fixed << std::setprecision(2) << rates[i].rate << std::endl;
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
        std::vector<ExchangeRate> outfile = readData(filename);
        std::vector<ExchangeRate> rates = readData("data.csv");
        printRates(outfile);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}