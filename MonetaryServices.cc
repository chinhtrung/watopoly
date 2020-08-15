#include <cstdlib>
#include <ctime>
#include "MonetaryServices.h"
using namespace std;


static const int MIN_TIMS_ROLL = 1;
static const int MAX_TIMS_ROLL = 100;
static const int SECRET_NUM = 83;
static const int MIN = 1;
static const int MAX = 18;
static const int OSAP = 0;
static const int TUITION = 4;
static const int NEEDLES_HALL = 36;
static const int COOP_FEE = 38;


MonetaryServices::MonetaryServices(int ID, string name) 
	: Unownable(ID, name)
{}


int MonetaryServices::needlesHall() {
	srand(time(NULL));
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
	       + MIN_TIMS_ROLL;
	if (timsRoll == SECRET_NUM) {
		return 0;
	}
	int spin = rand() % (MAX - MIN + 1) + MIN;
	if (spin == 1) {
		return -200;
	} else if (spin >= 2 && spin <= 3) {
		return -100;
	} else if (spin >= 4 && spin <= 6) {
		return -50;
	} else if (spin >= 7 && spin <= 12) {
		return 25;
	} else if (spin >= 13 && spin <= 15) {
		return 50;
	} else if (spin >= 16 && spin <= 17) {
		return 100;
	} else if (spin == 18) {
		return 200;
	} else {
	}
	return 0;
}


int MonetaryServices::needlesHallTest() {

	srand(103);
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
	       + MIN_TIMS_ROLL;
	if (timsRoll == SECRET_NUM) {
		return 0;
	}
	int spin = rand() % (MAX - MIN + 1) + MIN;
	if (spin == 1) {
		return -200;
	} else if (spin >= 2 && spin <= 3) {
		return -100;
	} else if (spin >= 4 && spin <= 6) {
		return -50;
	} else if (spin >= 7 && spin <= 12) {
		return 25;
	} else if (spin >= 13 && spin <= 15) {
		return 50;
	} else if (spin >= 16 && spin <= 17) {
		return 100;
	} else if (spin == 18) {
		return 200;
	} else {

	}
	return 0;
}


int MonetaryServices::collectOSAP() {
	return 200;
}


int MonetaryServices::payCoop() {
	return -150;
}


int MonetaryServices::payTuition(shared_ptr<Player> p) {
	char option = '\0';
	while (option != 'A' && option != 'B' && !cin.fail()) {
		cout << "It's time to pay tuition!" << endl;
		cout << "Please select one of the following options." << endl;
		cout << "Enter 'A' if you wish to pay a $300 ";
		cout << "flat tuition fee." << endl;
		cout << "Enter 'B' if you wish to pay 10% of ";
		cout << "your total worth." << endl;
		cin >> option;
		if (option == 'A') {
			return -300;
		} else if (option == 'B') {
			if (p->getAssets() % 10 < 5) {
				return p->getAssets() / 10 * -1;
			} else {
				return p->getAssets() / 10 * -1 - 1;
			}
		}
	}
	return 0;
}


void MonetaryServices::actionAtIndex(shared_ptr<Player> p) {
	int amt = 0;
	if (p->getCurrPos() == OSAP) {
		amt = collectOSAP();
	} else if (p->getCurrPos() == TUITION) {
		amt = payTuition(p);
	} else if (p->getCurrPos() == NEEDLES_HALL) {
		amt = needlesHall();
	} else if (p->getCurrPos() == COOP_FEE) {
		amt = payCoop();
	}
	p->addFund(amt);
	return;
}
