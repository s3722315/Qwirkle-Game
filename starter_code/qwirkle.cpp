
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
    
    if (menuSelect == 1){
       std::cout << "Starting a New Game" << '\n';
       std::cout << "Enter a name for player 1 (uppercase characters only)" << '\n';
       std::cin >> p1Name;
       std::cout << "Enter a name for player 2 (uppercase characters only)" << '\n';
       std::cin >> p2Name;

       std::cout << "Let's play" << '\n';
    }
    else if( menuSelect == 2 ){

       //loadgame here

    }
    else if( menuSelect == 3 ){
       std::cout << "Name: Yousef Fares" << '\n';
       std::cout << "Student ID: 3724131" << '\n';
       std::cout << "Email: s3724131@student.rmit.edu.au" << '\n';

       std::cout << '\n' << "Name: Andy Pham" << '\n';
       std::cout << "Student ID: 3722315" << '\n';
       std::cout << "Email: s3722315@student.rmit.edu.au" << '\n';

       std::cout << '\n' << "Name: Wenlin Zhang" << '\n';
       std::cout << "Student ID: 3629698" << '\n';
       std::cout << "Email: s3629698@student.rmit.edu.au" << '\n';
    }
    else if( menuSelect == 4 ){
      std::cout << "Goodbye" << '\n';
      exit(0); 

    }
    
   }
   return EXIT_SUCCESS;
}
