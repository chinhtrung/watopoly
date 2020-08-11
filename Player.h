#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "square.h"
#include "ownable.h"
#include "gameState.h"
#include "./utility/seeds.h"

class Square;
class Ownable;
class GameState;

class Player {
    std::string name;
    char gamePiece;
    int pos;
    int funds;
    int timsCups;
    std::vector<std::string> ownedProperties;
    std::map<std::string, int> improvements; // ie: {"MC": 0, "DC": 5}
    std::vector<std::string> mortgagedProperties;
    std::vector<std::string> monopolyBlocks;

  public:
    Player(std::string name, char gamePiece, int pos, int funds, int timsCups);

    bool checkIfInMonopolyBlock(std::string squareName); // return true the square is inside the monopoly block own by this player
    bool ownThisProp(std::string squareName); // return true if the square is owned by this player
    bool addFund(int amt); // return true if player successfully add fund
    bool payFund(int amt); // return true if player successfully pay fund
    bool addProp(std::string squareName); // return true if player successfully add property (side effect: add props to improvement and set the value as 0)
    bool removeProp(std::string squareName); // return true if player successfully remove property (can remove only the associate key in improvement is 0 )
    bool mortageProp(std::string squareName); // return true if player successfully mortgage property
    bool unmortageProp(std::string squareName); // return true if player successfully unmortgage property
    bool checkPropMortgage(std::string squareName); // return true if player has this property morgated
    char getGamePiece() const;
    std::string getName() const;
    int getCurrPos() const;
    int getFunds() const;
    int getAssets() const;
    void movePlayer(int roll);
    void moveToTims();
    void declareBankruptcy();
    void auctionProperty(std::shared_ptr<Ownable> ptr);
    void loadFromSave(std::shared_ptr<GameState> ptr);
    void updatePlayer();
};

#endif
