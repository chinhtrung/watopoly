#include "testing.h"

using namespace std;

void testing() {
    int defaultMoneyToStart = 1500;

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
    auto player = make_shared<Player>(name, gamePiece, defaultMoneyToStart);
    while (true) {
        cout << "Your current position is ";
        cout << player->getCurrPos();
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
            player->movePlayer(roll);
        }
    }
	return;
}
