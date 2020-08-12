<<<<<<< HEAD
#include <iostream>
#include <string>
#include "Dice.h"
#include "Unownable.h"
using namespace std;


// Commands
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

const int MAX_TIM_CUPS = 4;


int main(int argc, char * argv[]) {
	cout << "WATOPOLY PROJECT" << endl;

	string command;
	string name;
	string give;
	string receive;
	string property;
	string action;
	string filename;

	if (argv[0] == LOAD) {
	}

	if (argv[1] == TESTING) {
	}
	
	while (true) {
		cout << "Please type a valid command." << endl;
		cin >> command;

		if (cin.fail()) {
			break;
		}

		if (command == ROLL) {
		} else if (command == NEXT) {
		} else if (command == TRADE) {
		} else if (command == IMPROVE) {
			cin >> property >> action;
			if (action == BUY) {
			} else if (action == SELL) {
			}
		} else if (command == MORTGAGE) {
		} else if (command == UNMORTGAGE) {
		} else if (command == BANKRUPT) {
		} else if (command == ASSETS) {
		} else if (command == ALL) {
		} else {
			cout << "Unrecognized command!" << endl;
		}
	}
	return 0;
}
=======
#include <iostream>
#include <string>

// basic command (such as roll, next,...) and action (such as buy, sell)
const std::string ROLL = "roll";
const std::string NEXT = "next";
const std::string TRADE = "trade";
const std::string IMPROVE = "improve";
const std::string BUY = "buy";
const std::string SELL = "sell";
const std::string MORTGAGE = "mortgage";
const std::string UNMORTGAGE = "unmortgage";
const std::string BANKRUPT = "bankrupt";
const std::string ASSETS = "assets";
const std::string ALL = "all";
const std::string SAVE = "save";
const std::string LOAD = "-load";

// main drive
int main () {

    std::cout << "WATOPOLY PROJECT" << std::endl;
    std::cout << "type a command" << std::endl;

    std::string command, name, give, receive, property, action, filename;

    while (true) {
        std::cin >> command;
        if (std::cin.fail()) break;

        // load command
        if ( command == ROLL ) {

            // replace this code
            std::cout << "+ calling " << command << std::endl;

        } else if ( command == NEXT ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;

        } else if ( command == TRADE ) {

            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cout << "(checking if we pass in enough parameters in)" << std::endl;
            std::cin >> name >> give >> receive;
            std::cout << "name: " << name << std::endl;
            std::cout << "give: " << give << std::endl;
            std::cout << "receive: " << receive << std::endl;

        } else if ( command == IMPROVE ) {

            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cout << "(checking if we pass in enough parameters in)" << std::endl;
            std::cin >> property >> action;
            std::cout << "property: " << property << std::endl;

            if ( action == BUY ) {
                // calling buy action
                std::cout << "call buy action" << std::endl;
            } else if ( action == SELL ) {
                // calling sell action
                std::cout << "call sell action" << std::endl;
            }

        } else if ( command == MORTGAGE ) {

            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cin >> property;
            std::cout << "attempt to mortgage: " << property << std::endl;

        } else if ( command == UNMORTGAGE ) {

            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cin >> property;
            std::cout << "attempt to unmortgage: " << property << std::endl;

        } else if ( command == BANKRUPT ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cout << "(only available when a player must pay more money than they currently have)" << std::endl;
            std::cout << "GAME OVER!!" << std::endl;
            break;

        } else if ( command == ASSETS ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;

        } else if ( command == ALL ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;

        } else if ( command == SAVE ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cin >> filename;
            std::cout << "invoking function to save  " << filename << std::endl;

        } else if ( command == LOAD ) {
            
            // replace this code
            std::cout << "+ calling " << command << std::endl;
            std::cin >> filename;
            std::cout << "invoking function to load  " << filename << std::endl;

        } else {
            std::cout << "Unrecognized command!" << std::endl;
        }

    }

}
>>>>>>> spiderSam
