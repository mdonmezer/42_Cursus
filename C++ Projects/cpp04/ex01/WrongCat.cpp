#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "[WrongCat] A deceptive feline materializes." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] Copy constructor invoked." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] Assignment operator invoked." << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor called. The deceptive feline fades." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] BARK! Wait... that's not right." << std::endl;
}
