#ifndef TIMSLINE_H
#define TIMSLINE_H
#include <memory>
#include "Unownable.h"
#include "player.h"

class Unownable;
class Player;

class TimsLine : public Unownable {
	map<char, int> captured; // e.g. "A": 2, "B": 0
	public:
		TimsLine();
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
		void addRoll(char player);
		bool isCaptured(char player);
		int turnsInLine(char player);
};

#endif
