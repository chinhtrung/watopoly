#include "Board.h"
#include "Square.h"
#include "Player.h"
#include "Dice.h"

const int MAX_TIMS_CUPS = 4;

Board::Board( num and type of players ) {
    timsCupsRem = MAX_TIMS_CUPS;
}


void Board::drawBoard() {

}


string Board::getMonopoly( int acadID ){
    
}


int Board::getTimsCupsRem(){
    return timsCupsRem;
}


bool Board::checkAcad( string acadID ){
    string monoBlock = 
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


// the update functions are not necessary with version B
//    acad/res/gym state structures
void Board::updateByTransPforP( shared_ptr<Ownable> prop1, char own1,
                                  shared_ptr<Ownable> prop2, char own2 ){

}


void Board::updateByTrans( shared_ptr<Ownable> prop, char own ){

}
