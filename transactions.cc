#include "transactions.h"

void Transactions::tradeMforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int give, std::shared_ptr<Ownable> receive) {
    return;
}

void Transactions::tradePforP(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, std::shared_ptr<Ownable> receive) {
    return;
}

void Transactions::tradePforM(std::shared_ptr<Player> from, std::shared_ptr<Player> to, std::shared_ptr<Ownable> give, int receive) {
    return;
}

void Transactions::payRent(std::shared_ptr<Player> from, std::shared_ptr<Player> to, int rent) {
    return;
}

void Transactions::payBank(std::shared_ptr<Player> from) {
    return;
}

void Transactions::payPlayer(std::shared_ptr<Player> to) {
    return;
}

void Transactions::buyProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    return;
}

void Transactions::sellProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    return;
}

void Transactions::improveProperty(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    return;
}

void Transactions::sellImprove(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    return;
}

void Transactions::mortgageProper(std::shared_ptr<Ownable> prop, std::shared_ptr<Player> own) {
    return;
}
