#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "--- 1. CLAP, SCAV, AND FRAG CONSTRUCTION CHAIN ---" << std::endl;
	ClapTrap c("ClassicClap");
	ScavTrap s("SuperiorScav");
	FragTrap f("FabulousFrag");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	FragTrap fCopy(f);
	FragTrap fAssign;
	fAssign = f;

	std::cout << "\n--- 3. SPECIFIC ABILITIES AND ATTRIBUTES ---" << std::endl;
	c.attack("Target 1");
	s.attack("Target 2");
	f.attack("Target 3");

	std::cout << "\n--- 4. TAKING DAMAGE AND REPAIRING ---" << std::endl;
	f.takeDamage(50);
	f.beRepaired(25);

	std::cout << "\n--- 5. SPECIAL ABILITIES ---" << std::endl;
	s.guardGate();
	f.highFivesGuys();

	std::cout << "\n--- 6. FATAL DAMAGE TEST ---" << std::endl;
	f.takeDamage(1000);
	f.highFivesGuys();
	f.attack("Enemy");
	f.beRepaired(10);

	std::cout << "\n--- 7. DESTRUCTION CHAIN ---" << std::endl;
	return 0;
}
