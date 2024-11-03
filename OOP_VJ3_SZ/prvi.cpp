#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"
#include <iostream>
#include <vector>

void unesi_vektor(std::vector<int>& vektor, int broj_elementa) {
 
    for (int i = 0; i < broj_elementa; ++i) {
        int el;
        std::cout << "unesite element " << std::endl;
        std::cin >> el;
        vektor.push_back(el);
    }
}

void unesi_vektor_interval(std::vector<int>& vektor, int donja_granica, int gornja_granica) {
  
    int el;
    while (true) {
        std::cout << "unesite element unutar zadanog intervala: ";
        std::cin >> el;
        if ((el < donja_granica) || (el > gornja_granica)) {
            break;
        }
        vektor.push_back(el);
    }
}

void ispisi_vektor(std::vector<int>& vektor) {
    for (int& el : vektor) {
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}