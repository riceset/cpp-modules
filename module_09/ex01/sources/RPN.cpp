#include "RPN.hpp"

static bool isOperator(const std::string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

static bool isNumber(const std::string &s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
        if (!std::isdigit(*it))
            return (false);
    return (true);
}

bool validInput(int argc, char **argv) {
    std::string arg;
    for (int i = 1; i < argc; i++) {
        arg = argv[i];
        if (!isNumber(arg) && !isOperator(arg)) {
            std::cerr << "rpn: input is invalid!" << std::endl;
            return (false);
        }
    }
    return (true);
}

void createStringStreamFromArgs(int argc, char **argv, std::stringstream &ss) {
    for (int i = 1; i < argc; ++i)
        ss << argv[i] << " ";
}

int evaluateRPN(std::stringstream &ss) {
    std::stack<int> stack;
    std::string token;

    while (ss >> token) {
        if (isNumber(token)) {
            stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                std::cerr << "rpn: insufficient operands for operator '" << token << "'" << std::endl;
                exit(EXIT_FAILURE);
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    std::cerr << "rpn: division by zero" << std::endl;
                    exit(EXIT_FAILURE);
                }
                stack.push(a / b);
            }
        } else {
            std::cerr << "rpn: invalid token '" << token << "'" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (stack.size() != 1) {
        std::cerr << "rpn: invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (stack.top());
}