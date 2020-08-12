#include "board.h"
#include "square.h"
#include "player.h"
#include "dice.h"
#include "boardDisplay.h"

const int MAX_TIMS_CUPS = 4;
const int NUM_SQUARES = 40;
const int MAX_PLAYERS = 8;

Board::Board() {
   
    timsCupsRem = MAX_TIMS_CUPS;
    unique_ptr<BoardDisplay> bd(); 

}

Board::Board( string fileName ){
    std::ifstream inf{fileName};
    // initialize board with save file
  
}


void Board::addPlayer( shared_ptr<Player> p ){
  //  players.emplace_back(p); //doesn't throw if main doesn't add more than 8 players
}

void Board::movePlayer( char gamepiece, int newSqr ){
    int sqrX = squares[newSqr].getPosX();
    int sqrY = squares[newSqr].getPosY();
    int oldSqr = players[gamepiece].getCurrSqr();
    squares[oldSqr].removePlayer();
    squares[newSqr].addPlayer();

    int newX = sqrX + squares[id].getNumPlayers();
    int newY = sqrY + 4;

    bd.movePlayer(player.getPosX(), player.getPosY(), newX, newY, gamepiece);
    player.setPos(newX, newY);
}


void Board::addImpr( int building ){
    squares[building].addImprove();
    int sqrX = squares[building].getPosX();
    int sqrY = squares[building].getPosY();
    int x = sqrX + squares[building].getImprLevel() - 1;
    int y = sqrY + 2;
    bd.addImpr( int x, int y );
}


void Board::removeImpr( int building ){
    int sqrX = squares[building].getPosX();
    int sqrY = squares[building].getPosY();
    int x = sqrX + squares[building].getImprLevel() - 1;
    int y = sqrY + 2;
    squares[building].removeImprove();
    bd.removeImpr( int x, int y );
}


int Board::getTimsCupsRem(){
    return timsCupsRem;
}

// requires that the gym indicated by gymID is owned
int Board::checkGymsOwned( string gymID ){
    char owner = gymState[gymID].getOwnerChar();
    int numOwned = 0;
    for (auto &p: gymState){
        if (p.second.getOwnerChar() == owner){
	    numOwned++;
	}
    }
    return numOwned;
}


int Board::checkResOwned( string resID ){
    char owner = resState[resID].getOwnerChar();
    int numOwned = 0;
    for (auto &p: resState){
        if (p.second.getOwnerChar() == owner){
            numOwned++;
        }
    }
    return numOwned;
}


std::ostream & operator<<( std::ostream & out, const Board & b ){
    out << *(b.bd);
    return out;
}
