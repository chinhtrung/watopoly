#include "board.h"
#include "./utility/positionMap.h"
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

    timsCupsRem = MAX_TIMS_CUPS;
    bd = std::make_unique<BoardDisplay> ();
}

void Board::updateInfo(){
   for (auto &p: sqrImproves){
       if (p.second > 0){
           int sqrC = colOfSquare(p.first);
           int sqrR = rowOfSquare(p.first);
	   int r = sqrR + 1;
	   for (int i = 0; i < p.second; i++){
	       int c = sqrC + i;
	       bd->addImpr(r, c);
	   }
       }	   
   } 

   // keeps track of number of players at each square,
   //    increments when another player is found at that square
   // e.g. 0 : 1, 32: 5, 12: 2
   map<int, int> numPlayers;
   for (auto &p: playerPos){   
       int sqrC = colOfSquare(p.second);
       int sqrR = rowOfSquare(p.second);
       auto it = numPlayers.find(p.second);

       int c = sqrC;
       if (it != numPlayers.end()){
	   c += it->second;
           numPlayers[p.second]++;
       } else {
           numPlayers[p.second] = 1;
       }

       int r = sqrR + 4;
       bd->addPlayer(r, c, p.first);
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

void Board::removeImpr( string building ){
    sqrImproves[building]--;
}

void Board::movePlayer( char gamepiece, int newSqr ){
    playerPos[gamepiece] = newSqr; 
}


void Board::addImpr( string building ){
    sqrImproves[building]++; 
}

int Board::getTimsCupsRem(){
    return timsCupsRem;
}

