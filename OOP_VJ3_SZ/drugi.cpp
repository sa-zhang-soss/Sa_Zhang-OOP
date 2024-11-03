#define _CRT_SECURE_NO_WARNINGS
#include "header.hpp"
#include <iostream>
#include <vector>

std::vector<int> prvi_bez_drugi(std::vector<int>& vektor1, std::vector<int>& vektor2) {
	std::vector<int> rez;
	int t_f;

	for (int el_1 : vektor1) {

		t_f = 0;

		for (int el_2 : vektor2) {

			if (el_1 == el_2) {
				t_f = 1;
				break;
			}
		}

		if (t_f == 0) {
			rez.push_back(el_1);
		}
	}

	return rez;
}