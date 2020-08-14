#ifndef _BOARD_H
#define _BOARD_H
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <vector>
using std::shared_ptr;
using std::string;
using std::map;
using std::vector;

class BoardDisplay;

class Board {
    // i.e. "MC": 1, "DC": 0, "AL": -1
    map<string, int> sqrImproves; 

    // i.e. "A": 34, "G": 2
    map<char, int> playerPos;
    //vector<shared_ptr<Square>> squares;
    //vector<shared_ptr<Player>> players;
    std::unique_ptr<BoardDisplay> bd = nullptr;

    // called in drawBoard to update BoardDisplay
    void updateInfo();

  public:
    Board();

    void drawBoard();

    // main calls this to add a player to Board's playerPos vector
    void addPlayer( char player );

    // removes player if they go bankrupt
    void removePlayer( char gamepiece );

    // updates display with player's new position and modifies
    //    player's posX, posY fields acccordingly
    void movePlayer( char gamepiece, int newSqr );

    // udpates display with added improvement
    void addImpr( string building );

    void removeImpr( string building ); 

    int getImpr( string building );
};

#endif
