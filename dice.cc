#include "dice.h"
  
void Dice::rollDice(){
    srand (time(NULL));
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    return;
}

void Dice::rollDiceTest() {
	srand (100);
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	return;
}

bool Dice::isDouble(){
    return die1 == die2;
}

int Dice::diceSum(){
    return die1 + die2;
}
