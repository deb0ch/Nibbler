//
// Randomizer.cpp for nibbler in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Wed Apr  9 10:51:36 2014 chauvo_t
// Last update Thu Apr 10 01:02:38 2014 chauvo_t
//

#include "../include/Randomizer.hh"

// Public

int	Randomizer::rangeRand(int from, int to)
{
  if (from >= to)
    return (0);
  return (random() % (to - from + 1) + from);
}

bool	Randomizer::probaRand(double proba)
{
  return (random() < RAND_MAX * proba);
}

Randomizer::Randomizer()
{
  srandom(time(NULL));
}

// Private
