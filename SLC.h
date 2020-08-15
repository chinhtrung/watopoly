#ifndef SLC_H
#define SLC_H
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>
#include "Unownable.h"

class Player;

class SLC: public Unownable {
	public:
		SLC(int ID, std::string name);
		virtual void actionAtIndex(std::shared_ptr<Player>) override;
		static void determinePlayerPos(std::shared_ptr<Player>);
	 	void testAction(std::shared_ptr<Player>);
};

#endif
