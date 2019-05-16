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

  this->yIndexMap.insert(std::pair<char,int>('A',0));
  this->yIndexMap.insert(std::pair<char,int>('B',1));
  this->yIndexMap.insert(std::pair<char,int>('C',2));
  this->yIndexMap.insert(std::pair<char,int>('D',3));
  this->yIndexMap.insert(std::pair<char,int>('E',4));
  this->yIndexMap.insert(std::pair<char,int>('F',5));
  this->yIndexMap.insert(std::pair<char,int>('G',6));
  this->yIndexMap.insert(std::pair<char,int>('H,7));
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
            if (checkWantedPos(placedTile, this->yIndexMap.find(yPos), xPos) == true) {
              /* code */
              if (checkColAmount(yPos, xPos) < 6 && checkRowAmount(yPos, xPos) < 6) {
                /* code */
                if (checkRowShape(yPos, xPos) == true || checkRowColour(yPos, xPos) == true) {
                  /* code */
                  if (checkColShape(yPos, xPos) == true || checkColColour(yPos, xPos) == true) {
                    /* code */
                    Tile* placingTile = this->players[playerNum].placeTile(&placedTile, this->tileBag);

                    this->board[this->yIndexMap.find(yPos)][xPos] = placingTile;

                    returnBool = true;
                  }
                }
              }
            }
            else if (emptyBoard() = true)
            {
              Tile* placingTile = this->players[playerNum].placeTile(&placedTile, this->tileBag);

              this->board[this->yIndexMap.find(yPos)][xPos] = placingTile;

              returnBool = true;
            }
          }
        }
      }
    }
  }

  if (returnBool == true) {
    /* code */
    pointUpdate(playerNum, this->yIndexMap.find(yPos), xPos);
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
          this->players[playerNum].removeFromHand(&placedTile, this->tileBag);

          returnBool = true;
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


bool GameEngine::checkPos(Tile checkTile, int yPos, int xPos) {
  bool returnBool = false;

  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      if (this->board[yPos][xPos].colour == checkTile.colour) {
        /* code */
        returnBool = true;
      }
      else if (this->board[yPos][xPos].shape == checkTile.shape) {

        returnBool = true;
      }
      else if (this->board[yPos][xPos] == NULL) {
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
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
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
  if (yPos + 1 >= sizeOf(this->Board)) {
    /* code */
    sideCounter++;
  }
  if (xPos - 1 < 0) {
    /* code */
    sideCounter++;
  }
  if (xPos + 1 >= sizeOf(this->Board[0])) {
    /* code */
    sideCounter++;
  }

  return sideCounter;
}

int GameEngine::nullChecker(int yPos, int xPos)
{
  int nullCount = 0;
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board)) {
      if (yPos - 1 >= 0) {
        /* code */
        if (this->board[yPos - 1][xPos] == NULL) {
          /* code */
          nullCount++;
        }
      }

      if (xPos - 1 >= 0) {
        /* code */
        if (this->board[yPos][xPos - 1] == NULL) {
          /* code */
          nullCount++;
        }
      }

      if (yPos + 1 < sizeOf(this->board)) {
        /* code */
        if (this->board[yPos + 1][xPos] == NULL) {
          /* code */
          nullCount++;
        }
      }

      if (xPos + 1 < sizeOf(this->board[0])) {
        /* code */
        if (this->board[yPos][xPos  1] == NULL) {
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
  if (playerNum = 0 || playerNum = 1) {
    /* code */
    if (checkRowAmount(yPos, xPos) < 6 && checkRowAmount(yPos, xPos) > 0) {
      /* code */
      player[playerNum].addScore(checkRowAmount(yPos, xPos) + 1);
    }
    if (checkColAmount(yPos, xPos) < 6 && checkColAmount(yPos, xPos) > 0) {
      /* code */
      player[playerNum].addScore(checkColAmount(yPos, xPos) + 1);
    }

    if (checkColAmount(yPos, xPos) == 0 && checkRowAmount(yPos, xPos) == 0) {
      /* code */

      player[playerNum].addScore(1);
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

  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    while (leftCheck >= 0 && leftStop == false) {
      /* code */
      if (this->board[yPos][leftCheck] != NULL) {
        /* code */
        rowAmount++;
      }
      else {
        leftStop = true;
      }

      leftCheck--;
    }

    while (rightCheck < sizeOf(this->board[yPos]) && rightStop == false) {
      /* code */
      if (this->board[yPos][rightCheck] != NULL) {
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

  if (xPos >= 0 && xPos < sizeOf(this->board[0])) {
    while (upCheck >= 0 && upStop == false) {
      /* code */
      if (this->board[yPos][upCheck] != NULL) {
        /* code */
        colAmount++;
      }
      else {
        upStop = true;
      }

      upCheck--;
    }

    while (downCheck < sizeOf(this->board[yPos]) && downStop == false) {
      /* code */
      if (this->board[yPos][downCheck] != NULL) {
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
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      while(leftCheck >= 0 && leftStop == false && rowSameColour == true) {
        if (this->board[yPos][leftCheck] != NULL) {
          /* code */
          if (this->board[yPos][leftCheck].colour == checkTile.colour) {
            /* code */
            if (this->board[yPos][leftCheck].shape == checkTile.shape) {
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

      while(rightCheck < sizeOf(this->board[yPos]) && rightStop == false && rowSameColour == true) {
        if (this->board[yPos][rightCheck] != NULL) {
          /* code */
          if (this->board[yPos][rightCheck].colour == checkTile.colour) {
            /* code */
            if (this->board[yPos][rightCheck].shape == checkTile.shape) {
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
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      while(leftCheck >= 0 && leftStop == false && rowSameShape == true) {
        if (this->board[yPos][leftCheck] != NULL) {
          /* code */
          if (this->board[yPos][leftCheck].shape == checkTile.shape) {
            /* code */
            if (this->board[yPos][leftCheck].colour == checkTile.colour) {
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

      while(rightCheck < sizeOf(this->board[yPos]) && rightStop == false && rowSameShape == true) {
        if (this->board[yPos][rightCheck] != NULL) {
          /* code */
          if (this->board[yPos][rightCheck].shape == checkTile.shape) {
            /* code */
            if (this->board[yPos][rightCheck].colour == checkTile.colour) {
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
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != NULL) {
          /* code */
          if (this->board[upCheck][xPos].colour == checkTile.colour) {
            /* code */
            if (this->board[upCheck][xPos].shape == checkTile.shape) {
              /* code */
              leftStop = true;
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

      while(downCheck < sizeOf(this->board[yPos]) && downStop == false && colSameColour == true) {
        if (this->board[downCheck][xPos] != NULL) {
          /* code */
          if (this->board[downCheck][xPos].colour == checkTile.colour) {
            /* code */
            if (this->board[downCheck][xPos].shape == checkTile.shape) {
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
  if (yPos >= 0 && yPos < sizeOf(this->board)) {
    /* code */
    if (xPos >= 0 && xPos < sizeOf(this->board[yPos])) {
      while(upCheck >= 0 && upStop == false && colSameColour == true) {
        if (this->board[upCheck][xPos] != NULL) {
          /* code */
          if (this->board[upCheck][xPos].shape == checkTile.shape) {
            /* code */
            if (this->board[upCheck][xPos].colour == checkTile.colour) {
              /* code */
              leftStop = true;
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

      while(downCheck < sizeOf(this->board[yPos]) && downStop == false && colSameColour == true) {
        if (this->board[downCheck][xPos] != NULL) {
          /* code */
          if (this->board[downCheck][xPos].shape == checkTile.shape) {
            /* code */
            if (this->board[downCheck][xPos].colour == checkTile.colour) {
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

  for (size_t i = 0; i < sizeOf(this->board); i++) {
    /* code */
    for (size_t j = 0; j < sizeOf(this->board[i]); j++) {
      /* code */
      if (this->board[i][j] != NULL) {
        /* code */
        empty = false;
      }
    }
  }

  return empty;
}
