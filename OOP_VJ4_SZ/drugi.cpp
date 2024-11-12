#include "header.hpp"
#include<iostream>


void ispravi_recenicu(std::string& str) {

	int duzina_str = str.size();

	for (int i = 0; i < duzina_str; i++) {

		if (str[i] == ',' && str[i - 1] == ' ') {
			str.erase(i - 1, 1);
			duzina_str = str.size();
		}
	}

	for (int j = 0; j < duzina_str; j++) {

		if (str[j] == ',' && str[j + 1] != ' ' && j< duzina_str) {
			str.insert(j + 1, " ");
			duzina_str = str.size();
		}
	}
}