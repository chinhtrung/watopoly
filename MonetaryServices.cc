#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "MonetaryServices.h"


static const int MIN_TIMS_ROLL = 1;
static const int MAX_TIMS_ROLL = 100;
static const int SECRET_NUM = 83;
static const int MIN = 1;
static const int MAX = 18;


int MonetaryServices::needlesHall(void) {
	srand((unsigned) time(NULL));
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
		throw (out_of_range);
	}
	return 0;
}



