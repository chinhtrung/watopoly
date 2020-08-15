#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include "commands.h"
#include "seeds.h"
#include "positionMap.h"
#include "gamePieces.h"
#include "player.h"
#include "dice.h"
#include "transactions.h"
#include "board.h"
#include "boardDisplay.h"
#include "loadSave.h"

using namespace std;

class Board;
class Player;
class Dice;
class Transactions;

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    vector<char> pieceCharTaken;

    string command, name, give, receive, property, action, filename;

    int MAX_TIMS = 4;
    const int MAX_PLAYERS = 7;
    const int MIN_PLAYERS = 2;
    const int TUITION_POS = 4;
    const int DC_TIMS_POS = 10;

    auto b = std::make_shared<Board>();
    vector<shared_ptr<Player>> group;
    int defaultMoneyToStart = 1500;

    if ( argc > 1) { // check the number of arguments
        if (argv[1] == LOAD) {

            cout << "Loading in saved game from " << argv[2] << endl;
            
            std::ifstream inf{argv[2]};

            int numPlayers;
            inf >> numPlayers; 

            for (int i = 0; i < numPlayers; i++){
                string name;
                char gamepiece;
                int numTimsCups;
                int funds;
                int sqrPos;

                inf >> name;	
                inf >> gamepiece;
                inf >> numTimsCups;
                inf >> funds;
                inf >> sqrPos;
            
                auto p = std::make_shared<Player>(name, gamepiece, funds);
                p->setTimsCups(numTimsCups);
                b->addPlayer(gamepiece);

                if (sqrPos == DC_TIMS_POS){
                    bool inLine;
                    inf >> inLine;
                    if (inLine){
                        b->movePlayer(gamepiece, DC_TIMS_POS);
                    int turnsInLine;
                    inf >> turnsInLine;
                    p->moveToDCTims();
                    } else {
                        p->movePlayer(sqrPos); //but without collecting Go money
                        b->movePlayer(gamepiece, sqrPos);
                    }
                } else {
                    p->movePlayer(sqrPos); //but without collecting Go money
                    b->movePlayer(gamepiece, sqrPos);
                }

                group.push_back(p);
            }

            for (int i = 0; i < OWNABLE_SIZE; i++){
                string name;
                string owner;
                int imprLevel;
                inf >> name;
                inf >> owner;
                inf >> imprLevel;
            
                if (name != "BANK"){
                    int playerIndex = 0;
                    int size = group.size();
                    for (int i = 0; i < size; i++){
                        if (group[i]->getName() == name){
                            playerIndex = i;
                        }
                    }  

                    auto ls = std::make_unique<LoadSave>();
                    ls->loadProperty(name, group[playerIndex], imprLevel);
                }
            }
        }
    }
    else {
        cout << "Fail to call load or testing mode, initiate a new game" << endl;
    
        cout << "Please input the number of player for this game" << endl;
        int num = 0;
        cin >> num;
        if (cin.fail()) cin.clear();
        while (num < MIN_PLAYERS || num > MAX_PLAYERS || cin.fail()) {
            if (cin.fail()) break;
            cout << "The number of players should be between 2 and 7." << endl;
	    cout << "input number of player again" << endl;
            cin >> num;
        };
        cout << "The number of player is " << num << endl;
        for(int i = 0; i < num; i++) {
            cout << "Hey player " << i + 1 << "! Please input your name " << endl;
            string name;
            cin >> name;
	    while (name == "BANK"){
	        cout << "Sorry, you can't have the name BANK. Please input a different name." << endl;
	        cin >> name;
	    }

            if (cin.fail()) break;

            cout << "Please choose one from the available piece char to represent yourself on board ";
            showAllCharExcept(pieceCharTaken);
            char piece;
            cin >> piece;
            if (cin.fail()) {
		    break;
	    }
	    //pieceCharTaken.push_back(piece);
            while (!isGamePiece(piece) && !cin.fail()) {
                cout << "Your game piece should be one of the char here ";
                showAllCharExcept(pieceCharTaken);
                cin >> piece;
            }
            pieceCharTaken.push_back(piece);
            cout << "Hi " << name << "! Your piece is " << piece << endl;
            cout << "---------------------------------" << endl;


            auto newPlayer = make_shared<Player>(name, piece, defaultMoneyToStart);
            group.push_back(newPlayer);

            // reset game piece
            piece = ' ';
        }
    }
    
    // setup game tracker and helper method
    int currIndex = 0;
    auto currActingPlayer = group[currIndex];
    auto twoDices = make_shared<Dice>();
    int numberOfPlayer = group.size();
    bool rollThisTurn = false;
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

    while (true) {
        if (cin.fail()) break;

        currActingPlayer = group[currIndex];

        if (currActingPlayer->getBankruptStatus()) {
            currIndex = currIndex % group.size();
            continue;
        }

        if (numberOfPlayer == 1) {
            cout << "Congratulation! The winner is " << currActingPlayer->getName();
            cout << " with the total assest of " << currActingPlayer->getAssets() << endl;
            break;
        }

        cout << "Your turn " << currActingPlayer->getName();
        cout << " - your piece: " << currActingPlayer->getGamePiece() << endl;
        cout << "available commands - [\"roll\",\"next\",\"trade\",\"improve\",\"mortgage\",\"unmortgage\",\"assets\",\"all\",\"save\"]" << endl;
        cout << "Please type a command with the procedure accordingly" << endl;
        
        cin >> command;

        // load command
        if ( command == ROLL ) {
            if (rollThisTurn) {
                cout << "You rolled this turn, please make other commands" << endl;
                continue;
            }
            int availableDoubleRoll = 3;
            int rollValue;

            while (availableDoubleRoll > 0) {
                // roll two dices
		bool testMode = false;
		bool rollOverload = false;
		if (argc > 1 && (argv[1] == TESTING || argv[3] == TESTING)) {
			testMode = true;
		}
		string rollStr1 = "";
		string rollStr2 = "";
		if (testMode) {
			cin >> rollStr1 >> rollStr2;
			if (isNumber(rollStr1) && isNumber(rollStr2)) {
				int roll1 = stoi(rollStr1);
				int roll2 = stoi(rollStr2);
				rollValue = roll1 + roll2;
				rollOverload = true;
			}
		}
		if (!rollOverload) {
			twoDices->rollDice();
			cout << "Rolling your dice ........" << endl;
                	cout << "and you get " << twoDices->diceSum() << endl;
		}
                if (!twoDices->isDouble()) {
		    if (!rollOverload) {
			    rollValue = twoDices->diceSum();
		    }
                    currActingPlayer->movePlayer(rollValue);
                    b->drawBoard();
                    followRollCommand(group, currActingPlayer, testMode, b);
                    break;
                } else {
                    if (availableDoubleRoll == 1) {
                        cout << "Congrats! You have rolled double 3 time, go to Tims Line " << endl;
                        //send to jail
                        continue;
                    }
		    if (!rollOverload) {
                    	rollValue = twoDices->diceSum();
		    }
                    //acting here;
                    currActingPlayer->movePlayer(rollValue);
                    b->drawBoard();
                    followRollCommand(group, currActingPlayer, testMode, b);

                    availableDoubleRoll--;
                }
            }

            rollThisTurn = true;

        } else if ( command == NEXT) {
            if (!rollThisTurn) {
                cout << "Please roll before finishing your turn" << endl;
                continue;
            }

            currIndex += 1;
            currIndex = currIndex % group.size();
            rollThisTurn = false;

        } else if ( command == TRADE ) {

            followTradeCommand(group, currActingPlayer);

        } else if ( command == IMPROVE ) {

            followImproveCommand(group, currActingPlayer);

        } else if ( command == MORTGAGE ) {

            followMortgageCommand(currActingPlayer);

        } else if ( command == UNMORTGAGE ) {

            followUnmortgageCommand(currActingPlayer);

        } else if ( command == BANKRUPT ) {
            cout << "The bankrupt command cannot be called here" << endl;
            continue;

        } else if ( command == ASSETS ) {
            if (currActingPlayer->getCurrPos() != TUITION_POS) {
		    cout << "Your total assets are worth $";
	    	    cout << currActingPlayer->getAssets() << endl;
	    } else {
		    cout << "You may not check your assets when ";
		    cout << "paying tuition!" << endl;
	    }

            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == ALL ) {
           	
            // replace this code
            cout << "+ calling " << command << endl;
	     if (currActingPlayer->getCurrPos() != TUITION_POS) {
		    cout << "The list below shows each player, ";
		    cout << "listed by total assets." << endl;
		    for (unsigned int i = 0; i < group.size(); ++i) {
			    cout << group[i]->getName() << " ";
			    cout << group[i]->getGamePiece() << " ";
			    cout << group[i]->getAssets() << endl;
		    }
	    } else {
		    cout << "You may not check your assets when ";
		    cout << "paying tuition!" << endl;
	    }

        } else if ( command == SAVE ) {
		/*
	    string file;
	    cin >> file;
	    cout << "Saving game to " << file << endl;
	    std::ofstream outf{file};

	    int size = group.size();
	    outf << size << endl;

	    for (int i = 0; i < size; i++){
                outf << group[i]->getName() << " ";
		outf << group[i]->getGamePiece() << " ";
		outf << group[i]->getTimsCups() << " ";
		outf << group[i]->getFunds() << " ";
		outf << group[i]->getCurrPos();
		if (group[i]->getCurrPos() == DC_TIMS_POS){
		    char gp = group[i]->getGamePiece();
	            // check if player is in Line
		    // ^ (at start of game, TimsLine square is created by main,
		     bool inLine = tl->isCaptured(gp);
		     if (inLine){
		         int turnsInLine = tl->turnsInLine(gp);
		         outf << " " << 1 << " ";
		         outf << turnsInLine << endl;
		     } else {
		         outf << " " << 0 << endl;
		     }	
		} else {
		    outf << endl;
		}
	    }

	    for (int i = 0; i < OWNABLE_SIZE; i++){
	        outf << OWNABLE[i][0] << " ";
		int size = group.size();
		bool owned = false;
		for (int j = 0; j < size; j++){
		    if (group[j]->ownThisProp(OWNABLE[i][0])){
		        outf << group[j]->getName() << " ";
			owned = true;
			break;
		    }
		}
		 
		if (!owned){
		    outf << "BANK" << " ";
		}
		outf << b->getImpr(OWNABLE[i][0]) << endl;
	    }
	    */

        } else {
            cout << "Unrecognized command!" << endl;
        }
    }
}

