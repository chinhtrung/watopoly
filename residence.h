#ifndef RESIDENCE_H
#define RESIDENCE_H
#include <iostream>
#include <string>
#include "ownable.h"
#include "seeds.h"

class Residence: public Ownable {
	int rent;
	public:
		Residence(int ID, std::string name, int costToBuy, char owner);
		virtual int amountToPay() override;
		void setRent();
};

#endif
