#include <iostream>
#include "residence.h"
using namespace std;


static const int RENT_1 = 25;
static const int RENT_2 = 50;
static const int RENT_3 = 100;
static const int RENT_4 = 200;


Residence::Residence(int ID, string name, int costToBuy, char owner)
	: Ownable(ID, name, costToBuy, owner)
{}


int Residence::amountToPay() {
	return rent;
}


void Residence::setRent() {
	if (this->payLevel == 1) {
		rent = RENT_1;
	} else if (this->payLevel == 2) {
		rent = RENT_2;
	} else if (this->payLevel == 3) {
		rent = RENT_3;
	} else if (this->payLevel == 4) {
		rent = RENT_4;
	}
	return;
}
