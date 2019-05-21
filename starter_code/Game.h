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

    void menu();
    void startGame(int playerTurn);
    void save(std::string fileName, int currentPlayer);

    bool loadGame(std::string fileName);

    Player* loadPlayer(std::ifstream& openFile);
    Tile*** loadBoard(std::ifstream& openFile, int* boardSize);
    Bag* loadBag(std::ifstream& openFile);

    void help();

};
