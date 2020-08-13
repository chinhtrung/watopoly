#include "boardDisplay.h"
#include <fstream>

BoardDisplay::BoardDisplay(){
    std::ifstream disFile{ "display.txt" };
    char c;

    for (int i = 0; i < B_ROWS; i++){
        for (int j = 0; j < B_COLS; j++){
            disFile.get(c);
            display[i][j] = c;
        }
    }
    std::cout << std::endl;
    disFile.close();
}

void BoardDisplay::reset(){
    std::ifstream disFile{ "display.txt" };
    char c;

    for (int i = 0; i < B_ROWS; i++){
        for (int j = 0; j < B_COLS; j++){
            disFile.get(c);
            display[i][j] = c;
        }
    }
}

void BoardDisplay::addPlayer( int row, int col, char player ){ 
    display[row][col] = player;
}


void BoardDisplay::addImpr( int row, int col ){
    display[row][col] = 'I';
}

void BoardDisplay::draw(){
    for (int i = 0; i < B_ROWS; i++){
        for (int j = 0; j < B_COLS; j++){
            std::cout << display[i][j];
        }
    }
    std::cout << std::endl;
}

