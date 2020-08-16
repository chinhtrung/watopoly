#include "commands.h"

using namespace std;

// methods
void followWhenInsufficientFunds(vector<shared_ptr<Player>> group, 
		shared_ptr<Player> curPlayer, shared_ptr<Board> b, shared_ptr<Player> propOwner,
		bool payBank){
    cout << "Please select one of the available commands to increase your funds, or declare bankruptcy." << endl;
    cout << "Available commands [\"bankrupt\",\"mortage\",\"improve\"] with their according procedure" << endl;
    
    string action;
    cin >> action;

    // call other command here
    if (action == BANKRUPT)
    {
       if (!payBank){
	   curPlayer->setBankruptStatus(true);
           followBankruptCommandWithPlayer(curPlayer, propOwner);
       }
    }
    else if (action == TRADE)
    {
       followTradeCommand(group, curPlayer);
    }
    else if (action == MORTGAGE)
    {
        followMortgageCommand(curPlayer);
    }
    else if (action == IMPROVE)
    {
        followImproveCommand(group, curPlayer, b);
    }
}

void followRollCommand(vector<shared_ptr<Player>> group,
                       shared_ptr<Player> curPlayer, bool testMode,
                       shared_ptr<Board> b)
{
//    bool bankruptStatus = false;

    // inner helper function
    auto pointerOfPlayer = [group](char trackingPiece) {
        int sizeGroup = group.size();
        shared_ptr<Player> result;
        for (int i = 0; i < sizeGroup; i++)
        {
            if (group[i]->getGamePiece() == trackingPiece)
            {
                return group[i];
            }
        }
        cout << "why trackingPiece is not in this player group? hmmm..." << endl;
        // this will return empty share_ptr of player
        return result;
    };

    // we want to know if they are stepping on the ownable or unownable property to act accordingly
    string steppingSquare = curPlayer->getSquareAtCurrPos();

    if (isOwnableBlock(steppingSquare))
    { // they're on an ownable block
        // check if this block is owned by someone
        if (Transactions::isInOwnedList(steppingSquare))
        { // this property belongs to someone, pay rent
            shared_ptr<Ownable> propPointer = Transactions::pointerOfProp(steppingSquare);
            shared_ptr<Player> propOwner = pointerOfPlayer(propPointer->getOwner());

            cout << "You are stepping on " << steppingSquare << ", which belongs to ";

            if (propOwner == curPlayer)
            {
                cout << propOwner->getName() << ". That's you! No payment required." << endl;
            }
            else if (propOwner != curPlayer && !propPointer->getMortStatus())
            {
                // ^check if the property belongs to the current player and not mortgaged
                cout << propOwner->getName() << ", let's pay fee" << endl;

                if (isGym(propPointer->getName()))
                {
                    cout << "You landed on a Gym. Please roll again to calculate the fee you owe." << endl;
                    auto gym = std::dynamic_pointer_cast<Gym>(propPointer);
                    int roll = 0;
                    bool rollOverload = false;
                    string command;
                    cin >> command;
                    while (command != ROLL)
                    {
                        cout << "Sorry, you have to roll first." << endl;
                        cin >> command;
                    }

                    if (testMode)
                    {
                        std::string die1;
                        std::string die2;
                        cin >> die1;
                        if (!cin.fail() && isNumber(die1))
                        {
                            cin >> die2;
                            if (!cin.fail() && isNumber(die2))
                            {
                                roll = std::stoi(die1) + std::stoi(die2);
                                rollOverload = true;
                            }
                            gym->setRoll(roll);
                        }
                    }

                    if (!rollOverload)
                    {
                        auto twoDices = make_unique<Dice>();
                        cout << "Rolling your dice ........" << endl;
                        cout << "and you get ";
                        cout << twoDices->getDie1() << " + ";
                        cout << twoDices->getDie2() << " = ";
                        cout << twoDices->diceSum() << "!" << endl;
                        gym->setRoll(twoDices->diceSum());
                    }
                }

                // pay rent action
                while (!Transactions::payPlayer(curPlayer, propOwner, propPointer->amountToPay()))
                { //if not success paying
                    cout << "You don't have enough money to pay the rent. Please make other commands to gain more funds or \"bankrupt\" to declare bankruptcy" << endl;

                    string action;
                    cin >> action;

		    followWhenInsufficientFunds(group, curPlayer, b, propOwner, false);
                    /*// call other command here
                    if (action == BANKRUPT)
                    {
                        followBankruptCommandWithPlayer(curPlayer, propOwner);
                        bankruptStatus = true;
                        break;
                    }

                    if (action == TRADE)
                    {
                        followTradeCommand(group, curPlayer);
                    }

                    if (action == MORTGAGE)
                    {
                        followMortgageCommand(curPlayer);
                    }

                    if (action == IMPROVE)
                    {
                        followImproveCommand(group, curPlayer, b);
                    }*/
                }

		if (!curPlayer->getBankruptStatus()){
		    cout << "fee pay successfully" << endl;
		}
                //if (!bankruptStatus)
                  //  cout << "fee pay successfully" << endl;
            }
        }
        else
        { // buy or auction
            cout << "You are stepping on " << steppingSquare << ", you can buy this property!" << endl;
            cout << "type \"buy\" to buy or type anything to let the bank auction this property." << endl;
            string input;
            cin >> input;

            if (input == BUY)
            {
                while (!Transactions::buyProperty(steppingSquare, curPlayer))
                {
                    cout << "You don't have enough money to buy this property. Make command TRADE or MORTGAGE to gain more funds" << endl;
                    cout << "(type \"auction\" to stop BUYING action - the bank will auction this property)" << endl;
                    cin >> input;

                    if (input == AUCTION)
                    {
                        // run the auction command
                        followAuctionCommand(group, curPlayer, steppingSquare);
                        break;
                    }

                    if (input == TRADE)
                    {
                        followTradeCommand(group, curPlayer);
                    }

                    if (input == MORTGAGE)
                    {
                        followMortgageCommand(curPlayer);
                    }

                    if (input == IMPROVE)
                    {
                        followImproveCommand(group, curPlayer, b);
                    }
                }
                curPlayer->printOwnedProp();
            }
            else
            {
                // run the auction
                followAuctionCommand(group, curPlayer, steppingSquare);
            }
        }
    }
    else
    { // they're on an unownable block
        if (steppingSquare == "SLC"){
            cout << "You have arrived at the SLC!" << endl;
            SLC::determinePlayerPos(curPlayer);
            b->movePlayer(curPlayer->getGamePiece(), curPlayer->getCurrPos());
            b->drawBoard();
            followRollCommand(group, curPlayer, testMode, b);	
	} 
	else if (steppingSquare == "DC Tims Line"){
	    cout << "You have arrived at DC Tims Line." << endl;
            cout << "You get your coffee immediately." << endl;	
	} 
	else if (steppingSquare == "GO TO TIMS") {
	    cout << "After pulling an all-nighter, you need coffee." << endl;
            cout << "Unfortunately, the line is a mile long." << endl;
            curPlayer->moveToDCTims();	
	} 
	else if (steppingSquare == "NEEDLES HALL") {
	    cout << "You have arrived at Needles Hall." << endl;
            int changeInFunds = MonetaryServices::needlesHall(curPlayer);
            if (changeInFunds < 0){

		// if player does not have enough money
	        while (!Transactions::payBank(curPlayer, changeInFunds)){
                    cout << "Insufficient funds!" << endl;	
                    followWhenInsufficientFunds(group, curPlayer, b, nullptr, true);
                }

		if (!curPlayer->getBankruptStatus()){
		    cout << "Successfully paid!" << endl;
		}

	    } else {
	        curPlayer->addFund(changeInFunds);
	    }   
	} else {  // step on payment square
	    int payment = 0; 
	    if (steppingSquare == "TUITION"){
                payment = MonetaryServices::payTuition(curPlayer);
            } else if (steppingSquare == "COOP FEE"){
                int payment = MonetaryServices::payCoop();
	        cout << "You are assessed a $" << payment << " co-op fee." << endl;
            } else if (steppingSquare == "Goose Nesting"){
	        cout << "You are attacked by a flock of geese, but nothing ";
                cout << "else happens." << endl; 
	    }   

	    // if player does not have enough money
	    while (!Transactions::payBank(curPlayer, payment)){
	        cout << "Insufficient funds!" << endl;
	        // helper
		followWhenInsufficientFunds(group, curPlayer, b, nullptr, true);
	    }

	    if (!curPlayer->getBankruptStatus()){
	        cout << "Successfully paid!" << endl;
	    }
	} 
    }
}

// helper function
bool isNumber(string a)
{
    int size = a.size();
    string initial = "";

    for (int i = 0; i < size; i++)
    {
        char each = a[i];
        initial += each;
        try
        {
            stoi(initial);
            initial = "";
        }
        catch (invalid_argument err)
        {
            return false;
        }
    }

    return true;
}

void followTradeCommand(vector<shared_ptr<Player>> group, shared_ptr<Player> curPlayer)
{
    string receiver, offer, want;
    int sizeGroup = group.size();

    cout << "--> Please enter the name of the player you want to trade with. List of remaining players and the game piece" << endl;

    for (int i = 0; i < sizeGroup; i++) {
        if (group[i] == curPlayer) continue;
        cout << " ~> name:" << group[i]->getName() << " - piece:" << group[i]->getGamePiece() << endl;
    }

    cin >> receiver;

    shared_ptr<Player> pointerReceiver;
    bool validateReceiver = false;

    for (int i = 0; i < sizeGroup; i++)
    {
        if (group[i]->getName() == receiver)
        {
            pointerReceiver = group[i];
            validateReceiver = true;
        }
    }

    // validate this transaction
    if (!validateReceiver)
    {
        cout << "The player name doesn't exist" << endl;
        cout << "Abort trading!" << endl;
        return;
    }

    cout << "--> You are now trading with " << pointerReceiver->getName() << " <--" << endl;
    

    cout << endl;

    cout << "--> Enter the name of item or the amount of money you want to offer" << endl;
    cout << "--> here is the list of your properties" << " <--" << endl;
    int sizeListY = curPlayer->getOwnedPropList().size();
    for (int i = 0; i < sizeListY; i++) {
        cout << "~> " << curPlayer->getOwnedPropList()[i]->getName(); 
        cout << " - original cost:" << curPlayer->getOwnedPropList()[i]->getCostToBuy()  << endl;
    }

    cin >> offer;

    cout << "--> Enter the name of item or the amount of money you want to take" << endl;
    cout << "--> here is the list of properties of " << pointerReceiver->getName() << " <--" << endl;
    int sizeListR = pointerReceiver->getOwnedPropList().size();
    for (int i = 0; i < sizeListR; i++) {
        cout << "~> " << pointerReceiver->getOwnedPropList()[i]->getName(); 
        cout << " - original cost:" << pointerReceiver->getOwnedPropList()[i]->getCostToBuy()  << endl;
    }

    cin >> want;

    if (isNumber(offer) && isNumber(want))
    {
        cout << "*** Please don't offer money for money ***" << endl;
        return;
    }

    if ( !isNumber(offer))
    {
        if (!isOwnableBlock(offer)) 
        {
            cout << "*** Your offer item is not either a property or money ***" << endl;
            cout << "--> Abort trading! <--" << endl;
            return;
        }
    }

    if (!isNumber(want))
    {
        if (!isOwnableBlock(want)) 
        {
            cout << "*** Your wanted item is not either a property or money ***" << endl;
            cout << "--> Abort trading! <--" << endl;
            return;
        }
    }

    string permission;
    cout << "========================= IMPORTANT =========================" << endl;
    cout << "--> " << curPlayer->getName() << " wants to trade "<< offer << " with "; 
    cout << pointerReceiver->getName() << " for " << want << " <--" << endl;
    cout << "Hi " << pointerReceiver->getName() <<"! please type YES to make the transaction, type otherwise to cancel" << endl;
    cout << "=============================================================" << endl;
    cin >> permission;

    if (permission != "YES") {
        cout << "--> This trading action has been cancel by " << pointerReceiver->getName() << " <--" << endl;
        return;
    }


    if (isNumber(offer))
    {
        if (!Transactions::tradeMforP(curPlayer, pointerReceiver, stoi(offer), Transactions::pointerOfProp(want)))
        {
            cout << "--> Abort trading! <--" << endl;
        }
        return;
    }

    if (isNumber(want))
    {
        if (!Transactions::tradePforM(curPlayer, pointerReceiver, Transactions::pointerOfProp(offer), stoi(want)))
        {
            cout << "--> Abort trading! <--" << endl;
        }
        return;
    }

    if (!Transactions::tradePforP(curPlayer, pointerReceiver, Transactions::pointerOfProp(offer), Transactions::pointerOfProp(want)))
    {
        cout << "--> Abort trading! <--" << endl;
        return;
    }
}

void followImproveCommand(vector<shared_ptr<Player>> group, shared_ptr<Player> curPlayer,
                          std::shared_ptr<Board> b)
{
    string property, action;

    cout << "--> Hi " << curPlayer->getName() << " please choose your property to improve <--" << endl;
    int sizeListY = curPlayer->getOwnedPropList().size();
    if (sizeListY == 0) {
        cout << "--> You don't have any property to make improvement <--" << endl;
        cout << "--> Abort Improvement action! <--" << endl;
        return;
    }
    cout << "--> here is the list of your properties" << " <--" << endl;
    for (int i = 0; i < sizeListY; i++) {
        cout << "~> " << curPlayer->getOwnedPropList()[i]->getName(); 
        cout << " - original cost:" << curPlayer->getOwnedPropList()[i]->getCostToBuy()  << endl;
    }

    cin >> property;

    cout << "--> please type in \"buy\" or \"sell\" action" << endl;

    cin >> action;

    while (true) {
        if (action == BUY || action == SELL || cin.fail()) break;
        cout << "--> unregconize action for improvement command! <--" << endl;
        cout << "--> please type in \"buy\" or \"sell\" action" << endl;
        cin >> action;
    }

    shared_ptr<Ownable> pointerProperty;

    if (!Transactions::isInOwnedList(property))
    {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort buying/selling improvement!" << endl;
        return;
    }
    else
    {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (action == BUY)
    {
        if (!Transactions::improveProperty(pointerProperty, curPlayer))
        {
            cout << "Abort buying/selling improvement!" << endl;
        }
        else
        {
            b->addImpr(pointerProperty->getName());
            b->drawBoard();
        }
    }
    else if (action == SELL)
    {
        if (!Transactions::sellImprove(pointerProperty, curPlayer))
        {
            cout << "Abort buying/selling improvement!" << endl;
        }
        else
        {
            b->removeImpr(pointerProperty->getName());
            b->drawBoard();
        }
    }
    else
    {
        cout << "Unregconized action command" << endl;
        cout << "Abort buying/selling improvement!" << endl;
    }
}

void followMortgageCommand(shared_ptr<Player> curPlayer)
{
    string property;
    cin >> property;

    shared_ptr<Ownable> pointerProperty;

    if (!Transactions::isInOwnedList(property))
    {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort mortgage action!" << endl;
        return;
    }
    else
    {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (!Transactions::mortgageProperty(pointerProperty, curPlayer))
    {
        cout << "Abort mortgage action!" << endl;
    }
}

void followUnmortgageCommand(shared_ptr<Player> curPlayer)
{
    string property;
    cin >> property;

    shared_ptr<Ownable> pointerProperty;

    if (!Transactions::isInOwnedList(property))
    {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort unmortgage action!" << endl;
        return;
    }
    else
    {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (!Transactions::unmortgageProperty(pointerProperty, curPlayer))
    {
        cout << "Abort unmortgage action!" << endl;
    }
}

void followAuctionCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer, std::string ownableItem)
{
    // make new auction
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "The BANK is now running auction on " << ownableItem << " property" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Each player is now asked for bidding decision" << endl << endl;

    // setup before bidding
    auto newAuction = make_shared<Auction>(group, curPlayer, ownableItem);
    int curIndexPlayer = 0; // current bidder
    int sizeGroup = group.size();
    int numberOfBidder = sizeGroup;
    vector<bool> trackingGiveUpBid;
    for (int i = 0; i < sizeGroup; i++)
    {
        trackingGiveUpBid.push_back(false);
        if (group[i] == curPlayer)
        {
            curIndexPlayer = i;
        }
    }
    // we want a person who is next to the one calling auction bid first
    curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
    bool nextBidder = true;

    string action; // can choose between RAISE/WITHDRAW
    while (true)
    {
        string curPlayerName = group[curIndexPlayer]->getName();

        if (numberOfBidder == 1) {
            cout << "Congratulation! You won this bidding section " << curPlayerName << endl;
            break;
        }

        
        if (trackingGiveUpBid[curIndexPlayer])
        {
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
            continue;
        }

        if (nextBidder) {
            cout << "----------> $$$ -------------> Property ----------------> $$$$$$" << endl;
            cout << "The current bidding player is " << curPlayerName << endl;
            cout << "----------------------------------------------------------------" << endl << endl;
            nextBidder = false;
        }
        
        cout << "--> Please choose your action \"raise\" or \"withdraw\" for the bid " << curPlayerName << endl;
        cin >> action;
        if (cin.fail()) break; 

        if (action == RAISE)
        {
            std::string amount;
            cout << "--> please enter the amount you want to bid" << endl;
            cin >> amount;
            while (!isNumber(amount))
            {
                cout << "--> The bidding amount have to be a number" << endl;
                cout << "--> Please enter the amount you want to raise " << curPlayerName << endl;
                cin >> amount;
            }

            if (!newAuction->placeBid(group[curIndexPlayer], stoi(amount))) {
                cout << "--> Bid has not been placed, please try \"raise\" again or type \"withdraw\" to withdraw from auction " << curPlayerName << endl;
                continue;
            }
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
            nextBidder = true;
        }
        else if (action == WITHDRAW)
        {
            newAuction->withdrawBid(group[curIndexPlayer]);
            trackingGiveUpBid[curIndexPlayer] = true;
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
            nextBidder = true;
            numberOfBidder--;
        }
        else
        {
            cout << "unregconized action for bidding, the BANK will be prompted to ask you again" << endl << endl;
        }
    }
}

void followBankruptCommandWithPlayer(std::shared_ptr<Player> curPlayer, std::shared_ptr<Player> toPlayer)
{
    curPlayer->setBankruptStatus(true);

    // take all their funds
    toPlayer->addFund(curPlayer->getFunds());

    // take all their property and re-set the owner
    vector<shared_ptr<Ownable>> propListToTransfer = curPlayer->getOwnedPropList();
    int sizeList = propListToTransfer.size();
    for (int i = 0; i < sizeList; i++)
    {
        toPlayer->addProp(propListToTransfer[i]);
        propListToTransfer[i]->setOwner(toPlayer->getGamePiece());
    }
}

void followBankruptCommandWithBank(std::shared_ptr<Player> curPlayer)
{
}
