#include "academic.h"

Academic::Academic(int ID, std::string name, int costToBuy, 
		           char owner, std::string monopolyBlock) 
    : Ownable(ID, name, costToBuy, owner), monopolyBlock{monopolyBlock} {
    tuition = costToPayUnimprProp(name);    
}

int Academic::amountToPay() {
    return tuition;
}

void Academic::updateTuition() {
    if (this->getMortStatus()){
        tuition = 0;
    } else if (blockOwned){
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
