#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Parameterized constructor called for " << this->_name << "!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap Copy constructor called, cloning " << this->_name << "!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called for " << this->_name << " from " << other._name << "!" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called for " << this->_name << "!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is completely broken and cannot attack!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is out of juice and has no energy to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already destroyed, stop hitting it!" << std::endl;
		return;
	}
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
	} else {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount
				  << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is beyond repair! It's dead, Jim!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " doesn't have the energy to lift a spanner to repair itself!" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount
			  << " hit points!" << std::endl;
}
