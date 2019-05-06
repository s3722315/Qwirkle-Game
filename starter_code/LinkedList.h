
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   void addNode(Node* nodeAdding);

   void removeNode(tile tileMatch);

   void clear();
private:
   Node* head;
};



#endif // ASSIGN2_LINKEDLIST_H
