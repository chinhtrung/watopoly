#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "utility/commands.h"
#include "utility/seeds.h"
#include "utility/positionMap.h"
#include "utility/gamePieces.h"
#include "player.h"
#include "dice.h"

using namespace std;

class Player;
class Dice;
// Used C++ Reference Pages cplusplus.com, en.cppreference.com, 
// https://medium.com/prodopsio/
//   solving-git-merge-conflicts-with-vim-c8a8617e3633

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    vector<char> pieceCharTaken;

    string command, name, give, receive, property, action, filename;

    const int MAX_TIMS = 4;
    const int MAX_PLAYERS = 7;
    const int MIN_PLAYERS = 2;
    const int DC_TIMS_POS = 10;

    vector<shared_ptr<Player>> group;
    int defaultMoneyToStart = 1500;

    if ( argc > 1) { // check the number of arguments
        if (argv[1] == LOAD) {

	    cout << "Loading in saved game from " << argv[2] << endl;
	    
	    std::ifstream inf{argv[2]};

	    int numPlayers;
	    inf >> numPlayers; 
	    //auto board = std::make_unique<Board>;
	    //create squares?

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
		p->setTimsCup(numTimsCups);
		//b.addPlayer(gamepiece);

		if (sqrPos == DC_TIMS_POS){
		    bool inLine;
		    inf >> inLine;
		    if (inLine){
		        //b.movePlayer(gamepiece, DC_TIMS_POS);
			int turnsInLine;
			inf >> turnsInLine;
			p->moveToDCTims();
		    } else {
		        p->movePlayer(sqrPos); //but without collecting Go money
		    }
		} else {
		    p->movePlayer(sqrPos); //but without collecting Go money
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
		    int playerIndex;
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

        if (argv[1] == TESTING) {
            cout << "+ calling from arguments " << argv[1]; 
            cout << ": testing mode enable" << endl;
            cout << "Welcome to WATOPOLY testing mode!" << endl;
            char cmd;
            string name;
            char gamePiece;
            cout << "Enter a name for your player." << endl;
            cin >> name;
	    while (true) {
            	cout << "Select your game piece for the test from the set ";
            	showAllCharExcept(pieceCharTaken);
            	cin >> gamePiece;
		if (gamePiece == 'G' || gamePiece == 'B' || gamePiece == 'D'
				|| gamePiece == 'P' || gamePiece == 'S'
				|| gamePiece == '$' || gamePiece == 'L'
				|| gamePiece == 'T') {
			break;
		}
		cout << "Invalid Game Piece" << endl;
	    }
            auto player = make_shared<Player>(name, gamePiece, 
			    defaultMoneyToStart);
            while (true) {
                cout << "Your current position is ";
                cout << player->getCurr
                cout << "Enter q if you wish to quit ";
                cout << "testing mode." << endl;
                cout << "Enter any other character otherwise." << endl;
                cin >> cmd;
                if (cmd == 'q') {
                    cout << "You have quit testing mode." << endl;
                    break;
                }
                cout << player->getSquareAtCurrPos() << endl;
                cout << "Enter roll <d1> <d2>, where d1 and d2 ";
                cout << "are the rolls, which must be ";
                cout << "non-negative integers." << endl;
                string roll;
                int d1;
                int d2;
                cin >> roll >> d1 >> d2;
                if (roll != "roll" || d1 < 0 || d2 < 0) {
                    cout << "Invalid Roll" << endl;
                } else {
                    int roll = d1 + d2;
                    movePlayer(roll);
                }
            }
    } else {
        cout << "Fail to call load or testing mode, initiate a new game" << endl;
        cout << "Please input the number of player for this game" << endl;
        int num = 0;
        cin >> num;
        if (cin.fail()) cin.clear();
        while (num < 1 || num > 7 || cin.fail()) {
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


            /*auto newPlayer = make_shared<Player>(name, piece, defaultMoneyToStart);
            group.push_back(newPlayer);

            // reset game piece
            piece = ' ';*/
        }
    }

    // setup game tracker
    int currIndex = 0;
    //shared_ptr<Player> currActingPlayer = group[currIndex];
    auto twoDices = std::make_shared<Dice>();

    while (true) {
        if (cin.fail()) break;

        cout << "type a command" << endl;
        
        cin >> command;

        // load command
        if ( command == ROLL ) {
            int availableDoubleRoll = 3;
            currActingPlayer = group[currIndex];
            int rollValue;

            while (availableDoubleRoll > 0) {
                // roll two dices 
                twoDices->rollDice();

                if (!twoDices->isDouble()) {
                    rollValue = twoDices->diceSum();
                    //acting here
                    break;
                } else {
                    rollValue = twoDices->diceSum();
                    //acting here;
                    availableDoubleRoll--;
                }
            }

            if (availableDoubleRoll == 0) {
                //send to jail
            }

            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == NEXT ) {
            currIndex += 1;
            currIndex = currIndex % group.size();
            currActingPlayer = group[currIndex];
            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == TRADE ) {

            // replace this code
            cout << "+ calling " << command << endl;
            cout << "(checking if we pass in enough parameters in)" << endl;
            cin >> name >> give >> receive;
            cout << "name: " << name << endl;
            cout << "give: " << give << endl;
            cout << "receive: " << receive << endl;

        } else if ( command == IMPROVE ) {

            // replace this code
            cout << "+ calling " << command << endl;
            cout << "(checking if we pass in enough parameters in)" << endl;
            cin >> property >> action;
            cout << "property: " << property << endl;

            if ( action == BUY ) {
                // calling buy action
                cout << "call buy action" << endl;
            } else if ( action == SELL ) {
                // calling sell action
                cout << "call sell action" << endl;
            }

        } else if ( command == MORTGAGE ) {

            // replace this code
            cout << "+ calling " << command << endl;
            cin >> property;
            cout << "attempt to mortgage: " << property << endl;

        } else if ( command == UNMORTGAGE ) {

            // replace this code
            cout << "+ calling " << command << endl;
            cin >> property;
            cout << "attempt to unmortgage: " << property << endl;

        } else if ( command == BANKRUPT ) {
            
            // replace this code
            cout << "+ calling " << command << endl;
            cout << "(only available when a player must pay more money than they currently have)" << endl;
            cout << "GAME OVER!!" << endl;
            break;

        } else if ( command == ASSETS ) {
            
            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == ALL ) {
            
            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == SAVE ) {
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
		outf << group[i]->getCurrPos();
		if (group[i]->getCurrPos == DC_TIMS_POS){
		    char gp = group[i]->getGamePiece();
	            // check if player is in Line
		    // ^ (at start of game, TimsLine square is created by main,
		    // bool inLine = tl->isCaptured(gp);
		    // if (inLine){
		    //     int turnsInLine = tl->turnsInLine(gp);
		    //     outf << " " << 1 << " ";
		    //     outf << turnsInLine << endl;
		    // } else {
		    //     outf << " " << 0 << endl;
		    // }	
		} else {
		    outf << endl;
		}
	    }

	    for (int i = 0; i < OWNABLE_SIZE; i++){
	        outf << OWNABLE[i] << " ";

	    }

	    

        } else {
            cout << "Unrecognized command!" << endl;
        }

    }

}
