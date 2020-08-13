#include "boardDisplay.h"
#include <fstream>

const int B_ROWS = 90;
const int B_COLS = 56;

BoardDisplay::BoardDisplay(){
    display.resize(B_ROWS, std::vector<char>(B_COLS, ' '));
    std::ifstream disFile{ "display.txt" };
    char c;

    for (int i = 0; i <= B_ROWS; i++){
        for (int j = 0; j < B_COLS; j++){
            disFile.get(c); 
            display[i][j] = c; 
        }
    }   
    std::cout << std::endl; 
}

void BoardDisplay::reset(){
    std::ifstream disFile{ "display.txt" };
    char c;

    for (int i = 0; i <= B_ROWS; i++){
        for (int j = 0; j < B_COLS; j++){
            disFile.get(c);
            display[i][j] = c;
        }
    }
    std::cout << std::endl;
}

void BoardDisplay::addPlayer( int row, int col, char player ){
    display[row][col] = player;
}


void BoardDisplay::addImpr( int row, int col ){
    display[row][col] = 'I';
}

void BoardDisplay::draw(){
    for (size_t i = 0; i < B_ROWS; i++){
        for (size_t j = 0; j < B_COLS; j++){
	    std::cout << display[i][j];
        }
	std::cout << std::endl;
    }
}
