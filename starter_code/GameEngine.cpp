#include "GameEngine.h"

GameEngine::GameEngine(){}

GameEngine::GameEngine(Player* player1, Player* player2, Player* player3,
  Player* player4)
{
  this->players[0] = player1;
  this->players[1] = player2;
  this->players[2] = player3;
  this->players[3] = player4;

  this->tileBag = new Bag();

  this->rowColSize = 6;
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


  for (int i = 0; i < 4; i++) {
    /* code */
    this->players[i]->initalHand(this->tileBag);
  }

  makeYIndexMap();
}

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

bool GameEngine::placePiece(int playerNum, Tile placedTile, char yPos, int xPos)
{
  bool returnBool = false;
  int yPosInt = this->yIndexMap.find(yPos)->second;
  if (playerNum >= 0 && playerNum < 4)
  {;
    if (players[playerNum] != nullptr) {
      /* code */
      if ((this->players[playerNum]->getHand())->contains(&placedTile)) {
        /* code */
        if ((yPosInt < this->rowColSize) && xPos < this->rowColSize) {
          /* code */
          if (this->board[yPosInt][xPos] == nullptr) {
            /* code */
            if (checkWantedPos(placedTile, yPosInt, xPos) == true) {
              /* code */
              if (checkColAmount(yPosInt, xPos) < 6 && checkRowAmount(yPosInt, xPos) < 6) {
                /* code */
                if (checkRowShape(placedTile, yPosInt, xPos) == true || checkRowColour(placedTile, yPosInt, xPos) == true) {
                  /* code */
                  if (checkColShape(placedTile, yPosInt, xPos) == true || checkColColour(placedTile, yPosInt, xPos) == true) {
                    /* code */
                    Tile* placingTile = this->players[playerNum]->placeTile(&placedTile, this->tileBag);

                    this->board[yPosInt][xPos] = placingTile;

                    returnBool = true;
                  }
                }
              }
            }
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

  if (returnBool == true) {
    /* code */
    pointUpdate(playerNum, yPosInt, xPos);
    expandBoard();
  }
  return returnBool;
}

bool GameEngine::replacePiece(int playerNum, Tile replacedTile)
{
  bool returnBool = false;

  if (playerNum >= 0 && playerNum < 4)
  {
    if (this->players[playerNum] != nullptr) {

      if ((this->players[playerNum]->getHand())->contains(&replacedTile)) {
        /* code */
        this->players[playerNum]->replaceFromHand(&replacedTile, this->tileBag);
        returnBool = true;
      }
    }
  }
  return returnBool;
}

bool GameEngine::checkGameOver()
{
  bool returnBool = false;
  for (int i = 0; i < 4; i++) {
    /* code */
    if (this->players[i] != nullptr) {
      /* code */
      if ((this->players[i]->getHand())->size() == 0) {
        /* code */
        returnBool = true;
      }
    }
  }

  return returnBool;
}

void GameEngine::expandBoard()
{
  if (checkRow(0) || checkColumn(0) || checkRow(this->rowColSize - 1)
  || checkColumn(this->rowColSize - 1)) {
    /* code */
    if ((this->rowColSize < 26) && ((this->rowColSize + 2) <= 26)) {
      /* code */
      Tile*** bigBoard = new Tile**[this->rowColSize + 2];

      for(int i = 0; i < (this->rowColSize + 2); i++)
      {
        bigBoard[i] = new Tile*[this->rowColSize + 2];
      }

      for (int i = 0; i < (this->rowColSize + 2); i++) {
        /* code */
        for (int j = 0; j < (this->rowColSize + 2); j++) {
          /* code */
          bigBoard[i][j] = nullptr;
        }
      }

      for (int i = 0; i < this->rowColSize; i++) {
        /* code */
        for (int j = 0; j < this->rowColSize; j++) {
          /* code */
          bigBoard[i + 1][j + 1] = this->board[i][j];
        }
      }

      this->board = bigBoard;
      this->rowColSize = this->rowColSize + 2;
    }
  }
}

bool GameEngine::checkRow(int row)
{
  bool needExpanding = false;
  if ((row < this->rowColSize) && (row >= 0)) {
    /* code */
    for (int i = 0; i < this->rowColSize; i++) {
      /* code */
      if (this->board[row][i] != nullptr) {
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
  if ((column < this->rowColSize) && (column >= 0)) {
    /* code */
    for (int i = 0; i < this->rowColSize; i++) {
      /* code */
      if (this->board[i][column] != nullptr) {
        /* code */
        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

std::string GameEngine::boardToString()
{
  std::string returnString = "";
  for (int i = 0; i < this->rowColSize; i++) {
    /* code */
    if (i == 0) {
      /* code */
      returnString += "   ";
    }
    if (i < 10) {
      /* code */
      returnString += "  ";
      returnString += std::to_string(i);
    }
    else {
      returnString += " ";
      returnString += std::to_string(i);
    }

    if (i == (this->rowColSize - 1)) {
      /* code */
      returnString += '\n';
    }
  }

  for (int i = 0; i < this->rowColSize; i++) {
    /* code */
    if (i == 0) {
      /* code */
      returnString += "  -";
    }
    returnString += "---";

    if (i == this->rowColSize - 1) {
      /* code */
      returnString += '\n';
    }
  }
  for (int i = 0; i < this->rowColSize; i++) {
    /* code */
    for (int j = 0; j < this->rowColSize; j++) {
      /* code */
      if (j == 0) {
        /* code */
        returnString += getKey(i);
        returnString += " |";
      }
      if (this->board[i][j] == nullptr) {
        /* code */
        returnString += "  |";
      }
      else {

        returnString += this->board[i][j]->colour;
        returnString += std::to_string(this->board[i][j]->shape);
        returnString += "|";
      }

      if (j == (this->rowColSize - 1)) {
        /* code */
        returnString += '\n';
      }
    }
  }
  return returnString;
}

char GameEngine::getKey(int value)
{
  char returnKey = '\0';
  for (auto& x: yIndexMap)
  {
    if (x.second == value) {
      /* code */
      returnKey = x.first;
    }
  }
  return returnKey;
}


bool GameEngine::checkPos(Tile checkTile, int yPos, int xPos) {
  bool returnBool = false;

  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {

      if (this->board[yPos][xPos] == nullptr) {
        /* code */
        returnBool = true;
      }
      else if (this->board[yPos][xPos]->shape == checkTile.shape) {

        returnBool = true;
      }
      else if (this->board[yPos][xPos]->colour == checkTile.colour) {
        /* code */
        returnBool = true;
      }
    }
  }
  return returnBool;
}

bool GameEngine::checkWantedPos(Tile checkTile, int yPos, int xPos)
{
  bool returnBool = false;
  int checkableSides = 4;
  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      /* code */
      int sideCount = sideCounter(yPos, xPos);
      checkableSides = checkableSides - sideCount;
      int acceptCount = 0;
      int nullCount = nullChecker(yPos, xPos);

      if (checkPos(checkTile, yPos - 1, xPos) == true) {
        /* code */
        acceptCount++;
      }
      if (checkPos(checkTile, yPos + 1, xPos) == true) {
        /* code */
        acceptCount++;
      }
      if (checkPos(checkTile, yPos, xPos - 1) == true) {
        /* code */
        acceptCount++;
      }
      if (checkPos(checkTile, yPos, xPos + 1) == true) {
        /* code */
        acceptCount++;
      }

      if (nullCount < checkableSides && acceptCount == checkableSides) {
        /* code */
        returnBool = true;
      }
    }
  }

  return returnBool;
}

int GameEngine::sideCounter(int yPos, int xPos)
{
  int sideCounter = 0;
  if (yPos - 1 < 0) {
    /* code */
    sideCounter++;
  }
  if (yPos + 1 >= this->rowColSize) {
    /* code */
    sideCounter++;
  }
  if (xPos - 1 < 0) {
    /* code */
    sideCounter++;
  }
  if (xPos + 1 >= this->rowColSize) {
    /* code */
    sideCounter++;
  }

  return sideCounter;
}

int GameEngine::nullChecker(int yPos, int xPos)
{
  int nullCount = 0;
  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      if (yPos - 1 >= 0) {
        /* code */
        if (board[yPos - 1][xPos] == nullptr) {
          /* code */
          nullCount++;
        }
      }

      if (xPos - 1 >= 0) {
        /* code */
        if (this->board[yPos][xPos - 1] == nullptr) {
          /* code */
          nullCount++;
        }
      }

      if (yPos + 1 < this->rowColSize) {
        /* code */
        if (this->board[yPos + 1][xPos] == nullptr) {
          /* code */
          nullCount++;
        }
      }

      if (xPos + 1 < this->rowColSize) {
        /* code */
        if (this->board[yPos][xPos + 1] == nullptr) {
          /* code */
          nullCount++;
        }
      }
    }

  }
  return nullCount;
}

void GameEngine::pointUpdate(int playerNum, int yPos, int xPos)
{
  if (playerNum >= 0 && playerNum < 4) {
    /* code */
    if (checkRowAmount(yPos, xPos) < 6 && checkRowAmount(yPos, xPos) > 0) {
      /* code */
      this->players[playerNum]->addScore(checkRowAmount(yPos, xPos) + 1);
    }
    if (checkColAmount(yPos, xPos) < 6 && checkColAmount(yPos, xPos) > 0) {
      /* code */
      this->players[playerNum]->addScore(checkColAmount(yPos, xPos) + 1);
    }

    if (checkColAmount(yPos, xPos) == 0 && checkRowAmount(yPos, xPos) == 0) {
      /* code */

      this->players[playerNum]->addScore(1);
    }
  }

}

int GameEngine::checkRowAmount(int yPos, int xPos)
{
  int rowAmount = 0;
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool leftStop = false;
  bool rightStop = false;


  if (yPos >= 0 && yPos < this->rowColSize) {
    while (leftCheck >= 0 && leftStop == false) {
      /* code */
      if (this->board[yPos][leftCheck] != nullptr) {
        /* code */
        rowAmount++;
      }
      else {
        leftStop = true;
      }

      leftCheck--;
    }

    while (rightCheck < this->rowColSize && rightStop == false) {
      /* code */
      if (this->board[yPos][rightCheck] != nullptr) {
        /* code */
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

int GameEngine::checkColAmount(int yPos, int xPos)
{
  int colAmount = 0;
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool upStop = false;
  bool downStop = false;

  if (xPos >= 0 && xPos < this->rowColSize) {
    while (upCheck >= 0 && upStop == false) {
      /* code */
      if (this->board[upCheck][xPos] != nullptr) {
        /* code */
        colAmount++;
      }
      else {
        upStop = true;
      }

      upCheck--;
    }

    while (downCheck < this->rowColSize && downStop == false) {
      /* code */
      if (this->board[downCheck][xPos] != nullptr) {
        /* code */
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

bool GameEngine::checkRowColour(Tile checkTile, int yPos, int xPos)
{
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool rowSameColour = true;
  bool leftStop = false;
  bool rightStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      while(leftCheck >= 0 && leftStop == false && rowSameColour == true) {

        if (this->board[yPos][leftCheck] != nullptr) {
          /* code */
          if (this->board[yPos][leftCheck]->colour == checkTile.colour) {
            /* code */
            if (this->board[yPos][leftCheck]->shape == checkTile.shape) {
              /* code */
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
        leftCheck--;
      }

      while(rightCheck < this->rowColSize && rightStop == false && rowSameColour == true) {
        if (this->board[yPos][rightCheck] != nullptr) {
          /* code */
          if (this->board[yPos][rightCheck]->colour == checkTile.colour) {
            /* code */
            if (this->board[yPos][rightCheck]->shape == checkTile.shape) {
              /* code */
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

bool GameEngine::checkRowShape(Tile checkTile, int yPos, int xPos)
{
  int leftCheck = xPos - 1;
  int rightCheck = xPos + 1;

  bool rowSameShape = true;
  bool leftStop = false;
  bool rightStop = false;


  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      while(leftCheck >= 0 && leftStop == false && rowSameShape == true) {
        if (this->board[yPos][leftCheck] != nullptr) {
          /* code */
          if (this->board[yPos][leftCheck]->shape == checkTile.shape) {
            /* code */
            if (this->board[yPos][leftCheck]->colour == checkTile.colour) {
              /* code */
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
          /* code */
          if (this->board[yPos][rightCheck]->shape == checkTile.shape) {
            /* code */
            if (this->board[yPos][rightCheck]->colour == checkTile.colour) {
              /* code */
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

bool GameEngine::checkColColour(Tile checkTile, int yPos, int xPos)
{
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool colSameColour = true;
  bool upStop = false;
  bool downStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != nullptr) {
          /* code */
          if (this->board[upCheck][xPos]->colour == checkTile.colour) {
            /* code */
            if (this->board[upCheck][xPos]->shape == checkTile.shape) {
              /* code */
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
          /* code */
          if (this->board[downCheck][xPos]->colour == checkTile.colour) {
            /* code */
            if (this->board[downCheck][xPos]->shape == checkTile.shape) {
              /* code */
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

bool GameEngine::checkColShape(Tile checkTile, int yPos, int xPos)
{
  int upCheck = yPos - 1;
  int downCheck = yPos + 1;

  bool colSameColour = true;
  bool upStop = false;
  bool downStop = false;

  if (yPos >= 0 && yPos < this->rowColSize) {
    /* code */
    if (xPos >= 0 && xPos < this->rowColSize) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != nullptr) {
          /* code */
          if (this->board[upCheck][xPos]->shape == checkTile.shape) {
            /* code */
            if (this->board[upCheck][xPos]->colour == checkTile.colour) {
              /* code */
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
          /* code */
          if (this->board[downCheck][xPos]->shape == checkTile.shape) {
            /* code */
            if (this->board[downCheck][xPos]->colour == checkTile.colour) {
              /* code */
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

bool GameEngine::emptyBoard()
{
  bool empty = true;
  for (int i = 0; i < this->rowColSize; i++) {
    /* code */
    for (int j = 0; j < this->rowColSize; j++) {
      /* code */
      if (this->board[i][j] != nullptr) {
        /* code */
        empty = false;
      }
    }
  }

  return empty;
}

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

std::string GameEngine::toString(int playerNum)
{
  std::string returnString = "";
  if (this->players[0] != nullptr && this->players[1] != nullptr &&
    this->players[2] != nullptr && this->players[3] != nullptr)
  {
    if (this->tileBag != nullptr) {
      /* code */
      for (int i = 0; i < 4; i++) {
        /* code */
        returnString += this->players[i]->toString();
        returnString += '\n';
      }

      returnString += boardToString();
      returnString += this->tileBag->toString();
      returnString += '\n';

      returnString += this->players[playerNum]->getName();
    }
  }

  return returnString;
}

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
    /* code */
    returnPlayer = this->players[playerNum];
  }
  return returnPlayer;
}
