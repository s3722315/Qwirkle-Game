#include "Bag.h"
#include <iostream>

int main() {
	Bag bag;
		std::cout << bag.toString() << '\n';

	Tile* taken = bag.getTile();
		std::cout << bag.toString() << '\n';

	bag.addTile(new Tile('R', 1));
	std::cout << bag.toString() << '\n';

	bag.addTile(taken);
	std::cout << bag.toString() << '\n';
	return 0;
}
