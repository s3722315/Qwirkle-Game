
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
  clear();
}

 //add a Tile to the front of the linked list
void LinkedList::addFront(Tile* data)
{
  Node* newNode = new Node(data, this->head);
  this->head = newNode;
}

//add a Tile to the back of the linked list
void LinkedList::addBack(Tile* data)
{
  if (data != nullptr)
  {

    Node* newNode = new Node(data, nullptr);
    //if the linked list is empty
    if (this->head == nullptr)
    {

      this->head = newNode;
    }
    else
    {
      //if the linked list has nodes
      Node* currentNode = this->head;
      bool nodeAdded = false;
      while (currentNode != nullptr && nodeAdded == false)
      {

        if (currentNode->next == nullptr)
        {
          currentNode->next = newNode;
          nodeAdded = true;
        }

        currentNode = currentNode->next;
      }
    }

  }
}

//this will search for a specific tile and delete that node.
void LinkedList::removeNode(Tile* tileMatch)
{
  Node* currentNode = this->head;
  Node* previousNode = nullptr;
  bool hasTile = false;


  while (currentNode != nullptr && hasTile == false)
  {
    //comparing tiles in the linked list to see if the tile is in the node
    if (currentNode->tile->colour == tileMatch->colour &&
      currentNode->tile->shape == tileMatch->shape)
    {
      //if at front
      if (previousNode == nullptr) {
        deleteFront();
      }
      else
      {

        //if the node is in the middle or end of the linked list
        previousNode->next = currentNode->next;
        currentNode->tile = nullptr;
        delete currentNode;
        currentNode = nullptr;
      }
      hasTile = true;
    }
    else
    {
      //next nodes checked
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

  }
}

// deletes the node at the front
void LinkedList::deleteFront()
{
  if (this->head != nullptr)
  {
    Node* front = this->head;
    this->head = front->next;
    delete front;
  }
}

// deletes the node at the end
void LinkedList::deleteBack()
{
  Node* currentNode = this->head;
  Node* previousNode = nullptr;
  while (currentNode !=nullptr)
  {
    if (currentNode->next == nullptr)
    {
      if (previousNode != nullptr)
      {
        previousNode->next = nullptr;
      }

      delete currentNode;
      currentNode = nullptr;
    }
    else
    {
      previousNode = currentNode;
			currentNode = currentNode->next;
    }
  }
}

//prints the linkedlist to console
void LinkedList::printAll() {
	Node* currentNode = this->head;
	while (currentNode != nullptr) {
		std::cout << currentNode->tile->colour<< currentNode->tile->shape;
		if (currentNode->next) {
			std::cout << ",";
		}
		currentNode = currentNode->next;
	}
}

Tile* LinkedList::getFront() {
	Tile* returnTile = nullptr;
  if (this->head != nullptr) {

    returnTile = this->head->tile;
  }

  return returnTile;
}

Tile* LinkedList::getBack() {
	Tile* returnTile = nullptr;
  if (this->head != nullptr) {
    
    Node* currentNode = this->head;

    while (currentNode != nullptr) {

      if (currentNode->next == nullptr) {

        returnTile = currentNode->tile;
      }
      currentNode = currentNode->next;
    }
  }

  return returnTile;
}

//returns the wanted Tile
Tile* LinkedList::getSpecTile(Tile* specTile)
{
  Node* currentNode = this->head;
  Tile* wantedTile = nullptr;
  bool hasTile = false;
  if (specTile != nullptr) {

    while (currentNode != nullptr && hasTile == false)
    {
      if (currentNode->tile->colour == specTile->colour &&
        currentNode->tile->shape == specTile->shape)
      {
        wantedTile = currentNode->tile;
        hasTile = true;
      }
      currentNode = currentNode->next;
    }
  }

  return wantedTile;
}

// clears the whole LinkedList, deletes everything
void LinkedList::clear()
{
  int nodeCount = size();
  for (int i = 0; i < nodeCount; i++) {
    delete this->head->tile;
    deleteFront();
  }
}

// gives the size of the linkedlist
int LinkedList::size()
{
  int count = 0;
  Node* currentNode = this->head;
  while (currentNode != nullptr) {

    count++;
    currentNode = currentNode->next;
  }
  return count;
}

// Checks if the tile wanted exist in the linkedList
bool LinkedList::contains(Tile* tileCheck)
{
  Node* currentNode = this->head;
  bool hasTile = false;
  if (tileCheck != nullptr) {

    while (currentNode != nullptr && hasTile == false)
    {
      if (currentNode->tile->colour == tileCheck->colour &&
        currentNode->tile->shape == tileCheck->shape)
      {
        hasTile = true;
      }
      currentNode = currentNode->next;
    }
  }
  return hasTile;
}


std::string LinkedList::toString()
{
  std::string returnString = "";

  Node* currentNode = this->head;
	while (currentNode != nullptr) {
		returnString += currentNode->tile->colour;
    returnString += std::to_string(currentNode->tile->shape);
		if (currentNode->next) {
      returnString += ",";
		}
		currentNode = currentNode->next;
	}

  return returnString;
}
