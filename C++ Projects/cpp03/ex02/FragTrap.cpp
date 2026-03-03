#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("Default") {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called!" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Parameterized constructor called for " << this->_name << "!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called, cloning " << this->_name << "!" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap Copy assignment operator called for " << this->_name << " from " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for " << this->_name << "!" << std::endl;
}

// Special ability
void FragTrap::highFivesGuys(void) {
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is broken and can't high five anyone!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " requests a positive HIGH FIVE! ✋" << std::endl;
}
