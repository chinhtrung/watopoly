#ifndef POSITIONMAP_H
#define POSITIONMAP_H
#include <string>
#include <vector>

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
        if (nameSquare == MAP_GAME[i]) {
            indexResult = i;
            break;
        }
    }

    return indexResult;
}

#endif
