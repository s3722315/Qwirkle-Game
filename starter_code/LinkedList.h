
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <cstddef>
#include <iostream>
#include <string>

class LinkedList {
public:

   LinkedList();
   ~LinkedList();
   //This will read in a tile, then add it to the front of the linked list
   void addFront(Tile* data);
   //this will read in a tile, then add it to the end of the linked List
   void addBack(Tile* data);

   //this will search for a specific tile and delete that node.
   void removeNode(Tile* tileMatch);
   // deletes the node at the front
   void deleteFront();
   // deletes the node at the end
   void deleteBack();

   void printAll();

   Tile* getFront();

   Tile* getBack();

   Tile* getSpecTile(Tile* specTile);
   // clears the whole LinkedList, deletes everything
   void clear();
   // gives the size of the linkedlist
   int size();
   // CHecks if the tile wanted exist in the linkedList
   bool contains(Tile* tileCheck);

   std::string toString();
private:
   Node* head;
};



#endif // ASSIGN2_LINKEDLIST_H
