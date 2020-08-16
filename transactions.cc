#include "transactions.h"

//helper functions for trading usage only
bool checkFundIsEnoughToUse(std::shared_ptr<Player> player, int amt) {
    if (player->getFunds() < amt) {
        std::cout << "The player " << player->getName() << " doesn't have enough funds to use" << std::endl;
        return false;
    }
    return true;
}

bool checkIfPlayerOwnProp(std::shared_ptr<Player> player, std::shared_ptr<Ownable> prop) {
    if (player->ownThisProp(prop->getName())) return true;
    std::cout << "The player " << player->getName() << " doesn't own this property" << std::endl;
    return false;
}

bool checkIfPropSaveToTrade(std::shared_ptr<Ownable> prop) {
    if (prop->getImprLevel() == 0) return true;

    std::cout << "You need to sell all the improvement before trading this property" << std::endl;
    return false;
}
// end helper functions

bool Transactions::isInOwnedList(std::string nameSquare) {
    int sizeOwnedList = ownedList.size();
    for (int i = 0; i < sizeOwnedList; i++) {
        if (ownedList[i]->getName() == nameSquare) {
            return true;
        }
    }

    return false;
}

bool Transactions::tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive) {
    // check if the player "from" has enough funds to offer
    if (!checkFundIsEnoughToUse(from, give)) return false;

    // check if the player "to" has the property of offer
    if (!checkIfPlayerOwnProp(to, receive)) return false;

    // check if the property of offer is save to trade (selling all the improvement)
    if (!checkIfPropSaveToTrade(receive)) return false;

    std::string receiveName = receive->getName();

    // if block of receive was owned by to, set blockOwned of receive to false
    if (isAcademic(receiveName)){
	auto acad = std::dynamic_pointer_cast<Academic>(receive);
        if (acad->getBlockOwned()){
            acad->setBlockOwned(false);
        }
    }

    // the transaction occur if all checking pass
    from->payFund(give);
    to->removeProp(receive);
    from->addProp(receive);

    // update Monopoly blocks of both players
    from->updateMonopolyBlock();
    to->updateMonopolyBlock();

    // set correct paylevel and tuition
    if (isGym(receiveName)){
	receive->setPayLevel(to->getNumGymOwned() - 1);
    } else if (isResidence(receiveName)){
	receive->setPayLevel(to->getNumResOwned() - 1);
    } else if (isAcademic(receiveName)){
        if (from->checkIfInMonopolyBlock(receiveName)){
	    auto acad = std::dynamic_pointer_cast<Academic>(receive);
            acad->setBlockOwned(true);
	}
    }

    std::cout << "The transaction is completed!" << std::endl;
    return true;
}

bool Transactions::tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive) {
    // check if the player "from" has the property they offer
    // and check if this prop is save to trade
    if (!checkIfPlayerOwnProp(from, give)) return false;
    if (!checkIfPropSaveToTrade(give)) return false;

    // check if the player "to" has the property to trade
    // and check if this prop is save to trade
    if (!checkIfPlayerOwnProp(to, receive)) return false;
    if (!checkIfPropSaveToTrade(receive)) return false;

    std::string giveName = give->getName();
    std::string receiveName = receive->getName();

    // if block of give was owned by from, set blockOwned of give to false
    if (isAcademic(giveName)){
	auto acad = std::dynamic_pointer_cast<Academic>(give);
        if (acad->getBlockOwned()) {
            acad->setBlockOwned(false);
        } 
    }

    // if block of receive was owned by to, set blockOwned of receive to false
    if (isAcademic(receiveName)){
	auto acad = std::dynamic_pointer_cast<Academic>(receive);
        if (acad->getBlockOwned()){
            acad->setBlockOwned(false);
        }
    }

    // the transaction occur if all check pass
    from->removeProp(give);
    from->addProp(receive);
    to->removeProp(receive);
    to->addProp(give);

    // update Monopoly blocks
    from->updateMonopolyBlock();
    to->updateMonopolyBlock();

    // set correct paylevel and tuition
    if (isGym(receiveName)){
        receive->setPayLevel(to->getNumGymOwned() - 1);
    } else if (isResidence(receiveName)){
        receive->setPayLevel(to->getNumResOwned() - 1);
    } else if (isAcademic(receiveName)){
        if (from->checkIfInMonopolyBlock(receiveName)){
	    auto acad = std::dynamic_pointer_cast<Academic>(receive);
            acad->setBlockOwned(true);
        }
    }

    // set correct paylevel and tuition
    if (isGym(giveName)){
        give->setPayLevel(from->getNumGymOwned() - 1);
    } else if (isResidence(giveName)){
        give->setPayLevel(from->getNumResOwned() - 1);
    } else if (isAcademic(giveName)){
        if (from->checkIfInMonopolyBlock(giveName)){
	    auto acad = std::dynamic_pointer_cast<Academic>(give);
            acad->setBlockOwned(true);
        }
    }

    std::cout << "The transaction is completed!" << std::endl;
    return true;
}

bool Transactions::tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive) {
    return Transactions::tradeMforP(to, from, receive, give); 
}

bool Transactions::payPlayer(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int amt) {
    if(!checkFundIsEnoughToUse(from, amt)) return false;

    // the transaction occur if all check pass
    from->payFund(amt);
    to->addFund(amt);
    return true;
}

bool Transactions::payBank(std::shared_ptr<Player> from, int amt) {
    if(!checkFundIsEnoughToUse(from, amt)) return false;

    // the transaction occur if all check pass
    from->payFund(amt);
    return true;
}

// assume the ownableName is passed in correctly
bool Transactions::buyProperty(std::string ownableName, std::shared_ptr<Player> buyer) {
    // create a new property for player to buy
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    // check if the buyer has enough money to buy
    if (!checkFundIsEnoughToUse(buyer, propCostToBuy)) return false;

    std::shared_ptr<Ownable> ownable;

    if (isGym(ownableName)){
        auto production = std::make_shared<Gym>(propID, ownableName, propCostToBuy, propOwner);
	ownable = std::dynamic_pointer_cast<Ownable>(production);	
    }
    else if (isResidence(ownableName)){
	auto production = std::make_shared<Residence>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production); 
    }
    else if (isAcademic(ownableName)){
	auto production = std::make_shared<Academic>(propID, ownableName, propCostToBuy, propOwner);
	ownable = std::dynamic_pointer_cast<Ownable>(production);
    }

    // charge money to buy
    buyer->addProp(ownable);
    buyer->updateMonopolyBlock();
    ownedList.push_back(ownable);
    buyer->payFund(propCostToBuy);

    // set correct payLevel and tuition for the property
    if (isGym(ownableName)){
        ownable->setPayLevel(buyer->getNumGymOwned() - 1);
    } else if (isResidence(ownableName)){
        ownable->setPayLevel(buyer->getNumResOwned() - 1);
    } else if (isAcademic(ownableName)){
        auto acad = std::dynamic_pointer_cast<Academic>(ownable);

	if (buyer->checkIfInMonopolyBlock(ownableName)){
	    acad->setBlockOwned(true);
	}
    }  

    std::cout << "Successfully buy " << ownableName << "!" << std::endl;
    return true;
}

bool Transactions::improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return false;

    // check if the player has enough money to improve the property
    int cost = costToImprProp(prop->getName());
    if (!checkFundIsEnoughToUse(own, cost)) return false;

    // checks if prop is improvable (i.e. is Academic and own owns the block)
    if (isGym(prop->getName()) || isResidence(prop->getName())){
	std::cout << "You can't improve a gym or residence!" << std::endl;
	return false;
    } else {
	auto acad = std::dynamic_pointer_cast<Academic>(prop);
        if (!acad->getBlockOwned()){
	    std::cout << "You can't improve this academic building because you don't own the block yet!" << std::endl;
            return false;
	}	
    }

    // the transaction occur if all check pass
    own->payFund(cost);
    prop->setImprLevel(prop->getImprLevel() + 1);
    prop->setPayLevel(prop->getPayLevel() + 1);
    return true;
}

bool Transactions::sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return false;

    // check if the propery level is 0 or -1
    // assumes Gyms and Residences always have imprLevel of 0 or -1
    // assumes that if imprLevel > 0, prop's block is owned by own
    if (prop->getImprLevel() <= 0) {
        std::cout << "(testing) there is no improvement to sell" << std::endl;
        return false;
    }

    // the transaction occur if all check pass
    own->addFund(costToSellImprProp(prop->getName()));
    prop->setImprLevel(prop->getImprLevel() - 1);
    return true;
}

bool Transactions::mortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return false;

    // check if the property is morgaged
    if(prop->getMortStatus()) {
        std::cout << "(testing) you cannot mortgage a mortgaged property" << std::endl;
        return false;
    }

    // the transaction occur if all check pass
    int price = costToMortProp(prop->getName());
    own->addFund(price);
    prop->setMortStatus(true);
    own->updateMonopolyBlock();
        
    if (isAcademic(prop->getName())){
	std::shared_ptr<Academic> acad = std::dynamic_pointer_cast<Academic>(prop);
        if (acad->getBlockOwned()){
	    acad->setBlockOwned(false);
	}
    } 
    return true;
}

bool Transactions::unmortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    // check if the player is actually own this property
    if(!checkIfPlayerOwnProp(own, prop)) return false;

    // check if the property is unmorgaged
    if(!prop->getMortStatus()) {
        std::cout << "(testing) this property is not mortgaged (to be unmortgaged)" << std::endl;
        return false;
    }

    // check if the player has enough money to unmortgage
    int cost = costToUnmortProp(prop->getName());
    if (!checkFundIsEnoughToUse(own, cost)) return false;

    // the transaction occur if all check pass
    own->payFund(cost);
    prop->setMortStatus(false);
    own->updateMonopolyBlock();

    if (isAcademic(prop->getName())){
	std::shared_ptr<Academic> acad = std::dynamic_pointer_cast<Academic>(prop);
        if (own->checkIfInMonopolyBlock(acad->getMonoBlock())){
	    acad->setBlockOwned(true);
	}
    }

    return true;
}

// assume ownableName is already added to ownedList
std::shared_ptr<Ownable> Transactions::pointerOfProp(std::string ownableName) {
    std::shared_ptr<Ownable> result;
    int sizeOwnedList = ownedList.size();

    for (int i = 0; i < sizeOwnedList; i++) {
        if (ownedList[i]->getName() == ownableName) {
            return ownedList[i];
        }
    }

    return result;
}

// assume the ownableName is passed in correctly
void Transactions::addPropByAuction(std::string ownableName, std::shared_ptr<Player> buyer, int price) {
    // create a new property for player to buy
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    std::shared_ptr<Ownable> ownable;

    if (isGym(ownableName)){
        auto production = std::make_shared<Gym>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }
    else if (isResidence(ownableName)){
        auto production = std::make_shared<Residence>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }
    else if (isAcademic(ownableName)){
        auto production = std::make_shared<Academic>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }

    // charge money to buy
    buyer->addProp(ownable);
    buyer->updateMonopolyBlock();
    ownedList.push_back(ownable);
    buyer->payFund(price);

    // set correct payLevel and tuition for the property
    if (isGym(ownableName)){
        ownable->setPayLevel(buyer->getNumGymOwned() - 1);
    } else if (isResidence(ownableName)){
        ownable->setPayLevel(buyer->getNumResOwned() - 1);
    } else if (isAcademic(ownableName)){
        auto acad = std::dynamic_pointer_cast<Academic>(ownable);

        if (buyer->checkIfInMonopolyBlock(ownableName)){
            acad->setBlockOwned(true);
        }
    }
 
    std::cout << "Buy " << ownableName << " successfully" << std::endl;
}

