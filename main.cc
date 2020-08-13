#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "./utility/commands.h"
#include "./utility/positionMap.h"
#include "./utility/seeds.h"

using namespace std;

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    string command, name, give, receive, property, action, filename;
    const int MAX_TIMS = 4;
    const int NUM_OWNABLE = 28;

    if ( argc == 3) { // check the number of arguments
        if (argv[1] == LOAD) {
	    std::ifstream saveFile{argv[2]};

	    int numPlayers;
	    saveFile >> numPlayers;
	    char firstPlayer;
	    int timsCupsActive;
	    Board *b = new Board();
	    std::map<char, std::shared_ptr<Player>> players;

	    for (int i = 0; i < numPlayers; i++){
	        string name;
		char gamepiece;
		int numTimsCups;
		int funds;
		int sqrPos;

		cin >> name;
		if (name == "BANK"){
		    cout << "Invalid: Cannot have player named BANK." << endl;
		}
		cin >> gamepiece;
		cin >> numTimsCups;
		timsCupsActive += numTimsCups;
		if (timsCupsActive > MAX_TIMS){
		    cout << "Too many cups!" << endl;
		}
		cin >> funds;
		cin >> sqrPos;
		
		if (int i = 0){
                    firstPlayer = gamepiece;
		} 

		auto p = std::make_shared<Player>( name, gamepiece, numTimsCups, funds, sqrPos );
		players[gamepiece] = p;
		b.addPlayer(gamepiece);

		if (sqrPos == 10){
		    bool inLine;
		    cin >> inLine;
		    if (inLine){
		        b.movePlayer(gamepiece, 10);
			int turnsInLine;
			cin >> turnsInLine;
			// add to captured vector
		    }
		}
	    }

	    for (int i = 0; i < NUM_OWNABLE; i++){
	        string name;
	        string owner;
		int imprLevel;
		cin >> name;
		cin >> owner;
		cin >> imprLevel;
		if ((isGym(name) || isRes(name)) && imprLevel > 0){
		    cout << "Invalid input: Residences and gyms cannot be improved." << endl;
		}

		if (imprLevel == -1){
		    //mortgage property
		}


	    }
            cout << "+ calling from arguments " << argv[1] << " to load a game state" << endl;
            cout << "read in file with the name " << argv[2] << endl;
        }

        if (argv[1] == TESTING) {
            cout << "+ calling from arguments " << argv[1] << ": testing mode enable" << endl;
            cout << "read in file with the name " << argv[2] << endl;
        }
    } else {
        cout << "fail to call load or testing mode, initial a new game" << endl;
    }

    cout << "type a command" << endl;

    while (true) {
        cin >> command;
        if (cin.fail()) break;

        // load command
        if ( command == ROLL ) {
/*	    d.rollDice();
	    int numDoubles = 0;
	    if (d.isDoubles() && numDoubles < 3){
		numDoubles++;
	        cout << "You rolled doubles, so you get to roll again." << endl;
	    } else if (d.isDoubles()){
	        cout << "Whoops. You rolled three doubles, which means you pulled ";
		cout << "an all-nighter and have to line up at DC Tims." << endl;
		// send Player to DC Tims Line
	    } else {
	        int dieSum = d.dieSum();
	//	int currSqr = player.getCurrSqr();
		if (currSqr + dieSum > 40){
		    cout << "Collecting OSAP." << endl;
		    //pass Go, give money
		} 

		int newSqr = (currSqr + dieSum) % 40;
	//	b.movePlayer( player.getGamepiece(), newSqr );
	    }
	    continue;
*/
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
            
            // replace this code
            cout << "+ calling " << command << endl;
            cin >> filename;
            cout << "invoking function to save  " << filename << endl;

        } else {
            cout << "Unrecognized command!" << endl;
        }

    }

}

