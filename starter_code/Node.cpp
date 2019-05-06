
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   // TODO
   this->tile = tile;
   this->next = next;
}

Node::Node(Node& other)
{
   // TODO
   this->tile = other->tile;
   this->next = other->next;
}

Node::~Node() {
  if (this->next == nullptr)
  {
    delete this->next;
  }
  delete this->tile;
}

Tile* Node::getTile()
{
  return this->tile;
}

Next* Node::getNext()
{
  return this->next;
}

void Node::setNext(Node* nextNode)
{
  this->next* = nextNode;
}
