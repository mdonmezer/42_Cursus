#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "[Dog] A hound steps into the light." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] Copy constructor cloned a hound." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Assignment operator invoked." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor called. The hound retreats to the shadows." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Bark! Howl!" << std::endl;
}
