#ifndef TIMSLINE_H
#define TIMSLINE_H


#include <map>
#include <memory>
#include "Unownable.h"


class TimsLine: public Unownable {
	std::map<char, int> captured; // e.g. "A": 2, "B": 0
	public:
		TimsLine();
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
		void addRoll(char player);
		bool isCaptured(char player);
		int turnInLine(char player);
};


#endif
