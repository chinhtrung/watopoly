#ifndef GYM_H
#define GYM_H
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ownable.h"

class Ownable;

class Gym : public Ownable {
	int roll;
  public:
	Gym(int ID, std::string name, int costToBuy, char owner);
	virtual int amountToPay() override;
	void setRoll(int roll);
};

#endif
