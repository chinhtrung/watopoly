#ifndef AUCTION_H
#define AUCTION_H
#include <memory>
#include <map>
#include "player.h"

class Player;

class Auction{
    std::map<std::shared_ptr<Player>, int> bidLog;
    int maxBid;
    std::shared_ptr<Player> maxBidder;

  public:
    Auction();

    void placeBid(std::shared_ptr<Player> from, int amt);
    void withdrawBid(std::shared_ptr<Player> p);
    int getMaxBid() const;
    shd::shared_ptr<Player> getMaxBidder() const;
};

#endif
