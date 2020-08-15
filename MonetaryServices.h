#ifndef MONETARY_SERVICES_H
#define MONETARY_SERVICES_H
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "Unownable.h"

class Player;

class MonetaryServices: public Unownable{
	public:
		MonetaryServices(int ID, std::string name);
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
		static int needlesHall(std::shared_ptr<Player> p);
		static int needlesHallTest(std::shared_ptr<Player> p);
		static int collectOSAP();
		static int payCoop();
		static int payTuition(std::shared_ptr<Player> p);
};

#endif
