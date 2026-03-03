#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	// Constructors
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);

	// Assignment Operator
	ScavTrap& operator=(const ScavTrap& other);

	// Destructor
	~ScavTrap();

	// Subject Methods
	void attack(const std::string& target);
	void guardGate();
};

#endif
