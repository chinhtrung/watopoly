#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <memory>
#include <iostream>
#include <vector>
#include "seeds.h"
#include "player.h"
#include "ownable.h"
#include "auction.h"
#include "academic.h"
#include "gym.h"

class Player;
class Ownable;
class Auction;
class Academic;
class Gym;

class Transactions{
    static std::vector<std::shared_ptr<Ownable>> ownedList;

  public:
    Transactions();
    
    static bool isInOwnedList(std::string nameSquare); // return true if nameSquare is already in the ownedList, false otherwise
    static bool tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive); // return true if successfully trading, false otherwise
    static bool tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive); // return true if successfully trading, false otherwise
    static bool tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive); // return true if successfully trading, false otherwise
    static bool payPlayer(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int rent); // return true if player successfully pay another player, false otherwise
    static bool payBank(std::shared_ptr<Player> from, int amt); // return true if player successfully pay the bank, false otherwise
    static bool buyProperty(std::string ownableName, std::shared_ptr<Player> buyer); // return true if player successfully buy property, false otherwise
    static bool improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own); // return true if player successfully improve their property, false otherwise
    static bool sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own); // return true if player successfully sell improve their property, false otherwise
    static bool mortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own); // return true if player successfully mortgage their property, false otherwise
    static bool unmortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own); // return true if player successfully unmortgage their property, false otherwise
    static std::shared_ptr<Ownable> pointerOfProp(std::string ownableName);
    static void addPropByAuction(std::string ownableName, std::shared_ptr<Player> buyer, int price);
};

#endif
