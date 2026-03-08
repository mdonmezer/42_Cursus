#include "Animal.hpp"

Animal::Animal() : type("Generic Animal") {
    std::cout << "[Animal] Default constructor spawned an unknown entity." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor invoked." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Assignment operator invoked." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called. The generic entity returns to dust." << std::endl;
}

void Animal::makeSound() const {
    std::cout << "[Animal] * mysterious generic silence *" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
