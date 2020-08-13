#include "loadSave.h"

// assume the ownableName is passed in correctly
void LoadSave::loadProperty(std::string ownableName, std::shared_ptr<Player> buyer) {
    // create a new property for player
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    auto production = std::make_shared<Ownable>(propID, ownableName, propCostToBuy, propOwner);
    buyer->addProp(production);
}


void LoadSave::LoadMortProperty(std::string ownableName, std::shared_ptr<Player> own) {
    // create a new property for player
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    auto production = std::make_shared<Ownable>(propID, ownableName, propCostToBuy, propOwner);
    buyer->addProp(production); 
    prop->setMortStatus(true);
}
