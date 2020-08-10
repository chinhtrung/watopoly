#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "SLC.h"
using namespace std;


static const int MIN_TIMS_ROLL = 1;
static const int MAX_TIMS_ROLL = 100;
static const int SECRET_NUM = 42;
static const int MIN = 1;
static const int MAX = 24;


SLC::SLC(void) {
}


void SLC::actionAtIndex(shared_ptr<Player> p) {
	srand(time(NULL));
	int timsRoll = rand() % (MAX_TIMS_ROLL - MIN_TIMS_ROLL + 1) 
		+ MIN_TIMS_ROLL;
	// Need access to board
	if (timsRoll == secretNum && timsCupsRemaining < MAX_TIM_CUPS) {
		++(p->timsCups);
		return;
	}
	int spin = rand() % (MAX - MIN + 1) + MIN;
	if (spin >= 1 && spin <= 3) {
		// Move back 3
		p->pos -= 3;
	} else if (spin >= 4 && spin <= 7) {
		// Move back 2
		p->pos -= 2;
	} else if (spin >= 8 && spin <= 11) {
		// Move back 1
		--(p->pos);
	} else if (spin >= 12 && spin <= 14) {
		// Move forward 1
		++(p->pos);
	} else if (spin >= 15 && spin <= 18) {
		// Move forward 2
		p->pos += 2;
	} else if (spin >= 19 && spin <= 22) {
		// Move forward 3
		p->pos += 3;
	} else if (spin == 23) {
		// Go to DC Tims Line
		p->pos = 10;
	} else if (spin == 24) {
		// Advance to Collect OSAP
		p->pos = 0;
		p->funds += 200;
	} else {
		throw (out_of_range);
	}
	return;
}
