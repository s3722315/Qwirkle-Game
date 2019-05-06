
#include "LinkedList.h"

LinkedList::LinkedList() {
   this->head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
  delete this->head;
}

void LinkedList::addNode(Node* nodeAdding)
{
  if (this->head == nullptr)
  {

    this->head = nodeAdding;
  }
  else
  {
    Node* currentNode = (this->head)*;
    while (currentNode* != NULL)
    {

      if (currentNode*.getNext() == nullptr)
      {

        currentNode*.setNext(nodeAdding);
      }

      currentNode = currentNode*.getNext();
    }
  }
}

void LinkedList::removeNode(tile tileMatch)
{
  Node* currentNode = (this->head)*;
  Node* previousNode = nullptr;
  bool hasTile = false;
  while (currentNode != nullptr && hasTile == false)
  {

     if ((currentNode*.getTile())*.getColour() == tileMatch.getColour() &&
     (currentNode*.getTile())*.getShape() == tileMatch.getShape())
     {

       hasTile = true;
     }
     else
     {
       previousNode* = currentNode*;
       currentNode* = (currentNode*.getNext())*;
     }
  }

  if (hasTile == true)
  {
    if (previousNode == nullptr)
    {

      if (currentNode*.getNext() == nullptr)
      {
        this->head = nullptr;
        delete currentNode;
      }
      else
      {

        this->head = (currentNode*.getNext())*;
        delete currentNode;
      }
    }
    else
    {
      if (currentNode*.getNext() == nullptr) {
        /* code */
        previousNode*.setNext(nullptr);
        delete currentNode;
      }
      else
      {
        previousNode*.setNext(currentNode*.getNext());
        delete currentNode;
      }
    }
  }
}

void LinkedList::clear()
{
  while (this->head ==) {
    /* code */
  }
}
