#include "ClapTrap.hpp"

int main() {
	std::cout << "--- 1. CONSTRUCTORS TEST ---" << std::endl;
	ClapTrap defaultTrap;
	ClapTrap a("Arthur");
	ClapTrap b("Boris");

	std::cout << "\n--- 2. COPY CONSTRUCTOR & ASSIGNMENT TEST ---" << std::endl;
	ClapTrap c(a); // Test Copy constructor
	defaultTrap = b; // Test Copy assignment operator

	std::cout << "\n--- 3. BATTLE SIMULATION ---" << std::endl;
	a.attack("Boris");
	b.takeDamage(0); // Since Arthur's attackDamage is 0

	std::cout << "\n--- 4. TAKING REAL DAMAGE ---" << std::endl;
	a.takeDamage(5); // Arthur gets hit
	a.takeDamage(4); // Arthur takes more damage, 1 HP left

	std::cout << "\n--- 5. REPAIRING ---" << std::endl;
	a.beRepaired(8); // Arthur heals by 8
	a.beRepaired(2); // Arthur heals again

	std::cout << "\n--- 6. FATAL BLOW & DEAD CT INTERACTION ---" << std::endl;
	a.takeDamage(50); // Fatal damage, reduces hp to 0
	a.takeDamage(10); // Trying to damage a dead ClapTrap
	a.attack("Someone"); // Dead CT tries to attack
	a.beRepaired(10); // Dead CT tries to repair

	std::cout << "\n--- 7. ENERGY DEPLETION ---" << std::endl;
	ClapTrap worker("Workaholic");
	for (int i = 0; i < 9; i++) { // Workaholic starts with 10 energy, will use 9 here
		worker.attack("Air");
	}
	worker.beRepaired(1); // 10th energy point used
	worker.attack("Exhaustion"); // Should fail, no energy left
	worker.beRepaired(5); // Should fail, no energy left

	std::cout << "\n--- 8. DESTRUCTORS ---" << std::endl;
	return 0;
}
