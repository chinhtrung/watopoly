#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string>
#include "ownable.h"
#include "utility/seeds.h"

class Ownable;

class Academic : public Ownable {
    std::string monopolyBlock;
    int tuition;
  public:
    Academic(int ID, std::string name, int costToBuy, char owner, std::string monopolyBlock);
    virtual int amountToPay() override;
    void updateTuition();
};

#endif
