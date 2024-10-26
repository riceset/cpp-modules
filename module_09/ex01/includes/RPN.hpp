#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>

bool validInput(int argc, char **argv);
int evaluateRPN(std::stringstream &ss);
void createStringStreamFromArgs(int argc, char **argv, std::stringstream &ss);

#endif