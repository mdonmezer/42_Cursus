#include "ScavTrap.hpp"

int main() {
	std::cout << "--- 1. CLAPTRAP AND SCAVTRAP CONSTRUCTION CHAIN ---" << std::endl;
	ClapTrap c("ClassicClap");
	ScavTrap s("SuperiorScav");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	ScavTrap sCopy(s); // Copy constructor
	ScavTrap sAssign;
	sAssign = s; // Assignment operator

	std::cout << "\n--- 3. SPECIFIC ABILITIES AND ATTRIBUTES ---" << std::endl;
	c.attack("Target 1"); // ClapTrap Output
	s.attack("Target 2"); // ScavTrap Output (Uses 1 energy, deals 20 damage)

	std::cout << "\n--- 4. TAKING DAMAGE AND REPAIRING ---" << std::endl;
	s.takeDamage(50); // ScavTrap has 100 HP, should survive
	s.beRepaired(25); // Uses 1 of 50 energy

	std::cout << "\n--- 5. GUARD GATE SPECIAL ABILITY ---" << std::endl;
	s.guardGate();

	std::cout << "\n--- 6. FATAL DAMAGE TEST ---" << std::endl;
	s.takeDamage(1000); // Kills the ScavTrap
	s.guardGate(); // Should fail
	s.attack("Enemy"); // Should fail
	s.beRepaired(10); // Should fail

	std::cout << "\n--- 7. DESTRUCTION CHAIN ---" << std::endl;
	return 0;
}
