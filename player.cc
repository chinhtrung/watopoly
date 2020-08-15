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
        if (ownedProperties[i]->getName() == name) {
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

bool Player::addProp(std::shared_ptr<Ownable> prop) {
    // check if property is already owned
    if (this->ownThisProp(prop->getName())) {
        std::cout << "(testing) this props is owned" << std::endl;
        return false;
    }

    if (isGym(prop->getName())){
        numGymOwned++;
    } else if (isResidence(prop->getName())){
        numResOwned++;
    }
    ownedProperties.push_back(prop);
    return true;
}

bool Player::removeProp(std::shared_ptr<Ownable> prop) {
    // check if property is owned
    if (!this->ownThisProp(prop->getName())) {
        std::cout << "(testing) this props is not owned" << std::endl;
        return false;
    }

    for (unsigned int i = 0; i < ownedProperties.size(); i++) {
        if (prop == ownedProperties[i]) {
            ownedProperties.erase(ownedProperties.begin() + i);
            break;
        }
    }

    return true;
}

bool Player::mortageProp(std::shared_ptr<Ownable> prop) {
    // mortgage the prop and add fund accordingly
    int fundFromMortgage = costToMortProp(prop->getName());
    funds += fundFromMortgage;

    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        if (prop == ownedProperties[i]) {
            ownedProperties[i]->setMortStatus(true);
            break;
        }
    }

    return true;
}

bool Player::unmortageProp(std::shared_ptr<Ownable> prop) {
    // pay the fund and unmortgage props
    int fundToPay = costToUnmortProp(prop->getName());
    
    if (fundToPay > funds) {
        std::cout << "(testing) you don't have enough money to unmortgage" << std::endl;
        return false;
    }

    funds -= fundToPay;

    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        if (prop == ownedProperties[i]) {
            ownedProperties[i]->setMortStatus(false);
            break;
        }
    }

    return true;
}

char Player::getGamePiece() const {
    return gamePiece;
}

string Player::getName() const {
    return name;
}

string Player::getSquareAtCurrPos() {
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
    
    int sizeOwnProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnProp; i++) {
        result += costToMortProp(ownedProperties[i]->getName());
    }

    // minus the mortgaged properties prize
    for (int i = 0; i < sizeOwnProp; i++) {
        if (ownedProperties[i]->getMortStatus() == true) {}
            result -= costToMortProp(ownedProperties[i]->getName());
    }

    return result;
}

void Player::movePlayer(int roll) {
    pos += roll;
    pos = pos % MAP_GAME_SIZE;
}

void Player::moveToDCTims() {
    pos = 10; // position for DC Tims Line (hard coded)
    // action on DC Tims Line (need to change later)
}

void Player::setPos(int pos) {
	this->pos = pos;
}

void Player::addTimsCup(){
    timsCups++;
}

void Player::setTimsCups(int cups){
    timsCups = cups;
}

int Player::getTimsCups(){
    return timsCups;
}

void Player::setBankruptStatus(bool status) {
    bankruptStatus = status;
}

bool Player::getBankruptStatus() {
    return bankruptStatus;
}

std::vector<std::shared_ptr<Ownable>> Player::getOwnedPropList() {
    return ownedProperties;
}

void Player::updateMonopolyBlock() {
    // every falcuty need 3 building to finish a block except for Math faculty (they only need 2)
    int sizeOwnedProp = ownedProperties.size();
    std::map<std::string, int> trackingBuilding; // {"Sci1": 2, "Sci2": 3}
    std::string eachBlock;

    for (int i = 0; i < sizeOwnedProp; i++) {
        eachBlock = ownedProperties[i]->getMonoBlock();
	if (!ownedProperties[i]->getMortStatus()){
	    trackingBuilding[eachBlock] += 1;
	}
    }

    for (auto &block: trackingBuilding) {
        if (block.second == 2 && block.first == "Math") {
            monopolyBlocks.push_back(block.first);
        } else if (block.second == 3) {
            monopolyBlocks.push_back(block.first);
        }
    }

}

void Player::removeGym(){
    numGymOwned--;
}

void Player::removeRes(){
    numResOwned--;
}

void Player::addGym(){
    numGymOwned++;
}

void Player::addRes(){
    numResOwned++;
}

int Player::getNumGymOwned(){
    return numGymOwned;
}

int Player::getNumResOwned(){
    return numResOwned;
}

void Player::printOwnedProp(){
    int sizeOwnedProp = ownedProperties.size();
    cout << "Printing all properites owned by " << name << endl;
    for (int i = 0; i < sizeOwnedProp; i++) {
        cout << ownedProperties[i]->getName() << endl;
    }
}
