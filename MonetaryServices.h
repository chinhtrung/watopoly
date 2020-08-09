#ifndef MONETARY_SERVICES_H
#define MONETARY_SERVICES_H


#include <memory>


class MonetaryServices {
	int needlesHall(void);
	int collectOSAP(void);
	int payCoop(void);
	int payTuition(void);
	public:
		virtual void actionAtIndex(std::shard_ptr<Player> p) override;
};


#endif
