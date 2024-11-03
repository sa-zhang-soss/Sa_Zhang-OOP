#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<vector>

// 1 zadatak
void unesi_vektor(std::vector<int>& vektor, int broj_elementa);

void unesi_vektor_interval(std::vector<int>& vektor, int donja_granica, int gornja_granica);

void ispisi_vektor(std::vector<int>& vektor);

// 2 zadatak
std::vector<int> prvi_bez_drugi(std::vector<int>& vektor1, std::vector<int>& vektor2);

// 4 zadatak
void ukloni_el(std::vector<int>& vektor, int koji);