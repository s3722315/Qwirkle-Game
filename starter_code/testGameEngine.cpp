#include "GameEngine.h"
#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"
// #include "Bag.h"
// #include "Player.h"
#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {

  LinkedList bagList = LinkedList();

  bagList.addFront(new Tile(RED, CIRCLE));
  bagList.addFront(new Tile(GREEN, CIRCLE));
  bagList.addFront(new Tile(PURPLE, CIRCLE));
  bagList.addFront(new Tile(BLUE, CIRCLE));
  bagList.addFront(new Tile(YELLOW, CIRCLE));
  bagList.addFront(new Tile(RED, SQUARE));
  bagList.addFront(new Tile(GREEN, SQUARE));
  bagList.addFront(new Tile(PURPLE, SQUARE));
  bagList.addFront(new Tile(BLUE, SQUARE));
  bagList.addFront(new Tile(YELLOW, SQUARE));

  std::cout << "List:  " << bagList.toString() << '\n';
  LinkedList player1List = LinkedList();

  player1List.addFront(new Tile(RED, DIAMOND));
  player1List.addFront(new Tile(GREEN, DIAMOND));
  player1List.addFront(new Tile(PURPLE, DIAMOND));
  player1List.addFront(new Tile(BLUE, DIAMOND));
  player1List.addFront(new Tile(YELLOW, DIAMOND));
  player1List.addFront(new Tile(ORANGE, DIAMOND));

  LinkedList player2List = LinkedList();

  player2List.addFront(new Tile(RED, CLOVER));
  player2List.addFront(new Tile(GREEN, DIAMOND));
  player2List.addFront(new Tile(PURPLE, CLOVER));
  player2List.addFront(new Tile(BLUE, CLOVER));
  player2List.addFront(new Tile(YELLOW, CLOVER));
  player2List.addFront(new Tile(ORANGE, CLOVER));

  std::cout << "PLayers made" << '\n';
  Player* player1 = new Player("Player1", 3, &player1List);
  Player* player2 = new Player("player2", 2, &player2List);
  Bag* bag = new Bag(&bagList);

  std::cout << "bag made" << '\n';

  Tile*** board = new Tile**[6];
  for(int i = 0; i < 6; i++)
  {
    board[i] = new Tile*[6];
  }

  for (size_t i = 0; i < 6; i++) {
    /* code */
    for (size_t j = 0; j < 6; j++) {
      /* code */
      board[i][j] = nullptr;
    }
  }
  // board[1][1] = new Tile(RED, STAR_4);

  std::cout << "board made" << '\n';
  std::cout << sizeof(*board)/sizeof(Tile*)<< '\n';

  GameEngine* gameEngine = new GameEngine(player1, player2, bag, board, 6);
  std::cout << "game engine made" << '\n';

  // std::cout << "Bag:  " << bag->toString() << '\n';
  std::cout << "Player1:  ";
  player1->printHand();
  std::cout << '\n';
  std::cout << "Player2:  ";
  player2->printHand();
  std::cout << '\n';

  std::cout << gameEngine->toString(0) << '\n';

  bool piecePlaced = gameEngine->placePiece(0, Tile(RED, DIAMOND), 'B', 1);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(BLUE, DIAMOND), 'C', 1);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(PURPLE, DIAMOND), 'D', 1);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(ORANGE, DIAMOND), 'E', 1);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(YELLOW, DIAMOND), 'F', 1);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(YELLOW, CIRCLE), 'B', 2);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(0, Tile(YELLOW, DIAMOND), 'B', 2);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(GREEN, DIAMOND), 'A', 2);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(GREEN, DIAMOND), 'D', 3);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(ORANGE, CLOVER), 'F', 3);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(PURPLE, CLOVER), 'F', 4);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->replacePiece(1, Tile(PURPLE, CLOVER));
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(YELLOW, CLOVER), 'G', 3);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(BLUE, CLOVER), 'H', 3);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(RED, CLOVER), 'J', 4);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(PURPLE, CLOVER), 'L', 5);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(YELLOW, CIRCLE), 'J', 7);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(BLUE, CIRCLE), 'K', 7);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(RED, CIRCLE), 'L', 7);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(PURPLE, CIRCLE), 'M', 7);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  piecePlaced = gameEngine->placePiece(1, Tile(GREEN, CIRCLE), 'N', 7);
  std::cout << piecePlaced << '\n';
  std::cout << gameEngine->toString(0) << '\n';

  bool gameEnded = gameEngine->checkGameOver();
  std::cout << "Game is Over" << gameEnded <<'\n';
  delete bag;
  delete player1;
  delete player2;

  std::cout << "TODO: Implement Qwirkle!" << std::endl;

  return EXIT_SUCCESS;
}
