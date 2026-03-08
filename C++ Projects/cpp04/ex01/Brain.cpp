#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] A new brain has been formed with 100 empty ideas." << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Copy constructor duplicated a brain." << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Assignment operator transferring thoughts." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor called. Thoughts vanish into the void." << std::endl;
}
