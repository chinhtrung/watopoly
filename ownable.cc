#include "ownable.h"

using namespace std;

Ownable::Ownable(int ID, std::string name, int costToBuy, char owner) 
    : Square(ID, name), costToBuy{costToBuy}, owner{owner}
{}

void Ownable::setOwner(char owner) {
    owner = owner;
}

void Ownable::setMortgage(bool status) {
    mortgageStatus = status;
}

void Ownable::setImprLevel(int level) {
    imprLevel = level;
}

void Ownable::setPayLevel(int level) {
    payLevel = level;
}

char Ownable::getOwner() const {
    return owner;
}

bool Ownable::isMortgaged() const {
    return mortgageStatus;
}

int Ownable::getImprLevel() const {
    return imprLevel;
}

int Ownable::getPayLevel() const {
    return payLevel;
}
