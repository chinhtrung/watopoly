#ifndef SQUARE_H
#define SQUARE_H
#include <string>

class Square{
    int ID;
    std::string name;
  public:
    Square();

    void drawSqr();
    int getID();
    std::string getName();
};

#endif
