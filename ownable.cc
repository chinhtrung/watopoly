#include "square.cc"
using std::string;
using std::shared_ptr;

// owner stored as Player object in Ownable so main can pass owner object
//    to transaction class when making players pay rent
Ownable::Ownable( int costToBuy, shared_ptr<Player> owner, int id, string name )
    : Square{id, name}, costToBuy{costToBuy}, imprLevel{0},
          owner{owner}, isMortgaged{false} {}

