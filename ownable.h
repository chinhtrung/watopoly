#ifndef _OWNABLE_
#define _OWNABLE_

class Ownable{
    int costToBuy;
    int imprLevel;
    char owner;
    bool mortgageStatus = false;

  public:
    Ownable(int costToBuy, int imprLevel, char owner, bool mortgageStatus);

    int amountToPay(int buildingsOwned);
    void setOwner(char owner);
    void setMortgage(bool status);
    char getOwner() const;
    bool isMortgaged() const;
};

#endif
