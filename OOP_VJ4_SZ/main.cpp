#include "header.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#define _CRT_SECURE_NO_WARNINGS

int main(){

	// 1. zadatak
	std::string str = "string he he ha hi he he";
	std::string pod_str = "he";

	int rez = broj_podstringa(str, pod_str);
	std::cout << "broj podstringa: " << rez << std::endl;

	std::cout << "\n";

	// 2. zadatak 
	std::string str_recenica = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";
	ispravi_recenicu(str_recenica);
	std::cout << str_recenica << std::endl;

	std::cout << "\n";

	// 3. zadatak
	std::vector<std::string> vektor(4);
	sortiraj_stringove(vektor);

	std::cout << "\n";

	// 4. zadatak
	std::vector<std::string> vek_recenice = {
		"What time is it?",
		//"What time is now?",
		//"Hello ovo je primjer."
	};

	std::srand(static_cast<unsigned int>(std::time(0)));
	int slucajna_recenica = std::rand() % vek_recenice.size();
	std::string str_odabrani_string = vek_recenice[slucajna_recenica];

	piglatin(str_odabrani_string);

	return 0;
}