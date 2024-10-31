#include<iostream>
#include<iomanip>

typedef struct Matrica {
	int redovi_m;
	int stupci_n;
	float** elementi_matrice;

	void unos_matrice(int m, int n) {
		redovi_m = m;
		stupci_n = n;

		elementi_matrice = new float*[redovi_m];
		for (int i = 0; i < m; i++) {
			elementi_matrice[i] = new float[stupci_n];
		}

		std::cout << "Unesite elemente matrice:" << std::endl;
		for (int i = 0; i < redovi_m; i++) {
			for (int j = 0; j < stupci_n; j++) {
				std::cin >> elementi_matrice[i][j];
			}
		}
	}

	void generiraj_matricu(float pocetak, float kraj, int m, int n) {
		redovi_m = m;
		stupci_n = n;

		elementi_matrice = new float* [redovi_m];
		for (int i = 0; i < m; i++) {
			elementi_matrice[i] = new float[stupci_n];
		}
		
		float p = pocetak;
		for (int i = 0; i < redovi_m; i++) {
			for (int j = 0; j < stupci_n; j++) {
				elementi_matrice[i][j] = p;
				if (p < kraj) {
					p++;
				}
			}
		}
	}

	Matrica zbroji(Matrica& A, Matrica& B) {
		Matrica C;

		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cerr << "matrice nisu jednake " << std::endl;
			exit(1);
		}

		C.redovi_m = A.redovi_m;
		C.stupci_n = A.stupci_n;
		C.elementi_matrice = new float* [C.redovi_m];
		for (int i = 0; i < C.redovi_m; i++) {
			C.elementi_matrice[i] = new float[C.stupci_n];
		}

		for (int i = 0; i < C.redovi_m; i++) {
			for (int j = 0; j < C.stupci_n; j++) {
				C.elementi_matrice[i][j] = A.elementi_matrice[i][j] + B.elementi_matrice[i][j];
			}
		}

		return C;
	}

	Matrica oduzmi(Matrica& A, Matrica& B) {
		Matrica D;

		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cerr << "matrice nisu jednake " << std::endl;
			exit(1);
		}

		D.redovi_m = A.redovi_m;
		D.stupci_n = A.stupci_n;
		D.elementi_matrice = new float* [redovi_m];
		for (int i = 0; i < D.redovi_m; i++) {
			D.elementi_matrice[i] = new float[D.stupci_n];
		}

		for (int i = 0; i < D.redovi_m; i++) {
			for (int j = 0; j < D.stupci_n; j++) {
				D.elementi_matrice[i][j] = A.elementi_matrice[i][j] - B.elementi_matrice[i][j];
			}
		}

		return D;
	}

	Matrica pomnozi(Matrica& A, Matrica& B) {
		Matrica E;

		if (A.redovi_m != B.redovi_m || A.stupci_n != B.stupci_n) {
			std::cerr << "matrice nisu jednake " << std::endl;
			exit(1);
		}

		E.redovi_m = A.redovi_m;
		E.stupci_n = A.stupci_n;
		E.elementi_matrice = new float* [redovi_m];
		for (int i = 0; i < E.redovi_m; i++) {
			E.elementi_matrice[i] = new float[E.stupci_n];
		}

		for (int i = 0; i < E.redovi_m; i++) {
			for (int j = 0; j < E.stupci_n; j++) {
				E.elementi_matrice[i][j] = A.elementi_matrice[i][j] * B.elementi_matrice[i][j];
			}
		}

		return E;
	}

	Matrica transponiraj(Matrica& A) {
		Matrica T;
		T.redovi_m = A.stupci_n;
		T.stupci_n = A.redovi_m;

		T.elementi_matrice = new float* [T.redovi_m];
		for (int i = 0; i <	T.redovi_m; i++) {
			T.elementi_matrice[i] = new float[T.stupci_n];
		}

		for (int i = 0; i < T.redovi_m; i++) {
			for (int j = 0; j < T.stupci_n; j++) {
				T.elementi_matrice[i][j] = A.elementi_matrice[j][i];
			}
		}

		return T;
	}

	void ispis_matrice() {
		for (int i = 0; i < redovi_m; i++) {
			for (int j = 0; j < stupci_n; j++) {
				std::cout << std::fixed << std::setprecision(4) << std::setw(10) << elementi_matrice[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void izbrisi() {
		if (elementi_matrice) {
			for (int i = 0; i < redovi_m; ++i) {
				delete[] elementi_matrice[i];
			}
			delete[] elementi_matrice;
		}
	}

}Matrica;

int main() {

	Matrica A, B, C, D, E, T;

	A.unos_matrice(3, 3);
	B.generiraj_matricu(1, 9, 3, 3);

	std::cout << "matrica A:" << std::endl;
	A.ispis_matrice();

	std::cout << "matrica B:" << std::endl;
	B.ispis_matrice();

	C = A.zbroji(A, B);
	std::cout << "matrica A + B:" << std::endl;
	C.ispis_matrice();

	D = A.oduzmi(A, B);
	std::cout << "matrica A - B:" << std::endl;
	D.ispis_matrice();

	E = A.pomnozi(A, B);
	std::cout << "matrica A * B:" << std::endl;
	E.ispis_matrice();

	T = A.transponiraj(A);
	std::cout << "matrica T:" << std::endl;
	T.ispis_matrice();

	A.izbrisi();
	B.izbrisi();
	C.izbrisi();
	D.izbrisi();
	E.izbrisi();
	T.izbrisi();

	return 0;
}