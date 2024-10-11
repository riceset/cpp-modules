#include "BitcoinExchange.hpp"
#include <iomanip> // Include this header for std::fixed and std::setprecision

int main() {
    std::vector<ExchangeRate> rates = readData("data.csv");
    
    for (size_t i = 0; i < rates.size(); ++i) {
        std::cout << "Date: " << rates[i].date << ", Rate: " << std::fixed << std::setprecision(2) << rates[i].rate << std::endl;
    }

    return 0;
}