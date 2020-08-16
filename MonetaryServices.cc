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

int MonetaryServices::needlesHall(shared_ptr<Player> p) {
	srand(time(NULL));
	cout << "Your first spin will be a number from " << MIN_TIMS_ROLL;
	cout << " to " << MAX_TIMS_ROLL << "!" << endl;
	cout << "If your spin is " << SECRET_NUM << ", then you win ";
	cout << "a Tims Roll up the Rim Cup, which you can use to ";
	cout << "get out of DC Tims Line without rolling or paying!" << endl;
	cout << "In that case, you stay where you are." << endl;
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
	       + MIN_TIMS_ROLL;
	cout << "Your Tims Roll is " << timsRoll << "." << endl;
	if (timsRoll == SECRET_NUM) {
		cout << "Congratulations! You have won a TimsCup, which ";
		cout << "you can use to get out of DC Tims Line free!" << endl;
		p->addTimsCup();
		return 0;
	}
	cout << "You did not receive a TimsCup, so you spin a second time.";
   	cout << endl;
	cout << "What happens to you depends on your spin, listed in the ";
	cout << "table below." << endl;
	cout << "1: Lose $200" << endl;
	cout << "2-3: Lose $100" << endl;
	cout << "4-6: Lose $50" << endl;
	cout << "7-12: Win $25" << endl;
	cout << "13-15: Win $50" << endl;
	cout << "16-17: Win $100" << endl;
	cout << "18: Win $200" << endl;
	int spin = rand() % (MAX - MIN + 1) + MIN;
	cout << "Your Needles Hall Spin is " << spin << "." << endl;
	if (spin == 1) {
		cout << "You lose $200!" << endl;
		return -200;
	} else if (spin >= 2 && spin <= 3) {
		cout << "You lose $100!" << endl;
		return -100;
	} else if (spin >= 4 && spin <= 6) {
		cout << "You lose $50!" << endl;
		return -50;
	} else if (spin >= 7 && spin <= 12) {
		cout << "You win $25!" << endl;
		return 25;
	} else if (spin >= 13 && spin <= 15) {
		cout << "You win $50!" << endl;
		return 50;
	} else if (spin >= 16 && spin <= 17) {
		cout << "You win $100!" << endl;
		return 100;
	} else if (spin == 18) {
		cout << "Your win $200!" << endl;
		return 200;
	} else {
	}
	return 0;
}

int MonetaryServices::needlesHallTest(shared_ptr<Player> p) {

	srand(103);
	
	cout << "Your first spin will be a number from " << MIN_TIMS_ROLL;
	cout << " to " << MAX_TIMS_ROLL << "!" << endl;
	cout << "If your spin is " << SECRET_NUM << ", then you win ";
	cout << "a Tims Roll up the Rim Cup, which you can use to ";
	cout << "get out of DC Tims Line without rolling or paying!" << endl;
	cout << "In that case, you stay where you are." << endl;
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
	       + MIN_TIMS_ROLL;
	cout << "Your Tims Roll is " << timsRoll << "." << endl;
	if (timsRoll == SECRET_NUM) {
		cout << "Congratulations! You have won a TimsCup, which ";
		cout << "you can use to get out of DC Tims Line free!" << endl;
		p->addTimsCup();
		return 0;
	}
	cout << "You did not receive a TimsCup, so you spin a second time.";
   	cout << endl;
	cout << "What happens to you depends on your spin, listed in the ";
	cout << "table below." << endl;
	cout << "1: Lose $200" << endl;
	cout << "2-3: Lose $100" << endl;
	cout << "4-6: Lose $50" << endl;
	cout << "7-12: Win $25" << endl;
	cout << "13-15: Win $50" << endl;
	cout << "16-17: Win $100" << endl;
	cout << "18: Win $200" << endl;
	int spin = rand() % (MAX - MIN + 1) + MIN;
	cout << "Your Needles Hall Spin is " << spin << "." << endl;
	if (spin == 1) {
		cout << "You lose $200!" << endl;
		return -200;
	} else if (spin >= 2 && spin <= 3) {
		cout << "You lose $100!" << endl;
		return -100;
	} else if (spin >= 4 && spin <= 6) {
		cout << "You lose $50!" << endl;
		return -50;
	} else if (spin >= 7 && spin <= 12) {
		cout << "You win $25!" << endl;
		return 25;
	} else if (spin >= 13 && spin <= 15) {
		cout << "You win $50!" << endl;
		return 50;
	} else if (spin >= 16 && spin <= 17) {
		cout << "You win $100!" << endl;
		return 100;
	} else if (spin == 18) {
		cout << "Your win $200!" << endl;
		return 200;
	} else {
	}
	return 0;
}

int MonetaryServices::collectOSAP() {
	return 200;
}

int MonetaryServices::payCoop() {
	return 150;
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
			return 300;
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

// void MonetaryServices::actionAtIndex(shared_ptr<Player> p) {
// 	int amt = 0;
// 	if (p->getCurrPos() == OSAP) {
// 		amt = collectOSAP();
// 	} else if (p->getCurrPos() == TUITION) {
// 		amt = payTuition(p);
// 	} else if (p->getCurrPos() == NEEDLES_HALL) {
// 		amt = needlesHall(p);
// 	} else if (p->getCurrPos() == COOP_FEE) {
// 		amt = payCoop();
// 	}
// 	p->addFund(amt);
// 	return;
// }
