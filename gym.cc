#include "gym.h"

using namespace std;

const int MIN_ROLL = 1;
const int MAX_ROLL = 6;
const int OWN_1 = 4;
const int OWN_2 = 10;

Gym::Gym(int ID, string name, int costToBuy, char owner)
	: Ownable(ID, name, costToBuy, owner)
{}

int Gym::amountToPay() {
    return roll * costToPayImprProp(this->getName(), this->getPayLevel());
}

void Gym::setRoll(int n){
    roll = n;
}
