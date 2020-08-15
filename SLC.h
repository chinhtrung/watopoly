#ifndef SLC_H
#define SLC_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include "Unownable.h"

class Player;

class SLC: public Unownable {
	public:
		SLC(int ID, std::string name);
		static void determinePlayerPos(std::shared_ptr<Player>);
	 	void testAction(std::shared_ptr<Player>);
};

#endif
