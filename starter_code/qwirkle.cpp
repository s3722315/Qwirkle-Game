
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

int main(void) {
   LinkedList* list = new LinkedList();
   delete list;

   std::cout << "TODO: Implement Qwirkle!" << std::endl;

   std::cout << "Welcome to Quirkle!" << '\n';
   std::cout << "-------------------" << '\n';

   bool menuOff = false;

   while (menuOff = false) {
     std::cout << "Menu\n" << '\n';
     std::cout << "----" << '\n';
     std::cout << "1. New Game" << '\n';
     std::cout << "2. Load Game" << '\n';
     std::cout << "3. Show student information" << '\n';
     std::cout << "4. Quit" << '\n';

     int menuSelect = 0;
     std::string p1Name;
     std::string p2Name;

     std::cin >> menuSelect;

    //Switch statments are not allowed in this course

    
    //causes errors needs working on
    
    if (menuSelect == 1){
      std::cout << "Starting a New Game" << '\n';
       std::cout << "Enter a name for player 1 (uppercase characters only)" << '\n';
       std::cin >> p1Name;
       std::cout << "Enter a name for player 2 (uppercase characters only)" << '\n';
       std::cin >> p2Name;

       std::cout << "Let's play" << '\n';
    }
    else if( menuSelect == 2 ){
    
    }
    else if( menuSelect == 3 ){
      
    }
    else if( menuSelect == 4 ){
      
    }
    
   }
   return EXIT_SUCCESS;
}
