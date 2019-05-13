
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
  clear();
}

void LinkedList::addFront(Tile* data)
{
  Node* newNode = new Node(data, this->head);
  this->head = newNode;
}

void LinkedList::addBack(Tile* data)
{
  if (data != nullptr)
  {

    Node* newNode = new Node(data, nullptr);
    if (this->head == nullptr)
    {

      this->head = newNode;
    }
    else
    {
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

void LinkedList::removeNode(Tile* tileMatch)
{
  Node* currentNode = this->head;
  Node* previousNode = nullptr;
  bool hasTile = false;


  while (currentNode != nullptr && hasTile == false)
  {
    if (currentNode->tile->colour == tileMatch->colour &&
      currentNode->tile->shape == tileMatch->shape)
    {

      if (previousNode == nullptr) {
        deleteFront();
      }
      else
      {

        previousNode->next = currentNode->next;
        currentNode->tile = nullptr;
        delete currentNode;
        currentNode = nullptr;
      }
      hasTile = true;
    }
    else
    {
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

  }
}

void LinkedList::deleteFront()
{
  if (this->head != nullptr)
  {
    Node* front = this->head;
    this->head = front->next;
    delete front;
  }
}

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

void LinkedList::printAll() {
	Node* currentNode = this->head;
	while (currentNode != nullptr) {
		std::cout << currentNode->tile->colour<< currentNode->tile->shape;
		if (currentNode->next) {
			std::cout << ", ";
		}
		currentNode = currentNode->next;
	}
}

Tile* LinkedList::getFront() {
	Tile* returnTile = nullptr;
  if (this->head != nullptr) {
    /* code */
    returnTile = this->head->tile;
  }

  return returnTile;
}

Tile* LinkedList::getBack() {
	Tile* returnTile = nullptr;
  if (this->head != nullptr) {
    /* code */
    Node* currentNode = this->head;

    while (currentNode != nullptr) {
      /* code */
      if (currentNode->next == nullptr) {
        /* code */
        returnTile = currentNode->tile;
      }
      currentNode = currentNode->next;
    }
  }

  return returnTile;
}

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

void LinkedList::clear()
{
  int nodeCount = size();
  for (int i = 0; i < nodeCount; i++) {
    delete this->head->tile;
    deleteFront();
  }
}

int LinkedList::size()
{
  int count = 0;
  Node* currentNode = this->head;
  while (currentNode != nullptr) {
    /* code */
    count++;
    currentNode = currentNode->next;
  }
  return count;
}

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
