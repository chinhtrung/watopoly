// pseudocode for processing player landing on square

// main has input processor for trade, improve, initializing/loading/saving game
// main also controls turns
// makes sense for main to create Transactions, whose lifetime is limited to one turn

player rolls, lands on square {
    if (sqr.owner() != player){
        if (sqr.getOwnerChar() == ""){
	    cout << "The property is unowned!\n";
	    cout << "Would you like to buy or open up an auction?\n";
	    cout << "Enter <buy> to buy the building and <auction> to auction" << endl;
	    
	    if (buy){
		Transaction t;
		t.buyProperty(sqr, Player);
		// ^if this fails bc of insufficient funds, go to auction
	    } else if (auction){
	        player.auctionProperty(sqr);
	    }
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

//////////////////////////////////////////////////////////////////////

main reading in # of players {
    Board gb();
    int numPlayers = 0;
    cout << "Please enter the number of players, from 2 - 8.\n";
    cin >> numPlayers;
    if (numPlayers < 2 || numPlayers > 8){
        cout << "Invalid number of players. Try again." << endl;
    }
    cout << "Your choices of gamepiece characters are: \n";
    cout << "G, B, D, P, $, L, T\n";
    cout << "Enter each player name followed by their gamepiece character.";
    for (int i = 0; i < numPlayers; i++){
        string name;
	char gamepiece;
	cin >> name; //do exception handling
	cin >> gamepiece;
	shared_ptr<Player> p(new Player(name, gamepiece));
	gb.addPlayer(p);
    }
}
