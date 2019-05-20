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
    void loadGame(std::string fileName);
    void save(std::string fileName, int currentPlayer);

    Player* loadPlayer(std::ifstream myfile)

    void help();

};
