#include "Zombie.hpp"

int main( void ) {
	std::cout << "[1] Creating a zombie on the stack:" << std::endl;
	randomChump("Stack_Zombie");

	std::cout << "----------------------------------" << std::endl;

	std::cout << "[2] Creating a zombie on the heap:" << std::endl;
	Zombie* z = newZombie("Heap_Zombie");
	if (z)
	{
		z->announce();
		std::cout << "[3] Deleting the heap zombie:" << std::endl;
		delete z;
	}
	return (0);
}
