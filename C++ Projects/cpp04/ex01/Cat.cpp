#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "[Cat] A feline gracefully appears with a fresh brain." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] Copy constructor cloned a feline. Deep copying brain..." << std::endl;
    this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Assignment operator invoked. Deep copying brain..." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "[Cat] Destructor called. The feline vanishes." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow... Purrrrr..." << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}
