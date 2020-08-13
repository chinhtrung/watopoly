#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <memory>
#include <iostream>
#include <vector>
#include "player.h"
#include "ownable.h"

class Player;
class Ownable;

class Transactions{
  public:
    Transactions();
    
    void tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive);
    void tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive);
    void tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive);
    void payPlayer(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int rent);
    void payBank(std::shared_ptr<Player> from, int amt);
    void buyProperty(std::string ownableName, std::shared_ptr<Player> buyer);
    void improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    void sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    void mortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own);
    void unmortgageProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own); 
};

#endif
