#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default") {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Default constructor called!" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Parameterized constructor called for " << this->_name << "!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called, cloning " << this->_name << "!" << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap Copy assignment operator called for " << this->_name << " from " << other._name << "!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called for " << this->_name << "!" << std::endl;
}

// Attack function (Overridden)
void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is broken to pieces and cannot attack!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is exhausted and has no energy to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target
			  << ", dealing " << this->_attackDamage << " points of damage!" << std::endl;
}

// Special ability
void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is destroyed and cannot switch to Gate keeper mode!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
