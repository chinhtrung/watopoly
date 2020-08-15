#include "loadSave.h"
#include "player.h"
#include "ownable.h"
#include "square.h"
#include "residence.h"
#include "academic.h"
#include "gym.h"
#include "seeds.h"
#include "transactions.h"

// assume the ownableName is passed in correctly
void LoadSave::loadProperty(std::string ownableName, std::shared_ptr<Player> buyer, int imprLevel) {
    // create a new property for player
    int propID = indexOfSquare(ownableName); // the id is the unique index of square on the map
    int propCostToBuy = costToBuyProp(ownableName);
    char propOwner = buyer->getGamePiece();

    std::shared_ptr<Ownable> ownable;

    if (isGym(ownableName))
    {
        auto production = std::make_shared<Gym>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }
    else if (isResidence(ownableName))
    {
        auto production = std::make_shared<Residence>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }
    else if (isAcademic(ownableName))
    {
        auto production = std::make_shared<Academic>(propID, ownableName, propCostToBuy, propOwner);
        ownable = std::dynamic_pointer_cast<Ownable>(production);
    }

    buyer->addProp(ownable);

    if (imprLevel == -1) {
        ownable->setMortStatus(true);
    } else {
        ownable->setImprLevel(imprLevel + 1); 
    }
}
