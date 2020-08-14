#include <cassert>
#include "dice.h"

static const int DIE_MIN = 1;
static const int DIE_MAX = 6;
  
void Dice::rollDice(){
	assert(DIE_MAX >= DIE_MIN);
	srand (time(NULL));
	die1 = rand() % (DIE_MAX - DIE_MIN + 1) + DIE_MIN;
	die2 = rand() % (DIE_MAX - DIE_MIN + 1) + DIE_MIN;
	return;
}

void Dice::rollDiceTest() {
	assert(DIE_MAX >= DIE_MIN);
	srand (100);
	die1 = rand() % (DIE_MAX - DIE_MIN + 1) + DIE_MIN;
	die2 = rand() % (DIE_MAX - DIE_MIN + 1) + DIE_MIN;
	return;
}

bool Dice::isDouble(){
    return die1 == die2;
}

int Dice::diceSum(){
    return die1 + die2;
}

int Dice::getDie1() {
	return die1;
}

int Dice::getDie2() {
	return die2;
}
