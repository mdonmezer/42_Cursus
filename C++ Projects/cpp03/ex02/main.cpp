#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "--- 1. CLAP, SCAV, AND FRAG CONSTRUCTION CHAIN ---" << std::endl;
	ClapTrap c("ClassicClap");
	ScavTrap s("SuperiorScav");
	FragTrap f("FabulousFrag");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	FragTrap fCopy(f); // Copy constructor
	FragTrap fAssign;
	fAssign = f; // Assignment operator

	std::cout << "\n--- 3. SPECIFIC ABILITIES AND ATTRIBUTES ---" << std::endl;
	c.attack("Target 1"); // ClapTrap Output
	s.attack("Target 2"); // ScavTrap Output
	f.attack("Target 3"); // FragTrap Output (Inherited from ClapTrap, 30 damage, 1 energy cost)

	std::cout << "\n--- 4. TAKING DAMAGE AND REPAIRING ---" << std::endl;
	f.takeDamage(50); // FragTrap has 100 HP, should survive
	f.beRepaired(25); // Uses 1 of 100 energy, gains 25 HP

	std::cout << "\n--- 5. SPECIAL ABILITIES ---" << std::endl;
	s.guardGate();
	f.highFivesGuys();

	std::cout << "\n--- 6. FATAL DAMAGE TEST ---" << std::endl;
	f.takeDamage(1000); // Kills the FragTrap
	f.highFivesGuys(); // Should fail gracefully
	f.attack("Enemy"); // Should fail
	f.beRepaired(10); // Should fail

	std::cout << "\n--- 7. DESTRUCTION CHAIN ---" << std::endl;
	return 0;
}
