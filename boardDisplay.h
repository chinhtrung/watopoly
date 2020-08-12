#ifndef _BOARD_DISPLAY_
#define _BOARD_DISPLAY_
#include <vector>

class BoardDisplay{
    std::vector<std::vector<char>> display;

  public:
    BoardDisplay();
    void addPlayer( int x, int y, char player);
    void addImpr( int x, int y );
    void reset();
    void draw();
};

#endif
