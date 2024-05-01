#include "harl.hpp"

int main() {
    Harl harl;
    
    harl.complain("DEBUG");

    harl.complain("INFO");

    harl.complain("WARNING");

    harl.complain("ERROR");

    harl.complain("NON-EXISTENT");

    return 0;
}
