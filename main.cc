#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "utility/commands.h"
#include "utility/seeds.h"
#include "utility/positionMap.h"

using namespace std;

// main drive
int main (int argc, char** argv) {

    cout << "WATOPOLY PROJECT" << endl;

    string command, name, give, receive, property, action, filename;

    if ( argc == 3) { // check the number of arguments
        if (argv[1] == LOAD) {
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
            
            // replace this code
            cout << "+ calling " << command << endl;
            cin >> filename;
            cout << "invoking function to save  " << filename << endl;

        } else {
            cout << "Unrecognized command!" << endl;
        }

    }

}
