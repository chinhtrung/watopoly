#include "gamePieces.h"

std::string nameByChar(char c) {
    std::string result = "";
    for (int i = 0; i < GAMEPIECE_SIZE; i++) {
        if (GAMEPIECE_CHAR[i] == c) {
            result = GAMEPIECE_NAME[i];
        }
    }

    return result;
}

char charByName(std::string name) {
    char result = ' ';
    for (int i = 0; i < GAMEPIECE_SIZE; i++) {
        if (GAMEPIECE_NAME[i] == name) {
            result = GAMEPIECE_CHAR[i];
        }
    }

    return result;
}

void showAllCharExcept(std::vector<char> vec) {
    int vecSize = vec.size();
    bool first = false;

    auto isContain = [vec, vecSize] (char c) {
        for (int i = 0; i < vecSize; i++) {
            if (c == vec[i]) return true;
        }
        return false;
    };

    std::cout << "[";
    for (int i = 0; i < GAMEPIECE_SIZE; i++) {
        if (!isContain(GAMEPIECE_CHAR[i])) {
            if (first) std::cout << ",";
            std::cout << GAMEPIECE_CHAR[i];
            first = true;
        }
    }

    std::cout << "]" << std::endl;
}

bool isGamePiece(char c) {
    for (int i = 0; i < GAMEPIECE_SIZE; i++) {
        if (GAMEPIECE_CHAR[i] == c) {
            return true;
        }
    }

    return false;
}
