#ifndef GYM_H
#define GYM_H


#include <string>
#include "ownable.h"


class Gym: public Ownable {
	int rent;
	public:
		Gym(int ID, std::string name, int costToBuy, char owner);
		virtual int amountToPay() override;
		void roll(int roll);
		void rollTest();
		void setRent();
		void setRentTest();
};


#endif
