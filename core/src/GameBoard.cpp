//
// Game.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:21 2014 chauvo_t
// Last update Sat Apr  5 16:02:27 2014 chauvo_t
//

#include "../../interface/GameBoard.hh"

// Public

int	GameBoard::width() const
{
  return (_width);
}

int	GameBoard::height() const
{
  return (_height);
}

void	GameBoard::setWidth(int width)
{
  _width = width;
}

void	GameBoard::setHeight(int height)
{
  _height = height;
}

const std::list<SnakeRing*>&	GameBoard::snake() const
{
  return (_snake);
}

std::list<SnakeRing*>&	GameBoard::snake()
{
  return (_snake);
}

const std::list<Fruit*>&	GameBoard::fruits() const
{
  return (_fruits);
}

std::list<Fruit*>&	GameBoard::fruits()
{
  return (_fruits);
}

// Private
