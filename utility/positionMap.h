#ifndef POSITIONMAP_H
#define POSITIONMAP_H
#include <string>
#include <vector>
#include <map>

const std::map<int, std::vector<int>> MAP_COORD = {
    {0, {81,50}}, {1, {73,50}}, {2, {65,50}}, {3, {57,50}}, {4, {49,50}},
    {5, {41,50}}, {6, {33,50}}, {7, {25,50}}, {8, {17,50}}, {9, {9,50}},
    {10, {1,50}}, {11, {1,45}}, {12, {1,40}}, {13, {1,35}}, {14, {1,30}},
    {15, {1,25}}, {16, {1,20}}, {17, {1,15}}, {18, {1,10}}, {19, {1,5}},
    {20, {1,0}}, {21, {10,0}}, {22, {18,0}}, {23, {26,0}}, {24, {34,0}},
    {25, {42,0}}, {26, {50,0}}, {27, {58,0}}, {28, {66,0}}, {29, {74,0}},
    {30, {82,0}}, {31, {82,5}}, {32, {82,10}}, {33, {82,15}}, {34, {82,20}},
    {35, {82,25}}, {36, {82,30}}, {37, {82,35}}, {38, {82,40}}, {39, {82,45}},
    {40, {82,50}},
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

