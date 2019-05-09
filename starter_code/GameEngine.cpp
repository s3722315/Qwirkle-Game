#include "GameEngine.h"

GameEngine::GameEngine(Player player1, Player player2)
{
  this->players[0] = player1;
  this->players[1] = player2;

  tileBag = Bag();

  board = new Tile*[6];
  for(int i = 0; i < sizeOf(board); i++)
  {
    board[i] = new Tile[6];
  }

  clearBoard();
}

bool placePiece(int playerNum, Tile placedTile, char yPos, int xPos)
{
  LinkedList* playerHand = nullptr;
  if (playerNum == 0) {
    /* code */
    playerHand = players[0].getHand();
  }
  else {
    playerHand = players[1].getHand();
  }

  if (playerHand != nullptr) {
    /* code */
    if (playerHand.contains(placedTile)) {
      /* code */
      
    }
  }
}

void GameEngine::clearBoard()
{
  for (int i = 0; i < sizeOf(board); i++) {
    /* code */
    for (int j = 0; j < sizeOf(board[i]); j++) {
      /* code */
      board[i][j] = NULL;
    }
  }
}

void GameEngine::expandBoard()
{
  if (checkRow(0) || checkColumn(0) || checkRow(sizeOf(board))
  || checkColumn(sizeOf(board[0]))) {
    /* code */
    if ((sizeOf(board) < 26) && (sizeOf(board[0]) < 26)
    && ((sizeOf(board[0]) + 2) <= 26)) {
      /* code */
      Tile** bigBoard = new bigBoard*[(sizeOf(board) + 2)];

      for(int i = 0; i < (sizeOf(board) + 2); i++)
      {
        bigBoard[i] = new Tile[(sizeOf(board) + 2)];
      }

      for (int i = 0; i < sizeOf(board); i++) {
        /* code */
        for (int j = 0; j < sizeOf(board[0]); j++) {
          /* code */
          bigBoard[i + 1][j + 1] = board[i][j];
        }
      }

      board = bigBoard;
    }
  }
}

bool gameEngine::checkRow(int row)
{
  bool needExpanding = false;
  if ((row < sizeOf(board)) && (row >= 0)) {
    /* code */
    for (int i = 0; i < sizeOf(board[row]); i++) {
      /* code */
      if (board[row][i] != null) {
        /* code */
        needExpanding = true;
      }
    }
  }

  return needExpanding;
}

bool gameEngine::checkColumn(int column)
{
  bool needExpanding = false;
  if ((column < sizeOf(board[0])) && (column >= 0)) {
    /* code */
    for (int i = 0; i < sizeOf(board); i++) {
      /* code */
      if (board[i][column] != null) {
        /* code */
        needExpanding = true;
      }
    }
  }

  return needExpanding;
}
