#ifndef OWNABLE_H
#define OWNABLE_H
#include "square.h"

class Square;

class Ownable : Square{
    char owner;
    int costToBuy;
    int imprLevel = 0;
    int payLevel = 0; //almost the same with imprLevel except for gym and resident, this one show how many gym (or res) all own together 
    bool mortgageStatus = false;

  public:
    Ownable(int ID, std::string name, int costToBuy, char owner);

    virtual int amountToPay() = 0;
    void setOwner(char owner);
    void setMortStatus(bool status);
    void setImprLevel(int level);
    void setPayLevel(int level);
    char getOwner() const;
    bool getMortStatus() const;
    int getImprLevel() const;
    int getPayLevel() const;
};

#endif
