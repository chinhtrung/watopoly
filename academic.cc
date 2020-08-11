#include "academic.h"
#include "ownable.h"
using std::string;

Academic::Academic( string name, string monoBlock, int id, int costToBuy,
                      int imprCost, int tuitImpr0, int tuitImpr1,
                       int tuitImpr2, int tuitImpr3, int tuitImpr3,
                        int tuitImpr4, int tuitImpr5 )
        : Ownable{costToBuy, nullptr, id, name}, imprCost{imprCost}, monoBlock{monoBlock},
             tuition{tuitImpr0} {
    imprScheme.reserve(6);
    imprScheme[0] = tuitImpr0;
    imprScheme[1] = tuitImpr1;
    imprScheme[2] = tuitImpr2;
    imprScheme[3] = tuitImpr3;
    imprScheme[4] = tuitImpr4;
    imprScheme[5] = tuitImpr5;
}
