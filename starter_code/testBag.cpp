#include "Bag.h"
#include <iostream>
using namespace std;
int main() {
	Bag bag;
	bag._testToShowTiles();
	cout << endl;

	bag.getTile();
	bag._testToShowTiles();
	cout << endl;

	Tile tile('R', 1);
	bag.addTile(new Tile('R', 1));
	bag._testToShowTiles();
	cout << endl;
	return 0;
}
