#include "TimsLine.h"

using namespace std;

TimsLine::TimsLine(int ID, string name) 
	: Unownable(ID, name)
{}


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
