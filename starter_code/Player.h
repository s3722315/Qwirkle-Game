#include "LinkedList.h"
#include <string>

class Player {
  public:
    Player(std::string Name, std::string studentId, std::string email);

    LinkedList getHand();

    int getScore();
    std::string getEmail();
    std::string getName();
    std::string getStudentId();

    void setScore();
    void addScore(int plusValue);

    void addToHand(Tile addTile);
    void removeFromHand(Tile removeTile);

  private:
    LinkedList* Hand;
    std::string email;
    std::string name;
    std::string studentId;
    int score;
};
