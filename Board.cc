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


bool Board::checkAcad( int acadID ){

}


int Board::checkGymsOwned( int gymID ){

}


int Board::checkResOwned( int resID ){

}


void Board::updateByTransPforP( shared_ptr<Ownable> prop1, char own1,
                                  shared_ptr<Ownable> prop2, char own2 ){

}


void Board::updateByTrans( shared_ptr<Ownable> prop, char own ){

}
