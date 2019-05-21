#include "Player.h"
Player::Player(){}

//Constructor for a load game
Player::Player(std::string name, int score, LinkedList* hand)
{
	this->name = name;
	this->score = score;
	this->hand = hand;
}

// Constructor for a new game
Player::Player(std::string name) {
	this->name = name;
	this->score = 0;
	this->hand = new LinkedList();
}
LinkedList* Player::getHand()
{
	return this->hand;
}

//adds the begining hand
void Player::initalHand(Bag* bag) {
	const int numsOfTiles = 6;
	for (int i = 0; i < numsOfTiles; ++i) {
		Tile* tile = bag->getTile();
		addToHand(tile);
	}
}

//prints the players hand to console, in to string format
void Player::printHand() {
	this->hand->printAll();
}

int Player::getScore() {
	return this->score;
}

std::string Player::getName() {
	return this->name;
}

void Player::setScore(int score) {
	this->score = score;
}

//add an amount to the players score
void Player::addScore(int plusValue) {
	this->score += plusValue;
}

//add a node
void Player::addToHand(Tile* addTile) {
	this->hand->addBack(addTile);
}

//replace tile with bag
void Player::replaceFromHand(Tile* removeTile, Bag* bag) {
	//check if tile is in hand
	if (this->hand->contains(removeTile)) {

		//get the tile for return and remove it from hand
		Tile* movedTile = this->hand->getSpecTile(removeTile);
		this->hand->removeNode(removeTile);

		//get a tile from the bag and add to hand
		Tile* addedTile = bag->getTile();
		addToHand(addedTile);

		bag->addTile(movedTile);
	}
}

//return a tile and get a new tile from bag
Tile* Player::placeTile(Tile* placedTile, Bag* bag)
{
	Tile* placingTile = nullptr;
	if (this->hand->contains(placedTile)) {

		placingTile = this->hand->getSpecTile(placedTile);
		this->hand->removeNode(placedTile);

		Tile* addedTile = bag->getTile();
		addToHand(addedTile);
	}

	return placingTile;
}

//converts player info into a readable string
std::string Player::toString()
{
	std::string returnString = "";
	if (this->name.empty() == false) {

		returnString += this->name;
		returnString += '\n';
		returnString += std::to_string(this->score);
		returnString += '\n';

		returnString += hand->toString();
	}
	return returnString;
}
