
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
   //add a Tile to the front of the linked list
   void addFront(Tile* data);
   //add a Tile to the back of the linked list
   void addBack(Tile* data);

   //this will search for a specific tile and delete that node.
   void removeNode(Tile* tileMatch);
   // deletes the node at the front
   void deleteFront();
   // deletes the node at the end
   void deleteBack();

   //prints the linkedlist to console
   void printAll();

   Tile* getFront();

   Tile* getBack();

   //returns the wanted Tile
   Tile* getSpecTile(Tile* specTile);
   // clears the whole LinkedList, deletes everything
   void clear();
   // gives the size of the linkedlist
   int size();
   // CHhcks if the tile wanted exist in the linkedList
   bool contains(Tile* tileCheck);

   std::string toString();
private:
   Node* head;
};



#endif // ASSIGN2_LINKEDLIST_H
