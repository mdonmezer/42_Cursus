#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0; // Pure virtual function makes this class Abstract
    std::string getType() const;
};

#endif
