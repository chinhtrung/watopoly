#ifndef _BOARD_H
#define _BOARD_H
#include <map>
#include <vector>
#include <string>
#include <memory>
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

    // i.e. "olayer a": 34, "player b" 2
    map<string, int> playerPos;
    //vector<shared_ptr<Square>> squares;
    //vector<shared_ptr<Player>> players;
    int timsCupsRem;
    std::unique_ptr<BoardDisplay> bd = nullptr;

    // called in drawBoard to update BoardDisplay
    void updateInfo();

  public:
    Board();

    void drawBoard();
    // main calls this to add a player to Board's players vector
    void addPlayer( shared_ptr<Player> );

    // updates display with player's new position and modifies
    //    player's posX, posY fields acccordingly
    void movePlayer( char gamepiece, int newSqr );

    // udpates display with added improvement
    void addImpr( int building );

    // udpates display, removing improvement
    void removeImpr( int building );

    // Returns the number of available Tims Cups (Max = 4)
    int getTimsCupsRem();

    friend std::ostream & operator<<( std::ostream & out, const Board & b );
};

std::ostream & operator<<( std::ostream & out, const Board & b );

#endif
