#include "Tile.h"
#include "LinkedList.h"
#include "Player.h"
#include <map>
#include <string>
#include <cstddef>

class GameEngine {
  private:
    Tile*** board;
    Player* players[2];
    Bag* tileBag;
    std::map<char, int> yIndexMap;
    int rowColSize;
  public:
    GameEngine();

    GameEngine(Player* player1, Player* player2);

    GameEngine(Player* player1, Player* player2, Bag* bag, Tile*** board, int rowColSize);

    bool placePiece(int playerNum, Tile placedTile, char yPos, int xPos);

    bool replacePiece(int playerNum, Tile replacedTile);

    bool checkGameOver();

    void expandBoard();

    bool checkRow(int row);

    bool checkColumn(int column);

    // void boardToString();

    std::string boardToString();

    char getKey(int value);

    bool checkPos(Tile checkTile, int yPos, int xPos);

    bool checkWantedPos(Tile checkTile, int yPos, int xPos);

    int sideCounter(int yPos, int xPos);

    int nullChecker(int yPos, int xPos);

    void pointUpdate(int playerNum, int yPos, int xPos);

    int checkRowAmount(int yPos, int xPos);

    int checkColAmount(int yPos, int xPos);

    bool checkRowColour(Tile checkTile, int yPos, int xPos);

    bool checkRowShape(Tile checkTile, int yPos, int xPos);

    bool checkColColour(Tile checkTile, int yPos, int xPos);

    bool checkColShape(Tile checkTile, int yPos, int xPos);

    bool emptyBoard();

    std::string toString(int playerNum);

    std::string getHand(int playerNum);
};
