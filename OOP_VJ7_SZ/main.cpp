#include "food.hpp"
#include "VirtualPet.hpp"
#include<iostream>

int main() {
	// food
	Food Meso("Meso");

	Meso.povecaj_counter();
	Meso.povecaj_counter();
	Meso.smanji_counter();
	Meso.print_counter();

	// virtual pet 
	VirtualPet Boni("Boni", "pas");
	VirtualPet Flafy("Flafy", "pas");
	VirtualPet Clyde("Clyde", "macka");
	VirtualPet Shadow("Shadow", "lav");
	VirtualPet Max("Max", "zec");
	VirtualPet Oliver("Oliver", "ovca");

	if (Flafy == Boni) {
		std::cout << "isti su" << std::endl;
	}
	else if (Flafy != Boni) {
		std::cout << "nisu isti" << std::endl;
	}
	
	VirtualPet Jerry = Max;

	Flafy++;
	++Boni;

	if (Shadow < Max) {
		std::cout << "Max je sretniji" << std::endl;
	}
	else if (Shadow > Max) {
		std::cout << "Shadow je sretniji" << std::endl;
	}

	std::cout << Flafy << std::endl;

	return 0;
}