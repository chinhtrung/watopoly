#ifndef _BOARD_H
#define _BOARD_H
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "utility/seeds.h"
#include "utility/positionMap.h"
using std::shared_ptr;
using std::string;
using std::map;
using std::vector;

class Square;
class Player;
class BoardDisplay;

class Board {
    // i.e. "MC": 1, "DC": 0, "AL": -1
    map<string, int> sqrImproves; 

    // i.e. "A": 34, "G": 2
    map<char, int> playerPos;
    //vector<shared_ptr<Square>> squares;
    //vector<shared_ptr<Player>> players;
    int timsCupsRem;
    std::unique_ptr<BoardDisplay> bd = nullptr;

    // called in drawBoard to update BoardDisplay
    void updateInfo();

  public:
    Board();

    void drawBoard();

    // main calls this to add a player to Board's playerPos vector
    void addPlayer( char player );

    // updates display with player's new position and modifies
    //    player's posX, posY fields acccordingly
    void movePlayer( char gamepiece, int newSqr );

    // udpates display with added improvement
    void addImpr( string building );

    // udpates display, removing improvement
    void removeImpr( string building );

    // Returns the number of available Tims Cups (Max = 4)
    int getTimsCupsRem();
};

#endif
