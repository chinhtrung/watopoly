#include <iostream>
#include <string>

using namespace std;

// basic command (such as roll, next,...) and action (such as buy, sell)
const string ROLL = "roll";
const string NEXT = "next";
const string TRADE = "trade";
const string IMPROVE = "improve";
const string BUY = "buy";
const string SELL = "sell";
const string MORTGAGE = "mortgage";
const string UNMORTGAGE = "unmortgage";
const string BANKRUPT = "bankrupt";
const string ASSETS = "assets";
const string ALL = "all";
const string SAVE = "save";
const string LOAD = "-load";
const string TESTING = "-testing";

// main drive
int main () {

    cout << "WATOPOLY PROJECT" << endl;
    cout << "type a command" << endl;

    string command, name, give, receive, property, action, filename;

    if (argv[0] == LOAD) {
        cout << "+ calling " << argv[0] << " to load game state" << endl;
	}

	if (argv[1] == TESTING) {
        cout << "+ calling " << argv[0] << ": testing mode enable" << endl;
	}

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

        } else if ( command == LOAD ) {
            
            // replace this code
            cout << "+ calling " << command << endl;
            cin >> filename;
            cout << "invoking function to load  " << filename << endl;

        } else {
            cout << "Unrecognized command!" << endl;
        }

    }

}
