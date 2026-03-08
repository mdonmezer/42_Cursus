#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n================= " << title << " =================" << std::endl;
}

int main()
{
    printHeader("SUBJECT REQUIRED TESTS");
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    printHeader("ARRAY OF ANIMALS TEST");
    int numAnimals = 6;
    Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals; k++) {
        if (k % 2 == 0)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\n--- Deleting the array ---" << std::endl;
    for (int k = 0; k < numAnimals; k++) {
        delete animals[k];
    }


    printHeader("DEEP COPY TEST (DOG)");
    Dog basicDog;
    basicDog.getBrain()->ideas[0] = "I want to catch the postman.";
    basicDog.getBrain()->ideas[1] = "Need more treats.";

    std::cout << "Original Dog Idea[0]: " << basicDog.getBrain()->ideas[0] << std::endl;

    Dog copyDog = basicDog; // Calls copy constructor
    std::cout << "Copied Dog Idea[0] (should match original): " << copyDog.getBrain()->ideas[0] << std::endl;

    std::cout << "Modifying Original Dog Idea[0]..." << std::endl;
    basicDog.getBrain()->ideas[0] = "Squirrel!";

    std::cout << "Original Dog Idea[0]: " << basicDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copied Dog Idea[0] (should NOT change): " << copyDog.getBrain()->ideas[0] << std::endl;

    std::cout << "Original Brain address: " << basicDog.getBrain() << std::endl;
    std::cout << "Copied Brain address: " << copyDog.getBrain() << std::endl; // Should be completely different


    printHeader("DEEP COPY TEST (CAT ASSIGNMENT)");
    Cat catOne;
    catOne.getBrain()->ideas[0] = "I own the human.";

    Cat catTwo;
    catTwo.getBrain()->ideas[0] = "I should sleep all day.";

    std::cout << "Cat One Idea[0]: " << catOne.getBrain()->ideas[0] << std::endl;
    std::cout << "Cat Two Idea[0]: " << catTwo.getBrain()->ideas[0] << std::endl;

    std::cout << "Assigning Cat One to Cat Two..." << std::endl;
    catTwo = catOne; // Calls assignment operator

    std::cout << "Cat Two Idea[0] (should match Cat One): " << catTwo.getBrain()->ideas[0] << std::endl;
    std::cout << "Cat One Brain address: " << catOne.getBrain() << std::endl;
    std::cout << "Cat Two Brain address: " << catTwo.getBrain() << std::endl; // Should be different!

    printHeader("END OF PROGRAM");
    return 0;
}
