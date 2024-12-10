#include "food.hpp"

int Food::counter = 0;

Food::Food(std::string) {
	this->naziv = naziv;
}

void Food::povecaj_counter() {
	counter++;
}

void Food::smanji_counter() {
	counter--;
}

int get_counter() {
	return Food::counter;
}

void Food::print_counter() {
	std::cout << "counter: " << get_counter() << std::endl;
}

