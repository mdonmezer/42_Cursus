#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Generic AAnimal") {
    std::cout << "[AAnimal] Default constructor spawned an abstract entity." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "[AAnimal] Copy constructor invoked." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "[AAnimal] Assignment operator invoked." << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "[AAnimal] Destructor called. The abstract entity returns to dust." << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
