#include "square.h"

Square::Square(int ID, std::string name) : ID{ID}, name{name} {}


std::string Square::getName () {
    return name;
}


int Square::getID() {
    return ID;
}
