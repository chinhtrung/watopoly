#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <map>
#include <memory>
#include "square.h"
#include "ownable.h"
#include "gameState.h"

class Square;
class Ownable;
class GameState;

class Player {
    std::string name;
    char gamePiece;
    int pos;
    int funds;
    int timsCups;
    std::map<int, std::shared_ptr<Square>> ownedProperties;
    std::map<int, std::shared_ptr<Square>> mortgagedProperties;

  public:
    Player(std::string name, char gamePiece, int pos, int funds, int timsCups, std::map<int, 
    std::shared_ptr<Square>> ownedProperties, std::map<int, std::shared_ptr<Square>> mortgagedProperties);

    std::string getName() const;
    char getGamePiece() const;
    int getCurrPos() const;
    int getFunds() const;
    int getAssets() const;
    void movePlayer(int roll);
    void moveToTims();
    void declareBankruptcy();
    void auctionProperty(std::shared_ptr<Ownable> ptr);
    void loadFromSave(std::shared_ptr<GameState> ptr);
};

#endif
