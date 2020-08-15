#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "square.h"
#include "ownable.h"
#include "seeds.h"
#include "positionMap.h"

class Square;
class Ownable;
class GameState;

class Player {
    std::string name;
    char gamePiece;
    int funds;
    int pos = 0;
    int timsCups = 0;
    bool bankruptStatus = false;
    bool inJail = false;
    int numResOwned = 0;
    int numGymOwned = 0;
    std::vector<std::shared_ptr<Ownable>> ownedProperties;
    std::vector<std::string> monopolyBlocks; // ie: {"Sci1", "Math", "Eng"}

  public:
    Player(std::string name, char gamePiece, int funds);

    bool checkIfInMonopolyBlock(std::string squareName); // return true the square is inside the monopoly block own by this player
    bool ownThisProp(std::string squareName); // return true if the square is owned by this player
    bool addFund(int amt); // return true if player successfully add fund
    bool payFund(int amt); // return true if player successfully pay fund
    bool addProp(std::shared_ptr<Ownable> prop); // return true if player successfully add property (side effect: add props to improvement and set the value as 0)
    bool removeProp(std::shared_ptr<Ownable> prop); // return true if player successfully remove property (can remove only the associate key in improvement is 0 )
    bool mortageProp(std::shared_ptr<Ownable> prop); // return true if player successfully mortgage property
    bool unmortageProp(std::shared_ptr<Ownable> prop); // return true if player successfully unmortgage property
    char getGamePiece() const;
    std::string getName() const;
    std::string getSquareAtCurrPos();
    int getCurrPos() const;
    int getFunds() const;
    int getAssets() const;
    void movePlayer(int roll);
    void moveToDCTims();
    void setPos(int pos);
    void addTimsCup();
    void setTimsCups(int cups);  // used when loading from a game
    int getTimsCups();
    void setBankruptStatus(bool status);
    bool getBankruptStatus();
    std::vector<std::shared_ptr<Ownable>> getOwnedPropList();
    void updateMonopolyBlock(); // used when adding new properties
    void removeGym(); //decreases numGymOwned by 1
    void removeRes(); // decreases numResOwned by 1
    void addGym();  // increases numGymOwned by 1
    void addRes();  // increases numResOwned by 1

    static bool loadFromSave(std::string saveFile); // return true if successfully load saved game
    static bool saveGame(std::string saveFile); // write game state to saveFile, return true if successfully save
};

#endif
