//
// Game.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:21 2014 chauvo_t
// Last update Thu Apr  3 17:28:26 2014 chauvo_t
//

#include "../../interface/GameBoard.hh"

// Public

int	GameBoard::getWidth() const
{
  return (this->_width);
}

int	GameBoard::getHeight() const
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

GameBoard::GameBoard() {}

GameBoard::~GameBoard() {}

// Private
