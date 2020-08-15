#ifndef DICE_H
#define DICE_H
#include <time.h>
#include <cstdlib>
#include <cassert>

class Dice {
    int die1;
    int die2;

  public:
    // Sets die1 and die2 to randomly rolled values
    void rollDice();

    void rollDiceTest();

    // Returns true if die1 == die2
    bool isDouble();

    // Returns the sum of die1 and die2
    int diceSum();

    int getDie1();
    
    int getDie2();
};

#endif
