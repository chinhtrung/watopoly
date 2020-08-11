#include "square.h"
using std::string

Square::Square( int id, string name )
        : id{id}, name{name} {}

char Square::getOwnerChar(){
    return owner.getGamePiece();
}
