#include "player.h"

using namespace std;

Player::Player(string name, char gamePiece, int funds)
    : name{name}, gamePiece{gamePiece}, funds{funds}
{}

bool Player::checkIfInMonopolyBlock(std::string squareName) {
    std::string monoBlockOfSquare = monoBlockOfProp(squareName);
    int size = monopolyBlocks.size();

    for (int i = 0; i < size; i++) {
        if (monopolyBlocks[i] == monoBlockOfSquare) {
            return true;
        }
    }

    return false;
}

bool Player::ownThisProp(std::string name) {
    int size = ownedProperties.size();

    for (int i = 0; i < size; i++) {
        // perform upcasting from Ownable to Square
        std::shared_ptr<Square> tmpSquare = std::dynamic_pointer_cast<Square>(ownedProperties[i]);

        if (tmpSquare->getName() == name) {
            return true;
        }
    }

    return false;
}

bool Player::addFund(int amt) {
    funds += amt;
    return true;
}

bool Player::payFund(int amt) {
    if (bankruptStatus) {
        std::cout << "(testing) this player is bankrupted" << std::endl;
        return false;
    }

    if (funds < amt) {
        std::cout << "(testing) insufficient fund to pay, check to see if you can sell anything" << std::endl;
        return false;
    }

    funds -= amt;
    return true;
}

bool Player::addProp(std::string squareName) {
    // check if property is already owned
    if (this->ownThisProp(squareName)) {
        std::cout << "(testing) this props is owned" << std::endl;
        return false;
    }

    int newAddID = indexOfSquare(squareName); // the id is a unique position of property on map
    int newAddCostToBuy = costToBuyProp(squareName);

    //constuctor of Ownable(int ID, std::string name, int costToBuy, char owner);
    auto newAddOwnable = std::make_shared<Ownable>(newAddID, squareName, newAddCostToBuy, this->getGamePiece());

    ownedProperties.push_back(newAddOwnable);
    return true;
}

bool Player::removeProp(std::string squareName) {
    // check if property is owned
    if (!this->ownThisProp(squareName)) {
        std::cout << "(testing) this props is not owned" << std::endl;
        return false;
    }

    for (int i = 0; i < ownedProperties.size(); i++) {
        // perform upcasting from Ownable to Square
        std::shared_ptr<Square> tmpSquare = std::dynamic_pointer_cast<Square>(ownedProperties[i]);

        if (squareName == tmpSquare->getName()) {
            ownedProperties.erase(ownedProperties.begin() + i);
            break;
        }
    }

    return true;

}

bool Player::mortageProp(std::string squareName) {
    // check if property is already in morgaged list
    if (this->checkPropMortgage(squareName)) {
        std::cout << "(testing) this props is morgaged" << std::endl;
        return false;
    }

    // mortgage the prop and add fund accordingly
    int fundFromMortgage = costToMortProp(squareName);
    funds += fundFromMortgage;

    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        // perform upcasting from Ownable to Square
        std::shared_ptr<Square> tmpSquare = std::dynamic_pointer_cast<Square>(ownedProperties[i]);

        if (squareName == tmpSquare->getName()) {
            ownedProperties[i]->setMortStatus(true);
            break;
        }
    }

    return true;
}

bool Player::unmortageProp(std::string squareName) {
    // check if property is in morgaged list
    if (!this->checkPropMortgage(squareName)) {
        std::cout << "(testing) this props is not in morgaged list" << std::endl;
        return false;
    }

    // pay the fund and unmortgage props
    int fundToPay = costToUnmortProp(squareName);
    
    if (fundToPay > funds) {
        std::cout << "(testing) you don't have enough money to unmortgage" << std::endl;
        return false;
    }

    funds -= fundToPay;

    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        // perform upcasting from Ownable to Square
        std::shared_ptr<Square> tmpSquare = std::dynamic_pointer_cast<Square>(ownedProperties[i]);

        if (squareName == tmpSquare->getName()) {
            ownedProperties[i]->setMortStatus(false);
            break;
        }
    }

    return true;

}

bool Player::checkPropMortgage(std::string squareName) {
    int sizeOwnProp = ownedProperties.size();

    for (int i = 0; i < sizeOwnProp; i++) {
        // perform upcasting from Ownable to Square
        std::shared_ptr<Square> tmpSquare = std::dynamic_pointer_cast<Square>(ownedProperties[i]);

        if (tmpSquare->getName() == squareName) return true;
    }

    return false;
}

char Player::getGamePiece() const {
    return gamePiece;
}

string Player::getName() const {
    return name;
}

std::string Player::getSquareAtCurrPos() {
    return MAP_GAME[pos];
}

int Player::getCurrPos() const {
    return pos;
}

int Player::getFunds() const {
    return funds;
}

int Player::getAssets() const {
    int result = funds;
    // we still need to know if mortgaged property count as assets
    // this code is just for now
    
    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        result += ownedProperties[i]->getCostToBuy();
    }

    // minus the mortgaged properties prize
    for (int i = 0; i < sizeOwnProp; i++) {
        if (ownedProperties[i]->getMortStatus() == true) {}
            result -= ownedProperties[i]->getCostToBuy();
    }

    return result;
}

void Player::actionAtCurrPos() {
    std::string currSquare = this->getSquareAtCurrPos();
    if (isOwnableBlock(currSquare)) {
        // pay fee
    } else {
        // take other actions
    }
}

void Player::movePlayer(int roll) {
    pos += roll;
    if (pos > (MAP_GAME_SIZE - 1)) {
        pos -= MAP_GAME_SIZE;
    }
}

void Player::moveToDCTims() {
    pos = 10; // position for DC Tims Line (hard coded)
    // action on DC Tims Line (need to change later)
}

void Player::declareBankruptcy() {
    // check if qualify to declare bankruptcy
}

void Player::auctionProperty(std::string squareName) {
    // call the auction class
}

bool Player::loadFromSave(std::string saveFile) {
    return false;
}

bool saveGame(std::string saveFile) {
    return false;
}
