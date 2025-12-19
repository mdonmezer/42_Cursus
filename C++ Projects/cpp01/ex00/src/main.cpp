#include "Zombie.hpp"

int	main(void) {
	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	randomChump("StackZombie");
	delete heapZombie;

	return (0);
}
