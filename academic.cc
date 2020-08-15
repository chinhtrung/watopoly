#include "academic.h"

Academic::Academic(int ID, std::string name, int costToBuy, 
		           char owner) 
    : Ownable(ID, name, costToBuy, owner) {
    monopolyBlock = monoBlockOfProp(name);
    tuition = costToPayUnimprProp(name);    
}

int Academic::amountToPay() {
    if (blockOwned){
        return costToPayUnimprPropBlock(this->getName());
    } else if (this->getImprLevel() == 0){
        return costToPayUnimprProp(this->getName());
    }
    return costToPayImprProp(this->getName(), this->getImprLevel());
}

void Academic::updateTuition() {
    if (blockOwned){
        tuition = costToPayUnimprPropBlock(this->getName());
    } else if (this->getImprLevel() == 0){
        tuition = costToPayUnimprProp(this->getName());
    } else {
        tuition = costToPayImprProp(this->getName(), this->getImprLevel());
    } 
}

void Academic::setBlockOwned(bool status){
    blockOwned = status;
}

bool Academic::getBlockOwned(){
    return blockOwned;
}

std::string Academic::getMonoBlock() const {
    return monopolyBlock;
}
