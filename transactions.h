#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <memory>
#include <iostream>
#include <vector>
#include "utility/seeds.h"
#include "player.h"
#include "ownable.h"

class Player;
class Ownable;

class Transactions{
  public:
    Transactions();
    
    static void tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive);
    static void tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive);
    static void tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive);
    static void payPlayer(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int rent);
    static void payBank(std::shared_ptr<Player> from, int amt);
    static void buyProperty(std::string ownableName, std::shared_ptr<Player> buyer);
    static void improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    static void sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    static void mortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    static void unmortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    static void actingAtCurrentPosition(std::shared_ptr<Player> own);
};

#endif
