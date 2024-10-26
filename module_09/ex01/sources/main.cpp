#include "RPN.hpp"

int main(int argc, char **argv) {
    std::stringstream ss;

    if (!validInput(argc, argv))
        return (EXIT_FAILURE);

    createStringStreamFromArgs(argc, argv, ss);
    std::cout << "Result: " << evaluateRPN(ss) << std::endl;
    return (EXIT_SUCCESS);
}