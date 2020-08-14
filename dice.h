#ifndef DICE_H
#define DICE_H
#include <time.h>
#include <cstdlib>

class Dice {
    int die1;
    int die2;

  public:
    // Sets die1 and die2 to randomly rolled values from 1 -6
    void rollDice();

    void rollDiceTest();

    // Returns true if die1 == die2
    bool isDouble();

    // Returns the sum of die1 and die2
    int diceSum();
};

#endif
