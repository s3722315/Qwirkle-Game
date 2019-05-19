#include "Bag.h"
#include <vector>
#include <random>
#include <time.h>

Bag::Bag() {
	// the nums of the same tiles
	const int numsOfTheSameTile = 2;
	// use vectors to store the necessary attributes to initial Bag
	std::vector<Colour> colourVec{ RED ,ORANGE ,YELLOW ,GREEN ,BLUE ,PURPLE };
	std::vector<Shape> shapeVec{ CIRCLE ,STAR_4 ,DIAMOND ,SQUARE ,STAR_6 ,CLOVER };
	// we do NOT use vector to store the tileVec during the game,
	// but use it to make initial process easier
	std::vector<Tile> tileVec;
	// create the tiles for each cell of the board
	for (int numsOfColours = 0; numsOfColours < (int)colourVec.size(); ++numsOfColours) {
		for (int numsOfShape = 0; numsOfShape < (int)shapeVec.size(); ++numsOfShape) {
			// create tiles and add them into tileVec
			for (int numsOfTiles = 0; numsOfTiles < (int)numsOfTheSameTile; ++numsOfTiles) {
				tileVec.push_back(Tile(colourVec[numsOfColours], shapeVec[numsOfShape]));
			}
		}
	}
	//shuffling algorithm
	int sizeOfSwapIndex = tileVec.size();
	// set random number seed
	srand((unsigned)time(NULL));
	for (int i = 0; i < (int)(tileVec.size()-1); ++i) {
		// chose one of the tiles from 0 to sizeOfSwapIndex
		int swapIndex = rand() % sizeOfSwapIndex;
		// swap two tiles, and sizeOfSwapIndex-1
		std::swap(tileVec[swapIndex], tileVec[--sizeOfSwapIndex]);
	}
	// add tiles to linked list
	for (int i = 0; i < (int)tileVec.size(); ++i) {
		tiles.addBack(new Tile(tileVec[i].colour, tileVec[i].shape));
	}
}

Bag::Bag(LinkedList tiles) {
	this->tiles = tiles;
}

Tile* Bag::getTile() {
	Tile* resultTile = this->tiles.getFront();
	this->tiles.deleteFront();
	return resultTile;
}

void Bag::addTile(Tile* tile) {
	this->tiles.addBack(tile);
}


std::string Bag::toString() {
	return this->tiles.toString();
}
