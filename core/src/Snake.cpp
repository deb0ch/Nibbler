//
// Snake.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Fri Apr  4 16:24:06 2014 chauvo_t
// Last update Fri Apr  4 22:59:57 2014 chauvo_t
//

#include "../../interface/Snake.hh"

// Public

const std::list<SnakeRing>&	Snake::getRings() const
{
  return (_rings);
}

std::list<SnakeRing>*		Snake::getSnake()
{
  return (&_rings);
}
