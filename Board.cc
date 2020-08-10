#include "Board.h"
#include "Square.h"
#include "Player.h"
#include "Dice.h"

const int MAX_TIMS_CUPS = 4;
const int NUM_SQUARES = 40;
const int MAX_PLAYERS = 8;

Board::Board() {
    players.reserve(MAX_PLAYERS);
    Dice d;
    dice{d};
    timsCupsRem = MAX_TIMS_CUPS;

    squares.reserve(NUM_SQUARES);
    // would be better to initialize square in one line
    // i.e. squares[0] = new shared_ptr(new MonetaryServices...)
    shared_ptr<MonetaryServices> osap(new MonetaryServices("OSAP", 0));
    squares[0] = osap;
    shared_ptr<Academic> al(new Academic("AL", "Arts1", 1, 40, 50, 2, 10, 30, 90, 160, 250)); 
    squares[1] = al;
    shared_ptr<SLC> slc(new SLC("SLC", 2));
    squares[2] = slc;
    shared_ptr<Academic> ml(new Academic("ML", "Arts1", 3, 60, 50, 4, 20, 60, 180, 320, 450));
    squares[3] = ml;
    shared_ptr<MonetaryServices> tuit(new MonetaryServices("TUITION", 4));
    squares[4] = tuit;
    shared_ptr<Residence mkv(new Residence("MKV", 5));
    squares[5] = mkv;
    shared_ptr<Academic> ech(new Academic("ECH", "Arts2", 6, 100, 50, 6, 30, 90, 270, 400, 550));
    squares[6] = ech;
    shared_ptr<MonetaryServices> nh(new MonetaryServices("NEEDLES HALL", 7));
    squares[7] = nh;
    shared_ptr<Academic> pas(new Academic("PAS", "Arts2", 8,  100, 50, 6, 30, 90, 270, 400 550));
    squares[8] = pas;
    shared_ptr<Academic> hh(new Academic("HH", "Arts2", 9, 120, 50, 8, 40, 100, 300, 450, 600));
    squares[9] = hh;
    shared_ptr<TimsLine> dc(new TimsLine("DC Tims Line", 10));
    squares[10] = dc;
    shared_ptr<Academic> rch(new Academic("RCH", "Eng", 11, 140, 100, 10, 50, 150, 450, 625, 750));
    squares[11] = rch;
    shared_ptr<Gym> pac(new Gym("PAC", 12));
    squares[12] = pac;
    shared_ptr<Academic> dwe(new Academic("DWE", "Eng", 13, 140, 100, 10, 50, 150, 450, 625, 750));
    squares[13] = dwe;
    shared_ptr<Academic> cph(new Academic("CPH", "Eng", 14, 160, 100, 12, 60, 180, 500, 700, 900));
    squares[14] = cph;
    shared_ptr<Residence> uwp(new Residence("UWP", 15));
    squares[15] = uwp;
    shared_ptr<Academic> lhi(new Academic("LHI", "Health", 16, 180, 100, 14, 70, 200, 550, 750, 950));
    squares[16] = lhi;
    shared_ptr<SLC> slc2(new SLC("SLC", 17));
    squares[17] = slc2;
    shared_ptr<Academic> bmh(new Academic("BMH", "Health", 18, 180, 100, 14, 70, 200, 550, 750, 950));
    squares[18] = bmh;
    shared_ptr<Academic> opt(new Academic("OPT", "Health", 19, 200, 100, 16, 80 220, 600, 800, 1000));
    squares[19] = opt;
    shared_ptr<MonetaryServices> goose(new MonetaryServices("Goose Nesting", 20));
    squares[20] = goose;
    shared_ptr<Academic> ev1(new Academic("EV1", "Env", 21, 220, 150, 18, 90, 250, 700, 875, 1050));
    squares[21] = ev1;
    shared_ptr<MonetaryServices> nh2(new MonetaryServices("NEEDLES HALL", 22));
    squares[22] = nh2;
    shared_ptr<Academic> ev2(new Academic("EV2", "Env", 23, 220, 150, 18, 90, 250, 700, 875, 1050));
    squares[23] = ev2;
    shared_ptr<Academic> ev3(new Academic("EV3", "Env", 24, 240, 150, 20, 100, 300, 750, 925, 1100));
    squares[24] = ev3;
    shared_ptr<Residence> v1(new Residence("V1", 25));
    squares[25] = v1;
    shared_ptr<Academic> phys(new Academic("PHYS", "Sci1", 26, 260, 150, 22, 110, 330, 800, 975, 1150));
    squares[26] = phys;
    shared_ptr<Academic> b1(new Academic("B1", "Sci1", 27, 260, 150, 22, 110, 330, 800, 975, 1150));
    squares[27] = b1;
    shared_ptr<Gym> cif(new Gym("CIF", 28));
    squares[28] = cif;
    shared_ptr<Academic> b2(new Academic("B2", "Sci1", 29, 280, 150, 24, 120, 360, 850, 1025, 1200));
    squares[29] = b2;
    shared_ptr<TimsLine> gtt(new TimsLine("GO TO TIMS", 30));
    squares[30] = gtt;
    shared_ptr<Academic> eit(new Academic("EIT", "Sci2", 31, 300, 200, 26, 130, 390, 900, 1100, 1275));
    squares[31] = eit;
    shared_ptr<Academic> esc(new Academic("ESC", "Sci2", 32, 300, 200, 26, 130, 390, 900, 1100, 1275));
    squares[32] = esc;
    shared_ptr<SLC> slc3(new SLC("SLC", 33));
    squares[33] = slc3;
    shared_ptr<Academic> c2(new Academic("C2", "Sci2", 34, 320, 200, 28, 150, 450, 1000, 1200, 1400));
    squares[34] = c2;
    shared_ptr<Residence> rev(new Residence("REV", 25));
    squares[35] = rev;
    shared_ptr<MonetaryServices> nh3(new MonetaryServices("NEEDLES HALL", 36));
    squares[36] = nh3;
    shared_ptr<Academic> mc(new Academic("MC", "Math", 37, 350, 200, 35, 175, 500, 1100, 1300, 1500));
    squares[37] = mc;
    shared_ptr<MonetaryServices coop(new MonetaryServices("COOP", 38));
    squares[38] = coop;
    shared_ptr<Academic> dc(new Academic("DC", "Math", 39, 400, 200, 50, 200, 600, 1400, 1700, 2400));
    squares[39] = dc;
    

    gymState["PAC"] = pac;
    gymState["CIF"] = cif;
    resState["MKV"] = mkv;
    resState["UWP"] = uwp;
    resState["V1"] = v1;
    resState["REV"] = rev;
}


void Board::addPlayer( shared_ptr<Player> p ){
    players.emplace_back(p); //doesn't throw if main doesn't add more than 8 players
}


void Board::drawBoard() {

}


string Board::getMonopoly( int acadID ){
    
}


int Board::getTimsCupsRem(){
    return timsCupsRem;
}


bool Board::checkAcad( string acadID ){
    string monoBlock = 
}


// requires that the gym indicated by gymID is owned
int Board::checkGymsOwned( string gymID ){
    char owner = gymState[gymID].getOwnerChar();
    int numOwned = 0;
    for (auto &p: gymState){
        if (p.second.getOwnerChar() == owner){
	    numOwned++;
	}
    }
    return numOwned;
}


int Board::checkResOwned( string resID ){
    char owner = resState[resID].getOwnerChar();
    int numOwned = 0;
    for (auto &p: resState){
        if (p.second.getOwnerChar() == owner){
            numOwned++;
        }
    }
    return numOwned;
}


// the update functions are not necessary with version B
//    acad/res/gym state structures
/*void Board::updateByTransPforP( shared_ptr<Ownable> prop1, char own1,
                                  shared_ptr<Ownable> prop2, char own2 ){

}


void Board::updateByTrans( shared_ptr<Ownable> prop, char own ){

}*/
