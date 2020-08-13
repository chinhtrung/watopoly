#include "transactions.h"

//helper functions for trading usage only
bool checkFundIsEnoughToUse(std::shared_ptr<Player> player, int amt) {
    if (player->getFunds() < amt) {
        std::cout << "(testing) this player doesn't have enough money to use" << std::endl;
        return false;
    }
    return true;
}

bool checkIfPlayerOwnProp(std::shared_ptr<Player> player, std::shared_ptr<Ownable> prop) {
    std::shared_ptr<Square> tempProp = std::dynamic_pointer_cast<Square>(prop); // cast the Ownable pointer to Square

    if (player->ownThisProp(tempProp->getName())) return true;    
    std::cout << "(testing) the player doesn't own this property to buy" << std::endl;
    return false;
}

bool checkIfPropSaveToTrade(std::shared_ptr<Ownable> prop) {
    if (prop->getImprLevel() == 0) return true;

    std::cout << "(testing) you need to sell all the improvement before trading this property" << std::endl;
    return false;
}
// end helper functions

void Transactions::tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive) {
    // check if the player "from" has enough funds to offer
    if (!checkFundIsEnoughToUse(from, give)) return;

    // check if the player "to" has the property of offer
    if (!checkIfPlayerOwnProp(to, receive)) return;

    // check if the property of offer is save to trade (selling all the improvement)
    if (!checkIfPropSaveToTrade(receive)) return;

    // the transaction occur if all checking pass
    std::shared_ptr<Square> tmp = std::dynamic_pointer_cast<Square>(receive);
    from->addProp(receive);
    to->removeProp(receive);
    to->addFund(give);
}

void Transactions::tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive) {
    // check if the player "from" has the property they offer
    // and check if this prop is save to trade
    if (!checkIfPlayerOwnProp(from, give)) return;
    if (!checkIfPropSaveToTrade(give)) return;

    // check if the player "to" has the property to trade
    // and check if this prop is save to trade
    if (!checkIfPlayerOwnProp(to, receive)) return;
    if (!checkIfPropSaveToTrade(receive)) return;

    // the transaction occur if all check pass
    from->removeProp(give);
    from->addProp(receive);
    to->removeProp(receive);
    to->addProp(give);
}

void Transactions::tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive) {
    this->tradeMforP(to, from, receive, give);
}

void Transactions::payPlayer(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int amt) {
    if(!checkFundIsEnoughToUse(from, amt)) return;

    // the transaction occur if all check pass
    from->payFund(amt);
    to->addFund(amt);
}

void Transactions::payBank(std::shared_ptr<Player> from, int amt) {
    if(!checkFundIsEnoughToUse(from, amt)) return;

    // the transaction occur if all check pass
    from->payFund(amt);
}

// assume the ownableName is passed in correctly
void Transactions::buyProperty(std::string ownableName, std::shared_ptr<Player> buyer) {
    // create a new property for player to buy
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    // check if the buyer has enough money to buy
    if (!checkFundIsEnoughToUse(buyer, propCostToBuy)) return;

    auto production = std::make_shared<Ownable>(propID, ownableName, propCostToBuy, propOwner);
    buyer->addProp(production);
}

void Transactions::improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return;

    // check if the player has enough money to improve the property
    std::shared_ptr<Square> tmp = std::dynamic_pointer_cast<Square>(prop);
    int cost = costToImprProp(tmp->getName());
    if (!checkFundIsEnoughToUse(own, cost)) return;

    // the transaction occur if all check pass
    own->payFund(cost);
    prop->setImprLevel(prop->getImprLevel() + 1);
    prop->setPayLevel(prop->getPayLevel() + 1);
}

void Transactions::sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return;

    // check if the propery level is 0
    if (prop->getImprLevel() == 0) {
        std::cout << "(testing) there is no improvement to sell" << std::endl;
        return;
    }

    // the transaction occur if all check pass
    std::shared_ptr<Square> tmp = std::dynamic_pointer_cast<Square>(prop);
    own->addFund(costToSellImprProp(tmp->getName()));
    prop->setImprLevel(prop->getImprLevel() - 1);
    prop->setPayLevel(prop->getPayLevel() - 1);
}

void Transactions::mortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return;

    // check if the property is morgaged
    if(prop->getMortStatus()) {
        std::cout << "(testing) you cannot mortgage a mortgaged property" << std::endl;
        return;
    }

    // the transaction occur if all check pass
    std::shared_ptr<Square> tmp = std::dynamic_pointer_cast<Square>(prop);
    int price = costToMortProp(tmp->getName());
    own->addFund(price);
    prop->setMortStatus(true);
}

void Transactions::unmortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return;

    // check if the property is unmorgaged
    if(!prop->getMortStatus()) {
        std::cout << "(testing) this property is not mortgaged" << std::endl;
        return;
    }

    // check if the player has enough money to unmortgage
    std::shared_ptr<Square> tmp = std::dynamic_pointer_cast<Square>(prop);
    int cost = costToUnmortProp(tmp->getName());
    if (!checkFundIsEnoughToUse(own, cost)) return;

    // the transaction occur if all check pass
    own->payFund(cost);
    prop->setMortStatus(false);
}
