
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   void addFront(Tile data);
   void addBack(Tile data);

   void removeNode(Tile tileMatch);

   void deleteFront();
   void deleteBack();

   void clear();

   int size();

   bool contains(Tile tileCheck);

private:
   Node* head;
};



#endif // ASSIGN2_LINKEDLIST_H
