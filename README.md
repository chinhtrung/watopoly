# Watopoly CS246 project

## About the project
Watopoly is among many choices of topic to choose for the final project of CS246. It is the monopoly game style with the modification of building/environment/gameplay of the University of Waterloo campus. This project is contributed by Trung Nguyen, William Wang and Catherine Wang. Thanks guys for your hard working.

**Note**: For UWaterloo CS246 students, please **do not use** this code for your final project, which would be detected by the university plagiarism checking system. ***This repository is used only to show for who is not in the course and for people to play the game.***

[![watopoly screenshot][watopoly-screenshot]][watopoly-screenshot]

## Install, Setup and Play
1. Clone the current repo
    ```sh
    $ git clone https://github.com/chinhtrung/watopoly.git
    ```
2. Run ```make``` file
    ```sh
    $ make
    ```
3. Start the game
    ```sh
    $ ./watopoly
    ```
4. Follow the commands from terminal to play the game 🎲

## Plan of attack
The components are shared to build between teamate and are subject to change as the first plan of attack. We also breakdown the whole project relative classes/components with their relationship into the UML model diagram  
The completed plan of attack this problem can be found [HERE](./documents/initial_game_plan.pdf) and the UML model is [HERE](./documents/UML.pdf)

## Convention on parameters, classes, file names and preprocessor guards for contributors
Here we want to be consistent in naming each code components for the sake of readability and debugging activity

### Parameters
The parameters name, including variables and methods, should be in camelCase except for ID keywords (which is in allcaps)
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
Followed by the convention of CS246 course note, please note that DO NOT USE `using namespace std;` in the `.h` files to minimize the chance of conflict due to implicit interpretation
```CPP
#ifndef GAMESTATE_H
#define GAMESTATE_H

...

#endif
```

## Tools / Cheat sheet
1. To set up to track remote branch for reference without merging to your current branch
```sh
git branch -f <local_branch> origin/<remote_branch>
```
2. To check all active branches in remote repository
```sh
git ls-remote origin
```
3. To update the existence of a branch when you just created a new branch in remote repository
```sh
git fetch origin <remote_branch>
```

## Good luck and have fun :smile:

[watopoly-screenshot]: ./documents/watopoly_map.PNG