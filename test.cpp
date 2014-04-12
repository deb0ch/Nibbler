//
// test.cpp for lol in /home/ubuntu/perso/nibbler
//
// Made by chauvo_t
// Login   <chauvo_t@epitech.net>
//
// Started on  Thu Apr 10 11:53:54 2014 chauvo_t
// Last update Thu Apr 10 11:56:41 2014 chauvo_t
//

#include <cstdlib>
#include <iostream>
#include <ctime>

bool	probaRand(double proba)
{
  return (random() < RAND_MAX * proba);
}

int	main(int ac, char **av)
{
  int	count = 0;

  srandom(time(NULL));
  for (int i = 0; i < 100; ++i)
    {
      std::cout << (count += probaRand(1.0 / 10.0)) << std::endl;
    }
  return (0);
}
