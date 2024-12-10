#pragma once
#include <iostream>
#include <string>

class Food {
private:
	std::string naziv;
	static int counter;

public:
	Food(std::string);

	void povecaj_counter();
	void smanji_counter();
	void print_counter();

	friend int get_counter();
};