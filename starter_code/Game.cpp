#include "Game.h"

Game::Game()
{
  menu();
}

//the menu
void Game::menu()
{
  //to turn off the menu
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
    //check if input is end of file
    if (!std::cin.eof()) {

      //get the string that the user entered
      std::cin >> menuString;
      std::cin.ignore();

      menuSelect = std::atoi(&menuString[0]);
    }
    else {
      menuSelect = 4;
    }

    //new game
    if (menuSelect == 1){

      std::cout << "Starting a New Game" << '\n';
      std::cout << "Enter a name for player 1 (uppercase characters only)" << '\n';

      bool skip = false;

      //asking for player names
      if (!std::cin.eof()) {
        std::cin >> p1Name;
        std::cin.ignore();

        std::cout << "Enter a name for player 2 (uppercase characters only)" << '\n';
        if (!std::cin.eof()) {
          std::cin >> p2Name;
          std::cin.ignore();

          std::cout << "Enter a name for player 3 (uppercase characters only)" << '\n';
          if (!std::cin.eof()) {
            std::cin >> p3Name;
            std::cin.ignore();

            std::cout << "Enter a name for player 4 (uppercase characters only)" << '\n';
            if (!std::cin.eof()) {
            std::cin >> p4Name;
            std::cin.ignore();
            }
            else {
              menuOff = true;
              skip = true;
            }
          }
          else {
            menuOff = true;
            skip = true;
          }
        }
        else {
          menuOff = true;
          skip = true;
        }
      }
      else {
        menuOff = true;
        skip = true;
      }

      if (skip == false) {

        //checking if all player names are in caps
        bool allCaps = true;
        allCaps = checkAllCaps(p1Name);
        allCaps = checkAllCaps(p2Name);
        allCaps = checkAllCaps(p3Name);
        allCaps = checkAllCaps(p4Name);

        if (allCaps == true) {

          //create the new game
          std::cout << "Let's play" << '\n';
          this->gameEngine = GameEngine(new Player(p1Name), new Player(p2Name),
        new Player(p3Name), new Player(p4Name));

          //start the new game with player 1s turn
          startGame(0);
          menuOff = true;
        }
        else {
          std::cout << "Invalid Input" << '\n';
        }
      }
    }

    //load game
    else if( menuSelect == 2 ){

      std::cout << "Enter the filename from which load a game" << '\n';
      std::string loadFile;

      //look for the file and attempt to load game
      if (!std::cin.eof()) {
        std::cin >> loadFile;
        std::cin.ignore();

        menuOff = loadGame(loadFile);
      }
      else {
        menuOff = true;
      }
    }

    //group information
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

    //quit
    else if( menuSelect == 4 ){
      menuOff = true;
    }
    else {
      std::cout << "Invalid Input" << '\n';
    }
   }
   std::cout << "Goodbye" << '\n';
}

//the game output
void Game::startGame(int playerTurn)
{
  bool gameEnded = false;
  //current playersTurn
  int currentPlayer = playerTurn;

  //loop till game is left or ends
  while (gameEnded == false) {

    //display player info and board
    std::cout << this->gameEngine.getPlayer(currentPlayer)->getName() << ". It's your turn" <<'\n';

    for (int i = 0; i < 4; i++) {

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

    //loop for the current player turn
    while (turnEnded == false) {
      std::string userOption;
      bool gameSaved = false;
      bool helped = false;

      //check the players input
      if (!std::cin.eof()) {
        getline(std::cin, userOption);
      }
      else {
        userOption = "quit";
      }

      //check if player is replacing piece
      if (userOption.compare(0, 7, "replace") == 0) {

        if (userOption.length() == 10) {

          char inputColour = userOption[8];
          std::cout << inputColour << '\n';

          int inputShape = std::atoi(&userOption[9]);
          std::cout << inputShape << '\n';

          //attempt to replace piece
          if (this->gameEngine.replacePiece(currentPlayer, Tile(inputColour, inputShape)) == true) {

            turnEnded = true;
          }
        }

      }

      //checking if player is placing piece
      else if (userOption.compare(0, 5, "place") == 0) {

        if (userOption.compare(9, 2, "at") == 0) {

          if (userOption.length() == 14 || userOption.length() == 15) {

            std::string tileInput = userOption.substr(6, 7);
            char inputColour = tileInput[0];
            int inputShape = std::atoi(&tileInput[1]);

            std::string inputPos = userOption.substr(12, userOption.length());
            char inputYPos = inputPos[0];
            int inputXPos = std::atoi(&inputPos[1]);

            //attempt to place piece
            if (this->gameEngine.placePiece(currentPlayer, Tile(inputColour, inputShape), inputYPos, inputXPos) == true) {

              turnEnded = true;
            }
          }
        }
      }

      //save the game
      else if (userOption.compare(0, 4, "save") == 0)
      {
        if (userOption.find(" ") > 0) {

          std::string saveFileName = userOption.substr(userOption.find(" ") + 1, userOption.length());
          save(saveFileName, currentPlayer);
          gameSaved = true;

          std::cout << "Game successfully saved" << '\n';
        }

      }
      //quit the game
      else if (userOption.compare("quit") == 0) {

        quit = true;
      }

      //help options
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

      // check if player quit
      if (quit == true) {

        turnEnded = true;
        gameEnded = true;
      }

      //check for invalid input
      if (turnEnded == false && gameSaved == false && helped == false) {

        std::cout << "Invalid input" << '\n';
        std::cout << "Enter 'help' for command list" << '\n';
      }

      //check for turn ended
      if (turnEnded == true) {

        //check game is over
        if (this->gameEngine.checkGameOver() == true) {

          std::cout << "Game over" << '\n';

          int winnerScore = 0;
          int winner = 0;

          for (int i = 0; i < 4; i++) {

            //print the players final scores
            std::cout << "Score for ";
            std::cout << this->gameEngine.getPlayer(i)->getName();
            std::cout << ": ";
            std::cout << this->gameEngine.getPlayer(i)->getScore() << '\n';

            if (this->gameEngine.getPlayer(i)->getScore() > winnerScore) {

              winnerScore = this->gameEngine.getPlayer(i)->getScore();
              winner = i;
            }
          }

          std::cout << "Player " << this->gameEngine.getPlayer(winner)->getName();
          std::cout << " won!" << '\n';

          gameEnded = true;
        }

        //if the player is the fourth, the next player is the first player
        if (currentPlayer == 3) {

          currentPlayer = 0;
        }
        else {
          currentPlayer++;
        }
      }
    }
  }
}

//saves the current game
void Game::save(std::string fileName, int currentPlayer)
{
  fileName += ".save";
  std::ofstream outFile;

  outFile.open(fileName);

  outFile << this->gameEngine.toString(currentPlayer);
  outFile.close();
}

//loads in a game
bool Game::loadGame(std::string fileName)
{
  bool gameLoaded = false;
  std::string line;
  fileName += ".save";
  std::ifstream openFile(fileName);

  //check if file exist
  if (openFile.is_open()) {

    //creating players from file
    Player* p1 = loadPlayer(openFile);
    Player* p2 = loadPlayer(openFile);
    Player* p3 = loadPlayer(openFile);
    Player* p4 = loadPlayer(openFile);

    //creating board
    int* boardSize = new int(0);
    Tile*** board = loadBoard(openFile, boardSize);

    //creating bag
    Bag* bag = loadBag(openFile);

    //checking the current players turn
    getline(openFile, line);
    std::string currentPlayer = line;
    int currentPlayerNum = 0;

    if (currentPlayer.compare(p1->getName()) == 0) {

      currentPlayerNum = 0;
    }
    else if (currentPlayer.compare(p2->getName()) == 0) {

      currentPlayerNum = 1;
    }
    else if (currentPlayer.compare(p3->getName()) == 0) {

      currentPlayerNum = 2;
    }
    else if (currentPlayer.compare(p4->getName()) == 0) {

      currentPlayerNum = 3;
    }

    //creating the loaded game
    this->gameEngine = GameEngine(p1, p2, p3, p4, bag, board, *boardSize);

    gameLoaded = true;
    openFile.close();
    std::cout << "Qwirkle game successfully loaded" << '\n';

    //start the game from the loaded player
    startGame(currentPlayerNum);
  }
  else {
    std::cout << "Invalid Input" << '\n';
  }

  return gameLoaded;
}

//loads in the player info
Player* Game::loadPlayer(std::ifstream& openFile)
{
  Player* player = nullptr;

  if (openFile.is_open()) {

    // loading the player name and score
    std::string line;
    getline(openFile, line);
    std::string playerName;
    playerName = line;
    int playerScore;

    //getting the player hand
    getline(openFile, line);
    playerScore = std::atoi(&line[0]);

    getline(openFile, line);
    std::string handString;
    handString = line;
    std::string tile;

    //converting playerhand into a linkedlist
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

    //creating player
    player = new Player(playerName, playerScore, playerHand);

  }
  return player;
}

//loads in the board
Tile*** Game::loadBoard(std::ifstream& openFile, int* boardSize)
{
  std::string line;
  Tile*** board = nullptr;
  if (openFile.is_open()) {

    //reading the xAxis
    getline(openFile, line);
    std::string xAxis;
    xAxis = line;
    int rowCount = 0;

    //calculating teh board size
    for (size_t i = 0; i < xAxis.size(); i++) {

      if(std::isdigit(xAxis[i]))
      {
        rowCount++;
      }
    }

    if (rowCount > 10) {

      rowCount = rowCount - 10;
      rowCount = rowCount/2;
      rowCount = rowCount + 10;
    }

    *boardSize = rowCount;

    //creating board
    board = new Tile**[rowCount];
    for(int i = 0; i < rowCount; i++)
    {
      board[i] = new Tile*[rowCount];
    }

    for (int i = 0; i < rowCount; i++) {

      for (int j = 0; j < rowCount; j++) {

        board[i][j] = nullptr;
      }
    }

    //adding the tiles into the board
    getline(openFile, line);
    for (int i = 0; i < rowCount; i++) {

      getline(openFile, line);
      std::string row = line.substr(line.find("|") + 1, line.length());
      for (int j = 0; j < rowCount; j++) {

        if (line.find("|") != std::string::npos) {

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

//loads in the bag
Bag* Game::loadBag(std::ifstream& openFile)
{
  Bag* testBag = nullptr;
  if (openFile.is_open()) {
    std::string line;

    // geting the bag
    getline(openFile, line);
    std::string bag = line;

    // creating the bag linked list
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

    //creating the bag
    testBag = new Bag(bagTiles);
  }

  return testBag;
}

//checks if the string is all caps
bool Game::checkAllCaps(std::string checkString)
{
  bool allCaps = true;

  for (int i = 0; i < (int)checkString.length(); i++) {

    char c = checkString[i];
    if (islower(c) != 0) {

      allCaps = false;
    }
  }

  return allCaps;
}
