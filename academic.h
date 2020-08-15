#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string>
#include "ownable.h"
#include "seeds.h"

class Ownable;

class Academic : public Ownable {
    std::string monopolyBlock;
    int tuition;
    bool blockOwned = 0;
  public:
    Academic(int ID, std::string name, int costToBuy, char owner);
    virtual int amountToPay() override;
    void setBlockOwned(bool status);
    bool getBlockOwned();
    std::string getMonoBlock() const;
};

#endif
