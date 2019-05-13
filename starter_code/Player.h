#include "LinkedList.h"
#include "Bag.h"
#include <string>

//player class hols all the player information
class Player {
  public:
    Player(std::string name, int score, LinkedList* hand);

    Player(std::string name);
    LinkedList* getHand();

    void initalHand(Bag* bag);

    void printHand();

    int getScore();

    std::string getName();

    void setScore(int score);
    void addScore(int plusValue);

    //add a node
    void addToHand(Tile* addTile);
    //delete a node
    void replaceFromHand(Tile* removeTile, Bag* bag);

    Tile* placeTile(Tile* placedTile, Bag* bag);

  private:
    LinkedList* hand;
    std::string name;
    int score;
};
