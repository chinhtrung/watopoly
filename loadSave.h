#ifndef _LOADSAVE_H
#define _LOADSAVE_H
#include <string>
#include <memory>
#include "player.h"
#include "ownable.h"

class Player;
class Ownable;
class Academic;
class Residence;
class Gym;
class Square;

class LoadSave{
  public:
    void loadProperty(std::string ownableName, std::shared_ptr<Player> buyer, int imprLevel);
};

#endif
