#include "loadSave.h"

// assume the ownableName is passed in correctly
void LoadSave::loadProperty(std::string ownableName, std::shared_ptr<Player> buyer,
	                         int imprLevel) {
    // create a new property for player
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    auto prod = std::make_shared<Ownable>(propID, ownableName, propCostToBuy, propOwner);
    buyer->addProp(prod);

    if (imprLevel == -1){
        prod->setMortStatus(true);
    } else {
        prod->setImprLevel(imprLevel + 1);
	prod->setPayLevel(imprLevel + 1);
    }
}

