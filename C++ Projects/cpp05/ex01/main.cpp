#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

void printHeader(const std::string& testName) {
    std::cout << "\n" << CYAN << "=== " << testName << " ===" << RESET << std::endl;
}

int main() {
    printHeader("1. Test: Form Creation Valid Grades");
    try {
        Form taxForm("Tax Form", 50, 20);
        std::cout << GREEN << taxForm << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    printHeader("2. Test: Form Creation Invalid High Grade");
    try {
        Form invalidForm("Invalid", 0, 50);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    printHeader("3. Test: Form Creation Invalid Low Grade");
    try {
        Form invalidForm2("Invalid2", 50, 151);
        std::cout << invalidForm2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    printHeader("4. Test: Bureaucrat Signs Form Successfully");
    try {
        Bureaucrat mayor("Mayor", 1);
        Form contract("City Contract", 10, 5);
        
        std::cout << "Before: " << contract.getIsSigned() << std::endl;
        mayor.signForm(contract);
        std::cout << GREEN << "After: " << contract.getIsSigned() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    printHeader("5. Test: Bureaucrat Fails to Sign Form");
    try {
        Bureaucrat intern("Intern", 150);
        Form secretDoc("Top Secret", 5, 1);
        
        intern.signForm(secretDoc);
        std::cout << YELLOW << secretDoc << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== Testing Completed ===" << RESET << std::endl;
    return 0;
}
