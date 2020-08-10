#ifndef MONETARY_SERVICES_H
#define MONETARY_SERVICES_H


#include <memory>


class MonetaryServices {
	int needlesHall(void);
	int collectOSAP(void);
	int payCoop(void);
	int payTuition(std::shared_ptr<Player> p);
	public:
		MonetaryServices(void);
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
};


#endif
