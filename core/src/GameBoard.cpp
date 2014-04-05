//
// Game.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:21 2014 chauvo_t
// Last update Sat Apr  5 11:30:59 2014 chauvo_t
//

#include "../../interface/GameBoard.hh"

// Public

int	GameBoard::width() const
{
  return (this->_width);
}

int	GameBoard::height() const
{
  return (this->_height);
}

void	GameBoard::setWidth(int width)
{
  this->_width = width;
}

void	GameBoard::setHeight(int height)
{
  this->_height = height;
}

Snake			&GameBoard::snake() const
{
  return (this->_snake);
}

Snake			&GameBoard::snake()
{
  return (this->_snake);
}

std::list<Fruit>	&GameBoard::fruits()
{
  return (this->_fruits);
}

GameBoard::GameBoard() {}

GameBoard::~GameBoard() {}

// Private
