#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Generic") {
    std::cout << "[WrongAnimal] Default constructor spawned an imposter." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "[WrongAnimal] Copy constructor invoked." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] Assignment operator invoked." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor called on the imposter." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] * chaotic weird sound *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
