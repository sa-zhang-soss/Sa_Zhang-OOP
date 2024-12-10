#include "header.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	
	int br_igraca = 0;
	std::string ime_igraca;
	std::vector <std::string> igraci;
	Mac mac;
	std::vector <Karta> sve_karte;

	Igrac igr1, igr2, igr3, igr4;
	std::vector <Igrac> Igraci_t{ igr1, igr2, igr3, igr4 };

	mac.make_mac();
	mac.shuffle();
	sve_karte = mac.get_mac();

	while ((br_igraca != 2) && (br_igraca != 4)) {
		std::cout << "Unesi broj igraca koji moze samo biti 2 ili 4: " << std::endl;
		std::cin >> br_igraca;
	}

	for (int i = 0; i < br_igraca; i++) {
		std::cout << "Unesi ime igraca" << std::endl;
		std::cin >> ime_igraca;
		igraci.push_back(ime_igraca);
	}
	
	for (int i = 0; i < br_igraca; i++) {
		Igraci_t[i].set_ime(igraci[i]);
		sve_karte = Igraci_t[i].set_ruka(sve_karte);
	}
	
	std::cout << "\n";
	for (int i = 0; i < br_igraca; i++) {
		Igraci_t[i].print_ruka();
		std::cout << "\n";
	}

	for (int i = 0; i < br_igraca; i++) {
		Igraci_t[i].akuze();
	}

	std::cout << "\n";
	for (int i = 0; i < br_igraca; i++) {
		Igraci_t[i].print_bodovi();
		std::cout << "\n";
	}
	std::cout <<sve_karte.size() ;
	return 0;
}