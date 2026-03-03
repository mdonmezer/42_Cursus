#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Constructors
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);

	// Assignment Operator
	FragTrap& operator=(const FragTrap& other);

	// Destructor
	~FragTrap();

	// Special ability
	void highFivesGuys(void);
};

#endif
