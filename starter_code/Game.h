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
    void startGame();
    void loadGame();
    void save(std::string fileName, int currentPlayer);

    void help();

};
