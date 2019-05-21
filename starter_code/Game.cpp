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
    std::string p3Name;
    std::string p4Name;

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

      std::cout << "Enter a name for player 3 (uppercase characters only)" << '\n';
      std::cin >> p3Name;
      std::cin.ignore();

      std::cout << "Enter a name for player 4 (uppercase characters only)" << '\n';
      std::cin >> p4Name;
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
      for (int i = 0; i < (int)p3Name.length(); i++) {
        /* code */
        char c = p3Name[i];
        if (islower(c) != 0) {
          /* code */
          allCaps = false;
        }
      }
      for (int i = 0; i < (int)p4Name.length(); i++) {
        /* code */
        char c = p4Name[i];
        if (islower(c) != 0) {
          /* code */
          allCaps = false;
        }
      }

      if (allCaps == true) {
        /* code */
        std::cout << "Let's play" << '\n';
        this->gameEngine = GameEngine(new Player(p1Name), new Player(p2Name),
      new Player(p3Name), new Player(p4Name));
        startGame(0);
        menuOff = true;
      }
      else {
        std::cout << "Invalid Input" << '\n';
      }
    }
    else if( menuSelect == 2 ){

      std::cout << "Enter the filename from which load a game" << '\n';
      std::string loadFile;
      std::cin >> loadFile;
      std::cin.ignore();

      menuOff = loadGame(loadFile);
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

void Game::startGame(int playerTurn)
{
  bool gameEnded = false;
  int currentPlayer = playerTurn;

  while (gameEnded == false) {
    /* code */
    std::cout << this->gameEngine.getPlayer(currentPlayer)->getName() << ". It's your turn" <<'\n';

    for (int i = 0; i < 4; i++) {
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
    bool quit = false;
    while (turnEnded == false) {
      std::string userOption;
      bool gameSaved = false;
      bool helped = false;

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
      else if (userOption.compare("help") == 0) {

        std::cout << "Commands:" << '\n';
        std::cout << "  replace <TILE> : will replace the <TILE> in Hand" << '\n';
        std::cout << "  place <TILE> at <POSITION>: will place the <TILE> in Hand" << '\n';
        std::cout << "       onto the board at <POSITION>. Yaxis then Xaxis, eXample 'B1'" << '\n';
        std::cout << "  save <FILENAME> : save the current progress of the game to" << '\n';
        std::cout << "       a file named <FILENAME>" << '\n';
        std::cout << "  quit : leave the game" << '\n';

        helped = true;
      }
      // if (userOption == EOF) {
      //   /* code */
      // }
      if (quit == true) {
        /* code */
        turnEnded = true;
        gameEnded = true;
      }

      if (turnEnded == false && gameSaved == false && helped == false) {
        /* code */
        std::cout << "Invalid input" << '\n';
        std::cout << "Enter 'help' for command list" << '\n';
      }

      if (turnEnded == true) {
        /* code */
        if (this->gameEngine.checkGameOver() == true) {
          /* code */
          gameEnded = true;
        }

        if (currentPlayer == 3) {
          /* code */
          currentPlayer = 0;
        }
        else {
          currentPlayer++;
        }
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

bool Game::loadGame(std::string fileName)
{
  bool gameLoaded = false;
  std::string line;
  fileName += ".save";
  std::ifstream openFile(fileName);

  if (openFile.is_open()) {
    Player* p1 = loadPlayer(openFile);
    Player* p2 = loadPlayer(openFile);
    Player* p3 = loadPlayer(openFile);
    Player* p4 = loadPlayer(openFile);

    int* boardSize = new int(0);
    Tile*** board = loadBoard(openFile, boardSize);

    Bag* bag = loadBag(openFile);

    getline(openFile, line);
    std::string currentPlayer = line;
    std::cout << currentPlayer << '\n';
    std::cout << p1->getName() << '\n';
    int currentPlayerNum = 0;

    if (currentPlayer.compare(p1->getName()) == 0) {
      /* code */
      currentPlayerNum = 0;
    }
    else if (currentPlayer.compare(p2->getName()) == 0) {
      /* code */
      currentPlayerNum = 1;
    }
    else if (currentPlayer.compare(p3->getName()) == 0) {
      /* code */
      currentPlayerNum = 2;
    }
    else if (currentPlayer.compare(p4->getName()) == 0) {
      /* code */
      currentPlayerNum = 3;
    }

    std::cout << currentPlayerNum << '\n';
    this->gameEngine = GameEngine(p1, p2, p3, p4, bag, board, *boardSize);

    gameLoaded = true;
    openFile.close();
    startGame(currentPlayerNum);
  }
  else {
    std::cout << "Invalid Input" << '\n';
  }

  return gameLoaded;
}

Player* Game::loadPlayer(std::ifstream& openFile)
{
  Player* player = nullptr;

  if (openFile.is_open()) {
    /* code */
    std::string line;
    getline(openFile, line);
    std::string playerName;
    playerName = line;
    int playerScore;

    getline(openFile, line);
    playerScore = std::atoi(&line[0]);

    getline(openFile, line);
    std::string handString;
    handString = line;
    std::string tile;

    LinkedList* playerHand = new LinkedList();

    while (handString.find(",") != std::string::npos)
    {
      tile = handString.substr(0, handString.find(","));

      char readColour = tile[0];
      int readShape = std::atoi(&tile[1]);

      playerHand->addBack(new Tile(readColour, readShape));

      handString = handString.substr(handString.find(",") + 1, handString.length());

    }
    char lastColour = handString[0];
    int lastShape = std::atoi(&handString[1]);

    playerHand->addBack(new Tile(lastColour, lastShape));

    player = new Player(playerName, playerScore, playerHand);

  }
  return player;
}

Tile*** Game::loadBoard(std::ifstream& openFile, int* boardSize)
{
  std::string line;
  Tile*** board = nullptr;
  if (openFile.is_open()) {

    getline(openFile, line);
    std::string xAxis;
    xAxis = line;
    int rowCount = 0;

    for (size_t i = 0; i < xAxis.size(); i++) {
      /* code */
      if(std::isdigit(xAxis[i]))
      {
        rowCount++;
      }
    }

    if (rowCount > 10) {
      /* code */
      rowCount = rowCount - 10;
      rowCount = rowCount/2;
      rowCount = rowCount + 10;
    }

    *boardSize = rowCount;

    board = new Tile**[rowCount];
    for(int i = 0; i < rowCount; i++)
    {
      board[i] = new Tile*[rowCount];
    }

    for (int i = 0; i < rowCount; i++) {
      /* code */
      for (int j = 0; j < rowCount; j++) {
        /* code */
        board[i][j] = nullptr;
      }
    }

    getline(openFile, line);
    for (int i = 0; i < rowCount; i++) {
      /* code */
      getline(openFile, line);
      std::string row = line.substr(line.find("|") + 1, line.length());
      for (int j = 0; j < rowCount; j++) {
        /* code */
        if (line.find("|") != std::string::npos) {
          /* code */
          std::string pos = row.substr(0, row.find("|"));

          if (pos.compare("  ") == 0) {
          }
          else {
            char posColour = pos[0];
            int posShape = std::atoi(&pos[1]);

            board[i][j] = new Tile(posColour, posShape);
          }

          row = row.substr(row.find("|") + 1, row.length());
        }
      }
    }
  }
  return board;
}

Bag* Game::loadBag(std::ifstream& openFile)
{
  Bag* testBag = nullptr;
  if (openFile.is_open()) {
    std::string line;

    getline(openFile, line);
    std::string bag = line;
    LinkedList* bagTiles = new LinkedList();

    while (bag.find(",") != std::string::npos)
    {
      std::string tile = bag.substr(0, bag.find(","));

      char readColour = tile[0];
      int readShape = std::atoi(&tile[1]);

      bagTiles->addBack(new Tile(readColour, readShape));

      bag = bag.substr(bag.find(",") + 1, bag.length());

    }
    char lastColour = bag[0];
    int lastShape = std::atoi(&bag[1]);

    bagTiles->addBack(new Tile(lastColour, lastShape));

    testBag = new Bag(bagTiles);
  }

  return testBag;
}
