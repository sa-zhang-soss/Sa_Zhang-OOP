#include<iostream>

int& vrati_el(int niz[], int i) {
	return niz[i];
}

int main() {
	int niz[] = {0,1,2,3,4,5,6,7,8,9};
	int i = 3;
	int duz = sizeof(niz) / sizeof(niz[0]);

	vrati_el(niz,i) += 1;

	for (int j = 0; j < duz; j++) {
		std::cout << niz[j] << std::endl;
	}
	return 0;
}