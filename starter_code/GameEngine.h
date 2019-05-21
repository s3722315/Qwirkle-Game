#include "Tile.h"
#include "LinkedList.h"
#include "Player.h"
#include <map>
#include <string>
#include <cstddef>

class GameEngine {
  private:
    //A 2D array of pointers to Tiles
    Tile*** board;

    Player* players[4];
    Bag* tileBag;

    //A Map used to convert Characters to numbers
    std::map<char, int> yIndexMap;

    //Number of rows/columns for the board
    int rowColSize;
  public:
    GameEngine();

    //Constructor for New Game
    GameEngine(Player* player1, Player* player2, Player* player3,
      Player* player4);

    //Constructor for a Loaded Game
    GameEngine(Player* player1, Player* player2, Player* player3,
      Player* player4, Bag* bag, Tile*** board, int rowColSize);

    //PlacePiece Method
    //The playerNum is to get the player from the array
    bool placePiece(int playerNum, Tile placedTile, char yPos, int xPos);

    //Replace Piece Method
    //The playerNum is to get the player from the array
    bool replacePiece(int playerNum, Tile replacedTile);

    //This will check if any of the players hands are empty
    bool checkGameOver();

    //Checks and expands the board when needed
    void expandBoard();

    //Checks the row for tiles
    bool checkRow(int row);

    //Checks the column for tiles
    bool checkColumn(int column);

    //A method to get the board in a string form
    std::string boardToString();

    // Method to get the key from the Map
    char getKey(int value);

    //Method that checks if the position on the board allows for placement of checkTile Next to it
    bool checkPos(Tile checkTile, int yPos, int xPos);

    //Method that checks surrounding tiles for if the tile is placeable
    bool checkWantedPos(Tile checkTile, int yPos, int xPos);

    //Checks the amount of positions around the given position
    int sideCounter(int yPos, int xPos);

    //checks the amount of empty board places around the given position
    int nullChecker(int yPos, int xPos);

    //updates the points for Players[playerNum]
    void pointUpdate(int playerNum, int yPos, int xPos);

    //check The number of tiles in a line horizontal
    int checkRowAmount(int yPos, int xPos);

    //check The number of tiles in a line vertically
    int checkColAmount(int yPos, int xPos);

    //The next four methods are very similar in functionality
    //checks if the given Tile has the same colour as those in the horizontal line
    bool checkRowColour(Tile checkTile, int yPos, int xPos);

    //checks if the given Tile has the same shape as those in the horizontal line
    bool checkRowShape(Tile checkTile, int yPos, int xPos);

    //checks if the given Tile has the same colour as those in the vertical line
    bool checkColColour(Tile checkTile, int yPos, int xPos);

    //checks if the given Tile has the same shape as those in the vertical line
    bool checkColShape(Tile checkTile, int yPos, int xPos);


    //check if the board is empty
    bool emptyBoard();

    //makes the yIndexMap
    void makeYIndexMap();

    //converts the game to a toString for the save function
    std::string toString(int playerNum);

    //converts the wanted players hand into a string
    std::string getHand(int playerNum);

    Player* getPlayer(int playerNum);

};
