#ifndef _LOADSAVE_H
#define _LOADSAVE_H
#include <string>
#include <memory>

class Player;
class Square;
class Ownable;
class Academic;
class Residence;
class Gym;
class Transactions;

class LoadSave{
  public:
    static void loadProperty(std::string ownableName, std::shared_ptr<Player> buyer, int imprLevel);
};

#endif
