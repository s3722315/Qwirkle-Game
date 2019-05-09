
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
  clear();
}

void LinkedList::addFront(Tile data)
{
  Node* newNode = new Node(data, this->head);
  this->head = newNode
}

void LinkedList::addBack(Tile data)
{
  if (data != NULL)
  {

    Node* newNode = new Node(data, nullptr);
    if (this->head == nullptr)
    {

      this->head = newNode;
    }
    else
    {
      Node* currentNode = this->head;
      while (currentNode != nullptr)
      {

        if (currentNode->next == nullptr)
        {
          currentNode->next = newNode;
        }

        currentNode = currentNode->next;
      }
    }

  }
}

void LinkedList::removeNode(Tile tileMatch)
{
  Node* currentNode = this->head;
  Node* previousNode = nullptr;
  bool hasTile = false;


  while (currentNode != nullptr && hasTile == false)
  {
    if (currentNode->tile->colour = tileMatch->colour &&
      currentNode->tile->shape = tileMatch->shape)
    {

      if (previousNode == nullptr) {
        deleteFront();
      }
      else
      {

        previousNode->next = currentNode->next;
        currentNode->tile = nullptr;
        delete currentNode;
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
    delete front->tile;
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

      delete currentNode->tile;
      delete currentNode;
    }
  }
}

void LinkedList::clear()
{
  int nodeCount = size();
  for (int i = 0; i < nodeCount; i++) {
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
    currentNode = currentNode->;
  }
  return count;
}

bool LinkedList::contains(Tile tileCheck)
{
  Node* currentNode = this->head;
  bool hasTile = false;
  if (tileCheck != NULL) {

    while (currentNode != nullptr && hasTile == false)
    {
      if (currentNode->tile->colour = tileCheck->colour &&
        currentNode->tile->shape = tileCheck->shape)
      {
        hasTile = true;
      }
    }
  }
  return hasTile;
}
