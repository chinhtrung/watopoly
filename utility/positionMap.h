#ifndef POSITIONMAP_H
#define POSITIONMAP_H
#include <string>
#include <vector>
#include <map>

const std::map<int, std::vector<int>> MAP_COORD = {
    {0, {50,82}}, {1, {0,0}}, {2, {0,0}}, {3, {0,0}}, {4, {0,0}},
    {5, {0,0}}, {6, {0,0}}, {7, {0,0}}, {8, {0,0}}, {9, {0,0}},
    {10, {0,0}}, {11, {0,0}}, {12, {0,0}}, {13, {0,0}}, {14, {0,0}},
    {15, {0,0}}, {16, {0,0}}, {17, {0,0}}, {18, {0,0}}, {19, {0,0}},
    {20, {0,0}}, {21, {0,0}}, {22, {0,0}}, {23, {0,0}}, {24, {0,0}},
    {25, {0,0}}, {26, {0,0}}, {27, {0,0}}, {28, {0,0}}, {29, {0,0}},
    {30, {0,0}}, {31, {0,0}}, {32, {0,0}}, {32, {0,0}}, {34, {0,0}},
    {35, {0,0}}, {36, {0,0}}, {37, {0,0}}, {38, {0,0}}, {39, {0,0}}, 
    {40, {0,0}},
};

int indexOfSquare(std::string nameSquare);

// This is a global constant to keep track of position block in game map
// where index is the position of block (string type)

const std::vector<std::string> MAP_GAME = 
{
    "COLLECT OSAP", "AL", "SLC", "ML", "TUITION", "MKV", "ECH", "NEEDLES HALL", "PAS", "HH", 
    "DC Tims Line", "RCH", "PAC", "DWE", "CPH", "UWP", "LHI", "SLC", "BMH", "OPT",
    "Goose Nesting", "EV1", "NEEDLES HALL", "EV2", "EV3", "V1", "PHYS", "B1", "CIF", "B2",
    "GO TO TIMS", "EIT", "ESC", "SLC", "C2", "REV", "NEEDLES HALL", "MC", "COOP FEE", "DC",
};
const int MAP_GAME_SIZE = MAP_GAME.size();

// return the first index of nameSquare in the MAP_GAME
// nameSquare should be a valid name
int indexOfSquare(std::string nameSquare) {
    int indexResult = 0;

    for (int i = 0; i < MAP_GAME_SIZE; i++) {
        if (nameSquare == MAP_GAME[i]) { //should number SLC, NEEDLES HALL as SLC1, SLC2,...
            indexResult = i;
            break;
        }
    }

    return indexResult;
}

int posXOfSquare(std::string nameSquare){
    int index = indexOfSquare(nameSquare);
    return MAP_COORD.at(index)[0];
    //return MAP_COORD[index][0];
    /*std::vector<int> tmp = MAP_COORD[index];
    return tmp[0];*/
}

int posYOfSquare(std::string nameSquare){
    int index = indexOfSquare(nameSquare);
    return MAP_COORD.at(index)[1];
    //return MAP_COORD[index][1];
    /*std::vector<int> tmp = MAP_COORD[index];
    return tmp[1];*/
}

int posXOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[0];
    //std::vector<int> tmp = MAP_COORD[indexOfSquare];
    //return MAP_COORD[indexOfSquare][0];
    //return tmp[0];
}

int posYOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[1];
    //std::vector<int> tmp = MAP_COORD[indexOfSquare];
    //return MAP_COORD[indexOfSquare][1];
    //return tmp[1];
}

#endif

