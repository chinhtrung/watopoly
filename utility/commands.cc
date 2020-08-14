#include "commands.h"

using namespace std;

// methods
void followRollCommand(vector<shared_ptr<Player>> group, shared_ptr<Player> curPlayer) {
    bool bankruptStatus = false;

    // inner helper function
    auto pointerOfPlayer = [group] (char trackingPiece) {
        int sizeGroup = group.size();
        shared_ptr<Player> result;
        for (int i = 0; i < sizeGroup; i++) {
            if (group[i]->getGamePiece() == trackingPiece) {
                return group[i];
            }
        }
        cout << "why trackingPiece is not in this player group? hmmm..." << endl;
        // this will return empty share_ptr of player
        return result;
    };

    // we want to know if they are stepping on the ownable or unownable property to act accordingly
    string steppingSquare = curPlayer->getSquareAtCurrPos();

    if (isOwnableBlock(steppingSquare)) { // they're on an ownable block
        // check if this block is owned by someone
        if (Transactions::isInOwnedList(steppingSquare)) { // this property belongs to someone, pay rent
            shared_ptr<Ownable> propPointer = Transactions::pointerOfProp(steppingSquare);
            shared_ptr<Player> propOwner = pointerOfPlayer(propPointer->getOwner());

            cout << "You are stepping on " << steppingSquare << ", which belongs to ";

            if (propOwner != curPlayer) { // check if the property belongs to the current player
                cout << propOwner->getName() << ", let's pay fee" << endl;

                // pay rent action
                while (!Transactions::payPlayer(curPlayer, propOwner, propPointer->amountToPay())) { //if not success paying
                    cout << "You don't have enough money to pay the rent. Please make other commands to gain more funds or \"bankrupt\" to declare bankruptcy" << endl;
                    cout << "Available commands [\"bankrupt\",\"mortage\",\"improve\"] with their according procedure"<< endl;
                    string action;
                    cin >> action;

                    // call other command here
                    if (action == BANKRUPT) {
                        followBankruptCommandWithPlayer(curPlayer, propOwner);
                        bankruptStatus = true;
                        break;
                    }

                    if (action == TRADE) {
                        followTradeCommand(group, curPlayer);
                    }

                    if (action == MORTGAGE) {
                        followMortgageCommand(curPlayer);
                    }

                    if (action == IMPROVE) {
                        followImproveCommand(group, curPlayer);
                    }

                }

                if (!bankruptStatus) cout << "fee pay successfully" << endl;

            } else {
                cout << "you! You're good to go" << endl;
            }

        } else { // buy or auction
            cout << "You are stepping on " << steppingSquare << ", you can buy this property!" << endl;
            cout << "type \"buy\" to buy or type anything to let the bank auction this property." << endl;
            string input;
            cin >> input;

            if (input == BUY) {
                while (!Transactions::buyProperty(steppingSquare, curPlayer)) {
                    cout << "You don't have enough money to buy this property. Make command TRADE or MORTGAGE to gain more funds" << endl;
                    cout << "(type \"auction\" to stop BUYING action - the bank will auction this property)" << endl;
                    cin >> input;

                    if (input == AUCTION) {
                        // run the auction command
                        followAuctionCommand(group, curPlayer, steppingSquare);
                        break;
                    }

                    if (input == TRADE) {
                        followTradeCommand(group, curPlayer);
                    }

                    if (input == MORTGAGE) {
                        followMortgageCommand(curPlayer);
                    }

                    if (input == IMPROVE) {
                        followImproveCommand(group, curPlayer);
                    }
                }
            } else {
                // run the auction
                followAuctionCommand(group, curPlayer, steppingSquare);
            }
        }

    } else { // they're on an unownable block
        
        
    }

}

// helper function
bool isNumber(string a) {
    int size = a.size();
    string initial = "";

    for (int i = 0; i < size; i++) {
        char each = a[i];
        initial += each;
        try {
            stoi(initial);
            initial = "";
        } catch (invalid_argument err) {
            return false;
        }
    }

    return true;
}

void followTradeCommand(vector<shared_ptr<Player>> group, shared_ptr<Player> curPlayer) {
    string receiver, offer, want;
    cin >> receiver >> offer >> want;
    shared_ptr<Player> pointerReceiver;
    bool validateReceiver = false;

    int sizeGroup = group.size();
    for (int i = 0; i < sizeGroup; i++) {
        if (group[i]->getName() == receiver) {
            pointerReceiver = group[i];
            validateReceiver = true;
        }
    }

    // validate this transaction
    if (!validateReceiver) {
        cout << "The player name doesn't exist" << endl;
        cout << "Abort trading!" << endl;
        return;
    }

    if (isNumber(offer) && isNumber(want)) {
        cout << "Please don't offer money for money" << endl;
        cout << "Abort trading!" << endl;
        return;
    }

    if (!isOwnableBlock(offer) && !isNumber(offer)) {
        cout << "Your offer item is not either a property or money" << endl;
        cout << "Abort trading!" << endl;
        return;
    }

    if (!isOwnableBlock(want) && !isNumber(want)) {
        cout << "Your wanted item is not either a property or money" << endl;
        cout << "Abort trading!" << endl;
        return;
    }

    if (isNumber(offer)) {
        if (!Transactions::tradeMforP(curPlayer, pointerReceiver, stoi(offer), Transactions::pointerOfProp(want))) {
            cout << "Abort trading!" << endl;
            return;
        }
    }

    if (isNumber(want)) {
        if (!Transactions::tradePforM(curPlayer, pointerReceiver, Transactions::pointerOfProp(offer), stoi(want))) {
            cout << "Abort trading!" << endl;
            return;
        }
    }

    if (!Transactions::tradePforP(curPlayer, pointerReceiver, Transactions::pointerOfProp(offer), Transactions::pointerOfProp(want))) {
        cout << "Abort trading!" << endl;
        return;
    }

}

void followImproveCommand(vector<shared_ptr<Player>> group, shared_ptr<Player> curPlayer) {
    string property, action;
    cin >> property >> action;

    shared_ptr<Ownable> pointerProperty;

    if(!Transactions::isInOwnedList(property)) {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort buying/selling improvement!" << endl;
        return;
    } else {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (action == BUY) {
        if (!Transactions::improveProperty(pointerProperty, curPlayer)) {
            cout << "Abort buying/selling improvement!" << endl;
        }
    } else if (action == SELL) {
        if (!Transactions::sellImprove(pointerProperty, curPlayer)) {
            cout << "Abort buying/selling improvement!" << endl;
        }
    } else {
        cout << "Unregconized action command" << endl;
        cout << "Abort buying/selling improvement!" << endl;
    }
}

void followMortgageCommand(shared_ptr<Player> curPlayer) {
    string property;
    cin >> property;

    shared_ptr<Ownable> pointerProperty;

    if(!Transactions::isInOwnedList(property)) {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort mortgage action!" << endl;
        return;
    } else {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (!Transactions::mortgageProperty(pointerProperty, curPlayer)) {
        cout << "Abort mortgage action!" << endl;
    }
}

void followUnmortgageCommand(shared_ptr<Player> curPlayer) {
    string property;
    cin >> property;

    shared_ptr<Ownable> pointerProperty;

    if(!Transactions::isInOwnedList(property)) {
        cout << "The player doesn't own this property or this property doesn't exist" << endl;
        cout << "Abort unmortgage action!" << endl;
        return;
    } else {
        pointerProperty = Transactions::pointerOfProp(property);
    }

    if (!Transactions::unmortgageProperty(pointerProperty, curPlayer)) {
        cout << "Abort unmortgage action!" << endl;
    }
}

void followAuctionCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer, std::string ownableItem) {
    // make new auction
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "The BANK is now running auction on " << ownableItem << " property" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Each player is now asked for bidding decision" << endl;
    
    // setup before bidding
    auto newAuction = make_shared<Auction>(group, curPlayer, ownableItem);
    int curIndexPlayer = 0; // current bidder
    int sizeGroup = group.size();
    int numberOfBidder = sizeGroup;
    vector<bool> trackingGiveUpBid;
    for (int i = 0; i < sizeGroup; i++) {
        trackingGiveUpBid[i] = false;
        if (group[i] == curPlayer) {
            curIndexPlayer = i;
        }
    }
    // we want a person who is next to the one calling auction bid first
    curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;

    string action; // can choose between RAISE/WITHDRAW
    while (numberOfBidder == 1) {
        if (trackingGiveUpBid[curIndexPlayer]) {
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
            continue;
        }

        string curPlayerName = group[curIndexPlayer]->getName();
        cout << "The current bidding player is " << curPlayerName << endl;
        cout << "Please choose your action \"raise <amount>\" or \"withdraw\" for the bid " << endl;
        cin >> action;

        if ( action == RAISE ) {
            std::string amount;
            cin >> amount;
            while (!isNumber(amount) || ) {
                cout << "The bidding amount have to be a number" << endl;
                cout << "Please enter the amount you want to raise " << curPlayerName << endl;
                cin >> amount;
            }
            while (!newAuction->placeBid(group[curIndexPlayer], stoi(amount))) {
                cout << "Bid has not been placed, please try another amount or type \"withdraw\" to withdraw from auction " << endl;
                cin >> amount;

                if (amount == WITHDRAW) {
                    newAuction->withdrawBid(group[curIndexPlayer]);
                    trackingGiveUpBid[curIndexPlayer] = true;
                    numberOfBidder--;
                    break;
                }
            }
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
        } else if ( action == WITHDRAW) {
            newAuction->withdrawBid(group[curIndexPlayer]);
            trackingGiveUpBid[curIndexPlayer] = true;
            curIndexPlayer = (curIndexPlayer + 1) % sizeGroup;
            numberOfBidder--;
        } else {
            cout << "unregconized action for bidding, the BANK will be prompted to ask you again" << endl;
        }
    }
}

void followBankruptCommandWithPlayer(std::shared_ptr<Player> curPlayer, std::shared_ptr<Player> toPlayer) {
    curPlayer->setBankruptStatus(true);

    // take all their funds
    toPlayer->addFund(curPlayer->getFunds());
    
    // take all their property and re-set the owner
    vector<shared_ptr<Ownable>> propListToTransfer = curPlayer->getOwnedPropList();
    int sizeList = propListToTransfer.size();
    for (int i = 0; i < sizeList; i++) {
        toPlayer->addProp(propListToTransfer[i]);
        propListToTransfer[i]->setOwner(toPlayer->getGamePiece());
    }
}

void followBankruptCommandWithBank(std::shared_ptr<Player> curPlayer) {
    
}
