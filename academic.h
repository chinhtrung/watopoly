#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string>
#include "ownable.h"
#include "utility/seeds.h"

class Ownable;

class Academic : Ownable {
    std::string monopolyBlock;
    int tuition;
  public:
    Academic(int ID, std::string name, int costToBuy, int imprLevel, char owner, std::string monopolyBlock);
    int amountToPay() override;
    void updateTuition();
};

#endif
