//
// Game.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  2 14:12:21 2014 chauvo_t
// Last update Fri Apr 11 00:39:04 2014 chauvo_t
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

int	GameBoard::score() const
{
  return (_score);
}

int	GameBoard::snakeSpeed() const
{
  return (_snakeSpeed);
}

void	GameBoard::setWidth(int width)
{
  _width = width;
}

void	GameBoard::setHeight(int height)
{
  _height = height;
}

void	GameBoard::setScore(int score)
{
  _score = score;
}

void	GameBoard::addScore(int score)
{
  _score += (score * (this->snakeSpeed()) / 100.0);
}

void	GameBoard::setSnakeSpeed(int speed)
{
  _snakeSpeed = speed;
}

void	GameBoard::addSnakeSpeed(int speed)
{
  _snakeSpeed += speed;
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
