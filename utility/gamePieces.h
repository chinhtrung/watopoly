#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <iostream>
#include <string>
#include <vector>

std::string nameByChar(char c);
char charByName(std::string name);
void showAllCharExcept(std::vector<char> vec);
bool isGamePiece(char c);

std::vector<std::string> GAMEPIECE_NAME = 
    {"Goose", "GRT Bus", "Tim Hortons Doughnut", "Professor", "Student", "Money", "Laptop", "Pink tie"};
std::vector<char> GAMEPIECE_CHAR = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
int GAMEPIECE_SIZE = GAMEPIECE_NAME.size();

// gamePieces["Goose"] = 'G';
// gamePieces["GRT Bus"] = 'B';
// gamePieces["Tim Hortons Doughnut"] = 'D';
// gamePieces["Professor"] = 'P';
// gamePieces["Student"] = 'S';
// gamePieces["Money"] = '$';
// gamePieces["Laptop"] = 'L';
// gamePieces["Pink tie"] = 'T';

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

#endif
