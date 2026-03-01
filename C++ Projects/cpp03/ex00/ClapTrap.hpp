#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	// Constructors
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);

	// Assignment Operator
	ClapTrap& operator=(const ClapTrap& other);

	// Destructor
	~ClapTrap();

	// Subject Methods
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
