#include "player.h"

using namespace std;

Player::Player(std::string name, char gamePiece, int pos, int funds, int timsCups, std::map<int, 
    std::shared_ptr<Square>> ownedProperties, std::map<int, std::shared_ptr<Square>> mortgagedProperties)
    : name{name}, gamePiece{gamePiece}, pos{pos}, funds{funds}, timsCups{timsCups}, ownedProperties{ownedProperties}, mortgagedProperties{mortgagedProperties}
{}

std::string Player::getName() const {
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
void Player::auctionProperty(std::shared_ptr<Ownable> ptr);
void Player::loadFromSave(std::shared_ptr<GameState> ptr);
