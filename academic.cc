#include "academic.h"
#include "seeds.h"

Academic::Academic(int ID, std::string name, int costToBuy, 
		           char owner, std::string monopolyBlock) 
    : Ownable(ID, name, costToBuy, owner) {
    monopolyBlock = monoBlockOfProp(name);
    tuition = costToPayUnimprProp(name);    
}

int Academic::amountToPay() {
    if (blockOwned){
        return costToPayUnimprPropBlock(name);
    } else if (this->getImprLevel() == 0){
        return costToPayUnimprProp(name);
    }
    return costToPayImprProp(name, this->getImprLevel);
}

void Academic::updateTuition() {
    if (blockOwned){
        tuition = costToPayUnimprPropBlock(name);
    } else if (this->getImprLevel() == 0){
        tuition = costToPayUnimprProp(name);
    } else {
        tuition = costToPayImprProp(name, this->getImprLevel);
    } 
}

void Academic::setBlockOwned(bool status){
    blockOwned = status;
}

bool Academic::getBlockOwned(){
    return blockOwned;
}

std::string Academic::getMonoBlock() {
    return monopolyBlock;
}
