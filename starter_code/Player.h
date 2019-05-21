#include "LinkedList.h"
#include "Bag.h"
#include <string>
#include <cstddef>
#include "Tile.h"
#include "TileCodes.h"

//player class hols all the player information
class Player {
  public:
    Player();

    //Constructor for a load game
    Player(std::string name, int score, LinkedList* hand);

    // Constructor for a new game
    Player(std::string name);

    LinkedList* getHand();

    //adds the begining hand
    void initalHand(Bag* bag);

    //prints the players hand to console, in to string format
    void printHand();

    int getScore();

    std::string getName();

    void setScore(int score);

    //add an amount to the players score
    void addScore(int plusValue);

    //add a node
    void addToHand(Tile* addTile);

    //replace tile with bag
    void replaceFromHand(Tile* removeTile, Bag* bag);

    //return a tile and get a new tile from bag
    Tile* placeTile(Tile* placedTile, Bag* bag);

    //converts player info into a readable string
    std::string toString();
    
  private:
    LinkedList* hand;
    std::string name;
    int score;
};
