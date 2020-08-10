// pseudocode for processing player landing on square

// main has input processor for trade, improve, initializing/loading/saving game
// main also controls turns
// makes sense for main to create Transactions, whose lifetime is limited to one turn

player rolls, lands on square {
    if (sqr.owner() != player){
        if (sqr.getOwnerChar() == ""){
	    // cout << "The property is unowned! Would you like to buy or open up an auction?"
	    // cout << "Enter <buy> to buy the building and <auction> to auction"
	    if (buy){
		Transaction t;
		t.buyProperty(sqr, Player);
	    } else if (auction){
	        player.auctionProperty(sqr);
	    }
	    // buy or auction
	} else {
	    Transaction t;
	    int toPay;

	    if (sqr == Academic){
	        toPay = sqr.getTuition(); // this assumes that Academic's tuition is accurate
	    } else {
		int numBuildingsOwned = 0;
	        if (sqr == Gym){ // use dynamic casting for this
	            numBuildingsOwned = board.checkGymsOwned(sqr);
		    sqr.setDiceSum(dice.getSum());
	        } else if (sqr == Residence){
	            numBuildingsOnwed = board.checkResOwned(sqr);
	        }
		toPay = sqr.amountToPay(numBuildingsOwned);
	    }

	    // sqr stores the owner as a Player object, sqr.getOwner() returns a 
	    // shared_ptr<Player>
	    t.payRent(player, sqr.getOwner(), toPay);
	}
    }
}


during transaction, after player buys Academic property
check if player owns all properties in block
   if true, set tuition to double within Transaction class

void Transaction::buyProperty(shared_ptr<Ownable> prop, shared_ptr<Player> own){
    // own->funds -= prop.costToBuy;
    // add prop to own's ownedProperties map
    // prop.setOwner(own);
    if (prop == Academic){
	string monoBlock = prop.getMonoBlock();
	string acadName = prop.getName();
	own.acadState[monoBlock][acadName] = true;

        bool allOwned = own.checkAcad(monoBlock); //Player method
	if (allOwned){
	    prop.doubleTuition();
	}
    } 
}

bool Player::checkAcad(string monoBlock){
    for (auto &p: acadState[monoBlock]){
        if (p.second == false){
	    return false;
	}
    }
    return true;
}

// key: Monopoly block name
// value: map (key: Academic building name, value: bool isOwned by that player)
player attribute: map<string, map<string, bool isOwnedByMe>> acadState

char Square::getOwnerChar(){
    return owner.getGamePiece();
}
