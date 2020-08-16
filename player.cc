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
   
    // assets = funds + printed prices of all prop (both mort and unmort) +
    //              costs of all improvements 
    int sizeOwnProp = ownedProperties.size();

    for (int i = 0; i < sizeOwnProp; i++){
	std::string propName = ownedProperties[i]->getName();
        result += costToBuyProp(propName);
	int imprLevel = ownedProperties[i]->getImprLevel();
	if (imprLevel > 0){
	    result += imprLevel * costToImprProp(propName);
	}
    }
    /*for (int i = 0; i < sizeOwnProp; i++) {
        result += costToMortProp(ownedProperties[i]->getName());
    }

    // minus the mortgaged properties prize
    for (int i = 0; i < sizeOwnProp; i++) {
        if (ownedProperties[i]->getMortStatus() == true) {}
            result -= costToMortProp(ownedProperties[i]->getName());
    }*/

    return result;
}

void Player::movePlayer(int roll) {
    pos += roll;
    if (pos >= MAP_GAME_SIZE) {
        std::cout << "***You receive OSAP SALARY for landing or passing it!***" << std::endl;
        pos = pos % MAP_GAME_SIZE;
        this->addFund(OSAP_SALARY);
    }
}

void Player::moveToDCTims() {
    pos = 10; // position for DC Tims Line (hard coded)
    // action on DC Tims Line (need to change later)
    return;
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

    numGymOwned = 0;
    numResOwned = 0;
    // track any owned buildings, mort or unmort
    // updates numGymOwned, numResOwned
    for (int i = 0; i < sizeOwnedProp; i++) {
        std::string propName = ownedProperties[i]->getName();
        if (isGym(propName)){
            numGymOwned++;
        } else if (isResidence(propName)){
            numResOwned++;
        }
	
	eachBlock = ownedProperties[i]->getMonoBlock();
	trackingBuilding[eachBlock] += 1;
    }

    for (auto &block: trackingBuilding) {
        if (block.second == 2 && block.first == "Math") {
            monopolyBlocks.push_back(block.first);
        } else if (block.second == 3) {
            monopolyBlocks.push_back(block.first);
        }
    }
}

int Player::getNumGymOwned(){
    return numGymOwned;
}

int Player::getNumResOwned(){
    return numResOwned;
}

void Player::printOwnedProp(){
    int sizeOwnedProp = ownedProperties.size();
    cout << "Displaying all properites owned by " << name << endl;
    for (int i = 0; i < sizeOwnedProp; i++) {
	std::string propName = ownedProperties[i]->getName();
        cout << propName << "\t";
	cout << "Cost: $" << costToBuyProp(propName) << "\t";
	cout << "Mortgaged: " ;
	if (ownedProperties[i]->getMortStatus()){
	    cout << "Yes" << endl;
	} else {
	    cout << "No\t";
	    cout << "Improvements: " << ownedProperties[i]->getImprLevel() << "\t";
	    cout << "Improvement Cost: " << costToImprProp(propName) << endl;
	} 
    }
}

void Player::displayAssets(){
    cout << "Displaying assets of " << name << endl;
    cout << "Funds: " << funds << endl;
    printOwnedProp();
    cout << "Tims Cups: " << timsCups << endl;
    cout << "Total worth: " << getAssets() << endl;
}

void Player::loadUpdateAmountToPay(){
    int sizeOwnedProp = ownedProperties.size();
    for (int i = 0; i < sizeOwnedProp; i++){
	std::string propName = ownedProperties[i]->getName();
        if (isGym(propName)){
	    ownedProperties[i]->setPayLevel(numGymOwned - 1);
	} else if (isResidence(propName)){
	    ownedProperties[i]->setPayLevel(numResOwned - 1);
	} else {
	    bool blockOwned = checkIfInMonopolyBlock(propName);
	    if (blockOwned){
		auto acad = std::dynamic_pointer_cast<Academic>(ownedProperties[i]);
		acad->setBlockOwned(true);
	    }
	}
    }
}

