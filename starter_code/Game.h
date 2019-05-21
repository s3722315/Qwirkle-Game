// this class is for the console print,
#include <ctype.h>
#include <string>
#include <fstream>
#include "GameEngine.h"


class Game {
  private:
    GameEngine gameEngine;
  public:
    Game();

    //the menu
    void menu();

    //the game output
    void startGame(int playerTurn);

    //saves the current game
    void save(std::string fileName, int currentPlayer);

    //loads in a game
    bool loadGame(std::string fileName);

    //loads in the player info
    Player* loadPlayer(std::ifstream& openFile);

    //loads in the board
    Tile*** loadBoard(std::ifstream& openFile, int* boardSize);

    //loads in the bag
    Bag* loadBag(std::ifstream& openFile);

    //checks if the string is all caps
    bool checkAllCaps(std::string checkString);


};
