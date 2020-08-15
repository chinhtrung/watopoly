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

#endif
