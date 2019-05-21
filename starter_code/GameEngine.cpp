#include "GameEngine.h"

GameEngine::GameEngine(){}

  //Constructor for New Game
GameEngine::GameEngine(Player* player1, Player* player2, Player* player3,
  Player* player4)
{
  this->players[0] = player1;
  this->players[1] = player2;
  this->players[2] = player3;
  this->players[3] = player4;

  this->tileBag = new Bag();

  this->rowColSize = 6;

  //Making the board and setting it to nullptrs
  this->board = new Tile**[this->rowColSize];
  for(int i = 0; i < this->rowColSize; i++)
  {
    this->board[i] = new Tile*[rowColSize];
  }

  for(int i = 0; i < this->rowColSize; i++)
  {
    for(int j = 0; j < this->rowColSize; j++)
    {
      this->board[i][j] = nullptr;
    }
  }


  //initialising all player hands
  for (int i = 0; i < 4; i++) {

    this->players[i]->initalHand(this->tileBag);
  }

  makeYIndexMap();
}

//Constructor for a Loaded Game
GameEngine::GameEngine(Player* player1, Player* player2, Player* player3,
  Player* player4, Bag* bag, Tile*** board, int rowColSize)
{
  this->players[0] = player1;
  this->players[1] = player2;
  this->players[2] = player3;
  this->players[3] = player4;

  this->tileBag = bag;
  this->board = board;
  this->rowColSize = rowColSize;

  makeYIndexMap();

}

//PlacePiece Method
//The playerNum is to get the player from the array
bool GameEngine::placePiece(int playerNum, Tile placedTile, char yPos, int xPos)
{
  bool returnBool = false;

  //converting the yPos into a int
  int yPosInt = this->yIndexMap.find(yPos)->second;
  if (playerNum >= 0 && playerNum < 4)
  {;
    if (players[playerNum] != nullptr) {

      //checking if the player has the piece
      if ((this->players[playerNum]->getHand())->contains(&placedTile)) {

        if ((yPosInt < this->rowColSize) && xPos < this->rowColSize) {

          if (this->board[yPosInt][xPos] == nullptr) {

            //checks the surrounding positions of the wanted positon
            if (checkWantedPos(placedTile, yPosInt, xPos) == true) {

              //Making sure that the line of tiles connecting to has less than 6 tiles
              if (checkColAmount(yPosInt, xPos) < 6 && checkRowAmount(yPosInt, xPos) < 6) {

                //checking that the tile provided has colour or shape in commmon with the lines of tiles
                if (checkRowShape(placedTile, yPosInt, xPos) == true || checkRowColour(placedTile, yPosInt, xPos) == true) {

                  if (checkColShape(placedTile, yPosInt, xPos) == true || checkColColour(placedTile, yPosInt, xPos) == true) {

                    //place Tile onto board
                    Tile* placingTile = this->players[playerNum]->placeTile(&placedTile, this->tileBag);

                    this->board[yPosInt][xPos] = placingTile;

                    returnBool = true;
                  }
                }
              }
            }

            // if the board is empty allow for the placement of the tile anywhere
            else if (emptyBoard() == true)
            {
              Tile* placingTile = this->players[playerNum]->placeTile(&placedTile, this->tileBag);

              this->board[yPosInt][xPos] = placingTile;

              returnBool = true;
            }
          }
        }
      }
    }
  }

  //if tile placed calculate the points obtained and check for neeed of expansion
  if (returnBool == true) {

    pointUpdate(playerNum, yPosInt, xPos);
    expandBoard();
  }
  return returnBool;
}

//Replace Piece Method
//The playerNum is to get the player from the array
bool GameEngine::replacePiece(int playerNum, Tile replacedTile)
{
  bool returnBool = false;

  if (playerNum >= 0 && playerNum < 4)
  {
    if (this->players[playerNum] != nullptr) {

      //checks player has the tile
      if ((this->players[playerNum]->getHand())->contains(&replacedTile)) {

        this->players[playerNum]->replaceFromHand(&replacedTile, this->tileBag);
        returnBool = true;
      }
    }
  }
  return returnBool;
}

//This will check if any of the players hands are empty
bool GameEngine::checkGameOver()
{
  bool returnBool = false;
  //loops through all players
  for (int i = 0; i < 4; i++) {

    if (this->players[i] != nullptr) {

      //checking the players hand size
      if ((this->players[i]->getHand())->size() == 0) {

        returnBool = true;
      }
    }
  }

  return returnBool;
}

//Checks and expands the board when needed
void GameEngine::expandBoard()
{
  //check the parimeter of the board for any tiles
  if (checkRow(0) || checkColumn(0) || checkRow(this->rowColSize - 1)
  || checkColumn(this->rowColSize - 1)) {

    //Checks that the board isn't already 26*26
    if ((this->rowColSize < 26) && ((this->rowColSize + 2) <= 26)) {

      //creating new board, which is 2 rows and columns bigger
      Tile*** bigBoard = new Tile**[this->rowColSize + 2];

      for(int i = 0; i < (this->rowColSize + 2); i++)
      {
        bigBoard[i] = new Tile*[this->rowColSize + 2];
      }

      for (int i = 0; i < (this->rowColSize + 2); i++) {

        for (int j = 0; j < (this->rowColSize + 2); j++) {

          bigBoard[i][j] = nullptr;
        }
      }

      //converting the tiles
      for (int i = 0; i < this->rowColSize; i++) {

        for (int j = 0; j < this->rowColSize; j++) {

          bigBoard[i + 1][j + 1] = this->board[i][j];
        }
      }

      //replacing board and updating rowColSize
      this->board = bigBoard;
      this->rowColSize = this->rowColSize + 2;
    }
  }
}

//Checks the row for tiles
bool GameEngine::checkRow(int row)
{
  bool needExpanding = false;
  if ((row < this->rowColSize) && (row >= 0)) {

    for (int i = 0; i < this->rowColSize; i++) {

      if (this->board[row][i] != nullptr) {

        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

//Checks the column for tiles
bool GameEngine::checkColumn(int column)
{
  bool needExpanding = false;
  if ((column < this->rowColSize) && (column >= 0)) {

    for (int i = 0; i < this->rowColSize; i++) {

      if (this->board[i][column] != nullptr) {

        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

//A method to get the board in a string form
std::string GameEngine::boardToString()
{
  std::string returnString = "";

  //making xAXis
  for (int i = 0; i < this->rowColSize; i++) {

    if (i == 0) {

      returnString += "   ";
    }
    if (i < 10) {

      returnString += "  ";
      returnString += std::to_string(i);
    }
    else {
      returnString += " ";
      returnString += std::to_string(i);
    }

    if (i == (this->rowColSize - 1)) {

      returnString += '\n';
    }
  }

  for (int i = 0; i < this->rowColSize; i++) {

    if (i == 0) {

      returnString += "  -";
    }
    returnString += "---";

    if (i == this->rowColSize - 1) {

      returnString += '\n';
    }
  }

  //making Yaxis
  for (int i = 0; i < this->rowColSize; i++) {

    for (int j = 0; j < this->rowColSize; j++) {

      if (j == 0) {

        //converting the yAxis into letters
        returnString += getKey(i);
        returnString += " |";
      }

      //printing tiles
      if (this->board[i][j] == nullptr) {

        returnString += "  |";
      }
      else {

        returnString += this->board[i][j]->colour;
        returnString += std::to_string(this->board[i][j]->shape);
        returnString += "|";
      }

      if (j == (this->rowColSize - 1)) {

        returnString += '\n';
      }
    }
  }
  return returnString;
}

// Method to get the key from the Map
char GameEngine::getKey(int value)
{
  char returnKey = '\0';
  for (auto& x: yIndexMap)
  {
    if (x.second == value) {

      returnKey = x.first;
    }
  }
  return returnKey;
}

//Method that checks if the position on the board allows for placement of checkTile Next to it
bool GameEngine::checkPos(Tile checkTile, int yPos, int xPos) {
  bool returnBool = false;

  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {

      //check if the tile and tile in the position have something in common
      if (this->board[yPos][xPos] == nullptr) {

        returnBool = true;
      }
      else if (this->board[yPos][xPos]->shape == checkTile.shape) {

        returnBool = true;
      }
      else if (this->board[yPos][xPos]->colour == checkTile.colour) {

        returnBool = true;
      }
    }
  }
  return returnBool;
}

//Method that checks surrounding tiles for if the tile is placeable
bool GameEngine::checkWantedPos(Tile checkTile, int yPos, int xPos)
{
  bool returnBool = false;

  //amount of checkable postions around the given position
  int checkableSides = 4;

  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {

      //updating checkable sides
      int sideCount = sideCounter(yPos, xPos);
      checkableSides = checkableSides - sideCount;
      int acceptCount = 0;
      int nullCount = nullChecker(yPos, xPos);

      //checking the positions around given position
      if (checkPos(checkTile, yPos - 1, xPos) == true) {

        acceptCount++;
      }
      if (checkPos(checkTile, yPos + 1, xPos) == true) {

        acceptCount++;
      }
      if (checkPos(checkTile, yPos, xPos - 1) == true) {

        acceptCount++;
      }
      if (checkPos(checkTile, yPos, xPos + 1) == true) {

        acceptCount++;
      }

      //making sure that all tile is in a position with other tiles next to it
      if (nullCount < checkableSides && acceptCount == checkableSides) {

        returnBool = true;
      }
    }
  }

  return returnBool;
}

//Checks the amount of positions around the given position
int GameEngine::sideCounter(int yPos, int xPos)
{
  int sideCounter = 0;
  if (yPos - 1 < 0) {

    sideCounter++;
  }
  if (yPos + 1 >= this->rowColSize) {

    sideCounter++;
  }
  if (xPos - 1 < 0) {

    sideCounter++;
  }
  if (xPos + 1 >= this->rowColSize) {

    sideCounter++;
  }

  return sideCounter;
}

//checks the amount of empty board places around the given position
int GameEngine::nullChecker(int yPos, int xPos)
{
  int nullCount = 0;
  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {
      if (yPos - 1 >= 0) {

        if (board[yPos - 1][xPos] == nullptr) {

          nullCount++;
        }
      }

      if (xPos - 1 >= 0) {

        if (this->board[yPos][xPos - 1] == nullptr) {

          nullCount++;
        }
      }

      if (yPos + 1 < this->rowColSize) {

        if (this->board[yPos + 1][xPos] == nullptr) {

          nullCount++;
        }
      }

      if (xPos + 1 < this->rowColSize) {

        if (this->board[yPos][xPos + 1] == nullptr) {

          nullCount++;
        }
      }
    }

  }
  return nullCount;
}

//updates the points for Players[playerNum]
void GameEngine::pointUpdate(int playerNum, int yPos, int xPos)
{
  if (playerNum >= 0 && playerNum < 4) {

    //checking the amount of tiles in a horizontal & vertical line
    if (checkRowAmount(yPos, xPos) < 6 && checkRowAmount(yPos, xPos) > 0) {

      this->players[playerNum]->addScore(checkRowAmount(yPos, xPos) + 1);
    }
    if (checkColAmount(yPos, xPos) < 6 && checkColAmount(yPos, xPos) > 0) {

      this->players[playerNum]->addScore(checkColAmount(yPos, xPos) + 1);
    }

    //updating score for a tile placed on a empty board
    if (checkColAmount(yPos, xPos) == 0 && checkRowAmount(yPos, xPos) == 0) {


      this->players[playerNum]->addScore(1);
    }

    //printing qwirkle to show that it is the 6th tile in that line
    if (checkColAmount(yPos, xPos) == 5 || checkRowAmount(yPos, xPos) == 5) {


      std::cout << "QWIRKLE!!!" << '\n';
    }
  }

}

//check The number of tiles in a line horizontal
int GameEngine::checkRowAmount(int yPos, int xPos)
{
  int rowAmount = 0;
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool leftStop = false;
  bool rightStop = false;


  if (yPos >= 0 && yPos < this->rowColSize) {
    //checks the left side to the postion
    while (leftCheck >= 0 && leftStop == false) {

      if (this->board[yPos][leftCheck] != nullptr) {

        rowAmount++;
      }
      else {
        leftStop = true;
      }

      leftCheck--;
    }

    //checks the right side to the postion
    while (rightCheck < this->rowColSize && rightStop == false) {

      if (this->board[yPos][rightCheck] != nullptr) {

        rowAmount++;
      }
      else {
        rightStop = true;
      }
      rightCheck++;
    }
  }

  return rowAmount;
}

//check The number of tiles in a line vertically
int GameEngine::checkColAmount(int yPos, int xPos)
{
  int colAmount = 0;
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool upStop = false;
  bool downStop = false;

  if (xPos >= 0 && xPos < this->rowColSize) {

    //checks on top of position
    while (upCheck >= 0 && upStop == false) {

      if (this->board[upCheck][xPos] != nullptr) {

        colAmount++;
      }
      else {
        upStop = true;
      }

      upCheck--;
    }

    //checks bellow position
    while (downCheck < this->rowColSize && downStop == false) {

      if (this->board[downCheck][xPos] != nullptr) {

        colAmount++;
      }
      else {
        downStop = true;
      }
      downCheck++;
    }
  }

  return colAmount;
}

//The next four methods are very similar in functionality
//checks if the given Tile has the same colour as those in the horizontal line
bool GameEngine::checkRowColour(Tile checkTile, int yPos, int xPos)
{
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool rowSameColour = true;
  bool leftStop = false;
  bool rightStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {
      // checking left of the position given
      while(leftCheck >= 0 && leftStop == false && rowSameColour == true) {

        if (this->board[yPos][leftCheck] != nullptr) {

          //checking if given tile has the same colour as the tile being checked
          if (this->board[yPos][leftCheck]->colour == checkTile.colour) {

            //making sure that there is no duplicate of the tile in the line already
            if (this->board[yPos][leftCheck]->shape == checkTile.shape) {

              leftStop = true;
              rowSameColour = false;
            }
          }
          else {
            leftStop = true;
            rowSameColour = false;
          }
        }
        else {
          leftStop = true;
        }
        //now check next position
        leftCheck--;
      }

      //check right side of the given position
      //almost hte same as left check
      while(rightCheck < this->rowColSize && rightStop == false && rowSameColour == true) {
        if (this->board[yPos][rightCheck] != nullptr) {

          if (this->board[yPos][rightCheck]->colour == checkTile.colour) {

            if (this->board[yPos][rightCheck]->shape == checkTile.shape) {

              leftStop = true;
              rowSameColour = false;
            }
          }
          else {
            rightStop = true;
            rowSameColour = false;
          }
        }
        else {
          rightStop = true;
        }
        rightCheck++;
      }

    }
  }

  return rowSameColour;
}

//checks if the given Tile has the same shape as those in the horizontal line
bool GameEngine::checkRowShape(Tile checkTile, int yPos, int xPos)
{
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool rowSameShape = true;
  bool leftStop = false;
  bool rightStop = false;


  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {
      while(leftCheck >= 0 && leftStop == false && rowSameShape == true) {
        if (this->board[yPos][leftCheck] != nullptr) {

          if (this->board[yPos][leftCheck]->shape == checkTile.shape) {

            if (this->board[yPos][leftCheck]->colour == checkTile.colour) {

              leftStop = true;
              rowSameShape = false;
            }
          }
          else {
            leftStop = true;
            rowSameShape = false;
          }
        }
        else {
          leftStop = true;
        }
        leftCheck--;
      }

      while(rightCheck < this->rowColSize && rightStop == false && rowSameShape == true) {
        if (this->board[yPos][rightCheck] != nullptr) {

          if (this->board[yPos][rightCheck]->shape == checkTile.shape) {

            if (this->board[yPos][rightCheck]->colour == checkTile.colour) {

              leftStop = true;
              rowSameShape = false;
            }
          }
          else {
            rightStop = true;
            rowSameShape = false;
          }
        }
        else {
          rightStop = true;
        }
        rightCheck++;
      }

    }
  }

  return rowSameShape;
}

//checks if the given Tile has the same colour as those in the vertical line
bool GameEngine::checkColColour(Tile checkTile, int yPos, int xPos)
{
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool colSameColour = true;
  bool upStop = false;
  bool downStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != nullptr) {

          if (this->board[upCheck][xPos]->colour == checkTile.colour) {

            if (this->board[upCheck][xPos]->shape == checkTile.shape) {

              upStop = true;
              colSameColour = false;
            }
          }
          else {
            upStop = true;
            colSameColour = false;
          }
        }
        else {
          upStop = true;
        }
        upCheck--;
      }

      while(downCheck < this->rowColSize && downStop == false && colSameColour == true) {
        if (this->board[downCheck][xPos] != nullptr) {

          if (this->board[downCheck][xPos]->colour == checkTile.colour) {

            if (this->board[downCheck][xPos]->shape == checkTile.shape) {

              downStop = true;
              colSameColour = false;
            }
          }
          else {
            downStop = true;
            colSameColour = false;
          }
        }
        else {
          downStop = true;
        }
        downCheck++;
      }

    }
  }

  return colSameColour;
}

//checks if the given Tile has the same shape as those in the vertical line
bool GameEngine::checkColShape(Tile checkTile, int yPos, int xPos)
{
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool colSameColour = true;
  bool upStop = false;
  bool downStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {

    if (xPos >= 0 && xPos < this->rowColSize) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != nullptr) {

          if (this->board[upCheck][xPos]->shape == checkTile.shape) {

            if (this->board[upCheck][xPos]->colour == checkTile.colour) {

              upStop = true;
              colSameColour = false;
            }
          }
          else {
            upStop = true;
            colSameColour = false;
          }
        }
        else {
          upStop = true;
        }
        upCheck--;
      }

      while(downCheck < this->rowColSize && downStop == false && colSameColour == true) {
        if (this->board[downCheck][xPos] != nullptr) {

          if (this->board[downCheck][xPos]->shape == checkTile.shape) {

            if (this->board[downCheck][xPos]->colour == checkTile.colour) {

              downStop = true;
              colSameColour = false;
            }
          }
          else {
            downStop = true;
            colSameColour = false;
          }
        }
        else {
          downStop = true;
        }
        downCheck++;
      }

    }
  }

  return colSameColour;
}

//check if the board is empty
bool GameEngine::emptyBoard()
{
  bool empty = true;
  for (int i = 0; i < this->rowColSize; i++) {

    for (int j = 0; j < this->rowColSize; j++) {

      if (this->board[i][j] != nullptr) {

        empty = false;
      }
    }
  }

  return empty;
}

//makes the yIndexMap
void GameEngine::makeYIndexMap()
{
  this->yIndexMap.insert(std::pair<char,int>('A',0));
  this->yIndexMap.insert(std::pair<char,int>('B',1));
  this->yIndexMap.insert(std::pair<char,int>('C',2));
  this->yIndexMap.insert(std::pair<char,int>('D',3));
  this->yIndexMap.insert(std::pair<char,int>('E',4));
  this->yIndexMap.insert(std::pair<char,int>('F',5));
  this->yIndexMap.insert(std::pair<char,int>('G',6));
  this->yIndexMap.insert(std::pair<char,int>('H',7));
  this->yIndexMap.insert(std::pair<char,int>('I',8));
  this->yIndexMap.insert(std::pair<char,int>('J',9));
  this->yIndexMap.insert(std::pair<char,int>('K',10));
  this->yIndexMap.insert(std::pair<char,int>('L',11));
  this->yIndexMap.insert(std::pair<char,int>('M',12));
  this->yIndexMap.insert(std::pair<char,int>('N',13));
  this->yIndexMap.insert(std::pair<char,int>('O',14));
  this->yIndexMap.insert(std::pair<char,int>('P',15));
  this->yIndexMap.insert(std::pair<char,int>('Q',16));
  this->yIndexMap.insert(std::pair<char,int>('R',17));
  this->yIndexMap.insert(std::pair<char,int>('S',18));
  this->yIndexMap.insert(std::pair<char,int>('T',19));
  this->yIndexMap.insert(std::pair<char,int>('U',20));
  this->yIndexMap.insert(std::pair<char,int>('V',21));
  this->yIndexMap.insert(std::pair<char,int>('W',22));
  this->yIndexMap.insert(std::pair<char,int>('X',23));
  this->yIndexMap.insert(std::pair<char,int>('Y',24));
  this->yIndexMap.insert(std::pair<char,int>('Z',25));
}

//converts the game to a toString for the save function
std::string GameEngine::toString(int playerNum)
{
  std::string returnString = "";
  if (this->players[0] != nullptr && this->players[1] != nullptr &&
    this->players[2] != nullptr && this->players[3] != nullptr)
  {
    if (this->tileBag != nullptr) {

      //list all the player info
      for (int i = 0; i < 4; i++) {

        returnString += this->players[i]->toString();
        returnString += '\n';
      }

      //add the board and bag
      returnString += boardToString();
      returnString += this->tileBag->toString();
      returnString += '\n';

      //add the current current player
      returnString += this->players[playerNum]->getName();
    }
  }

  return returnString;
}

//converts the wanted players hand into a string
std::string GameEngine::getHand(int playerNum)
{
  std::string returnString = "";
  if (playerNum >= 0 && playerNum < 4)
  {
    returnString += this->players[playerNum]->getHand()->toString();
  }

  return returnString;
}

Player* GameEngine::getPlayer(int playerNum)
{
  Player* returnPlayer = nullptr;
  if (playerNum >= 0 && playerNum < 4) {

    returnPlayer = this->players[playerNum];
  }
  return returnPlayer;
}
