#include "ScavTrap.hpp"

int main() {
	std::cout << "--- 1. CLAPTRAP AND SCAVTRAP CONSTRUCTION CHAIN ---" << std::endl;
	ClapTrap c("ClassicClap");
	ScavTrap s("SuperiorScav");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	ScavTrap sCopy(s);
	ScavTrap sAssign;
	sAssign = s;

	std::cout << "\n--- 3. SPECIFIC ABILITIES AND ATTRIBUTES ---" << std::endl;
	c.attack("Target 1");
	s.attack("Target 2");

	std::cout << "\n--- 4. TAKING DAMAGE AND REPAIRING ---" << std::endl;
	s.takeDamage(50);
	s.beRepaired(25);

	std::cout << "\n--- 5. GUARD GATE SPECIAL ABILITY ---" << std::endl;
	s.guardGate();

	std::cout << "\n--- 6. FATAL DAMAGE TEST ---" << std::endl;
	s.takeDamage(1000);
	s.guardGate();
	s.attack("Enemy");
	s.beRepaired(10);

	std::cout << "\n--- 7. DESTRUCTION CHAIN ---" << std::endl;
	return 0;
}
