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
