#include "player.h"

using namespace std;

Player::Player(string name, char gamePiece, int pos, int funds, int timsCups, map<int, 
    shared_ptr<Square>> ownedProperties, map<int, shared_ptr<Square>> mortgagedProperties)
    : name{name}, gamePiece{gamePiece}, pos{pos}, funds{funds}, timsCups{timsCups}, ownedProperties{ownedProperties}, mortgagedProperties{mortgagedProperties}
{}

string Player::getName() const {
    return name;
}

char Player::getGamePiece() const {
    return gamePiece;
}

int Player::getCurrPos() const {
    return pos;
}

int Player::getFunds() const {
    return funds;
}

int Player::getAssets() const {
    int result = 0
    // run the calculation on result
    return result;
}

void Player::movePlayer(int roll);
void Player::moveToTims();
void Player::declareBankruptcy();
void Player::auctionProperty(shared_ptr<Ownable> ptr);
void Player::loadFromSave(shared_ptr<GameState> ptr);
