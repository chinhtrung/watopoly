#ifndef GYM_H
#define GYM_H
#include <string>
#include "ownable.h"

class Ownable;

class Gym : Ownable {
	int rent;
	int roll;
  public:
	Gym(int ID, std::string name, int costToBuy, char owner);
	virtual int amountToPay() override;
	void roll();
	void rollTest();
	void setRent();
	void setRentTest();
};

#endif
