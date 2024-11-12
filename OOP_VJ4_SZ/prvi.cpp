#include "header.hpp"
#include<iostream>
#include<string>

int broj_podstringa(std::string& str, std::string& pod_str) {

	int broj_ponavljanja = 0;
	int pozicija = str.find(pod_str);

	while (pozicija != std::string::npos) {

		broj_ponavljanja++;
		pozicija = str.find(pod_str, pozicija + 1);

	}

	return broj_ponavljanja;
}