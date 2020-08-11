#ifndef _SQUARE_H
#define _SQUARE_H

class Square{
    int id;
    int posX;
    int posY;
    std::string name;
    int numPlayers;

  public:
    Square();
    int getNumPlayers();
    void removePlayer();
    void addPlayer();
    int getPosX();
    int getPosY();
};

#endif
