#include "auction.h"

using namespace std;

Auction::Auction(string ownableItem, std::shared_ptr<Player> callAtPlayer) : ownableItem{ownableItem}, maxBidder{callAtPlayer} {
	bidLog[callAtPlayer] = 0;
}

bool Auction::placeBid(shared_ptr<Player> from, int amt) {
	// only allow player bid when the amt higher than the maxBid
	if (amt <= maxBid) {
		cout << "You should bid higher than the current bid" << endl;
		return false;
	}

	// check if the player has enough money to bid that amt
	if (from->getFunds() < amt) {
		cout << "You don't have enough fund to bid the current amount" << endl;
		return false;
	}

	bidLog[from] = amt;
	maxBidder = from;
	cout << from->getName() << " current bid " << amt << endl;
	return true;
}

void Auction::withdrawBid(shared_ptr<Player> from) {
	cout << "The player " << from->getName() << " withdraw from the bid" << endl;
	bidLog.erase(from);

	// check if there is the last player in the bool to declare a bid winner
	if (bidLog.size() == 1) {
		for (auto &bid: bidLog) {
			cout << bid.first << " win the property " << ownableItem << " with the price " << bid.second << endl;
			// process to buy this prop and finish
			Transactions::addPropByAuction(ownableItem, bid.first, bid.second);
			cout << bid.first << " now own " << ownableItem << endl;
		}

		return;
	}

	// reset the maxBidder and the maxBid
	int newMax = 0;
	std::shared_ptr<Player> curMaxBidder;
	for (auto &bid: bidLog) {
		if (bid.second > newMax) {
			newMax = bid.second;
			curMaxBidder = bid.first;
		}
	}
	maxBid = newMax;
	maxBidder = curMaxBidder;

	cout << "The current highest bid is " << maxBid << " by " << maxBidder << endl;
	return;
}
