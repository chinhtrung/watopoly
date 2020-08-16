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
#include "TimsLine.h"

using namespace std;

class Board;
class Player;
class Dice;
class Transactions;
class Unownable;
class TimsLine;

// main drive
int main(int argc, char **argv)
{
    cout << "************** $.$ **************" << endl;
    cout << "---     WATOPOLY PROJECT      ---" << endl;
    cout << "*********************************" << endl;

    vector<char> pieceCharTaken;

    string command, name, give, receive, property, action, filename;

    //int MAX_TIMS = 4;
    const int MAX_PLAYERS = 7;
    const int MIN_PLAYERS = 2;
    const int TUITION_POS = 4;
    const int DC_TIMS_POS = 10;

    auto b = std::make_shared<Board>();
    vector<shared_ptr<Player>> group;
    int defaultMoneyToStart = 1500;
    bool testMode = false;
    auto tl = std::make_shared<TimsLine>(DC_TIMS_POS, MAP_GAME[DC_TIMS_POS]);

    if (argc > 1 && argv[1] == LOAD)
    {

        cout << "Loading in saved game from " << argv[2] << "\n"
             << endl;

        std::ifstream inf{argv[2]};

        int numPlayers;
        inf >> numPlayers;

        for (int i = 0; i < numPlayers; i++)
        {
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

            if (sqrPos == DC_TIMS_POS)
            {
                bool inLine;
                inf >> inLine;
                if (inLine)
                {
                    b->movePlayer(gamepiece, DC_TIMS_POS);
                    int turnsInLine;
                    inf >> turnsInLine;
                    p->moveToDCTims();
                }
                else
                {
                    p->movePlayer(sqrPos); //but without collecting Go money
                    b->movePlayer(gamepiece, sqrPos);
                }
            }
            else
            {
                p->movePlayer(sqrPos); //but without collecting Go money
                b->movePlayer(gamepiece, sqrPos);
            }

            group.push_back(p);
        }

        for (int i = 0; i < OWNABLE_SIZE; i++)
        {
            string propName;
            string owner;
            int imprLevel;
            inf >> propName;
            inf >> owner;
            inf >> imprLevel;

            if (owner != "BANK")
            {
                int playerIndex = 0;
                for (int i = 0; i < numPlayers; i++)
                {
                    if (group[i]->getName() == owner)
                    {
                        playerIndex = i;
                    }
                }
                LoadSave::loadProperty(propName, group[playerIndex], imprLevel);
            }
        }

        for (int i = 0; i < numPlayers; i++)
        {
            group[i]->updateMonopolyBlock();
            group[i]->loadUpdateAmountToPay();
        }

        cout << "Here are the current assets of all players, and the state of the board.\n " << endl;
        for (int i = 0; i < numPlayers; i++)
        {
            group[i]->displayAssets();
            cout << "\n" << endl;
        }

        b->drawBoard();
    }
    else
    {

        if (argc > 1 && (argv[1] == TESTING || argv[3] == TESTING))
        {
            testMode = true;
            cout << "Currently in test mode" << endl;
        }
        else
        {
            testMode = false;
            cout << "Fail to call load or test mode, initiate a new game" << endl;
        }

        cout << "Please input the number of player for this game" << endl;
        string num;
        cin >> num;

        while (!isNumber(num))
        {
            if (cin.fail())
                break;
            cout << "Please enter a number" << endl;
            cin >> num;
        }

        while (cin.fail() || stoi(num) < MIN_PLAYERS || stoi(num) > MAX_PLAYERS)
        {
            if (cin.fail())
                break;
            cout << "The number of players should be between 2 and 7." << endl;
            cout << "input number of player again" << endl;
            cin >> num;
        }

        cout << "The number of player is " << num << endl;

        for (int i = 0; i < stoi(num); i++)
        {
            cout << "Hey player " << i + 1 << "! Please input your name " << endl;
            string name;
            cin >> name;

            while (name == "BANK")
            {
                cout << "Sorry, you can't have the name BANK. Please input a different name." << endl;
                cin >> name;
            }

            if (cin.fail())
                break;

            cout << "Please choose one from the available piece char to represent yourself on board ";
            showAllCharExcept(pieceCharTaken);
            char piece;
            cin >> piece;
            int sizePiecesTaken = pieceCharTaken.size();
            bool takenStatus = false;

            while (true)
            {
                if (cin.fail())
                    break;
                for (int i = 0; i < sizePiecesTaken; i++)
                {
                    if (pieceCharTaken[i] == piece)
                    {
                        cout << piece << " has been taken, please choose another one" << endl;
                        takenStatus = true;
                        break;
                    }
                }
                if (!takenStatus && isGamePiece(piece))
                    break;
                takenStatus = false;

                cout << "Your game piece should be one of the char here ";
                showAllCharExcept(pieceCharTaken);
                cin >> piece;
            }
            pieceCharTaken.push_back(piece);
            cout << "Hi " << name << "! Your piece is " << piece << endl;
            cout << "---------------------------------" << endl
                 << endl;

            auto newPlayer = make_shared<Player>(name, piece, defaultMoneyToStart);
            group.push_back(newPlayer);

            // reset game piece
            piece = ' ';
        }
    }

    // setup game tracker and helper method
    int currIndex = 0;
    shared_ptr<Player> currActingPlayer = group[currIndex];
    auto twoDices = make_shared<Dice>();
    int numberOfPlayer = group.size();
    bool rollThisTurn = false;
    bool nextPlayer = true;
    auto pointerOfPlayer = [group](char trackingPiece) {
        int sizeGroup = group.size();
        shared_ptr<Player> result;
        for (int i = 0; i < sizeGroup; i++)
        {
            if (group[i]->getGamePiece() == trackingPiece)
            {
                return group[i];
            }
        }
        cout << "why trackingPiece is not in this player group? hmmm..." << endl;
        // this will return empty share_ptr of player
        return result;
    };

    cout << "++++  GAME START  ++++++++++++==" << endl;
    cout << "==============================" << endl
         << endl;
    cout << ">-------------------------------------------------------------<" << endl;

    while (true)
    {
        if (cin.fail())
            break;

        currActingPlayer = group[currIndex];

        if (currActingPlayer->getBankruptStatus())
        {
            currIndex = currIndex % group.size();
            continue;
        }

        if (numberOfPlayer == 1)
        {
            cout << "Congratulation! The winner is " << currActingPlayer->getName();
            cout << " with the total assest of " << currActingPlayer->getAssets() << endl;
            break;
        }

        if (nextPlayer)
        {
            cout << "Your turn " << currActingPlayer->getName();
            cout << " - your piece: " << currActingPlayer->getGamePiece() << endl;
            cout << ">-------------------------------------------------------------<" << endl;
            nextPlayer = false;
        }

        cout << endl;
        cout << "Available commands - [\"roll\",\"next\",\"trade\",\"improve\",\"mortgage\",\"unmortgage\",\"assets\",\"all\",\"save\"]" << endl;
        cout << "Please type a command with the procedure accordingly " << currActingPlayer->getName() << endl;
        cout << "-------------" << endl;

        cin >> command;

        // load command
        if (command == ROLL)
        {
            if (rollThisTurn)
            {
                cout << "You rolled this turn, please make other commands" << endl;
                continue;
            }
            int availableDoubleRoll = 3;
            int rollValue = 0;

            while (availableDoubleRoll > 0)
            {
                // roll two dices

                bool rollOverload = false;
                if (testMode)
                {
                    std::string die1;
                    std::string die2;
                    cin >> die1;
                    if (!cin.fail() && isNumber(die1))
                    {
                        cin >> die2;
                        if (!cin.fail() && isNumber(die2))
                        {
                            rollValue = std::stoi(die1) + std::stoi(die2);
                            rollOverload = true;
                        }
                    }
                }
                if (!rollOverload)
                {
                    twoDices->rollDice();
                    cout << "Rolling your dice ........" << endl;
                    cout << "and you get ";
                    cout << twoDices->getDie1() << " + ";
                    cout << twoDices->getDie2() << " = ";
                    cout << twoDices->diceSum() << "!" << endl;
                }
                if (!twoDices->isDouble())
                {
                    if (!rollOverload)
                    {
                        rollValue = twoDices->diceSum();
                    }
                    currActingPlayer->movePlayer(rollValue);
                    b->movePlayer(currActingPlayer->getGamePiece(),
                                  currActingPlayer->getCurrPos());
                    b->drawBoard();
                    followRollCommand(group, currActingPlayer, testMode, b);
                    break;
                }
                else
                {
                    if (availableDoubleRoll == 1)
                    {
                        cout << "--> Congrats! You have rolled a double ";
                        cout << "3 times in a row, go to Tims Line!!!! <--" << endl;
                        //send to jail
                        currActingPlayer->moveToDCTims();
                        continue;
                    }
                    if (!rollOverload)
                    {
                        rollValue = twoDices->diceSum();
                    }
                    //acting here;

                    currActingPlayer->movePlayer(rollValue);
                    b->movePlayer(currActingPlayer->getGamePiece(),
                                  currActingPlayer->getCurrPos());
                    b->drawBoard();

                    followRollCommand(group, currActingPlayer, testMode, b);

                    cout << "--> Congratulation, You have rolled a double and get one more roll turn  <--" << endl;
                    cout << "--> Type anything to start rolling <--" << endl;
                    
                    string dummy;
                    cin >> dummy;

                    availableDoubleRoll--;
                }
            }

            rollThisTurn = true;
        }
        else if (command == NEXT)
        {
            if (!rollThisTurn)
            {
                cout << "Please roll before finishing your turn" << endl;
                continue;
            }

            currIndex += 1;
            currIndex = currIndex % group.size();
            rollThisTurn = false;
            nextPlayer = true;
            cout << "Your turn finish, go to the next player!" << endl;
            cout << endl;
            cout << ">-------------------------------------------------------------<" << endl;
        }
        else if (command == TRADE)
        {

            followTradeCommand(group, currActingPlayer);
        }
        else if (command == IMPROVE)
        {

            followImproveCommand(group, currActingPlayer, b);
        }
        else if (command == MORTGAGE)
        {

            followMortgageCommand(currActingPlayer);
        }
        else if (command == UNMORTGAGE)
        {

            followUnmortgageCommand(currActingPlayer);
        }
        else if (command == BANKRUPT)
        {
            cout << "The bankrupt command cannot be called here" << endl;
            continue;
        }
        else if (command == ASSETS)
        {
            if (currActingPlayer->getCurrPos() != TUITION_POS)
            {
                currActingPlayer->displayAssets();
            }
            else
            {
                cout << "You may not check your assets when ";
                cout << "paying tuition!" << endl;
            }
        }
        else if (command == ALL)
        {

            if (currActingPlayer->getCurrPos() != TUITION_POS)
            {   
                cout << endl;
                cout << "--> Displaying assets of all players." << endl;
                cout << ".................." << endl;
                for (unsigned int i = 0; i < group.size(); ++i)
                {
                    group[i]->displayAssets();
                    cout << ".................." << endl;
                }
            }
            else
            {
                cout << "You may not check your assets when ";
                cout << "paying tuition!" << endl;
            }
        }
        else if (command == SAVE)
        {
            string file;
            cin >> file;
            cout << "Saving game to " << file << endl;
            std::ofstream outf{file};

            int size = group.size();
            outf << size << endl;

            for (int i = 0; i < size; i++)
            {
                outf << group[i]->getName() << " ";
                outf << group[i]->getGamePiece() << " ";
                outf << group[i]->getTimsCups() << " ";
                outf << group[i]->getFunds() << " ";
                outf << group[i]->getCurrPos();
                if (group[i]->getCurrPos() == DC_TIMS_POS)
                {
		    // check if player is in Line
                    /* bool inLine = tl->isCaptured(gp);
                    if (inLine){
                        int turnsInLine = tl->turnsInLine(gp);
                        outf << " " << 1 << " ";
                        outf << turnsInLine << endl;
                    } else {
                        outf << " " << 0 << endl;
                    }*/
                }
                else
                {
                    outf << endl;
                }
            }

            for (int i = 0; i < OWNABLE_SIZE; i++)
            {
                outf << OWNABLE[i][0] << " ";
                int size = group.size();
                bool owned = false;
                for (int j = 0; j < size; j++)
                {
                    if (group[j]->ownThisProp(OWNABLE[i][0]))
                    {
                        outf << group[j]->getName() << " ";
                        owned = true;
                        break;
                    }
                }

                if (!owned)
                {
                    outf << "BANK"
                         << " ";
                }
                outf << b->getImpr(OWNABLE[i][0]) << endl;
            }
        }
        else
        {
            cout << "Unrecognized command! Please make another command" << endl;
        }
    }
}

// Sources:
// cplusplus.com
// encppreference.com
// https://medium.com/prodopsio/solving-git-merge-conflicts-with-vim
//   -c8a8617e3633
// C Programming, A Modern Approach, 2nd Ed., by KN King
// CS 136 Course Slides
