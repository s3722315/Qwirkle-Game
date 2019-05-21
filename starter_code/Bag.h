#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"
#include <string>
#include <vector>
#include <random>
#include <time.h>

class Bag {
public:
	// constructor for a new Game
	Bag();

	//constructor for a load game
	Bag(LinkedList* tiles);
	// to get a tile from the linked list, it will remove a tile at the begin of the linked list
	// in this function we prefer returning a tile object from the linked list rather than LinkedList*,
	// it will be used to send a tile to player and then the player can store the tile to his hand easily
	// LinkedList.h should contain a function returning the first tile in the linked list
	Tile* getTile();

	// add a tile into bag
	void addTile(Tile* tile);


	std::string toString();


private:
	
	LinkedList* tiles;
};
