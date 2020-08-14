#ifndef RESIDENCE_H
#define RESIDENCE_H


#include "ownable.h"


class Residence: public Ownable {
	public:
		Residence();
		virtual amountToPay() override;
};


#endif
