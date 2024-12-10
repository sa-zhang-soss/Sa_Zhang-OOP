#pragma once
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Karta {
private:
	int broj;
	std::string zog;

public:

	Karta(int br, const std::string& z) : broj(br), zog(z) {}
	Karta() : broj(0), zog("") {}

	int get_broj() {
		return this->broj;
	}

	std::string get_zog() {
		return this->zog;
	}

	void set_karta(int br, std::string z) {
		this->broj = br;
		this->zog = z;
	}
};

class Mac {
private:
	std::vector<Karta> mac;
	Karta k;
	std::vector <int> brojevi{ 1,2,3,4,5,6,7,11,12,13 };
	std::vector <std::string> zogovi{ "spade", "kupe", "dinare", "bastone" };

public:

	std::vector <Karta> get_mac() {
		return this->mac;
	}
	void make_mac() {
		for (int i = 0; i < zogovi.size(); i++) {
			for (int j = 0; j < brojevi.size(); j++) {
				k.set_karta(brojevi[j], zogovi[i]);
				mac.push_back(k);
			}
		}
	}

	void shuffle() {
		std::random_device random_seed;
		std::mt19937 random_shuffle(random_seed());
		std::shuffle(mac.begin(), mac.end(), random_shuffle);
	}

};

class Igrac {
private:
	std::string ime;
	int broj_bodova = 0;
	std::vector<Karta> ruka;


public:


	void set_ime(std::string ime_igraca) {
		this->ime = ime_igraca;
	}

	void print_bodovi() {
		std::cout << ime << " ima " << broj_bodova <<" bodova akuze" << std::endl;
	}

	std::vector<Karta> set_ruka(std::vector <Karta> mac) {
		for (int i = 0; i < 10; i++) {
			ruka.push_back(mac[i]);
		}
		mac.erase(mac.begin(), mac.begin() + 10);
		return mac;
	}

	void print_ruka() {
		for (int j = 0; j < 10; j++) {
			std::cout << ruka[j].get_broj() << " " << ruka[j].get_zog() << std::endl;
		}

	}

	void akuze() {
		int spade[3] = {0,0,0};
		int kupe[3] = { 0,0,0 };
		int dinare[3] = { 0,0,0 };
		int bastone[3] = { 0,0,0 };

		for (int i = 0; i < ruka.size(); i++) {

			int broj = ruka[i].get_broj();
			std::string zog = ruka[i].get_zog();
			
			if ((broj == 1) || (broj == 2) || (broj == 3)) {
				if (zog == "spade") {
					spade[broj - 1]++;
				}
				else if (zog == "kupe") {
					kupe[broj - 1]++;
				}
				else if (zog == "dinare") {
					dinare[broj - 1]++;
				}
				else if (zog == "bastone") {
					bastone[broj - 1]++;
				}
			}
			
			if (spade[0] == 1 && spade[1] == 1 && spade[2] == 1) {
				broj_bodova += 3;
			}
			if (kupe[0] == 1 && kupe[1] == 1 && kupe[2] == 1) {
				broj_bodova += 3;
			}
			if (dinare[0] == 1 && dinare[1] == 1 && dinare[2] == 1) {
				broj_bodova += 3;
			}
			if (bastone[0] == 1 && bastone[1] == 1 && bastone[2] == 1){
			broj_bodova += 3;
			}

			
			for (int j = 0; j < 3; j++) {
				if ((spade[j] == 1 && kupe[j] == 1 && dinare[j] == 1) || 
					(kupe[j] == 1 && dinare[j] == 1 && bastone[j] == 1) ||
					(dinare[j] == 1 && bastone[j] == 1 && spade[j] == 1) || 
					(bastone[j] == 1 && spade[j] == 1 && kupe[j] == 1) ) {
					broj_bodova += 3;
				}
				
			}


		}
	}
};