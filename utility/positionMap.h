#ifndef POSITIONMAP_H
#define POSITIONMAP_H
#include <string>
#include <vector>
#include <map>

const std::map<int, std::vector<int>> MAP_COORD = {
    {0, {82,50}}, {1, {74,50}}, {2, {66,50}}, {3, {58,50}}, {4, {50,50}},
    {5, {42,50}}, {6, {34,50}}, {7, {26,50}}, {8, {18,50}}, {9, {10,50}},
    {10, {1,50}}, {11, {1,45}}, {12, {1,40}}, {13, {1,35}}, {14, {1,30}},
    {15, {1,25}}, {16, {1,20}}, {17, {1,15}}, {18, {1,10}}, {19, {1,5}},
    {20, {1,0}}, {21, {9,0}}, {22, {17,0}}, {23, {25,0}}, {24, {35,0}},
    {25, {42,0}}, {26, {49,0}}, {27, {57,0}}, {28, {65,0}}, {29, {73,0}},
    {30, {81,0}}, {31, {81,5}}, {32, {81,10}}, {33, {81,15}}, {34, {81,20}},
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

int colOfSquare(std::string nameSquare){
    int index = indexOfSquare(nameSquare);
    return MAP_COORD.at(index)[0]; 
}

int rowOfSquare(std::string nameSquare){
    int index = indexOfSquare(nameSquare);
    return MAP_COORD.at(index)[1]; 
}

int colOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[0]; 
}

int rowOfSquare(int indexOfSquare){
    return MAP_COORD.at(indexOfSquare)[1]; 
}

#endif

