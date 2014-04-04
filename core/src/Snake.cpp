//
// Snake.cpp for nibbler in /home/ubuntu/rendu/cpp_nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Fri Apr  4 16:24:06 2014 chauvo_t
// Last update Fri Apr  4 16:29:05 2014 chauvo_t
//

#include "../../interface/Snake.hh"

unsigned int	Snake::speed() const
{
  return (this->_speed);
}

void	Snake::setSpeed(unsigned int speed)
{
  this->_speed = speed;
}

Snake::Snake() {}
