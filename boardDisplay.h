#ifndef _BOARD_DISPLAY_
#define _BOARD_DISPLAY_
#include <vector>
#include <iostream>

const int B_COLS = 90;
const int B_ROWS = 56;

class BoardDisplay{
    char display[B_ROWS][B_COLS];

  public:
    BoardDisplay();
    void addPlayer( int row, int col, char player);
    void addImpr( int row, int col );
    void reset();
    void draw();
};

#endif
