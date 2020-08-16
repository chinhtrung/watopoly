#include "auction.h"

using namespace std;

Auction::Auction(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> callAtPlayer, std::string ownableItem) {
	this->group = group;
	this->ownableItem = ownableItem;
	this->maxBidder = callAtPlayer;
	numberOfBidders = group.size();
	bidLog[callAtPlayer] = 0; // at initial bid
}

bool Auction::placeBid(shared_ptr<Player> from, int amt) {
	// only allow player bid when the amt higher than the maxBid
	if (amt <= maxBid) {
		cout << "--> You should bid higher than the current bid" << endl;
		return false;
	}

	// check if the player has enough money to bid that amt
	if (from->getFunds() < amt) {
		cout << "--> You don't have enough fund to bid the current amount" << endl;
		return false;
	}

	bidLog[from] = amt;
	maxBid = amt;
	maxBidder = from;
	cout << "***** Congratulation! New bid is set *****" << endl;
	cout << from->getName() << " beast the recent bid for " << ownableItem <<" with " << "$" << amt  << ". Who next?" << endl << endl;
	return true;
}

// assume player(from) has not yet withdraw
void Auction::withdrawBid(shared_ptr<Player> from) {
	cout << "--> The player " << from->getName() << " withdraw from the bid" << endl << endl;
	bidLog.erase(from);
	numberOfBidders -= 1;

	// check if there is the last player in the bool to declare a bid winner
	if (bidLog.size() == 1 && numberOfBidders == 1) {
		for (auto &bid: bidLog) {
			cout << "$$$$$ Congratulation $$$$$ -->";
			cout << bid.first->getName() << " win the property " << ownableItem << " with $" << bid.second << "<--" << endl << endl;
			// process to buy this prop and finish
			Transactions::addPropByAuction(ownableItem, bid.first, bid.second);
			cout << bid.first->getName() << " now own " << ownableItem << endl;
		}

		return;
	}

	// reset the maxBidder and the maxBid
	int newLocalMaxBid = 0;
	std::shared_ptr<Player> curMaxBidder;
	for (auto &bid: bidLog) {
		if (bid.second > newLocalMaxBid) {
			newLocalMaxBid = bid.second;
			curMaxBidder = bid.first;
		}
	}
	maxBid = newLocalMaxBid;
	maxBidder = curMaxBidder;



	cout << "==> The current highest bid is " << maxBid << " by " << maxBidder->getName() << endl;
	return;
}
