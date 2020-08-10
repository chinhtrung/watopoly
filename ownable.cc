#include "ownable.h"

using namespace std;

Ownable::Ownable(int costToBuy, int imprLevel, char owner, bool mortgageStatus) 
    : costToBuy{costToBuy}, imprLevel{imprLevel}, owner{owner}, mortgageStatus{mortgageStatus}
{}
    
int Ownable::amountToPay(int buildingsOwned) {
    // need implementation
    return 0;
}

void Ownable::setOwner(char owner) {
    owner = owner;
}

void Ownable::setMortgage(bool status) {
    mortgageStatus = status;
}

char Ownable::getOwner() const {
    return owner;
}

bool Ownable::isMortgaged() const {
    return mortgageStatus;
}
