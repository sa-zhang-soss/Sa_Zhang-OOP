#include "VirtualPet.hpp"

VirtualPet::VirtualPet(std::string ime, std::string vrsta) {
	this->ime = ime;
	this->vrsta = vrsta;
}

VirtualPet::~VirtualPet() {

};

void VirtualPet::spavaj() {
	budan == false;
}

int VirtualPet::get_glad() {
	return this->glad;
}

int VirtualPet::get_sreca() {
	return this->sreca;
}

std::string VirtualPet::get_vrsta() {
	return this->vrsta;
}

bool VirtualPet::operator==(VirtualPet const& other) {
	return(    (this->ime==other.ime) 
			&& (this->vrsta == other.vrsta)
			&& (this->glad == other.glad)
			&& (this->sreca == other.sreca)
			&& (this->budan == other.budan)
		);
}

bool VirtualPet::operator!=(VirtualPet const& other) {
	return(    (this->ime != other.ime)
			|| (this->vrsta != other.vrsta)
			|| (this->glad != other.glad)
			|| (this->sreca != other.sreca)
			|| (this->budan != other.budan)
		);
}

VirtualPet VirtualPet::operator=(VirtualPet const& other) {
	VirtualPet new_pet(other.ime, other.vrsta);
	return new_pet;
}

int VirtualPet::operator++() {
	return --glad;
}

int VirtualPet::operator++(int) {
	return glad--;
}

bool VirtualPet::operator<(VirtualPet const& other) {
	return(this->sreca < other.sreca);
}
bool VirtualPet::operator>(VirtualPet const& other) {
	return(this->sreca > other.sreca);
}
bool VirtualPet::operator<=(VirtualPet const& other) {
	return(this->sreca <= other.sreca);
}
bool VirtualPet::operator>=(VirtualPet const& other) {
	return(this->sreca >= other.sreca);
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& pet) {
	os << "ime: " << pet.ime << std::endl
		<< "vrsta: " << pet.vrsta << std::endl
		<< "sreca: " << pet.sreca << std::endl
		<< "stanje: " << pet.budan << std::endl;
	return os;
}