#include "seeds.h"

void traverseOwnable() { // for testing
    for (int i = 0; i < OWNABLE_SIZE; i++) {
        for (int j = 0; j < ATTRIBUTE_BUILDING_SIZE; j++) {
            std::cout << OWNABLE[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}

bool isOwnableBlock(std::string squareName) {
    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            return true;
        }
    }

    return false;
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
int costToSellImprProp(std::string squareName) {
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result = std::stoi(OWNABLE[i][IMPR_COST_INDEX])* 0.5;
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

int costToPayUnimprPropBlock(std::string squareName){
    int result = 0;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][IMPR_PRICE_0_INDEX]);
        }
    }

    return result * 2;
}

// squareName should be valid ownable building name
int costToPayImprProp(std::string squareName, int imprLevel) {
    int result = 0;
    int levelIndex = 0;

    if (imprLevel == 0) levelIndex = IMPR_PRICE_0_INDEX;
    if (imprLevel == 1) levelIndex = IMPR_PRICE_1_INDEX;
    if (imprLevel == 2) levelIndex = IMPR_PRICE_2_INDEX;
    if (imprLevel == 3) levelIndex = IMPR_PRICE_3_INDEX;
    if (imprLevel == 4) levelIndex = IMPR_PRICE_4_INDEX;
    if (imprLevel == 5) levelIndex = IMPR_PRICE_5_INDEX;

    for (int i = 0; i < OWNABLE_SIZE; i++) {
        if (OWNABLE[i][NAME_INDEX] == squareName) {
            result += std::stoi(OWNABLE[i][levelIndex]);
        }
    }

    return result;
}


bool isGym(std::string squareName){
    for (int i = 0; i < GYM_SIZE; i++){
        if (GYM[i][NAME_INDEX] == squareName) {
            return true;
        }
    }
    return false;
}


bool isResidence(std::string squareName){
    for (int i = 0; i < RESIDENCES_SIZE; i++){
        if (RESIDENCES[i][NAME_INDEX] == squareName){
	    return true;
	}
    }
    return false;
}


bool isAcademic(std::string squareName){
    for (int i = 0; i < ACADEMIC_SIZE; i++){
        if (ACADEMIC[i][NAME_INDEX] == squareName){
	    return true;
	}
    }

}
