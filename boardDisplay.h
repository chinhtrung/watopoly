#ifndef _BOARD_DISPLAY_
#define _BOARD_DISPLAY_
#include <vector>

class BoardDisplay{
    std::vector<std::vector<char>> display;

  public:
    BoardDisplay();
    void movePlayer( int oldX, int oldY, int newX, int newY, char player);
    void addImpr( int x, int y );
    void removeImpr( int x, int y );

    friend std::ostream &operator<<(std::ostream &out, const BoardDisplay &td);
};

// Outputs the display
std::ostream &operator<<(std::ostream &out, const BoardDisplay &td);

#endif
