#ifndef SLC_H
#define SLC_H


#include <memory>
#include <string>
#include "Unownable.h"


class Player;


class SLC: public Unownable {
	public:
		SLC(int ID, std::string name);
		virtual void actionAtIndex(std::shared_ptr<Player>) override;
		void testAction(std::shared_ptr<Player>);
};


#endif
