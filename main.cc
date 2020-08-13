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

using namespace std;

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    std::vector<char> pieceCharTaken;

    string command, name, give, receive, property, action, filename;

    const int MAX_TIMS = 4;
    const int NUM_OWNABLE = 28;
    const int MAX_PLAYERS = 7;
    const int MIN_PLAYERS = 2;
    const int DC_TIMS_POS = 10;

    vector<shared_ptr<Player>> group;
    int defaultMoneyToStart = 1500;

    if ( argc == 3) { // check the number of arguments
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

	    for (int i = 0; i < NUM_OWNABLE; i++){
	        string name;
	        string owner;
		int imprLevel;
		inf >> name;
		inf >> owner;
		inf >> imprLevel;
		
		if (name != "BANK"){
		    int playerIndex;
		    for (int i = 0; i < group.size(); i++){
                        if (group[i]->getName() == name){
			    playerIndex = i;
                        }
                    }  

		    if (imprLevel == -1){ 
		        // add mortgage property
		    } else { 
		        group[playerIndex]->addProp();
		        // pass Ownable shared_ptr to addProp
			// b->addImpr(name, imprLevel);
		    }
		}
	    }
        }

        if (argv[1] == TESTING) {
            cout << "+ calling from arguments " << argv[1] << ": testing mode enable" << endl;
            cout << "read in file with the name " << argv[2] << endl;
        }
    } else {
        cout << "Fail to call load or testing mode, initiate a new game" << endl;
        cout << "Please input the number of player for this game" << endl;
        int num = 0;
        cin >> num;
        if (cin.fail()) cin.clear();
        while (num < 1 || num > 7 || cin.fail()) {
            if (cin.fail()) break;
            cout << "The number of player should be less than 8, input number of player again" << endl;
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
            if (cin.fail()) break;
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

    int currIndex = 0;
    //shared_ptr<Player> currActingPlayer = group[currIndex];

    while (true) {
        if (cin.fail()) break;

        cout << "type a command" << endl;
        cin >> command;

        // load command
        if ( command == ROLL ) {

            // replace this code
            cout << "+ calling " << command << endl;

        } else if ( command == NEXT ) {
            
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
	    outf << group.size() << endl;
            
	    for (int i = 0; i < group.size(); i++){
                outf << group[i].getName() << " ";
		outf << group[i].getGamePiece() << " ";
		outf << group[i].getTimsCups() << " ";
		outf << group[i].getCurrPos();
		if (group[i].getCurrPos == DC_TIMS_POS){
	            // check if player is in Line
		    // if (inLine){
		    //     int turnsInLine = ...;
		    //     outf << " " << 1 << " ";
		    //     outf << turnsInLine << endl;
		    // } else {
		    //     outf << " " << 0 << endl;
		    // }	
		} else {
		    outf << endl;
		}
	    } 


        } else {
            cout << "Unrecognized command!" << endl;
        }

    }

}
