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

void BoardDisplay::reset(){
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

void BoardDisplay::addPlayer( int x, int y, char player ){
    display[x][y] = player;
}


void BoardDisplay::addImpr( int x, int y ){
    display[x][y] = 'I';
}

void BoardDisplay::draw(){
    for (size_t i = 0; i < B_HEIGHT; i++){
        for (size_t j = 0; j < B_WIDTH; j++){
	    std::cout << display[i][j];
        }
	std::cout << std::endl;
    }
}
