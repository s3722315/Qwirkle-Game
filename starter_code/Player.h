#include "LinkedList.h"
#include <string>

//player class hols all the player information
class Player {
  public:
    Player(std::string Name, std::string studentId, std::string email);

    LinkedList* getHand();

    int getScore();
    std::string getEmail();
    std::string getName();
    std::string getStudentId();

    void setScore(int score);
    void addScore(int plusValue);
    
    //add a node
    void addToHand(Tile addTile);
    //delete a node
    void removeFromHand(Tile removeTile);

  private:
    LinkedList* Hand;
    std::string email;
    std::string name;
    std::string studentId;
    int score;
};
