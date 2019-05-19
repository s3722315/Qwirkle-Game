#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"
#include <string>
#include <vector>
#include <random>
#include <time.h>

class Bag {
public:
	// initial the tiles bag
	Bag();

	Bag(LinkedList* tiles);
	// to get a tile from the linked list, it will remove a tile at the begin of the linked list
	// in this function we prefer returning a tile object from the linked list rather than LinkedList*,
	// it will be used to send a tile to player and then the player can store the tile to his hand easily
	// LinkedList.h should contain a function returning the first tile in the linked list
	Tile* getTile();

	// add a tile into bag
	void addTile(Tile* tile);

	// to should tiles in LinkedList "tiles"
	std::string toString();

	//tell us when you update the file

private:
	// tiles should not be a pointer
	LinkedList* tiles;
};
