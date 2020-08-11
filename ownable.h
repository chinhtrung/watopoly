#ifndef OWNABLE_H
#define OWNABLE_H
#include "square.h"

class Square;

class Ownable : Square{
    int costToBuy;
    int imprLevel;
    char owner;
    bool mortgageStatus = false;

  public:
    Ownable(int ID, std::string name, int costToBuy, int imprLevel, char owner, bool mortgageStatus);

    int amountToPay(int buildingsOwned);
    void setOwner(char owner);
    void setMortgage(bool status);
    char getOwner() const;
    bool isMortgaged() const;
};

#endif
