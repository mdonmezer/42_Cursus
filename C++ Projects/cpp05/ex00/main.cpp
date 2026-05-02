#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

void printHeader(const std::string& testName) {
    std::cout << "\n" << CYAN << "=== " << testName << " ===" << RESET << std::endl;
}

int main() {
    printHeader("1. Test: Normal Initialization");
    try {
        Bureaucrat john("John", 50);
        std::cout << GREEN << john << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    printHeader("2. Test: Grade Too High on Initialization");
    try {
        Bureaucrat boss("Boss", 0);
        std::cout << boss << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    printHeader("3. Test: Grade Too Low on Initialization");
    try {
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    printHeader("4. Test: Increment Grade Normal");
    try {
        Bureaucrat alice("Alice", 2);
        std::cout << "Before: " << alice << std::endl;
        alice.incrementGrade();
        std::cout << GREEN << "After increment: " << alice << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    printHeader("5. Test: Increment Grade Exception (Exceeding limit)");
    try {
        Bureaucrat god("God", 1);
        std::cout << "Before: " << god << std::endl;
        god.incrementGrade();
        std::cout << god << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    printHeader("6. Test: Decrement Grade Normal");
    try {
        Bureaucrat bob("Bob", 149);
        std::cout << "Before: " << bob << std::endl;
        bob.decrementGrade();
        std::cout << GREEN << "After decrement: " << bob << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    printHeader("7. Test: Decrement Grade Exception (Exceeding limit)");
    try {
        Bureaucrat slacker("Slacker", 150);
        std::cout << "Before: " << slacker << std::endl;
        slacker.decrementGrade();
        std::cout << slacker << std::endl;
    } catch (std::exception& e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << CYAN << "=== Testing Completed ===" << RESET << std::endl;
    return 0;
}
