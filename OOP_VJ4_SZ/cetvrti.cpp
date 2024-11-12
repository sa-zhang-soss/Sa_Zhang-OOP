#include "header.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>

bool jeli_samoglasnik(char c) {

	c = std::tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void piglatin(std::string& str) {

	std::stringstream ss(str);
	std::string str_prevedeni;
	std::string rijec;
	char punk;

	while (ss >> rijec) {

		if (ispunct(rijec.back())) {

			punk = rijec.back();
			rijec.pop_back();
		}
		if (jeli_samoglasnik(rijec[0])) {
			rijec += "hay";
			str_prevedeni += rijec + ' ';
		}
		else {
			while (!jeli_samoglasnik(rijec[0])) {
				rijec.push_back(rijec[0]);
				rijec.erase(rijec.begin());
			}
			rijec += "ay";
			str_prevedeni += rijec + ' ';
		}
	}

	str_prevedeni += punk;
	std::cout << "predena recenica na pig latin: " << str_prevedeni << std::endl;
}