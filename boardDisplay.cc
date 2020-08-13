#include "boardDisplay.h"
#include <fstream>

const int B_COLS = 90;
const int B_ROWS = 56;

BoardDisplay::BoardDisplay(){
    display.resize(B_COLS, std::vector<char>(B_ROWS, ' '));
    std::ifstream disFile{ "display.txt" };
    char c;

    for (int i = 0; i < B_COLS; i++){
        for (int j = 0; j < B_ROWS; j++){
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

    for (int i = 0; i < B_COLS; i++){
        for (int j = 0; j < B_ROWS; j++){
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
    for (int i = 0; i < B_COLS; i++){
        for (int j = 0; j < B_ROWS; j++){
            std::cout << display[i][j];
        }
    }
    std::cout << std::endl;
}

