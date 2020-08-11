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
class Dice;

class Board {

    // squares contains all squares on the board
    // Note: this version has 40 squares so squares.size() == 40
    vector<shared_ptr<Square>> squares;

    vector<shared_ptr<Player>> players;
    Dice dice;
    int timsCupsRem;

    
    // VERSION A STATE STRUCTURES
    /*// key: Monopoly block name (e.g. Arts1)
    // value: map of Academic buildings in the block and the corresponding
    //           owner of that building
    // Note: if building is unowned, the shared_ptr<Player> is nullptr
    map<string, map<shared_ptr<Academic>, shared_ptr<Player>>> acadState;

    map<shared_ptr<Residence>, shared_ptr<Player>> resState;
    map<shared_ptr<Gym>, shared_ptr<Player>> gymState; */


    // VERSION B STATE STRUCTURES

    // key: Monopoly block name (e.g. Arts1)
    // value: map of Academic buildings in that block
    // 			key: name of Academic building
//    map<string, map<string,shared_ptr<Academic>>> acadState;

    // key: name of Residence
    map<string, shared_ptr<Residence>> resState;

    // key: name of Gym
    map<string, shared_ptr<Gym>> gymState;

  public:

    Board();

    // main calls this to add a player to Board's players vector
    void addPlayer( shared_ptr<Player> );

    void drawBoard();                   // Draws the board

    // Returns the name of the Monopoly block acadID belongs to
//    string getMonopoly( int acadID );

    // Returns the number of available Tims Cups (Max = 4)
    int getTimsCupsRem();

    // Returns true if the owner of acadID owns all properties in
    //     acadID's block
    // Else if not all properties owned or if acadID is unowned, 
    //     returns false
//    bool checkAcad( string acadID );

    // Returns the number of gyms owned by owner of gymID
    // Note: if gymID is unowned, returns 0
    int checkGymsOwned( string gymID );

    // Returns the number of res owned by owner of resID
    // Note: if resID is unowned, returns 0
    int checkResOwned( string resID );


    // VERSION A UPDATE METHODS
    /*// Updates the owner of prop1 to own2 and the owner of prop2
    //    to own1
    // Note: called by transaction class after two properties are traded
    void updateByTransPforP
            ( shared_ptr<Ownable> prop1, char own1,
              shared_ptr<Ownable> prop2, char own2 );

    // updates the owner of prop to own
    // Note: called by the transaction class after property is traded
    //    for money (either money for property or property for money)
    //    and after property is bought from bank
    void updateByTrans
            ( shared_ptr<Ownable> prop, char own ); */

};

#endif
