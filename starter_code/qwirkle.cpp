
#include "LinkedList.h"
#include "Game.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   //calls the game
   Game game = Game();

   return EXIT_SUCCESS;
}
