#include "TimsLine.h"
using namespace std;


TimsLine::TimsLine() {}


void TimsLine::actionAtIndex(shared_ptr<Player> p) {
	captured.insert(pair<char, int>(p->getGamePiece(), 0));
	return;
}


void TimsLine::addRoll(char player) {
	map<char, int>::iterator it = captured.find(player);
	if (it != captured.end()) {
		++(it->second);
	}
	return;
}


bool TimsLine::isCaptured(char player) {
	map<char, int>::iterator it = captured.find(player);
	return it != captured.end();
}


int TimsLine::turnInLine(char player){
        return captured[player];
}
