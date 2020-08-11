#ifndef _PLAYER_H
#define _PLAYER_H

class Player{
    int posX;
    int posY;
  public:
    int getPosX();
    int getPosY();
    int setPos( int x, int y );
};

#endif
