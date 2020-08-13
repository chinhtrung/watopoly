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
