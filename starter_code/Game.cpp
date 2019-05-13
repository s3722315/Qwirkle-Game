#include "Game.h"


void Game::menu()
{
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

    switch (menuSelect) {
      case 1:
      std::cout << "Starting a New Game" << '\n';
      try
      {
        std::cout << "Enter a name for player 1 (uppercase characters only)" << '\n';
        std::cin >> p1Name;
        if (p1Name.comapare()) {
          /* code */
        }
        std::cout << "Enter a name for player 2 (uppercase characters only)" << '\n';
        std::cin >> p2Name;

        std::cout << "Let's play" << '\n';
      }
      catch

      break;
      case 2:

      case 3:

      case 4:

    }
  }
}
