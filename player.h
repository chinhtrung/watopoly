#ifndef _PLAYER_H
#define _PLAYER_H

class Player{
    int posX;
    int posY;
    int currSqr;
    char gamepiece;
  public:
    int getPosX();
    int getPosY();
    void setPos( int x, int y );
    int getCurrSqr();
    char getGamePiece();
};

#endif
