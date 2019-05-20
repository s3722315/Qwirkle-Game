#include "Player.h"
Player::Player(){}

Player::Player(std::string name, int score, LinkedList* hand)
{
	this->name = name;
	this->score = score;
	this->hand = hand;
}

Player::Player(std::string name) {
	this->name = name;
	this->score = 0;
	this->hand = new LinkedList();
}
LinkedList* Player::getHand()
{
	return this->hand;
}

void Player::initalHand(Bag* bag) {
	const int numsOfTiles = 6;
	for (int i = 0; i < numsOfTiles; ++i) {
		Tile* tile = bag->getTile();
		addToHand(tile);
	}
}

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
void Player::addScore(int plusValue) {
	this->score += plusValue;
}

void Player::addToHand(Tile* addTile) {
	this->hand->addBack(addTile);
}

void Player::replaceFromHand(Tile* removeTile, Bag* bag) {
	if (this->hand->contains(removeTile)) {

		Tile* movedTile = this->hand->getSpecTile(removeTile);
		this->hand->removeNode(removeTile);

		Tile* addedTile = bag->getTile();
		addToHand(addedTile);

		bag->addTile(movedTile);
	}
}

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

std::string Player::toString()
{
	std::string returnString = "";
	if (this->name.empty() == false) {
		/* code */
		returnString += this->name;
		returnString += '\n';
		returnString += std::to_string(this->score);
		returnString += '\n';

		returnString += hand->toString();
	}
	return returnString;
}
