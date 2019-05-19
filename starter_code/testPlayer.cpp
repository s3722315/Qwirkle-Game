#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"
// #include "Bag.h"
#include "Player.h"
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
  LinkedList playerList = LinkedList();

  playerList.addFront(new Tile(RED, DIAMOND));
  playerList.addFront(new Tile(GREEN, DIAMOND));
  playerList.addFront(new Tile(PURPLE, DIAMOND));
  playerList.addFront(new Tile(BLUE, DIAMOND));
  playerList.addFront(new Tile(YELLOW, DIAMOND));
  playerList.addFront(new Tile(ORANGE, DIAMOND));


  Player* player = new Player("Player", 3, &playerList);
  Bag* bag = new Bag(&bagList);
  std::cout << "Bag:  " << bag->toString() << '\n';
  std::cout << "Player:  ";
  player->printHand();
  std::cout << '\n';

  player->placeTile(new Tile(RED, DIAMOND), bag);
  std::cout << "Bag:  " << bag->toString() << '\n';
  std::cout << "Player:  ";
  player->printHand();
  std::cout << '\n';

  player->replaceFromHand(new Tile(BLUE, DIAMOND), bag);
  std::cout << "Bag:  " << bag->toString() << '\n';
  std::cout << "Player:  ";
  player->printHand();
  std::cout << '\n';

  delete bag;
  delete player;

  std::cout << "TODO: Implement Qwirkle!" << std::endl;

  return EXIT_SUCCESS;
}
