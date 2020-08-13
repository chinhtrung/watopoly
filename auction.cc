#include "auction.h"

using namespace std;

Auction::Auction() {
	maxBid = 0;
	maxBidder = nullptr;
}

void Auction::placeBid(std::shared_ptr<Player> from, int amt) {
	bidLog.emplace(from, amt);
	if (amt > maxBid) {
		maxBid = amt;
		maxBidder = from;
	}
	return;
}

void Auction::withdrawBid(std::shared_ptr<Player> p) {
	bidLog.erase(p);
	return;
}


int Auction::getMaxBid() const {
	return maxBid;
}

shared_ptr<Player> Auction::getMaxBidder() const {
	return maxBidder;
}
