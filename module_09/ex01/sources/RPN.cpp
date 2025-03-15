#include "RPN.hpp"

bool RPN::isOperator(const std::string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

bool RPN::isNumber(const std::string &s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
        if (!std::isdigit(*it))
            return (false);
    int num = std::atoi(s.c_str());
    return (num >= 0 && num < 10);
}

bool RPN::willAddOverflow(int a, int b) {
    if (b > 0) {
        return a > INT_MAX - b;
    } else {
        return a < INT_MIN - b;
    }
}

bool RPN::willMultiplyOverflow(int a, int b) {
    if (a == 0 || b == 0) return false;
    if (a > 0) {
        if (b > 0) {
            return a > INT_MAX / b;
        } else {
            return b < INT_MIN / a;
        }
    } else {
        if (b > 0) {
            return a < INT_MIN / b;
        } else {
            return a < INT_MAX / b;
        }
    }
}

bool RPN::willSubtractOverflow(int a, int b) {
    if (b > 0) {
        return a < INT_MIN + b;
    } else {
        return a > INT_MAX + b;
    }
}

bool RPN::validInput(int argc, char **argv) {
    if (argc < 2)
        return (false);
    
    if (argc == 2 && strchr(argv[1], ' ') != NULL) {
        std::stringstream ss(argv[1]);
        std::string token;
        while (ss >> token) {
            if (!isNumber(token) && !isOperator(token)) {
                std::cerr << "rpn: input is invalid!" << std::endl;
                return (false);
            }
        }
        return (true);
    }
    
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

void RPN::createStringStreamFromArgs(int argc, char **argv, std::stringstream &ss) {
    if (argc == 2 && strchr(argv[1], ' ') != NULL) {
        ss << argv[1];
    } else {
        for (int i = 1; i < argc; ++i)
            ss << argv[i] << " ";
    }
}

int RPN::evaluate(int argc, char **argv) {
    std::stringstream ss;
    createStringStreamFromArgs(argc, argv, ss);
    
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
            
            if (token == "+") {
                if (willAddOverflow(a, b)) {
                    std::cerr << "rpn: arithmetic overflow" << std::endl;
                    exit(EXIT_FAILURE);
                }
                stack.push(a + b);
            }
            else if (token == "-") {
                if (willSubtractOverflow(a, b)) {
                    std::cerr << "rpn: arithmetic overflow" << std::endl;
                    exit(EXIT_FAILURE);
                }
                stack.push(a - b);
            }
            else if (token == "*") {
                if (willMultiplyOverflow(a, b)) {
                    std::cerr << "rpn: arithmetic overflow" << std::endl;
                    exit(EXIT_FAILURE);
                }
                stack.push(a * b);
            }
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