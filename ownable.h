#ifndef _OWNABLE_H
#define _OWNABLE_H

class Ownable: public Square{
    shared_ptr<Player> owner;
    int costToBuy;
    int imprLevel;
    bool mortgageStatus;
  public:
    Ownable();
    char getOwnerChar();
};

#endif
