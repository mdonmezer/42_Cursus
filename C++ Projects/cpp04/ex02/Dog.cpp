#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "[Dog] A hound steps into the light with a fresh brain." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "[Dog] Copy constructor cloned a hound. Deep copying brain..." << std::endl;
    this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Assignment operator invoked. Deep copying brain..." << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "[Dog] Destructor called. The hound retreats to the shadows." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Bark! Howl!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->_brain;
}
