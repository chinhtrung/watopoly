#include "player.h"
#include "SLC.h"

using namespace std;

static const int MIN_TIMS_ROLL = 1;
static const int MAX_TIMS_ROLL = 100;
static const int SECRET_NUM = 42;
static const int MIN = 1;
static const int MAX = 24;
static const int BOARD_SIZE = 40;
static const int OSAP = 200;

SLC::SLC(int ID, string name) 
	: Unownable(ID, name)
{}

bool passOSAP(int pos, int changeInPos){
    if (pos + changeInPos < 0 || pos + changeInPos > BOARD_SIZE){
       return true;
    } 
    return false;
}

void SLC::determinePlayerPos(shared_ptr<Player> p) {
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
	// Need access to board
	if (timsRoll == SECRET_NUM) {
		cout << "Congratulations! You have won a TimsCup, which ";
		cout << "you can use to get out of DC Tims Line free!" << endl;
		p->addTimsCup();
		return;
	}
	cout << "You did not receive a TimsCup, so you spin a second time.";
   	cout << endl;
	cout << "What happens to you depends on your spin, listed in the ";
	cout << "table below." << endl;
	cout << "1-3: Move back 3" << endl;
	cout << "4-7: Move back 2" << endl;
	cout << "8-11: Move back 1" << endl;
	cout << "12-14: Move forward 1" << endl;
	cout << "15-18: Move forward 2" << endl;
	cout << "19-22: Move forward 3" << endl;
	cout << "23: Go to DC Tims Line" << endl;
	cout << "24: Advance to Collect OSAP (collect $200)" << endl;
	int spin = rand() % (MAX - MIN + 1) + MIN;
	cout << "Your SLC Spin is " << spin << "." << endl;
	int changeInPos = 0;
	if (spin >= 1 && spin <= 3) {	
		// Move back 3
		cout << "You move back 3 spaces." << endl;
		changeInPos = -3;
	} else if (spin >= 4 && spin <= 7) {	
		cout << "You move back 2 spaces." << endl;
		// Move back 2
		changeInPos = -2;
	} else if (spin >= 8 && spin <= 11) {
		cout << "You move back 1 space." << endl;
		// Move back 1
		changeInPos = -1;
	} else if (spin >= 12 && spin <= 14) {
		cout << "You move forward 1 space." << endl;
		// Move forward 1
		changeInPos = 1;
	} else if (spin >= 15 && spin <= 18) {
		cout << "You move forward 2 spaces." << endl;
		// Move forward 2
		changeInPos = 2;
	} else if (spin >= 19 && spin <= 22) {
		cout << "You move forward 3 spaces." << endl;
		// Move forward 3
		changeInPos = 3;
	} else if (spin == 23) {
		// Go to DC Tims Line
		cout << "Go stand in the DC Tims Line." << endl;
		p->moveToDCTims();
	} else if (spin == 24) {
		// Advance to Collect OSAP
		p->setPos(0);
		cout << "You passed Collect OSAP! Enjoy your $200!" << endl;
		p->addFund(OSAP);
	} else {
	}

	if (spin != 24 && spin != 10){
	    if (passOSAP(p->getCurrPos(), changeInPos)){
	        p->addFund(OSAP);
		cout << "You passed Collect OSAP! Enjoy your $200!" << endl;
	    }
	    p->setPos((p->getCurrPos() + changeInPos) % BOARD_SIZE); 
	}
	return;
}


void SLC::testAction(shared_ptr<Player> p) {
	
	srand(1540);

	cout << "Your first spin will be a number from " << MIN_TIMS_ROLL;
	cout << " to " << MAX_TIMS_ROLL << "!" << endl;
	cout << "If your spin is " << SECRET_NUM << ", then you win ";
	cout << "a Tims Roll up the Rim Cup, which you can use to ";
	cout << "get out of DC Tims Line without rolling or paying!" << endl;
	cout << "In that case, you stay where you are." << endl;
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
		+ MIN_TIMS_ROLL;
	cout << "Your Tims Roll is " << timsRoll << "." << endl;
	// Need access to board
	if (timsRoll == SECRET_NUM) {
		cout << "Congratulations! You have won a TimsCup, which ";
		cout << "you can use to get out of DC Tims Line free!" << endl;
		p->addTimsCup();
		return;
	}
	cout << "You did not receive a TimsCup, so you spin a second time.";
   	cout << endl;
	cout << "What happens to you depends on your spin, listed in the ";
	cout << "table below." << endl;
	cout << "1-3: Move back 3" << endl;
	cout << "4-7: Move back 2" << endl;
	cout << "8-11: Move back 1" << endl;
	cout << "12-14: Move forward 1" << endl;
	cout << "15-18: Move forward 2" << endl;
	cout << "19-22: Move forward 3" << endl;
	cout << "23: Go to DC Tims Line" << endl;
	cout << "24: Advance to Collect OSAP (collect $200)" << endl;
	int spin = rand() % (MAX - MIN + 1) + MIN;
	cout << "Your SLC Spin is " << spin << "." << endl;
	int changeInPos = 0;
	if (spin >= 1 && spin <= 3) {	
		// Move back 3
		cout << "You move back 3 spaces." << endl;
		changeInPos = -3;
	} else if (spin >= 4 && spin <= 7) {	
		cout << "You move back 2 spaces." << endl;
		// Move back 2
		changeInPos = -2;
	} else if (spin >= 8 && spin <= 11) {
		cout << "You move back 1 space." << endl;
		// Move back 1
		changeInPos = -1;
	} else if (spin >= 12 && spin <= 14) {
		cout << "You move forward 1 space." << endl;
		// Move forward 1
		changeInPos = 1;
	} else if (spin >= 15 && spin <= 18) {
		cout << "You move forward 2 spaces." << endl;
		// Move forward 2
		changeInPos = 2;
	} else if (spin >= 19 && spin <= 22) {
		cout << "You move forward 3 spaces." << endl;
		// Move forward 3
		changeInPos = 3;
	} else if (spin == 23) {
		// Go to DC Tims Line
		cout << "Go stand in the DC Tims Line." << endl;
		p->moveToDCTims();
	} else if (spin == 24) {
		// Advance to Collect OSAP
		p->setPos(0);
		cout << "You passed Collect OSAP! Enjoy your $200!" << endl;
		p->addFund(OSAP);
	} else {
	}

	if (spin != 24 && spin != 10){
	    if (passOSAP(p->getCurrPos(), changeInPos)){
	        cout << "You passed Collect OSAP! Enjoy your $200!" << endl;
	        p->addFund(OSAP);
	    }
	    p->setPos((p->getCurrPos() + changeInPos) % BOARD_SIZE); 
	}
	return;
}       
