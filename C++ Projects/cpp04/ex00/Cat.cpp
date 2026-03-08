#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "[Cat] A feline gracefully appears." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] Copy constructor cloned a feline." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Assignment operator invoked." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor called. The feline vanishes." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow... Purrrrr..." << std::endl;
}
