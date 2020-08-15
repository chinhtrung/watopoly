#include "academic.h"

Academic::Academic(int ID, std::string name, int costToBuy, 
		           char owner, std::string monopolyBlock) 
    : Ownable(ID, name, costToBuy, owner), monopolyBlock{monopolyBlock}
{}

int Academic::amountToPay() {
    return tuition;
}

void Academic::updateTuition() {
    tuition = costToPayImprProp(this->getName(), this->getPayLevel());
}
