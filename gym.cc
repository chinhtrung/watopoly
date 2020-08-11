#include "gym.h"
#include "ownable.h"

Gym::Gym( string name, int id ){
        : Ownable{150, nullptr, id, name}, diceSum{-1} {}
