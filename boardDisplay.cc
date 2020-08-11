#include "boardDisplay.h"
#include <fstream>

const int B_HEIGHT = 89;
const int B_WIDTH = 55;

BoardDisplay::BoardDisplay(){
    display.resize(B_HEIGHT, std::vector<char>(B_WIDTH, ' '));
    std::ifstream disFile{ "display.txt" };
    char c;

    while (disFile.get(c)){
        for (int i = 0; i < B_HEIGHT; i++){
            for (int j = 0; j < B_WIDTH; j++){
                display[i][j] = c;
            }
        }
    }
}


void BoardDisplay::movePlayer
       ( int oldX, int oldY, int newX, int newY, char player ){
    display[oldX][oldY] = ' ';
    display[newX][newY] = player;
}


void BoardDisplay::addImpr( int x, int y ){
    display[x][y] = 'I';
}


void BoardDisplay::removeImpr( int x, int y ){
    display[x][y] = ' ';
}


std::ostream &operator<<(std::ostream &out, const BoardDisplay &bd) {
    for (size_t i = 0; i < B_HEIGHT; i++){
        for (size_t j = 0; j < B_WIDTH; j++){
            out << td.theDisplay[i][j];
        }
        out << std::endl;
    }
    return out;
}
