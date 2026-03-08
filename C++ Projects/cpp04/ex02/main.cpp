#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n================= " << title << " =================" << std::endl;
}

int main()
{
    printHeader("NEW ABSTRACT BEHAVIOR TEST");

    // Uncommenting the following line will cause a compilation error
    // because AAnimal contains a pure virtual function `virtual void makeSound() const = 0;`
    //
    // AAnimal* meta = new AAnimal();
    //
    // Error: cannot allocate an object of abstract type 'AAnimal'

    std::cout << "Attempting to create generic AAnimal is now forbidden by compiling rules!" << std::endl;
    std::cout << "Creating only concrete classes (Dog & Cat) instead." << std::endl;


    printHeader("STANDARD POLYMORPHISM & DEEP COPY (Ex01 Code)");
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "\n--- Sounds ---" << std::endl;
    j->makeSound();
    i->makeSound();

    std::cout << "\n--- Deletion ---" << std::endl;
    delete j;
    delete i;

    printHeader("END OF PROGRAM");
    return 0;
}
