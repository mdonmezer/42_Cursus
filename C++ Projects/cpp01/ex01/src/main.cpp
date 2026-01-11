#include "Zombie.hpp"

#define ZOMBIE_COUNT 5

int	main( void )
{
	Zombie	*horde;

	std::cout << "--- Creating Horde ---" << std::endl;
	horde = zombieHorde(ZOMBIE_COUNT, "Walker");

	if (horde == NULL)
	{
		std::cout << "Allocation failed or invalid size." << std::endl;
		return (1);
	}

	std::cout << "--- Announcing Horde ---" << std::endl;
	for (int i = 0; i < ZOMBIE_COUNT; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	std::cout << "--- Deleting Horde ---" << std::endl;
	delete [] horde;

	return (0);
}
