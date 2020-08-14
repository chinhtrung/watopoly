#include "positionMap.h"


// return the first index of nameSquare in the MAP_GAME
// nameSquare should be a valid name
int indexOfSquare(std::string nameSquare) {
    int indexResult = 0;

    for (int i = 0; i < MAP_GAME_SIZE; i++) {
        if (nameSquare == MAP_GAME[i]) {
            indexResult = i;
            break;
        }
    }

    return indexResult;
}

int colOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[0];
}

int rowOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[1];
}

