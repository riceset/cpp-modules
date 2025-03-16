#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <climits>

class RPN {
private:
    static bool isOperator(const std::string &s);
    static bool isNumber(const std::string &s);
    static bool willAddOverflow(int a, int b);
    static bool willMultiplyOverflow(int a, int b);
    static bool willSubtractOverflow(int a, int b);
    static void createStringStreamFromArgs(int argc, char **argv, std::stringstream &ss);

public:
    static bool validInput(int argc, char **argv);
    static int evaluate(int argc, char **argv);
};

#endif
