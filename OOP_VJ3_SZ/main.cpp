#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
	// 1.zad za prvi unos
	std::vector<int> vektor1;
	int broj_elementa = 5;

	unesi_vektor(vektor1, broj_elementa);
	std::cout << "Prvi vektor: " << std::endl;
	ispisi_vektor(vektor1);

	// 1.zad za drugi unos
	std::vector<int> vektor2;
	int donja_granica = 2, gornja_granica = 8;
	unesi_vektor_interval(vektor2, donja_granica, gornja_granica);
	std::cout << "Drugi vektor: " << std::endl;
	ispisi_vektor(vektor2);

	// 2.zad 
	std::vector<int> rez = prvi_bez_drugi(vektor1, vektor2);
	std::cout << "Prvi vektor bez elementa drugog: " << std::endl;
	ispisi_vektor(rez);

	// 3.zad
	std::vector<int> vektor3 = {2, 10, 1, 4, 5, 5, 6, 1, 8 ,9 };
	std::sort(vektor3.begin(), vektor3.end());
	vektor3.insert(vektor3.begin(), 0);
	int zbroj = std::accumulate(vektor3.begin(), vektor3.end(), 0);
	vektor3.push_back(zbroj);

	std::cout << "3. zadatak sortirani vektor: " << std::endl;
	ispisi_vektor(vektor3);
	
	// 4.zad
	std::vector<int> vektor4 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "vektor prije izbrisanog elementa:" << std::endl;
	ispisi_vektor(vektor4);
	ukloni_el(vektor4, 5);
	std::cout << "vektor nakon izbrisanog elementa:" << std::endl;
	ispisi_vektor(vektor4);

	return 0;
}