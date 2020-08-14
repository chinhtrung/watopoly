#ifndef AUCTION_H
#define AUCTION_H
#include <iostream>
#include <memory>
#include <map>
#include "player.h"
#include "ownable.h"
#include "transactions.h"

class Player;
class Ownable;
class Transactions;

class Auction{
    std::map<std::shared_ptr<Player>, int> bidLog;
    int maxBid = 0;
    int numberOfBidders;
    std::vector<std::shared_ptr<Player>> group;
    std::shared_ptr<Player> maxBidder;
    std::string ownableItem;

  public:
    Auction(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> callAtPlayer, std::string ownableItem);

    bool placeBid(std::shared_ptr<Player> from, int amt);
    void withdrawBid(std::shared_ptr<Player> from);
};

#endif
