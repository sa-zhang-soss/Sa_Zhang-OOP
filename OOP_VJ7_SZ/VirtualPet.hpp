#pragma once
#include <iostream>
#include <string>

class VirtualPet {

private:
	std::string ime;
	std::string vrsta;
	int glad = 2;
	int sreca = 0;
	bool budan = true;

public:

	VirtualPet(std::string ime, std::string vrsta);
	~VirtualPet();

	void spavaj();
	int get_glad();
	int get_sreca();
	std::string get_vrsta();

	bool operator==(VirtualPet const& other);
	bool operator!=(VirtualPet const& other);

	VirtualPet operator=(VirtualPet const& other);

	int operator++();
	int operator++(int);

	bool operator<(VirtualPet const& other);
	bool operator>(VirtualPet const& other);
	bool operator<=(VirtualPet const& other);
	bool operator>=(VirtualPet const& other);

	friend std::ostream& operator <<(std::ostream& os, const VirtualPet& pet);

};