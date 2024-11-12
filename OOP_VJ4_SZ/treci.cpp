#include "header.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void sortiraj_stringove(std::vector<std::string>& vektor) {

	std::string str;
	int duzina = vektor.size();

	for (int i = 0; i < duzina; i++) {

		std::cout << "unesi string" << std::endl;
		std::getline(std::cin, str);
		std::reverse(str.begin(), str.end());
		vektor[i] = str;
	}

	std::sort(vektor.begin(), vektor.end());
	std::cout << "SORTIRANI STRINGOVI: " << std::endl;

	for (int i = 0; i < duzina; i++) {
		std::cout << vektor[i] << std::endl;
	}
}