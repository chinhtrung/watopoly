#include "board.h"
#include "square.h"
#include "player.h"
#include "dice.h"
#include "boardDisplay.h"

const int MAX_TIMS_CUPS = 4;
const int NUM_SQUARES = 40;
const int MAX_PLAYERS = 8;

Board::Board() {
    sqrImproves  = {
        {"AL", 0},
	{"ML", 0},
	{"ECH", 0},
	{"PAS", 0},
	{"HH", 0},
	{"RCH", 0},
	{"DWE", 0},
	{"CPH", 0},
	{"LHI", 0},
	{"BMH", 0},
	{"OPT", 0},
	{"EV1", 0},
	{"EV2", 0},
	{"EV3", 0},
	{"PHYS", 0},
	{"B1", 0},
	{"B2", 0},
	{"EIT", 0},
	{"ESC", 0},
	{"C2", 0},
	{"MC", 0},
	{"DC", 0}
    };

    /*sqrImproves["AL"] = 0;
    sqrImproves["ML"] = 0;  
    sqrImproves["ECH"] = 0;
    sqrImproves["PAS"] = 0;
    sqrImproves["HH"] = 0;
    sqrImproves["RCH"] = 0;
    sqrImrpoves["DWE"] = 0;
    sqrImproves["CPH"] = 0;
    sqrImproves["LHI"] = 0;
    sqrImproves["BMH"] = 0;
    sqrImproves["OPT"] = 0;
    sqrImproves["EV1"] = 0;
    sqrImproves["EV2"] = 0;
    sqrImproves["EV3"] = 0;
    sqrImproves["PHYS"] = 0;
    sqrImproves["B1"] = 0;
    sqrImproves["B2"] = 0;
    sqrImproves["EIT"] = 0;
    sqrImproves["ESC"] = 0;
    sqrImproves["C2"] = 0;
    sqrImproves["MC"] = 0;
    sqrImproves["DC"] = 0;*/


    timsCupsRem = MAX_TIMS_CUPS;
    bd = std::make_unique<BoardDisplay> ();
}

void Board::updateInfo(){
   for (auto &p: sqrImproves){
       int sqrX = posXOfSquare(p.first);
       int sqrY = posYOfSquare(p.first);
       int x = sqrX + p.second - 1;
       int y = sqrY + 2;
       bd->addImpr( x, y );	       
   } 

   // keeps track of number of players at each square,
   //    increments when another player is found at that square
   // e.g. 0 : 1, 32: 5, 12: 2
   map<int, int> numPlayers;
   for (auto &p: playerPos){   
       int sqrX = posXOfSquare(p.second);
       int sqrY = posYOfSquare(p.second);
       auto it = numPlayers.find(p.second);

       int x = sqrX;
       if (it != numPlayers.end()){
	   int x += it->second;
           numPlayers[p.second]++;
       } else {
           numPlayers[p.second] = 1;
       }

       int y = sqrY + 4;
       bd->addPlayer(x, y, p.first);
   }
}

void Board::drawBoard(){
    updateInfo();
    bd->draw();
    bd->reset();
}

void Board::addPlayer( char player ){
    playerPos[player] = 0;
}

void Board::movePlayer( char gamepiece, int newSqr ){
    playerPos[gamepiece] = newSqr;
    /*int sqrX = squares[newSqr].getPosX();
    int sqrY = squares[newSqr].getPosY();
    int oldSqr = players[gamepiece].getCurrSqr();
    squares[oldSqr].removePlayer();
    squares[newSqr].addPlayer();

    int newX = sqrX + squares[id].getNumPlayers();
    int newY = sqrY + 4;

    bd.movePlayer(player.getPosX(), player.getPosY(), newX, newY, gamepiece);
    player.setPos(newX, newY);*/
}


void Board::addImpr( string building ){
    sqrImproves[building]++;

    /*squares[building].addImprove();
    int sqrX = squares[building].getPosX();
    int sqrY = squares[building].getPosY();
    int x = sqrX + squares[building].getImprLevel() - 1;
    int y = sqrY + 2;
    bd.addImpr( int x, int y );*/
}


void Board::removeImpr( string building ){
    sqrImproves[building]--;
    /*int sqrX = squares[building].getPosX();
    int sqrY = squares[building].getPosY();
    int x = sqrX + squares[building].getImprLevel() - 1;
    int y = sqrY + 2;
    squares[building].removeImprove();
    bd.removeImpr( int x, int y );*/
}


int Board::getTimsCupsRem(){
    return timsCupsRem;
}

