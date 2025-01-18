#include "header.hpp"
#include<iostream>

int main() {
	try {
		Boss Tea("Tea", 100, 500, "emocionalna bol");
		Monster Flafy("Flafy", 50, -1, "pokenja se u kuci");

		Tea.attack();
		std::cout << std::endl;
		Flafy.attack();
		std::cout << std::endl;

		Tea.displayInfo();
		std::cout << std::endl;
		Flafy.displayInfo();
	}
	catch(std::invalid_argument const& ex){
		std::cout << "Podaci su neispravni: " << ex.what() << std::endl;
	}
	

	return 0;
}