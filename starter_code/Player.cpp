#include "Player.h"
Player::Player(std::string name, int score, LinkedList* hand)
{
	this->name = name;
	this->score = score;
	this->hand = hand;
}

Player::Player(std::string name) {
	this->name = name;
	this->score = 0;
}
LinkedList* getHand()
{
	return this->hand;
}

void Player::initalHand(Bag* bag) {
	const int numsOfTiles = 6;
	for (int i = 0; i < numsOfTiles; ++i) {
		Tile* tile = bag.getTile();
		addToHand(tile);
	}
}

void Player::printHand() {
	this->hand.printAll();
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
	this->hand.addBack(addTile);
}

void Player::removeFromHand(Tile* removeTile, Bag* bag) {
	if (this->hand.contains(removeTile)) {

		Tile* movedTile = removeTile;
		this->hand.removeNode(removeTile);

		Tile* addedtile = bag.getTile();
		this->addToHand(addedTile);

		bag->addTile(movedTile);
	}
}

Tile* Player::placeTile(Tile* placedTile, Bag* bag)
{
	Tile* placingTile = nullptr;
	if (this->hand.contains(placedTile)) {

		placingTile = this->hand.getSpecTile(placedTile);
		this->hand.removeNode(placedTile);

		Tile* addedtile = bag.getTile();
		this->addToHand(addedTile);
	}

	return placingTile;
}
