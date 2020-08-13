#ifndef UNOWNABLE_H
#define UNOWNABLE_H


#include <memory>
#include "player.h"


class Unownable {
	public:
		Unownable();
		virtual void actionAtIndex(std::shared_ptr<Player> p) = 0;
};


#endif
