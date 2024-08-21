#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2 && argv[1] != NULL) {
        try {
            ScalarConverter::convert(argv[1]);
        } catch (std::exception &err) {
            std::cout << err.what() << std::endl;
        }
    }
    return (0);
}