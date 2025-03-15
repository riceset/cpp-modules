#include "RPN.hpp"

int main(int argc, char **argv) {
    if (!RPN::validInput(argc, argv)) {
        return (EXIT_FAILURE);
    }
    std::cout << RPN::evaluate(argc, argv) << std::endl;
    return (EXIT_SUCCESS);
}