#include "Game.h"

Game::Game()
{
  menu();
}

void Game::menu()
{
  bool menuOff = false;
  while (menuOff == false) {
    std::cout << "Menu" << '\n';
    std::cout << "----" << '\n';
    std::cout << "1. New Game" << '\n';
    std::cout << "2. Load Game" << '\n';
    std::cout << "3. Show student information" << '\n';
    std::cout << "4. Quit" << '\n';

    int menuSelect = 0;
    std::string p1Name;
    std::string p2Name;
    std::string menuString;
    std::cin >> menuString;
    std::cin.ignore();

    menuSelect = std::atoi(&menuString[0]);

    if (menuSelect == 1){
      std::cout << "Starting a New Game" << '\n';
      std::cout << "Enter a name for player 1 (uppercase characters only)" << '\n';
      std::cin >> p1Name;
      std::cin.ignore();

      std::cout << "Enter a name for player 2 (uppercase characters only)" << '\n';
      std::cin >> p2Name;
      std::cin.ignore();

      bool allCaps = true;
      for (int i = 0; i < (int)p1Name.length(); i++) {
        /* code */
        char c = p1Name[i];
        if (islower(c) != 0) {
          /* code */
          allCaps = false;
        }
      }
      for (int i = 0; i < (int)p2Name.length(); i++) {
        /* code */
        char c = p2Name[i];
        if (islower(c) != 0) {
          /* code */
          allCaps = false;
        }
      }

      if (allCaps == true) {
        /* code */
        std::cout << "Let's play" << '\n';
        this->gameEngine = GameEngine(new Player(p1Name), new Player(p2Name));
        startGame();
        menuOff = true;
      }
      else {
        std::cout << "Invalid Input" << '\n';
      }
    }
    else if( menuSelect == 2 ){

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
      menuOff = true;
    }
    else {
      std::cout << "Invalid Input" << '\n';
    }
   }
   std::cout << "Goodbye" << '\n';
}

void Game::startGame()
{
  bool gameEnded = false;
  int currentPlayer = 0;

  while (gameEnded == false) {
    /* code */
    std::cout << this->gameEngine.getPlayer(currentPlayer)->getName() << ". It's your turn" <<'\n';

    for (int i = 0; i < 2; i++) {
      /* code */
      std::cout << "Score for ";
      std::cout << this->gameEngine.getPlayer(i)->getName() <<": ";
      std::cout << this->gameEngine.getPlayer(i)->getScore() << '\n';
    }

    std::cout << this->gameEngine.boardToString() << '\n';
    std::cout << '\n';

    std::cout << "Your hand is" << '\n';
    std::cout << this->gameEngine.getHand(currentPlayer) << '\n';
    std::cout << '\n';

    bool turnEnded = false;
    bool gameSaved = false;
    bool quit = false;
    while (turnEnded == false) {
      std::string userOption;

      getline(std::cin, userOption);

      if (userOption.compare(0, 7, "replace") == 0) {
        /* code */
        if (userOption.length() == 10) {
          /* code */
          char inputColour = userOption[8];
          std::cout << inputColour << '\n';

          int inputShape = std::atoi(&userOption[9]);
          std::cout << inputShape << '\n';

          if (this->gameEngine.replacePiece(currentPlayer, Tile(inputColour, inputShape)) == true) {
            /* code */
            turnEnded = true;
          }
        }

      }
      else if (userOption.compare(0, 5, "place") == 0) {
        /* code */
        if (userOption.compare(9, 2, "at") == 0) {
          /* code */
          if (userOption.length() == 14 || userOption.length() == 15) {
            /* code */
            std::string tileInput = userOption.substr(6, 7);
            char inputColour = tileInput[0];
            int inputShape = std::atoi(&tileInput[1]);

            std::string inputPos = userOption.substr(12, userOption.length());
            char inputYPos = inputPos[0];
            int inputXPos = std::atoi(&inputPos[1]);

            if (this->gameEngine.placePiece(currentPlayer, Tile(inputColour, inputShape), inputYPos, inputXPos) == true) {

              turnEnded = true;
            }
          }
        }
      }
      else if (userOption.compare(0, 4, "save") == 0)
      {
        if (userOption.find(" ") > 0) {
          /* code */
          std::string saveFileName = userOption.substr(userOption.find(" ") + 1, userOption.length());
          save(saveFileName, currentPlayer);
          gameSaved = true;

          std::cout << "Game successfully saved" << '\n';
        }

      }
      else if (userOption.compare("quit") == 0) {

        quit = true;
      }
      // if (userOption == EOF) {
      //   /* code */
      // }

      if (turnEnded == false && gameSaved == false) {
        /* code */
        std::cout << "Invalid input" << '\n';
      }

      if (turnEnded == true) {
        /* code */
        if (this->gameEngine.checkGameOver() == true) {
          /* code */
          gameEnded = true;
        }

        if (currentPlayer == 1) {
          /* code */
          currentPlayer = 0;
        }
        else {

          currentPlayer++;
        }
      }

      if (quit == true) {
        /* code */
        turnEnded = true;
        gameEnded = true;
      }
    }
  }
}

void Game::save(std::string fileName, int currentPlayer)
{
  fileName += ".save";
  std::ofstream outFile;

  outFile.open(fileName);

  outFile << this->gameEngine.toString(currentPlayer);
  outFile.close();
}
