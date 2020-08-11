#include "residence.h"
#include "ownable.h"
using std::string;

Residence::Residence( string name, int id )
        : Ownable{200, nullptr, id, name} {}
