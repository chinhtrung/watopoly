#include <cstdlib>
#include <ctime>
#include <iostream>
#include "gym.h"
using namespace std;


static const int MIN_ROLL = 1;
static const int MAX_ROLL = 6;
static const int OWN_1 = 4;
static const int OWN_2 = 10;


Gym::Gym(int ID, string name, int costToBuy, char owner)
	: Ownable(ID, name, costToBuy, owner)
{}


int Gym::amountToPay(int roll) {
    return roll * costToPayImprProp(name, this->getPayLevel());
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
