#ifndef _SQUARE_H
#define _SQUARE_H
#include <string>

class Square{
    int id;
    int posX;
    int posY;
    std::string name;
    int numPlayers;

  public:
    Square( int id, std::string name, int x, int y );
    int getNumPlayers();
    void removePlayer();
    void addPlayer();
    int getPosX();
    int getPosY();
};

#endif
