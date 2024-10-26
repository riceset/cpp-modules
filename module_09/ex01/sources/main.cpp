#include "RPN.hpp"

bool isOperator(const std::string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

bool isNumber(const std::string &s) {
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

template <typename T>
void createList(std::stringstream &ss, std::list<T> &list) {
    std::string token;
    while (ss >> token)
        list.push_back(token);
}

template <typename T>
void printList(std::list<T> list) {
    typename std::list<T>::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it)
        std::cout << *it << std::endl;
}

int main(int argc, char **argv) {
    std::list<std::string> list;
    std::stringstream ss;

    if (!validInput(argc, argv))
        return (EXIT_FAILURE);
    createStringStreamFromArgs(argc, argv, ss);
    createList(ss, list);
    printList<std::string>(list);
    return (EXIT_SUCCESS);
}