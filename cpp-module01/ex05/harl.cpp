#include "harl.hpp"

void Harl::debug() {
	std::cout << DEBUG_MESSAGE << std::endl;
}

void Harl::info() {
	std::cout << INFO_MESSAGE << std::endl;
}

void Harl::warning() {
	std::cout << WARNING_MESSAGE << std::endl;
}

void Harl::error() {
	std::cout << ERROR_MESSAGE << std::endl;
}

void Harl::complain(std::string level) {
	f functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
}
