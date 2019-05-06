//player class
LinkedList* getHand();
String getPlayerInfo();


//gameengine class
void exapand2DArray();

//this will be used to check if the position on the 2dArray board is blank or not
boolean checkPosition(int yPos, int xPos);

//this will be used to place a tile into a certain position
void placeTile(Player player, Tile tile, int yPos, int xPos);

//this will be used to replace a tile in the players hand with a tile in the bag
void replaceTile(Player player, Tile tile);

//this will check if a game has ended. this will check both players hands and
//the bag for tiles. if they are empty end the game.
void checkGameEnded();
