#ifndef MONETARY_SERVICES_H
#define MONETARY_SERVICES_H


#include <memory>


class MonetaryServices {
	int needlesHall();
	int collectOSAP();
	int payCoop();
	int payTuition(std::shared_ptr<Player> p);
	public:
		MonetaryServices();
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
};


#endif
