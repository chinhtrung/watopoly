#include "square.h"
using std::string;

Square::Square( int id, string name, int x, int y )
        : id{id}, name{name}, posX{x}, posY{y}, numPlayers{0} {}


int Square::getNumPlayers(){
    return numPlayers;
}

void Square::addPlayer(){
    numPlayers++;
}

void Square::removePlayer(){
    numPlayers--;
}

int Square::getPosX(){
    return posX;
}

int Square::getPosY(){
    return posY;
}
