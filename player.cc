#include "player.h"

int Player::getPosX(){
    return posX;
}

int Player::getPosY(){
    return posY;
}

void Player::setPos( int x, int y ){
    posX = x;
    posY = y;
}

int Player::getCurrSqr(){
    return currSqr;
}
