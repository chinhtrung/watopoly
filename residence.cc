#include "residence.h"

using namespace std;

Residence::Residence(int ID, string name, int costToBuy, char owner)
	: Ownable(ID, name, costToBuy, owner)
{}

int Residence::amountToPay() {
    return costToPayImprProp(this->getName(), this->getPayLevel());
}

