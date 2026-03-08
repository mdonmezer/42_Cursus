#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n================= " << title << " =================" << std::endl;
}

int main()
{
    printHeader("SUBJECT PROVIDED TESTS");
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n--- Deletion ---" << std::endl;
    delete i;
    delete j;
    delete meta;


    printHeader("WRONG ANIMAL TESTS");
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    wrongI->makeSound();
    wrongMeta->makeSound();

    std::cout << "\n--- Deletion ---" << std::endl;
    delete wrongI;
    delete wrongMeta;


    printHeader("ADDITIONAL DIRECT OBJECT TESTS");
    Dog basicDog;
    Cat basicCat;
    WrongCat basicWrongCat;

    std::cout << "\n--- Direct object sounds ---" << std::endl;
    basicDog.makeSound();
    basicCat.makeSound();
    basicWrongCat.makeSound();

    std::cout << "\n--- Exiting Program ---" << std::endl;

    return 0;
}
