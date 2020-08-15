#include <cstdlib>
#include <ctime>
#include <iostream>
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

void Gym::setRent() {
	srand(time(NULL));
	int roll1 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;
	int roll2 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;
	cout << "You rolled " << roll1 << " and " << roll2 << "!" << endl;
	int roll = roll1 + roll2;
	rent = getPayLevel() * roll;
	return;
}

void Gym::setRentTest() {
	srand(10565);
	int roll1 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;
	int roll2 = rand() % (MAX_ROLL - MIN_ROLL + 1) + MIN_ROLL;
	cout << "You rolled " << roll1 << " and " << roll2 << "!" << endl;
	int roll = roll1 + roll2;
	rent = getPayLevel() * roll;
	return;
}
