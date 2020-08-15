#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include <iostream>
#include <memory>
#include "board.h"
#include "player.h"
#include "ownable.h"
#include "Unownable.h"
#include "dice.h"
#include "transactions.h"
#include "auction.h"
#include "MonetaryServices.h"
#include "SLC.h"
#include "positionMap.h"

class Board;
class Player;
class Ownable;
class Unownable;
class Dice;
class Transactions;
class Auction;
class SLC;
class MonetaryServices;

bool isNumber(std::string a);
void followRollCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer, bool testMode, std::shared_ptr<Board> b);
void followTradeCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer);
void followImproveCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer);
void followMortgageCommand(std::shared_ptr<Player> curPlayer);
void followUnmortgageCommand(std::shared_ptr<Player> curPlayer);
void followBankruptCommandWithPlayer(std::shared_ptr<Player> curPlayer, std::shared_ptr<Player> toPlayer);
void followBankruptCommandWithBank(std::shared_ptr<Player> curPlayer);
void followAssetsCommand(std::shared_ptr<Player> curPlayer);
void followAllCommand(std::vector<std::shared_ptr<Player>> group);
void followAuctionCommand(std::vector<std::shared_ptr<Player>> group, std::shared_ptr<Player> curPlayer, std::string ownableItem);

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
const std::string TESTING = "-testing";

// helper command
const std::string AUCTION = "auction"; // to call auction command
const std::string RAISE = "raise"; // place a bid in the auction command
const std::string WITHDRAW = "withdraw"; // withdraw from a bid

#endif
