#include "seeds.h"


void traverseOwnable() { // for testing
    for (int i = 0; i < OWNABLE_SIZE; i++) {
        for (int j = 0; j < ATTRIBUTE_BUILDING_SIZE; j++) {
            std::cout << OWNABLE[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}

// squareName should be valid ownable building name
std::string monoBlockOfProp(std::string squareName) {
    std::string result = "";

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result = OWNABLE[i][MONOBLOCK_INDEX];
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToBuyProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][BUY_COST_INDEX]);
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToImprProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][IMPR_COST_INDEX]);
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToMortProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][BUY_COST_INDEX]) * 0.5;
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToUnmortProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][BUY_COST_INDEX]) * 0.6;
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToPayUnimprProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][IMPR_PRICE_0_INDEX]);
        }
    }

    return result;
}

// squareName should be valid ownable building name
int costToPayImprProp(std::string squareName, int imprLevel) {
    int result = 0;
    int levelIndex = 0;

    if (imprLevel = 0) {
	    levelIndex = IMPR_PRICE_0_INDEX;
    } else if (imprLevel = 1) {
	    levelIndex = IMPR_PRICE_1_INDEX;
    } else if (imprLevel = 2) {
	    levelIndex = IMPR_PRICE_2_INDEX;
    } else if (imprLevel = 3) {
	    levelIndex = IMPR_PRICE_3_INDEX;
    } else if (imprLevel = 4) {
	    levelIndex = IMPR_PRICE_4_INDEX;
    } else if (imprLevel = 5) {
	    levelIndex = IMPR_PRICE_5_INDEX;
    }

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][levelIndex]);
        }
    }

    return result;
}
