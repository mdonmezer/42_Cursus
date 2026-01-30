#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "--- Test 1: DEBUG ---" << std::endl;
    harl.complain("DEBUG");

    std::cout << "--- Test 2: INFO ---" << std::endl;
    harl.complain("INFO");

    std::cout << "--- Test 3: WARNING ---" << std::endl;
    harl.complain("WARNING");

    std::cout << "--- Test 4: ERROR ---" << std::endl;
    harl.complain("ERROR");

    std::cout << "--- Test 5: Invalid Level ---" << std::endl;
    harl.complain("INVALID");

    return 0;
}
