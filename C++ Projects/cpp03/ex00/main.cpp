#include "ClapTrap.hpp"

int main() {
	std::cout << "--- 1. CONSTRUCTORS TEST ---" << std::endl;
	ClapTrap defaultTrap;
	ClapTrap a("Arthur");
	ClapTrap b("Boris");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	ClapTrap c(a);
	defaultTrap = b;

	std::cout << "\n--- 3. BATTLE SIMULATION ---" << std::endl;
	a.attack("Boris");
	b.takeDamage(0);

	std::cout << "\n--- 4. TAKING REAL DAMAGE ---" << std::endl;
	a.takeDamage(5);
	a.takeDamage(4);

	std::cout << "\n--- 5. REPAIRING ---" << std::endl;
	a.beRepaired(8);
	a.beRepaired(2);

	std::cout << "\n--- 6. FATAL BLOW & DEAD CT INTERACTION ---" << std::endl;
	a.takeDamage(50);
	a.takeDamage(10);
	a.attack("Someone");
	a.beRepaired(10);

	std::cout << "\n--- 7. ENERGY DEPLETION ---" << std::endl;
	ClapTrap worker("Workaholic");
	for (int i = 0; i < 9; i++) {
		worker.attack("Air");
	}
	worker.beRepaired(1);
	worker.attack("Exhaustion");
	worker.beRepaired(5);

	std::cout << "\n--- 8. DESTRUCTORS ---" << std::endl;
	return 0;
}
