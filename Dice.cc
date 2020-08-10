#include "Dice.h"
  
void Dice::rollDice(){
    srand (time(NULL));
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
}


bool Dice::isDouble(){
    return die1 == die2;
}


int Dice::diceSum(){
    return die1 + die2;
}
