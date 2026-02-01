#include "Zombie.hpp"

#define HORDE_SIZE 5

int	main(void) {
	Zombie*	horde = zombieHorde(HORDE_SIZE, "HordeZombie");

	if (horde == NULL)
	{
		std::cout << "Allocation failed or inavlid size!" << std::endl;
		return (1);
	}

	for (int i = 0; i < HORDE_SIZE; i++) {
		horde[i].announce();
	}

	delete [] horde;

	return (0);
}
