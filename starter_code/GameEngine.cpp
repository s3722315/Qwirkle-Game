#include "GameEngine.h"

GameEngine::GameEngine(Player player1, Player player2)
{
  this->players[0] = player1;
  this->players[1] = player2;

  this->tileBag = new Bag();

  this->board = new Tile*[6];
  for(int i = 0; i < sizeOf(this->board); i++)
  {
    this->board[i] = new Tile[6];
  }

  for (size_t i = 0; i < 2; i++) {
    /* code */
    this->players[0].initalHand(this->tileBag);
  }

  this->yIndexMap.insert(std::pair<char,int>('a',0));
  this->yIndexMap.insert(std::pair<char,int>('b',1));
  this->yIndexMap.insert(std::pair<char,int>('c',2));
  this->yIndexMap.insert(std::pair<char,int>('d',3));
  this->yIndexMap.insert(std::pair<char,int>('e',4));
  this->yIndexMap.insert(std::pair<char,int>('f',5));
  this->yIndexMap.insert(std::pair<char,int>('g',6));
  this->yIndexMap.insert(std::pair<char,int>('h',7));
  this->yIndexMap.insert(std::pair<char,int>('i',8));
  this->yIndexMap.insert(std::pair<char,int>('j',9));
  this->yIndexMap.insert(std::pair<char,int>('k',10));
  this->yIndexMap.insert(std::pair<char,int>('l',11));
  this->yIndexMap.insert(std::pair<char,int>('m',12));
  this->yIndexMap.insert(std::pair<char,int>('n',13));
  this->yIndexMap.insert(std::pair<char,int>('o',14));
  this->yIndexMap.insert(std::pair<char,int>('p',15));
  this->yIndexMap.insert(std::pair<char,int>('q',16));
  this->yIndexMap.insert(std::pair<char,int>('r',17));
  this->yIndexMap.insert(std::pair<char,int>('s',18));
  this->yIndexMap.insert(std::pair<char,int>('t',19));
  this->yIndexMap.insert(std::pair<char,int>('u',20));
  this->yIndexMap.insert(std::pair<char,int>('v',21));
  this->yIndexMap.insert(std::pair<char,int>('w',22));
  this->yIndexMap.insert(std::pair<char,int>('x',23));
  this->yIndexMap.insert(std::pair<char,int>('y',24));
  this->yIndexMap.insert(std::pair<char,int>('z',25));

  clearBoard();
}

bool GameEngine::placePiece(int playerNum, Tile placedTile, char yPos, int xPos)
{
  bool returnBool = false;
  if (playerNum == 0 || playerNum == 1)
  {
    if (this->players[playerNum] != NULL) {
      /* code */
      if ((this->players[playerNum].getHand()).contains(&placedTile)) {
        /* code */
        if ((this->yIndexMap.find(yPos) > sizeOf(this->board)) && xPos > sizeOf(this->board)) {
          /* code */
          if (this->board[this->yIndexMap.find(yPos)][xPos] == null) {
            /* code */
            Tile* placingTile = this->players[playerNum].placeTile(&placedTile, this->tileBag);

            this->board[this->yIndexMap.find(yPos)][xPos] = placingTile;

            returnBool = true;
          }
        }
      }
    }
  }

  if (returnBool == true) {
    /* code */

  }
  return returnBool;
}

bool GameEngine::replacePiece(int playerNum, Tile replacedTile)
{
  bool returnBool = false;
  if (playerNum == 0 || playerNum == 1)
  {
    if (this->players[playerNum] != NULL) {

      if ((this->players[playerNum].getHand()).contains(&placedTile)) {
        /* code */
        if ((this->yIndexMap.find(yPos) > sizeOf(this->board)) && xPos > sizeOf(this->board)) {
          /* code */
          if (this->board[this->yIndexMap.find(yPos)][xPos] == null) {
            /* code */
            this->players[playerNum].removeFromHand(&placedTile, this->tileBag);

            returnBool = true;
          }
        }
      }
    }
  }
  return returnBool;
}

bool GameEngine::checkGameOver()
{
  bool returnBool = false;
  for (int i = 0; i < 2; i++) {
    /* code */
    if (this->players[i] != NULL) {
      /* code */
      if ((this->player.getHand()).size() == 0) {
        /* code */
        returnBool = true;
      }
    }
  }

  return returnBool;
}

void GameEngine::clearBoard()
{
  for (int i = 0; i < sizeOf(this->board); i++) {
    /* code */
    for (int j = 0; j < sizeOf(this->board[i]); j++) {
      /* code */
      this->board[i][j] = NULL;
    }
  }
}

void GameEngine::expandBoard()
{
  if (checkRow(0) || checkColumn(0) || checkRow(sizeOf(this->board))
  || checkColumn(sizeOf(this->board[0]))) {
    /* code */
    if ((sizeOf(this->board) < 26) && (sizeOf(this->board[0]) < 26)
    && ((sizeOf(this->board[0]) + 2) <= 26)) {
      /* code */
      Tile** bigBoard = new bigBoard*[(sizeOf(this->board) + 2)];

      for(int i = 0; i < (sizeOf(this->board) + 2); i++)
      {
        bigBoard[i] = new Tile[(sizeOf(this->board) + 2)];
      }

      for (int i = 0; i < sizeOf(this->board); i++) {
        /* code */
        for (int j = 0; j < sizeOf(this->board[0]); j++) {
          /* code */
          bigBoard[i + 1][j + 1] = this->board[i][j];
        }
      }

      this->board = bigBoard;
    }
  }
}

bool GameEngine::checkRow(int row)
{
  bool needExpanding = false;
  if ((row < sizeOf(this->board)) && (row >= 0)) {
    /* code */
    for (int i = 0; i < sizeOf(this->board[row]); i++) {
      /* code */
      if (this->board[row][i] != null) {
        /* code */
        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

bool GameEngine::checkColumn(int column)
{
  bool needExpanding = false;
  if ((column < sizeOf(this->board[0])) && (column >= 0)) {
    /* code */
    for (int i = 0; i < sizeOf(this->board); i++) {
      /* code */
      if (this->board[i][column] != null) {
        /* code */
        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

void GameEngine::printBoard()
{
  for (size_t i = 0; i < sizeOf(this->board); i++) {
    /* code */
    if (i == 0) {
      /* code */
      std::cout << "   ";
    }

    std::cout << "  " << i;

    if (i == (sizeOf(this->board) - 1)) {
      /* code */
      std::cout << '\n';
    }
  }

  for (size_t i = 0; i < sizeOf(this->board); i++) {
    /* code */
    if (i == 0) {
      /* code */
      std::cout << "  -";
    }
    std::cout << "---";

    if (i == (sizeOf(this->board) - 1)) {
      /* code */
      std::cout << '\n';
    }
  }

  for (size_t i = 0; i < sizeOf(this->board); i++) {
    /* code */
    for (size_t j = 0; j < sizeOf(this->board[i]); j++) {
      /* code */
      if (j == 0) {
        /* code */
        std::cout << getKey(i) << " |";
      }

      if (this->board[i][j] == NULL) {
        /* code */
        std::cout << "  |";
      }
      else {

        std::cout << this->board[i][j].colour << this->board[i][j].shape << "|";
      }

      if (j == (sizeOf(this->board[i]) - 1)) {
        /* code */
        std::cout << '\n';
      }
    }
  }
}

char GameEngine::getKey(int value)
{
  char returnKey = NULL;
  for (auto& x: yIndexMap)
  {
    if (x.second == value) {
      /* code */
      returnKey = x.first;
    }
  }
  return returnKey;
}

bool GameEngine::checkPlaceable(Tile checkTile, int yPos, int xPos)
{

  if ((yPos - 1) < 0) {
    /* code */
    if (checkBoardPos(checkTile, yPos + 1, xPos)) {
      /* code */

    }
  }
  else if ((yPos + 1) >= sizeOf(this->board)) {
    /* code */

  }
  else if ((xPos - 1) < 0) {


  }
  else if ((xPos - 1) >= sizeOf(this->board)) {


  }
  else {

  }
}

bool GameEngine::checkCorner(Tile checkTile, int yPos, int xPos)
{
  bool returnBool = false;
  int emptyCount = 0;

  if (yPos == 0) {
    /* code */
    if (xPos == sizeOf(this->board) - 1) {
      /* code */
      if (this->board[yPos][xPos - 1] == NULL) {
        /* code */
      }
      else ()
    }
    else (xPos == 0) {


    }
  }

  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      /* code */

      if (this->board[yPos][xPos].colour == checkTile.colour) {
        /* code */
        returnBool = true;
      }
      else if (this->board[yPos][xPos].shape == checkTile.shape) {

        returnBool = true;
      }
    }
    else {

        returnBool = true;
    }

  }
  return returnBool;
}

bool GameEngine::checkPos(Tile checkTile, int yPos, int xPos) {
  bool returnBool = false;

  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      /* code */

      if (this->board[yPos][xPos].colour == checkTile.colour) {
        /* code */
        returnBool = true;
      }
      else if (this->board[yPos][xPos].shape == checkTile.shape) {

        returnBool = true;
      }
    }
    else {

        returnBool = true;
    }

  }
  return returnBool;
}
