#ifndef _BOARD_H
#define _BOARD_H
#include <map>
#include <string>
#include <memory>
using std::shared_ptr;
using std::string;
using std::map;

class Square;
class Player;
class BoardDisplay;

class Board {
    vector<shared_ptr<Square>> squares;
    vector<shared_ptr<Player>> players;
    int timsCupsRem;
    std::unique_ptr<BoardDisplay> bd = nullptr;

    // key: name of Residence
    map<string, shared_ptr<Residence>> resState;

    // key: name of Gym
    map<string, shared_ptr<Gym>> gymState;

  public:
    Board();

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

    // Returns the number of gyms owned by owner of gymID
    // Note: if gymID is unowned, returns 0
    int checkGymsOwned( string gymID );

    // Returns the number of res owned by owner of resID
    // Note: if resID is unowned, returns 0
    int checkResOwned( string resID );

    friend std::ostream & operator<<( std::ostream & out, const Board & b );
};

std::ostream & operator<<( std::ostream & out, const Board & b );

#endif
