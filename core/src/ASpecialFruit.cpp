//
// ASpecialFruit.cpp for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  9 11:37:57 2014 chauvo_t
// Last update Thu Apr 10 11:20:43 2014 chauvo_t
//

#include "../../interface/ASpecialFruit.hh"

// Public

int	ASpecialFruit::getTimer() const
{
  return (_timer);
}

void	ASpecialFruit::setTimer(int time)
{
  _timer = time;
}

void	ASpecialFruit::tick()
{
  --_timer;
}

// Private
