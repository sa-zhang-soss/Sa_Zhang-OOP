#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"
#include <iostream>
#include <vector>

void ukloni_el(std::vector<int>& vektor, int koji) {

	vektor[koji] = vektor.back();
	vektor.pop_back();

}