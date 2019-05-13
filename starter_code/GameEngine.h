#include "Tile.h"
#include "LinkedList.h"
#include "Player.h"
#include <map>
#include <string>

class GameEngine {
  private:
    Tile** board;
    Player players[2];
    Bag* tileBag;
    std::map<char, int> yIndexMap;
  public:
    GameEngine(Player player1, Player player2);

    bool placePiece(int playerNum, Tile placedTile, char yPos, int xPos);

    bool replacePiece(int playerNum, Tile replacedTile);

    bool checkGameOver();

    void endGame(bool gameEnded);

    void clearBoard();

    void expandBoard();

    bool checkRow(int row);

    bool checkColumn(int column);

    // void boardToString();

    void printBoard();

    char getKey(int value);

    bool checkPlaceable(Tile checkTile, int yPos, int xPos);

    bool checkCorner(Tile checkTile, int yPos, int xPos);

    bool checkPos(Tile checkTile, int yPos, int xPos);
}
