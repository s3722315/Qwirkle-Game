#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();

   list->addFront(new Tile(RED, CIRCLE));
   list->printAll();
   std::cout << '\n';

   list->addBack(new Tile(YELLOW, SQUARE));
   list->printAll();
   std::cout << '\n';

   list->addFront(new Tile(GREEN, STAR_4));
   list->printAll();
   std::cout << '\n';

   list->addFront(new Tile(PURPLE, STAR_4));
   list->printAll();
   std::cout << '\n';

   list->addBack(new Tile(BLUE, SQUARE));
   list->printAll();
   std::cout << '\n';

   std::cout << list->contains(new Tile(GREEN, STAR_4)) << '\n';

   std::cout << list->size() << '\n';
   list->deleteBack();
   list->printAll();
   std::cout << '\n';

   list->removeNode(new Tile(RED, CIRCLE));
   list->printAll();
   std::cout << '\n';

   list->deleteFront();
   list->printAll();
   std::cout << '\n';

   std::cout << list->toString() << '\n';

   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}
