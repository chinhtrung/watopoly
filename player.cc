#include "player.h"

int Player::getPosX(){
    return posX;
}

int Player::getPosY(){
    return posY;
}

int Player::setPos( int x, int y ){
    posX = x;
    posY = y;
}
