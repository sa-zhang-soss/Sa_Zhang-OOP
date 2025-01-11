#include "header.hpp"
#include<iostream>

int main() {
	
	Boss Tea("Tea", 100, 500, "emocionalna bol");
	Monster Flafy("Flafy", 50, 1, "pokenja se u kuci");

	Tea.attack();
	std::cout << std::endl;
	Flafy.attack();
	std::cout << std::endl;

	Tea.displayInfo();
	std::cout << std::endl;
	Flafy.displayInfo();

	return 0;
}