#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "./utility/constants.h"
#include "./utility/seeds.h"

using namespace std;

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    string command, name, give, receive, property, action, filename;

    if ( argc == 3) { // check the number of arguments
        if (argv[1] == LOAD) {
            Board *b = new Board(argv[2]);	    
            cout << "+ calling from arguments " << argv[1] << " to load a game state" << endl;
            cout << "read in file with the name " << argv[2] << endl;
        }

        if (argv[1] == TESTING) {
            cout << "+ calling from arguments " << argv[1] << ": testing mode enable" << endl;
            cout << "read in file with the name " << argv[2] << endl;
        }
    } else {
	Board b;
	Dice d;
        cout << "fail to call load or testing mode, initial a new game" << endl;
    }

    cout << "type a command" << endl;

    while (true) {
        cin >> command;
        if (cin.fail()) break;

        // load command
        if ( command == ROLL ) {
	    d.rollDice();
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
		int currSqr = player.getCurrSqr();
		if (currSqr + dieSum > 40){
		    cout << "Collecting OSAP." << endl;
		    //pass Go, give money
		} 

		int newSqr = (currSqr + dieSum) % 40;
		b.movePlayer( player.getGamepiece(), newSqr );
	    }
	    continue;

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

