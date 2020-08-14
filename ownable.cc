#include "ownable.h"

using namespace std;

Ownable::Ownable(int ID, std::string name, int costToBuy, char owner) 
    : Square(ID, name), costToBuy{costToBuy}, owner{owner}
{
    monopolyBlock = monoBlockOfProp(name);
}

void Ownable::setOwner(char owner) {
    this->owner = owner;
}

void Ownable::setMortStatus(bool status) {
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

bool Ownable::getMortStatus() const {
    return mortgageStatus;
}

int Ownable::getImprLevel() const {
    return imprLevel;
}

int Ownable::getPayLevel() const {
    return payLevel;
}

int Ownable::getCostToBuy() const {
    return costToBuy;
}

std::string Ownable::getMonoBlock() const {
    return monopolyBlock;
}
