#include<iostream>
#include <iomanip>

typedef struct matrica {
	int redovi_m;
	int stupci_n;
	float* niz_elemenata_matrice;

	void unos_matrice(int m, int n) {
		redovi_m = m;
		stupci_n = n;
		niz_elemenata_matrice = new float[m * n];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << "unesi elemente matrice" << std::endl;
				std::cin >> niz_elemenata_matrice[(i * n) + j];
			}
		}
	}

	void generiraj_matricu(int pocetak, int kraj, int m, int n) {
		niz_elemenata_matrice = new float[m * n];
		redovi_m = m;
		stupci_n = n;
		for (int i = pocetak; i < (m * n); i++) {
			std::cin >> niz_elemenata_matrice[i];
		}
	}

	matrica zbroji(matrica& A, matrica& B) {
		matrica C;
		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cout << "matrice nisu jednake" << std::endl;
			exit(1);
		}
		C.redovi_m = A.redovi_m;
		C.stupci_n = A.stupci_n;
		C.niz_elemenata_matrice = new float[C.redovi_m * C.stupci_n];

		for (int i = 0; i < (C.redovi_m * C.stupci_n); i++) {
			C.niz_elemenata_matrice[i] = (A.niz_elemenata_matrice[i] + B.niz_elemenata_matrice[i]);
		}

		return C;
	}

	matrica oduzmi(matrica& A, matrica& B) {
		matrica D;
		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cout << "matrice nisu jednake" << std::endl;
			exit(1);
		}
		D.redovi_m = A.redovi_m;
		D.stupci_n = A.stupci_n;
		D.niz_elemenata_matrice = new float[D.redovi_m * D.stupci_n];

		for (int i = 0; i < (D.redovi_m * D.stupci_n); i++) {
			D.niz_elemenata_matrice[i] = (A.niz_elemenata_matrice[i] - B.niz_elemenata_matrice[i]);
		}

		return D;
	}

	matrica pomnozi(matrica& A, matrica& B) {
		matrica E;
		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cout << "matrice nisu jednake" << std::endl;
			exit(1);
		}
		E.redovi_m = A.redovi_m;
		E.stupci_n = A.stupci_n;
		E.niz_elemenata_matrice = new float[E.redovi_m * E.stupci_n];

		for (int i = 0; i < (E.redovi_m * E.stupci_n); i++) {
			E.niz_elemenata_matrice[i] = (A.niz_elemenata_matrice[i] * B.niz_elemenata_matrice[i]);
		}

		return E;
	}

	void ispis_matrice(){
		for (int i = 0; i < redovi_m; i++) {
			for (int j = 0; j < stupci_n; j++) {
				std::cout << std::fixed << std::setprecision(4) << std::setw(10) << niz_elemenata_matrice[(i * stupci_n) + j] << " ";
			}
			std::cout << std::endl;
		}
	}


};


int main() {
	int m1 = 3;
	int n1 = 3;

	int m2 = 3;
	int n2 = 3;

	float pocetak_raspona = 2.1234;
	float kraj_raspona = 15.1234;

	matrica A;
	A.unos_matrice(m1,n1);

	matrica B;
	B.generiraj_matricu(pocetak_raspona, kraj_raspona, m2, n2);

	A.ispis_matrice();
	B.ispis_matrice();

	return 0;
}