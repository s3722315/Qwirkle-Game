
#include "Tile.h"

// Empty... for now?
Tile::Tile(Colour colour, Shape shape)
{
  this->colour = colour;
  this->shape = shape;
}

Shape Tile::getShape()
{
  return this->shape;
}
Colour Tile::getColour()
{
  return this->colour;
}
