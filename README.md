# Watopoly CS246 project

## About the project
Watopoly is the final project of CS246. It is the monopoly game style with the modification of building/environment/gameplay of the University of Waterloo campus. This project is always private and contributed by Trung Nguyen, William Wang and Catherine Wang. Thank guys for your hard working.

## Plan of attack
The components are shared to build between teamate and are subject to change as the first plan of attack. We also breakdown the whole project relative classes/components with their relationship into the UML model diagram  
The completed plan of attack this problem can be found [here](./documents/Initial game plan.pdf) and the UML model is [here](./documents/UML.pdf)

## Convention on parameters, classes, file names and preprocessor guards for contributors
Here we want to be consistent in naming each code components for the sake of readability and debugging purpose

### Parameters
The parameters name,including variables and methods, should be in camelCase except for ID keywords (which is in allcaps)
```CPP
std::string gameName;
char gamePiece;
int ID;
int getID();
int die1 = 6;
int rollDice()
```
### Classes
The class name should be in UpperCamelCase
```CPP
class Square{
    Square();
};

class GameState{
    GameState();
};
```
### File names
The file name should be in camelCase
```sh
gameState.h
gameState.cc
player.h
player.cc
main.cc
```
### Preprocessor guards
Followed by the convention of CS246 course note, please note that DO NOT USE `using namespace std;` in the `.h` files to minimize the chance of conflict due to implicity interpretation
```CPP
#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

...

#endif
```
