#ifndef UNOWNABLE_H
#define UNOWNABLE_H
#include <memory>
#include <string>
#include "square.h"
// #include "player.h"

// class Player;
class Square;

class Unownable: public Square {
	public:
		Unownable(int ID, std::string name);
		// virtual void actionAtIndex(std::shared_ptr<Player> p) = 0;
};

#endif
